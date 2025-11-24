#include "OrderWidget.h"
#include "ui_OrderWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>
#include <QLocale>
#include <QDateTime>

OrderWidget::OrderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderWidget),
    currentSubtotal(0)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("OrderWidget");

    ui->tblOrderItems->setColumnCount(4);
    ui->tblOrderItems->setHorizontalHeaderLabels({"Product", "Size", "Qty", "Total"});
    ui->tblOrderItems->horizontalHeader()->setStretchLastSection(true);
    ui->tblOrderItems->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tblOrderItems->verticalHeader()->setVisible(false);
    ui->tblOrderItems->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblOrderItems->setSelectionMode(QAbstractItemView::NoSelection);

    ui->spinPoints->setSingleStep(10);

    setupStyle();
}

OrderWidget::~OrderWidget() { delete ui; }

void OrderWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString OrderWidget::formatMoney(double amount) {
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German);
    return locale.toString(val) + " VND";
}

void OrderWidget::loadOrderData() {
    ui->tblOrderItems->setRowCount(0);
    Cart& cart = system->getCurrentCart();
    currentSubtotal = cart.calculateTotal();

    for (const auto& item : cart.getItems()) {
        int row = ui->tblOrderItems->rowCount();
        ui->tblOrderItems->insertRow(row);
        ui->tblOrderItems->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(item.getProduct().getName())));
        ui->tblOrderItems->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(item.getSelectedSize())));
        ui->tblOrderItems->setItem(row, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
        ui->tblOrderItems->setItem(row, 3, new QTableWidgetItem(formatMoney(item.getSubtotal())));
    }
    ui->lblSubtotal->setText("Subtotal: " + formatMoney(currentSubtotal));

    ui->cboPromotions->clear();
    ui->cboPromotions->addItem("No Promotion", -1);

    Customer* c = system->getCurrentCustomer();
    if (c) {
        for (const auto& promo : system->getPromotions()) {
            bool valid = promo.isValid();
            bool conditionMet = (currentSubtotal >= promo.getMinOrderAmount());
            bool notUsed = !c->hasUsedPromo(promo.getPromoId());

            if (valid && conditionMet && notUsed) {
                ui->cboPromotions->addItem(QString::fromStdString(promo.getName()), promo.getPromoId());
            }
        }

        int maxPoints = c->getLoyaltyPoints();
        ui->spinPoints->setMaximum(maxPoints);
        ui->spinPoints->setValue(0);
        ui->lblPointHint->setText("(You have: " + QString::number(maxPoints) + " pts. 10 pts = 1000 VND)");
    }

    calculateFinalTotal();
}

void OrderWidget::calculateFinalTotal() {
    double finalTotal = currentSubtotal;

    int promoIndex = ui->cboPromotions->currentIndex();
    double promoDisc = 0;

    if (promoIndex > 0) {
        int promoId = ui->cboPromotions->currentData().toInt();
        for(const auto& p : system->getPromotions()) {
            if (p.getPromoId() == promoId) {
                double rawDiscount = currentSubtotal * p.getDiscountRate();
                promoDisc = std::round(rawDiscount / 1000.0) * 1000.0;
                break;
            }
        }
    }

    finalTotal -= promoDisc;
    ui->lblDiscountVal->setText("-" + formatMoney(promoDisc));

    int points = ui->spinPoints->value();
    double pointDisc = points * 100.0;

    if (pointDisc > finalTotal) {
        pointDisc = finalTotal;
    }

    finalTotal -= pointDisc;
    ui->lblPointDiscountVal->setText("-" + formatMoney(pointDisc));

    ui->lblFinalTotal->setText(formatMoney(finalTotal));
}

void OrderWidget::on_cboPromotions_currentIndexChanged(int index) { Q_UNUSED(index); calculateFinalTotal(); }
void OrderWidget::on_spinPoints_valueChanged(int arg1) {
    Q_UNUSED(arg1);
    calculateFinalTotal();
}
void OrderWidget::on_spinPoints_editingFinished() {
    int val = ui->spinPoints->value();
    if (val % 10 != 0) {
        int rounded = (val / 10) * 10;
        ui->spinPoints->setValue(rounded);
    }
}

void OrderWidget::on_btnConfirmPay_clicked() {
    Customer* c = system->getCurrentCustomer();
    if (!c) return;

    int promoId = ui->cboPromotions->currentData().toInt();
    int pointsUsed = ui->spinPoints->value();
    string method = ui->cboPaymentMethod->currentText().toStdString();

    int newOrderId = c->placeOrder(*system, promoId, pointsUsed, method);

    if (newOrderId != -1) {
        system->saveAllData();

        Order* o = system->findOrder(newOrderId);
        QString msg = "Payment Successful!\n";
        msg += "Order ID: #" + QString::number(newOrderId) + "\n";
        msg += "Total Paid: " + formatMoney(o->getTotalAmount()) + "\n";
        msg += "Earned Points: " + QString::number((int)(o->getTotalAmount()/1000)) + "\n";
        msg += "Date: " + QDateTime::currentDateTime().toString();

        QMessageBox::information(this, "Invoice", msg);
        emit orderCompleted();
    } else {
        QMessageBox::critical(this, "Error", "Payment failed! Please check your cart.");
    }
}

void OrderWidget::on_btnBack_clicked() {
    emit backSignal();
}

void OrderWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"

        "QWidget#OrderWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"

        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; }"

        "QLabel#lblTitle { font-size: 24px; font-weight: 800; color: #1565C0; margin-bottom: 15px; }"
        "QLabel#lblSubtotal { font-size: 16px; font-weight: bold; color: #555; margin-top: 10px; }"

        "QTableWidget { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 8px; "
        "   gridline-color: #F5F5F5; "
        "   color: #333; "
        "   font-size: 13px; "
        "}"
        "QHeaderView::section { background-color: #F9FAFB; border: none; font-weight: bold; color: #555; padding: 8px; }"

        "QLabel#lblPaymentTitle { font-size: 18px; font-weight: bold; color: #555; margin-bottom: 15px; }"
        "QLabel { font-size: 13px; font-weight: 600; color: #444; }"

        "QLabel#lblFinalTotalLabel { font-size: 14px; color: #777; }"
        "QLabel#lblFinalTotal { font-size: 28px; font-weight: 800; color: #D32F2F; margin-bottom: 10px; }"

        "QComboBox, QSpinBox { "
        "   background-color: #F5F7F9; border: 1px solid #DDD; "
        "   border-radius: 8px; padding: 8px; "
        "   color: #333; font-size: 13px; "
        "}"
        "QComboBox QAbstractItemView { background-color: #34495E; color: #FFF; selection-background-color: #1976D2; }"

        "QPushButton#btnConfirmPay { background-color: #27AE60; color: white; border-radius: 22px; padding: 12px; font-weight: bold; font-size: 15px; }"
        "QPushButton#btnConfirmPay:hover { background-color: #219150; }"

        "QPushButton#btnBack { background-color: #FFF; border: 2px solid #95A5A6; color: #7F8C8D; border-radius: 22px; padding: 10px; font-weight: bold; }"
        "QPushButton#btnBack:hover { background-color: #F0F0F0; }"

        "Line#lineSeparator { border: 1px solid #EEEEEE; }"
        "QMessageBox { "
        "   background-color: #34495E; "
        "   border: 2px solid #1976D2; "
        "}"
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
