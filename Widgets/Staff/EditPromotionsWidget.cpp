#include "EditPromotionsWidget.h"
#include "ui_EditPromotionsWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>
#include <QLocale>
#include <ctime>

EditPromotionsWidget::EditPromotionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPromotionsWidget),
    currentSelectedId(-1)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("EditPromotionsWidget");

    ui->tblPromos->setColumnCount(4);
    ui->tblPromos->setHorizontalHeaderLabels({"ID", "Name", "Rate", "Min Order"});

    QHeaderView* header = ui->tblPromos->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Fixed); ui->tblPromos->setColumnWidth(0, 50);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(2, QHeaderView::Fixed); ui->tblPromos->setColumnWidth(2, 80);
    header->setSectionResizeMode(3, QHeaderView::Fixed); ui->tblPromos->setColumnWidth(3, 120);

    ui->tblPromos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblPromos->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblPromos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblPromos->verticalHeader()->setVisible(false);

    setupStyle();
}

EditPromotionsWidget::~EditPromotionsWidget() { delete ui; }

void EditPromotionsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString EditPromotionsWidget::formatMoney(double amount) {
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German);
    return locale.toString(val);
}

void EditPromotionsWidget::refreshData() {
    loadTable();

    ui->txtAddName->clear();
    ui->txtAddCondition->clear();
    ui->txtAddMinAmount->clear();
    ui->spinAddRate->setValue(0);

    ui->grpEdit->setEnabled(false);
    ui->lblSelectedId->setText("Selected ID: -");
    ui->txtEditName->clear();
    ui->txtEditCondition->clear();
    ui->txtEditMinAmount->clear();
    ui->spinEditRate->setValue(0);
    currentSelectedId = -1;
}

void EditPromotionsWidget::loadTable() {
    ui->tblPromos->setRowCount(0);
    const auto& promos = system->getPromotions();

    for(const auto& p : promos) {
        int r = ui->tblPromos->rowCount();
        ui->tblPromos->insertRow(r);
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(p.getPromoId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tblPromos->setItem(r, 0, idItem);
        ui->tblPromos->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
        QString rateStr = QString::number(p.getDiscountRate() * 100) + "%";
        QTableWidgetItem* rateItem = new QTableWidgetItem(rateStr);
        rateItem->setTextAlignment(Qt::AlignCenter);
        ui->tblPromos->setItem(r, 2, rateItem);

        QString minStr = formatMoney(p.getMinOrderAmount());
        QTableWidgetItem* minItem = new QTableWidgetItem(minStr);
        minItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tblPromos->setItem(r, 3, minItem);
    }
}

void EditPromotionsWidget::on_tblPromos_cellClicked(int row, int column) {
    Q_UNUSED(column);
    currentSelectedId = ui->tblPromos->item(row, 0)->text().toInt();
    ui->lblSelectedId->setText("Selected ID: " + QString::number(currentSelectedId));
    ui->grpEdit->setEnabled(true);

    const auto& promos = system->getPromotions();
    for(const auto& p : promos) {
        if (p.getPromoId() == currentSelectedId) {
            ui->txtEditName->setText(QString::fromStdString(p.getName()));
            ui->txtEditCondition->setText(QString::fromStdString(p.getCondition()));
            ui->spinEditRate->setValue(p.getDiscountRate() * 100.0);
            ui->txtEditMinAmount->setText(QString::number((long long)p.getMinOrderAmount()));
            break;
        }
    }
}

void EditPromotionsWidget::on_btnAdd_clicked() {
    QString name = ui->txtAddName->text().trimmed();
    QString cond = ui->txtAddCondition->text().trimmed();
    double minAmt = ui->txtAddMinAmount->text().toLongLong();
    double rate = ui->spinAddRate->value() / 100.0;

    if (name.isEmpty() || minAmt < 0) {
        QMessageBox::warning(this, "Error", "Invalid input!");
        return;
    }
    int newId = system->getNewPromoId();
    Promotion p(newId, name.toStdString(), rate, cond.toStdString(), minAmt, 0, 0);
    system->addPromotion(p);
    system->saveAllData();
    QMessageBox::information(this, "Success", "Promotion added!");
    refreshData();
}

void EditPromotionsWidget::on_btnSave_clicked() {
    if (currentSelectedId == -1) return;

    QString name = ui->txtEditName->text().trimmed();
    QString cond = ui->txtEditCondition->text().trimmed();
    double minAmt = ui->txtEditMinAmount->text().toLongLong();
    double rate = ui->spinEditRate->value() / 100.0;

    if (name.isEmpty() || minAmt < 0) {
        QMessageBox::warning(this, "Error", "Invalid input!");
        return;
    }
    vector<Promotion>& promos = system->getPromotions();
    for(auto& p : promos) {
        if (p.getPromoId() == currentSelectedId) {
            p.setName(name.toStdString());
            p.setCondition(cond.toStdString());
            p.setDiscountRate(rate);
            p.setMinOrderAmount(minAmt);
            break;
        }
    }
    system->saveAllData();
    QMessageBox::information(this, "Success", "Promotion updated!");
    refreshData();
}

void EditPromotionsWidget::on_btnDelete_clicked() {
    if (currentSelectedId == -1) return;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Delete this promotion?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        system->removePromotion(currentSelectedId);
        system->saveAllData();
        QMessageBox::information(this, "Deleted", "Promotion deleted.");
        refreshData();
    }
}

void EditPromotionsWidget::on_btnBack_clicked() { emit backSignal(); }

void EditPromotionsWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"
        "QWidget#EditPromotionsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"
        "QLabel#lblTitle, QLabel#lblManageTitle { font-size: 20px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#lblHint { color: #777; font-style: italic; margin-top: 5px; }"
        "QLabel#lblSelectedId { font-weight: bold; color: #555; }"
        "QGroupBox { font-weight: bold; border: 1px solid #DDD; border-radius: 8px; margin-top: 20px; padding-top: 15px; background-color: #FAFAFA; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #1565C0; }"
        "QLineEdit, QDoubleSpinBox { background-color: #FFFFFF; border: 1px solid #DDD; border-radius: 8px; padding: 8px; color: #333; }"
        "QLineEdit:focus, QDoubleSpinBox:focus { border: 2px solid #1976D2; }"
        "QTableWidget { background-color: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 8px; gridline-color: #F0F0F0; color: #333; selection-background-color: #1976D2; selection-color: #FFFFFF; outline: 0; }"
        "QHeaderView::section { background-color: #F9FAFB; border: none; font-weight: bold; color: #1565C0; padding: 5px; border-bottom: 1px solid #DDD; }"
        "QPushButton { background-color: #1976D2; color: white; border-radius: 18px; padding: 10px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1565C0; }"
        "QPushButton#btnDelete { background-color: #D32F2F; }"
        "QPushButton#btnDelete:hover { background-color: #C62828; }"
        "QPushButton:disabled { background-color: #BDC3C7; }"
        "QPushButton#btnBack { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 20px; }"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"
        "Line#lineSeparator { border: 1px solid #EEEEEE; }"
        "QMessageBox QLabel { "
        "   color: #FFFFFF; "
        "   font-size: 14px; "
        "   font-weight: bold; "
        "}"
        "QMessageBox QPushButton { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border-radius: 5px; "
        "   padding: 5px 15px; "
        "   min-width: 60px; "
        "}"
        "QMessageBox QPushButton:hover { "
        "   background-color: #1565C0; "
        "}"
        );
}
