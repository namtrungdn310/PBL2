#include "EditProductsWidget.h"
#include "ui_EditProductsWidget.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>

EditProductsWidget::EditProductsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProductsWidget),
    currentEditingProduct(nullptr),
    isAddMode(false),
    lastGeneratedProductId(0)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("EditProductsWidget");

    ui->tblProducts->setColumnCount(3);
    ui->tblProducts->setHorizontalHeaderLabels({"ID", "Name", "Price"});
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed); ui->tblProducts->setColumnWidth(0, 50);
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tblProducts->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); ui->tblProducts->setColumnWidth(2, 100);
    ui->tblProducts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblProducts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblProducts->verticalHeader()->setVisible(false);

    ui->tblSizes->setColumnCount(2);
    ui->tblSizes->setHorizontalHeaderLabels({"Size Name", "Quantity"});
    ui->tblSizes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblSizes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblSizes->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblSizes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblSizes->verticalHeader()->setVisible(false);

    populateSizeCombo();
    setupStyle();
    for(const auto& p : system->getProducts()) {
        if (p.getProductId() > lastGeneratedProductId) {
            lastGeneratedProductId = p.getProductId();
        }
    }
}

EditProductsWidget::~EditProductsWidget() { delete ui; }

void EditProductsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event); QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void EditProductsWidget::refreshData() {
    ui->stackEdit->setCurrentIndex(0);
    currentEditingProduct = nullptr;
    isAddMode = false;
    tempSizes.clear();
    loadCategories();
    on_btnFilter_clicked();
}

void EditProductsWidget::loadCategories() {
    ui->cboCategoryFilter->clear();
    ui->cboCategoryEdit->clear();

    ui->cboCategoryFilter->addItem("All Categories", 0);
    for(const auto& cat : system->getCategories()) {
        QString name = QString::fromStdString(cat.getName());
        ui->cboCategoryFilter->addItem(name, cat.getCategoryId());
        ui->cboCategoryEdit->addItem(name, cat.getCategoryId());
    }
}

void EditProductsWidget::populateSizeCombo() {
    ui->cboSizeSelect->clear();
    QStringList sizes = {
        "XS", "S", "M", "L", "XL", "XXL",
        "28", "29", "30", "31", "32", "33", "34", "35", "36",
        "37", "38", "39", "40", "41", "42", "43", "44"
    };
    ui->cboSizeSelect->addItems(sizes);
    ui->cboSizeSelect->setEditable(true); // Cho phép nhập size lạ
}

void EditProductsWidget::on_btnFilter_clicked() {
    int catId = ui->cboCategoryFilter->currentData().toInt();
    string kw = ui->txtSearch->text().toStdString();
    vector<Product> result = system->searchProducts(catId, kw, 0, -1, SORT_DEFAULT);
    displayProducts(result);
}

void EditProductsWidget::displayProducts(const vector<Product>& list) {
    ui->tblProducts->setRowCount(0);
    for(const auto& p : list) {
        int r = ui->tblProducts->rowCount();
        ui->tblProducts->insertRow(r);

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(p.getProductId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(r, 0, idItem);

        ui->tblProducts->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
        ui->tblProducts->setItem(r, 2, new QTableWidgetItem(QString::number(p.getPrice())));
    }
}

void EditProductsWidget::on_tblProducts_cellDoubleClicked(int row, int column) {
    Q_UNUSED(column);
    int pid = ui->tblProducts->item(row, 0)->text().toInt();
    Product* p = system->findProduct(pid);
    if (p) loadProductToForm(p);
}

void EditProductsWidget::loadProductToForm(Product* p) {
    isAddMode = false;
    currentEditingProduct = p;
    ui->lblEditTitle->setText("EDIT PRODUCT");
    ui->btnDeleteProduct->setVisible(true); // Hiện nút xóa
    ui->btnConfirm->setText("Confirm Save");
    ui->txtName->setText(QString::fromStdString(p->getName()));
    ui->txtPrice->setText(QString::number(p->getPrice()));
    ui->txtBrand->setText(QString::fromStdString(p->getBrand()));
    ui->txtDesc->setText(QString::fromStdString(p->getDescription()));
    ui->txtName->setText(QString::fromStdString(p->getName()));
    int idx = ui->cboCategoryEdit->findData(p->getCategoryId());
    if (idx != -1) ui->cboCategoryEdit->setCurrentIndex(idx);
    tempSizes = p->getSizes();
    updateSizeTable();

    ui->stackEdit->setCurrentIndex(1);
}

void EditProductsWidget::updateSizeTable() {
    ui->tblSizes->setRowCount(0);
    for(const auto& s : tempSizes) {
        int r = ui->tblSizes->rowCount();
        ui->tblSizes->insertRow(r);
        ui->tblSizes->setItem(r, 0, new QTableWidgetItem(QString::fromStdString(s.getSizeName())));
        ui->tblSizes->setItem(r, 1, new QTableWidgetItem(QString::number(s.getQuantity())));
    }
}

void EditProductsWidget::on_btnAddSize_clicked() {
    QString sName = ui->cboSizeSelect->currentText().trimmed();
    int qty = ui->spinStock->value();

    if (sName.isEmpty()) return;
    bool found = false;
    for(auto& s : tempSizes) {
        if (s.getSizeName() == sName.toStdString()) {
            s.setQuantity(qty);
            break;
        }
    }

    if (!found) {
        tempSizes.push_back(Size(0, sName.toStdString(), qty));
    }

    updateSizeTable();
}

void EditProductsWidget::on_btnRemoveSize_clicked() {
    int r = ui->tblSizes->currentRow();
    if (r >= 0 && static_cast<size_t>(r) < tempSizes.size()) {
        tempSizes.erase(tempSizes.begin() + r);
        updateSizeTable();
    }
}

void EditProductsWidget::on_btnConfirm_clicked() {
    QString name = ui->txtName->text().trimmed();
    long long price = ui->txtPrice->text().toLongLong();
    if (name.isEmpty() || price < 0) {
        QMessageBox::warning(this, "Error", "Invalid Name or Price!");
        return;
    }
    if (isAddMode) {
        lastGeneratedProductId++;
        int newId = lastGeneratedProductId;
        int catId = ui->cboCategoryEdit->currentData().toInt();
        string desc = ui->txtDesc->toPlainText().toStdString();
        string brand = ui->txtBrand->text().toStdString();
        Product newP(newId, name.toStdString(), price, brand, desc, catId);
        newP.getSizes() = tempSizes;
        system->addProduct(newP);
        system->saveAllData();
        QMessageBox::information(this, "Success", "New product added successfully!");
        refreshData();
        return;
    }
    if (!currentEditingProduct) return;
    QString warningMsg = "";

    for (const auto& newSize : tempSizes) {
        int inCart = system->countTotalInCarts(currentEditingProduct->getProductId(), newSize.getSizeName());
        if (newSize.getQuantity() < inCart) {
            warningMsg += "- Size " + QString::fromStdString(newSize.getSizeName()) +
                          ": New stock (" + QString::number(newSize.getQuantity()) +
                          ") < In Carts (" + QString::number(inCart) + ")\n";
        }
    }
    for (const auto& oldSize : currentEditingProduct->getSizes()) {
        bool stillExists = false;
        for (const auto& ns : tempSizes) {
            if (ns.getSizeName() == oldSize.getSizeName()) { stillExists = true; break; }
        }

        if (!stillExists) {
            int inCart = system->countTotalInCarts(currentEditingProduct->getProductId(), oldSize.getSizeName());
            if (inCart > 0) {
                warningMsg += "- Size " + QString::fromStdString(oldSize.getSizeName()) +
                              " deleted but " + QString::number(inCart) + " items are in carts.\n";
            }
        }
    }

    if (!warningMsg.isEmpty()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(this, "Warning: Cart Conflict",
                                     "Reducing stock may affect pending carts:\n\n" + warningMsg +
                                         "\nDo you still want to proceed? (Customer carts will be auto-adjusted later)",
                                     QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::No) return;
    }

    currentEditingProduct->setName(name.toStdString());
    currentEditingProduct->setDescription(ui->txtDesc->toPlainText().toStdString());
    currentEditingProduct->setPrice(price);
    currentEditingProduct->setBrand(ui->txtBrand->text().toStdString());
    currentEditingProduct->setCategoryId(ui->cboCategoryEdit->currentData().toInt());

    currentEditingProduct->getSizes() = tempSizes;

    system->saveAllData();

    QMessageBox::information(this, "Success", "Product updated successfully!");
    on_btnFilter_clicked();
}

void EditProductsWidget::on_btnDeleteProduct_clicked() {
    if (!currentEditingProduct) return;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Product",
                                  "Are you sure you want to delete this product?\nIt will be removed from all carts!",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        system->removeProduct(currentEditingProduct->getProductId());
        system->saveAllData();

        QMessageBox::information(this, "Deleted", "Product deleted.");
        refreshData();
    }
}
void EditProductsWidget::on_btnAddProduct_clicked() {
    isAddMode = true;
    currentEditingProduct = nullptr;

    ui->txtName->clear();
    ui->txtPrice->clear();
    ui->txtBrand->clear();
    ui->txtDesc->clear();

    tempSizes.clear();
    updateSizeTable();

    ui->lblEditTitle->setText("ADD NEW PRODUCT");
    ui->btnDeleteProduct->setVisible(false); // Ẩn nút xóa khi đang thêm mới
    ui->btnConfirm->setText("Confirm Add");
    ui->stackEdit->setCurrentIndex(1);
    ui->txtName->setFocus();
}
void EditProductsWidget::on_btnBack_clicked() { emit backSignal(); }

void EditProductsWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->btnAddProduct->setStyleSheet("background-color: #2E7D32; color: white; border-radius: 18px; padding: 10px; font-weight: bold;");
    ui->mainCard->setGraphicsEffect(shadow);
    this->setStyleSheet(
        "QWidget { "
        "   color: #333333; "
        "   font-family: 'Segoe UI'; "
        "}"
        "QWidget#EditProductsWidget { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"
        "QFrame#mainCard { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   border: 1px solid #E0E0E0; "
        "}"
        "QComboBox { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #DDD; "
        "   border-radius: 8px; "
        "   padding: 8px; "
        "   color: #333333; "
        "   min-height: 20px; "
        "}"
        "QComboBox QAbstractItemView { "
        "   background-color: #FFFFFF; "
        "   color: #333333; "
        "   selection-background-color: #1976D2; "
        "   selection-color: #FFFFFF; "
        "   border: 1px solid #DDD; "
        "   outline: none; "
        "}"
        "QTableWidget { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 8px; "
        "   gridline-color: #F0F0F0; "
        "   color: #333333; "
        "   selection-background-color: #1976D2; "
        "   selection-color: #FFFFFF; "
        "   outline: 0; "
        "}"
        "QTableWidget::item:selected { "
        "   background-color: #1976D2; "
        "   color: #FFFFFF; "
        "}"
        "QHeaderView::section { "
        "   background-color: #F9FAFB; "
        "   border: none; "
        "   font-weight: bold; "
        "   color: #1565C0; "
        "   padding: 5px; "
        "   border-bottom: 1px solid #DDD; "
        "}"
        "QLabel#lblTitle, QLabel#lblEditTitle { font-size: 20px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#lblHint, QLabel#lblEmpty { color: #777; font-style: italic; }"
        "QLineEdit, QSpinBox, QTextEdit { "
        "   background-color: #FFFFFF; border: 1px solid #DDD; "
        "   border-radius: 8px; padding: 8px; color: #333; "
        "}"
        "QLineEdit:focus, QTextEdit:focus, QComboBox:focus, QSpinBox:focus { "
        "   border: 2px solid #1976D2; "
        "}"
        "QGroupBox { "
        "   font-weight: bold; border: 1px solid #DDD; border-radius: 8px; "
        "   margin-top: 10px; padding-top: 15px; background-color: #FAFAFA; "
        "}"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #1565C0; }"
        "QPushButton { "
        "   background-color: #1976D2; color: white; "
        "   border-radius: 18px; padding: 10px; font-weight: bold; "
        "}"
        "QPushButton:hover { background-color: #1565C0; }"
        "QPushButton#btnDeleteProduct, QPushButton#btnRemoveSize { "
        "   background-color: #D32F2F; margin-top: 5px; "
        "}"
        "QPushButton#btnDeleteProduct:hover, QPushButton#btnRemoveSize:hover { background-color: #C62828; }"
        "QPushButton#btnBack { "
        "   background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 10px; "
        "}"
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
