#include "EditCategoriesWidget.h"
#include "ui_EditCategoriesWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>

EditCategoriesWidget::EditCategoriesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditCategoriesWidget),
    currentSelectedCatId(-1)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("EditCategoriesWidget");

    ui->tblCategories->setColumnCount(3);
    ui->tblCategories->setHorizontalHeaderLabels({"ID", "Name", "Products"});
    ui->tblCategories->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tblCategories->setColumnWidth(0, 50);
    ui->tblCategories->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tblCategories->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tblCategories->setColumnWidth(2, 100);

    ui->tblCategories->verticalHeader()->setVisible(false);
    ui->tblCategories->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblCategories->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblCategories->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tblBlockingProducts->setColumnCount(3);
    ui->tblBlockingProducts->setHorizontalHeaderLabels({"ID", "Product Name", "Stock Info"});
    ui->tblBlockingProducts->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tblBlockingProducts->setColumnWidth(0, 50);
    ui->tblBlockingProducts->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tblBlockingProducts->setColumnWidth(1, 150);
    ui->tblBlockingProducts->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tblBlockingProducts->verticalHeader()->setVisible(false);

    setupStyle();
}

EditCategoriesWidget::~EditCategoriesWidget() { delete ui; }

void EditCategoriesWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void EditCategoriesWidget::refreshData() {
    ui->stackActions->setCurrentIndex(0);
    loadCategoriesTable();

    ui->txtNewName->clear();
    ui->txtEditName->clear();
    ui->lblSelectedId->setText("Selected ID: -");
    currentSelectedCatId = -1;
    ui->btnRename->setEnabled(false);
    ui->btnDelete->setEnabled(false);
}

int EditCategoriesWidget::countProductsInCategory(int catId) {
    int count = 0;
    for (const auto& p : system->getProducts()) {
        if (p.getCategoryId() == catId) count++;
    }
    return count;
}

void EditCategoriesWidget::loadCategoriesTable() {
    ui->tblCategories->setRowCount(0);
    for (const auto& cat : system->getCategories()) {
        int row = ui->tblCategories->rowCount();
        ui->tblCategories->insertRow(row);

        QTableWidgetItem* itemId = new QTableWidgetItem(QString::number(cat.getCategoryId()));
        itemId->setTextAlignment(Qt::AlignCenter);
        ui->tblCategories->setItem(row, 0, itemId);

        ui->tblCategories->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(cat.getName())));

        int prodCount = countProductsInCategory(cat.getCategoryId());
        QTableWidgetItem* itemCount = new QTableWidgetItem(QString::number(prodCount));
        itemCount->setTextAlignment(Qt::AlignCenter);
        ui->tblCategories->setItem(row, 2, itemCount);
    }
}

void EditCategoriesWidget::on_tblCategories_cellClicked(int row, int column) {
    Q_UNUSED(column);
    currentSelectedCatId = ui->tblCategories->item(row, 0)->text().toInt();
    QString name = ui->tblCategories->item(row, 1)->text();

    ui->lblSelectedId->setText("Selected ID: " + QString::number(currentSelectedCatId));
    ui->txtEditName->setText(name);
    ui->btnRename->setEnabled(true);
    ui->btnDelete->setEnabled(true);
}

int EditCategoriesWidget::getNewCategoryId() {
    int maxId = 0;
    for (const auto& cat : system->getCategories()) {
        if (cat.getCategoryId() > maxId) maxId = cat.getCategoryId();
    }
    return maxId + 1;
}

void EditCategoriesWidget::on_btnAdd_clicked() {
    QString name = ui->txtNewName->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a category name.");
        return;
    }

    int newId = getNewCategoryId();
    Category newCat(newId, name.toStdString());
    system->addCategory(newCat);
    system->saveAllData();

    QMessageBox::information(this, "Success", "Category added successfully!");
    refreshData();
}

void EditCategoriesWidget::on_btnRename_clicked() {
    if (currentSelectedCatId == -1) return;
    QString newName = ui->txtEditName->text().trimmed();
    if (newName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Name cannot be empty.");
        return;
    }

    vector<Category>& cats = const_cast<vector<Category>&>(system->getCategories());
    for (auto& cat : cats) {
        if (cat.getCategoryId() == currentSelectedCatId) {
            cat.setName(newName.toStdString());
            break;
        }
    }

    system->saveAllData();
    QMessageBox::information(this, "Success", "Category renamed!");
    refreshData();
}

void EditCategoriesWidget::on_btnDelete_clicked() {
    if (currentSelectedCatId == -1) return;

    vector<Product> blockingProds;
    for (const auto& p : system->getProducts()) {
        if (p.getCategoryId() == currentSelectedCatId) {
            blockingProds.push_back(p);
        }
    }

    if (!blockingProds.empty()) {
        ui->tblBlockingProducts->setRowCount(0);
        for(const auto& p : blockingProds) {
            int r = ui->tblBlockingProducts->rowCount();
            ui->tblBlockingProducts->insertRow(r);

            ui->tblBlockingProducts->setItem(r, 0, new QTableWidgetItem(QString::number(p.getProductId())));
            ui->tblBlockingProducts->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));

            QString sizeInfo = "";
            for(const auto& s : p.getSizes()) {
                sizeInfo += QString::fromStdString(s.getSizeName()) + ": " + QString::number(s.getQuantity()) + ", ";
            }
            if(sizeInfo.endsWith(", ")) sizeInfo.chop(2);

            ui->tblBlockingProducts->setItem(r, 2, new QTableWidgetItem(sizeInfo));
        }

        ui->stackActions->setCurrentIndex(1);
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this category?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        vector<Category>& cats = const_cast<vector<Category>&>(system->getCategories());
        for (auto it = cats.begin(); it != cats.end(); ++it) {
            if (it->getCategoryId() == currentSelectedCatId) {
                cats.erase(it);
                break;
            }
        }

        system->saveAllData();
        QMessageBox::information(this, "Deleted", "Category deleted successfully!");
        refreshData();
    }
}

void EditCategoriesWidget::on_btnBackToForm_clicked() {
    ui->stackActions->setCurrentIndex(0);
}

void EditCategoriesWidget::on_btnBack_clicked() { emit backSignal(); }

void EditCategoriesWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { "
        "   color: #333333; "
        "   font-family: 'Segoe UI'; "
        "}"

        "QWidget#EditCategoriesWidget { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"

        "QFrame#mainCard { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   border: 1px solid #E0E0E0; "
        "}"

        "QLabel#lblTitle, QLabel#lblManageTitle { "
        "   font-size: 20px; font-weight: 800; color: #1565C0; margin-bottom: 10px; "
        "}"

        "QLabel#lblHint { color: #777; font-size: 11px; font-style: italic; margin-top: 5px; }"

        "QGroupBox { "
        "   font-weight: bold; border: 1px solid #DDD; border-radius: 8px; "
        "   margin-top: 20px; padding-top: 15px; background-color: #FAFAFA; "
        "}"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #1565C0; }"

        "QLineEdit { "
        "   background-color: #FFFFFF; border: 1px solid #DDD; "
        "   border-radius: 8px; padding: 8px; color: #333; "
        "}"
        "QLineEdit:focus { border: 2px solid #1976D2; }"

        "QTableWidget { "
        "   background-color: #FFFFFF; border: 1px solid #E0E0E0; "
        "   border-radius: 8px; gridline-color: #F0F0F0; "
        "   selection-background-color: #1976D2; selection-color: #FFF; outline: 0; "
        "}"
        "QHeaderView::section { "
        "   background-color: #F9FAFB; border: none; "
        "   font-weight: bold; color: #1565C0; padding: 5px; "
        "}"

        "QPushButton { "
        "   background-color: #1976D2; color: white; "
        "   border-radius: 18px; padding: 10px; font-weight: bold; "
        "}"
        "QPushButton:hover { background-color: #1565C0; }"
        "QPushButton:pressed { background-color: #0D47A1; }"

        "QPushButton#btnDelete { background-color: #D32F2F; margin-top: 5px; }"
        "QPushButton#btnDelete:hover { background-color: #C62828; }"

        "QPushButton:disabled { background-color: #BDC3C7; color: #F0F0F0; }"

        "QPushButton#btnBack { "
        "   background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 10px; "
        "}"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"

        "Line#lineSeparator { border: 1px solid #EEEEEE; }"

        "QLabel#lblWarnTitle { color: #D32F2F; font-size: 18px; font-weight: bold; }"
        "QLabel#lblWarnMsg { color: #555; font-size: 13px; margin-bottom: 10px; }"
        "QPushButton#btnBackToForm { background-color: #333; color: white; margin-top: 10px; }"
        "QPushButton#btnBackToForm:hover { background-color: #000; }"
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
