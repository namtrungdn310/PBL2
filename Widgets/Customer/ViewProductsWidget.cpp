#include "ViewProductsWidget.h"
#include "ui_ViewProductsWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>

ViewProductsWidget::ViewProductsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewProductsWidget),
    currentSelectedProduct(nullptr)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("ViewProductsWidget");

    ui->tblProducts->setColumnCount(3);
    ui->tblProducts->setHorizontalHeaderLabels({"ID", "Name", "Price"});

    QHeaderView* header = ui->tblProducts->horizontalHeader();

    header->setStretchLastSection(false);

    header->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tblProducts->setColumnWidth(0, 40);

    header->setSectionResizeMode(1, QHeaderView::Stretch);

    header->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tblProducts->setColumnWidth(2, 120);
    ui->tblProducts->setWordWrap(true);

    ui->tblProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblProducts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblProducts->verticalHeader()->setVisible(false);

    ui->cboSort->addItem("Price: Default", SORT_DEFAULT);
    ui->cboSort->addItem("Price: Low to High", PRICE_ASC);
    ui->cboSort->addItem("Price: High to Low", PRICE_DESC);

    setupStyle();
}

ViewProductsWidget::~ViewProductsWidget() {
    delete ui;
}

void ViewProductsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ViewProductsWidget::refreshData() {
    ui->productStack->setCurrentIndex(0);
    loadCategories();
    ui->txtSearch->clear();
    ui->cboSort->setCurrentIndex(0);
    ui->cboCategory->setCurrentIndex(0);
    on_btnFilter_clicked();
}

void ViewProductsWidget::loadCategories() {
    ui->cboCategory->clear();
    ui->cboCategory->addItem("All Categories", 0);
    for(const auto& cat : system->getCategories()) {
        ui->cboCategory->addItem(QString::fromStdString(cat.getName()), cat.getCategoryId());
    }
}

void ViewProductsWidget::on_btnFilter_clicked() {
    int catId = ui->cboCategory->currentData().toInt();
    string keyword = ui->txtSearch->text().toStdString();
    SortOption sort = static_cast<SortOption>(ui->cboSort->currentData().toInt());

    MyVector<Product> result = system->searchProducts(catId, keyword, 0, -1, sort);
    displayProducts(result);
}

void ViewProductsWidget::displayProducts(const MyVector<Product>& list) {
    ui->tblProducts->setRowCount(0);
    for(const auto& p : list) {
        int row = ui->tblProducts->rowCount();
        ui->tblProducts->insertRow(row);

        QTableWidgetItem* itemId = new QTableWidgetItem(QString::number(p.getProductId()));
        itemId->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(row, 0, itemId);

        ui->tblProducts->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));

        QString price = QString::number(p.getPrice()) + " VND";
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(row, 2, itemPrice);
    }

    ui->tblProducts->resizeRowsToContents();
}

void ViewProductsWidget::on_tblProducts_cellDoubleClicked(int row, int column) {
    Q_UNUSED(column);
    int prodId = ui->tblProducts->item(row, 0)->text().toInt();
    Product* p = system->findProduct(prodId);
    if (p) {
        showProductDetails(p);
    }
}

void ViewProductsWidget::showProductDetails(Product* p) {
    currentSelectedProduct = p;
    ui->lblProdName->setText(QString::fromStdString(p->getName()));
    ui->lblProdPrice->setText(QString::number(p->getPrice()) + " VND");
    ui->lblProdDesc->setText(QString::fromStdString(p->getDescription()));

    ui->cboSize->clear();
    for(const auto& size : p->getSizes()) {
        int avail = system->getAvailableStock(p->getProductId(), size.getSizeName());
        if (avail > 0) {
            ui->cboSize->addItem(QString::fromStdString(size.getSizeName()), avail);
        }
    }

    if (ui->cboSize->count() > 0) {
        ui->cboSize->setCurrentIndex(0);
        on_cboSize_currentIndexChanged(0);
        ui->btnAddToCart->setEnabled(true);
    } else {
        ui->lblStockAvailable->setText("Out of Stock");
        ui->spinQty->setMaximum(0);
        ui->btnAddToCart->setEnabled(false);
    }
    ui->productStack->setCurrentIndex(1);
}

void ViewProductsWidget::on_cboSize_currentIndexChanged(int index) {
    if (index < 0) return;
    int maxAvail = ui->cboSize->currentData().toInt();
    ui->lblStockAvailable->setText("Available: " + QString::number(maxAvail));
    ui->spinQty->setRange(1, maxAvail);
    ui->spinQty->setValue(1);
}

void ViewProductsWidget::on_btnAddToCart_clicked() {
    if (!currentSelectedProduct) return;
    string sizeName = ui->cboSize->currentText().toStdString();
    int qty = ui->spinQty->value();

    system->getCurrentCart().addItem(
        currentSelectedProduct->getProductId(),
        sizeName,
        qty,
        *currentSelectedProduct
        );
    QMessageBox::information(this, "Success", "Added to Cart Successfully!");
    ui->productStack->setCurrentIndex(0);
    on_btnFilter_clicked();
}

void ViewProductsWidget::on_btnBackList_clicked() {
    emit backSignal();
}

void ViewProductsWidget::on_btnBackDetail_clicked() {
    ui->productStack->setCurrentIndex(0);
}

void ViewProductsWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->cardFrame->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"
        "QWidget#ViewProductsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#cardFrame { background-color: #FFFFFF; border-radius: 20px; }"
        "QLabel#lblTitleList { font-size: 24px; font-weight: bold; color: #1565C0; margin-bottom: 15px; }"
        "QLabel#lblProdName { font-size: 22px; font-weight: bold; color: #1565C0; }"
        "QLabel#lblProdPrice { font-size: 18px; font-weight: bold; color: #E65100; margin-bottom: 10px; }"
        "QLabel#lblProdDesc { font-size: 14px; color: #555555; margin-bottom: 20px; }"
        "QLineEdit, QComboBox, QSpinBox { background-color: #F5F7F9; border: 1px solid #E0E0E0; border-radius: 8px; padding: 8px; color: #333333; font-size: 13px; }"
        "QLineEdit:focus, QComboBox:focus, QSpinBox:focus { background-color: #FFFFFF; border: 2px solid #1976D2; }"
        "QComboBox QAbstractItemView { background-color: #34495E; color: #FFFFFF; selection-background-color: #1976D2; selection-color: #FFFFFF; border: 1px solid #2C3E50; outline: none; }"
        "QTableWidget { background-color: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 8px; gridline-color: #EEEEEE; color: #333333; }"
        "QHeaderView::section { background-color: #F5F7F9; border: none; font-weight: bold; color: #1565C0; padding: 5px; }"
        "QPushButton { background-color: #1976D2; color: white; border-radius: 18px; padding: 10px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1565C0; }"
        "QPushButton:pressed { background-color: #0D47A1; }"
        "QPushButton#btnBackList, QPushButton#btnBackDetail { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 10px; }"
        "QPushButton#btnBackList:hover, QPushButton#btnBackDetail:hover { background-color: #FFEBEE; }"
        "QMessageBox { background-color: #34495E; border: 2px solid #1976D2; }"
        "QMessageBox QLabel { color: #FFFFFF; font-size: 14px; font-weight: bold; }"
        "QMessageBox QPushButton { background-color: #1976D2; color: white; border-radius: 5px; padding: 5px 15px; min-width: 60px; }"
        "QMessageBox QPushButton:hover { background-color: #1565C0; }"
        );
}
