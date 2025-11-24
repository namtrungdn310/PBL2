#include "ViewCartWidget.h"
#include "ui_ViewCartWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>
#include <QLocale>

ViewCartWidget::ViewCartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewCartWidget)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("ViewCartWidget");

    ui->tblCart->setColumnCount(5);
    ui->tblCart->setHorizontalHeaderLabels({"Product", "Size", "Price", "Qty", "Total"});

    QHeaderView* header = ui->tblCart->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::Stretch);
    header->setSectionResizeMode(1, QHeaderView::Fixed); ui->tblCart->setColumnWidth(1, 50);
    header->setSectionResizeMode(2, QHeaderView::Fixed); ui->tblCart->setColumnWidth(2, 120);
    header->setSectionResizeMode(3, QHeaderView::Fixed); ui->tblCart->setColumnWidth(3, 50);
    header->setSectionResizeMode(4, QHeaderView::Fixed); ui->tblCart->setColumnWidth(4, 130);

    ui->tblCart->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblCart->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblCart->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblCart->setFocusPolicy(Qt::NoFocus);
    ui->tblCart->verticalHeader()->setVisible(false);

    setupStyle();
}

ViewCartWidget::~ViewCartWidget() {
    delete ui;
}

void ViewCartWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString ViewCartWidget::formatMoney(double amount) { //format lại tiền
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German);
    return locale.toString(val) + " VND";
}

void ViewCartWidget::refreshCart() {
    string warningMsg = system->validateCartStock();
    if (!warningMsg.empty()) {
        QMessageBox::warning(this, "Stock Update",
                             QString::fromStdString("Cart updated due to stock changes:\n\n" + warningMsg));
    }
    loadCartTable();
}

void ViewCartWidget::loadCartTable() {
    ui->tblCart->setRowCount(0);
    Cart& cart = system->getCurrentCart();

    if (cart.isEmpty()) {
        ui->lblTotalMoney->setText("0 VND");
        return;
    }

    for (const auto& item : cart.getItems()) {
        int row = ui->tblCart->rowCount();
        ui->tblCart->insertRow(row);

        ui->tblCart->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(item.getProduct().getName())));
        ui->tblCart->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(item.getSelectedSize())));
        ui->tblCart->setItem(row, 2, new QTableWidgetItem(formatMoney(item.getProduct().getPrice())));
        ui->tblCart->setItem(row, 3, new QTableWidgetItem(QString::number(item.getQuantity())));
        ui->tblCart->setItem(row, 4, new QTableWidgetItem(formatMoney(item.getSubtotal())));
    }

    ui->lblTotalMoney->setText(formatMoney(cart.calculateTotal()));
}

void ViewCartWidget::on_btnDecrease_clicked() {
    int currentRow = ui->tblCart->currentRow();

    if (currentRow < 0) {
        QMessageBox::warning(this, "Warning", "Please select an item to decrease.");
        return;
    }

    Cart& cart = system->getCurrentCart();
    int currentQty = cart.getItems()[currentRow].getQuantity();

    if (currentQty > 1) {
        system->getCurrentCart().updateItemQuantity(currentRow, currentQty - 1);

        loadCartTable();

        if (currentRow < ui->tblCart->rowCount()) {
            ui->tblCart->selectRow(currentRow);
        }

    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove Item", "Quantity is 1. Remove this item?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            system->getCurrentCart().removeItem(currentRow);
            loadCartTable();
        }
    }
}

void ViewCartWidget::on_btnRemove_clicked() {
    int currentRow = ui->tblCart->currentRow();
    if (currentRow >= 0) {
        system->getCurrentCart().removeItem(currentRow);
        loadCartTable();
        QMessageBox::information(this, "Success", "Item removed.");
    } else {
        QMessageBox::warning(this, "Warning", "Please select an item to remove.");
    }
}

void ViewCartWidget::on_btnCheckout_clicked() {
    if (system->getCurrentCart().isEmpty()) {
        QMessageBox::warning(this, "Empty", "Your cart is empty!");
        return;
    }
    emit goToCheckout();
}

void ViewCartWidget::on_btnBack_clicked() {
    emit backSignal();
}

void ViewCartWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333; font-family: 'Segoe UI'; }"
        "QWidget#ViewCartWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; }"

        "QLabel#lblTitle { font-size: 24px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#lblSummaryTitle { font-size: 18px; font-weight: bold; color: #555; margin-bottom: 20px; }"
        "QLabel#lblTotalLabel { font-size: 14px; color: #777; font-weight: 600; }"
        "QLabel#lblTotalMoney { font-size: 22px; font-weight: 800; color: #E65100; margin-bottom: 30px; margin-top: 5px; }"

        "Line#lineSeparator { border: 1px solid #EEEEEE; }"

        "QTableWidget { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 8px; "
        "   gridline-color: #F5F5F5; "
        "   font-size: 13px; "
        "   selection-background-color: #64B5F6; "
        "   selection-color: #FFFFFF; "
        "   outline: 0; "
        "}"

        "QTableWidget::item:focus { outline: none; border: none; }"

        "QPushButton:focus { outline: none; }"
        "QTableWidget::item:selected { "
        "   background-color: #64B5F6; "
        "   color: white; "
        "}"

        "QHeaderView::section { "
        "   background-color: #F9FAFB; border: none; font-weight: bold; color: #555; padding: 8px; "
        "}"

        "QPushButton { border-radius: 20px; padding: 10px; font-weight: bold; font-size: 13px; }"
        "QPushButton#btnCheckout { background-color: #1976D2; color: white; margin-bottom: 10px; padding: 12px; font-size: 14px; }"
        "QPushButton#btnCheckout:hover { background-color: #1565C0; }"

        "QPushButton#btnRemove, QPushButton#btnDecrease { background-color: #FFF; border: 1px solid #E57373; color: #E57373; margin-bottom: 8px; }"
        "QPushButton#btnRemove:hover, QPushButton#btnDecrease:hover { background-color: #FFEBEE; }"

        "QPushButton#btnBack { background-color: transparent; color: #757575; border: none; }"
        "QPushButton#btnBack:hover { color: #333; text-decoration: underline; }"

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
