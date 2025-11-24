#include "ReviewsWidget.h"
#include "ui_ReviewsWidget.h"
#include "include/FileManager.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>
#include <QLocale>

ReviewsWidget::ReviewsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReviewsWidget),
    currentProduct(nullptr)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("ReviewsWidget");

    ui->tblProducts->setColumnCount(3);
    ui->tblProducts->setHorizontalHeaderLabels({"Product Name", "Price", "Rating"});

    QHeaderView* header = ui->tblProducts->horizontalHeader();
    header->setStretchLastSection(false);

    header->setSectionResizeMode(0, QHeaderView::Stretch);

    header->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->tblProducts->setColumnWidth(1, 110);

    header->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->tblProducts->setColumnWidth(2, 110);

    ui->tblProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblProducts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblProducts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblProducts->verticalHeader()->setVisible(false);

    ui->tblProducts->setWordWrap(true);

    ui->cboSort->addItem("Price: Default", SORT_DEFAULT);
    ui->cboSort->addItem("Price: Low to High", PRICE_ASC);
    ui->cboSort->addItem("Price: High to Low", PRICE_DESC);

    ui->spinRating->setRange(1, 5);

    setupStyle();
}

ReviewsWidget::~ReviewsWidget() { delete ui; }

void ReviewsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event); QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ReviewsWidget::refreshData() {
    ui->reviewStack->setCurrentIndex(0);
    loadCategories();
    ui->txtSearch->clear();
    ui->cboSort->setCurrentIndex(0);
    ui->cboCategory->setCurrentIndex(0);
    on_btnFilter_clicked();
}

void ReviewsWidget::loadCategories() {
    ui->cboCategory->clear(); ui->cboCategory->addItem("All Categories", 0);
    for(const auto& cat : system->getCategories())
        ui->cboCategory->addItem(QString::fromStdString(cat.getName()), cat.getCategoryId());
}

pair<double, int> ReviewsWidget::calculateRating(int prodId) {
    vector<Review> reviews = system->getReviewsForProduct(prodId);
    if (reviews.empty()) return {0.0, 0};
    double sum = 0;
    for(const auto& r : reviews) sum += r.getRating();
    double avg = sum / reviews.size();
    avg = std::round(avg * 10.0) / 10.0;
    return {avg, (int)reviews.size()};
}

QString ReviewsWidget::getStarString(int rating) {
    QString stars = ""; for(int i=0; i<rating; ++i) stars += "★"; return stars;
}

void ReviewsWidget::on_btnFilter_clicked() {
    int catId = ui->cboCategory->currentData().toInt();
    string keyword = ui->txtSearch->text().toStdString();
    SortOption sort = static_cast<SortOption>(ui->cboSort->currentData().toInt());
    vector<Product> result = system->searchProducts(catId, keyword, 0, -1, sort);
    displayProductList(result);
}

void ReviewsWidget::displayProductList(const vector<Product>& list) {
    ui->tblProducts->setRowCount(0);
    for(const auto& p : list) {
        int row = ui->tblProducts->rowCount();
        ui->tblProducts->insertRow(row);

        QTableWidgetItem* itemName = new QTableWidgetItem(QString::fromStdString(p.getName()));
        itemName->setData(Qt::UserRole, p.getProductId());
        itemName->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tblProducts->setItem(row, 0, itemName);

        long long val = p.getPrice();
        QLocale locale(QLocale::German);
        QString priceStr = locale.toString(val) + " VND";
        QTableWidgetItem* itemPrice = new QTableWidgetItem(priceStr);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(row, 1, itemPrice);

        pair<double, int> rateData = calculateRating(p.getProductId());
        QString rateStr;
        QTableWidgetItem* itemRate;

        if (rateData.second > 0) {
            rateStr = QString::number(rateData.first, 'f', 1) + " ★ (" +
                      QString::number(rateData.second) + ")";
            itemRate = new QTableWidgetItem(rateStr);
            itemRate->setForeground(QBrush(QColor(243, 156, 18)));
        } else {
            itemRate = new QTableWidgetItem("No reviews");
            itemRate->setForeground(QBrush(QColor(149, 165, 166)));
        }

        itemRate->setTextAlignment(Qt::AlignCenter);
        ui->tblProducts->setItem(row, 2, itemRate);
    }

    ui->tblProducts->resizeRowsToContents();
}

void ReviewsWidget::on_tblProducts_cellDoubleClicked(int row, int column) {
    Q_UNUSED(column);
    int prodId = ui->tblProducts->item(row, 0)->data(Qt::UserRole).toInt();
    Product* p = system->findProduct(prodId);
    if (p) showProductDetail(p);
}

void ReviewsWidget::showProductDetail(Product* p) {
    currentProduct = p;
    ui->reviewStack->setCurrentIndex(1);
    ui->lblProdName->setText(QString::fromStdString(p->getName()));
    ui->lblProdDesc->setText(QString::fromStdString(p->getDescription()));
    pair<double, int> rateData = calculateRating(p->getProductId());
    ui->lblRatingInfo->setText(QString::number(rateData.first, 'f', 1) + " Stars (" + QString::number(rateData.second) + " reviews)");
    loadReviewsForProduct(p->getProductId());
    ui->spinRating->setValue(5);
    ui->txtComment->clear();
    ui->tabReviews->setCurrentIndex(0);
}

void ReviewsWidget::loadReviewsForProduct(int prodId) {
    QLayout* layout = ui->scrollContent->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) { delete item->widget(); delete item; }
    vector<Review> reviews = system->getReviewsForProduct(prodId);
    if (reviews.empty()) {
        QLabel* empty = new QLabel("No reviews yet. Be the first!", ui->scrollContent);
        empty->setStyleSheet("color: #777; font-style: italic; margin-top: 20px;");
        empty->setAlignment(Qt::AlignCenter);
        layout->addWidget(empty);
    } else {
        for (const auto& r : reviews) {
            QFrame* card = new QFrame(ui->scrollContent);
            card->setStyleSheet(
                "QFrame { background: #FAFAFA; border: 1px solid #E0E0E0; border-radius: 8px; }"
                "QLabel { border: none; }"
                );
            QVBoxLayout* l = new QVBoxLayout(card);
            QLabel* name = new QLabel(QString::fromStdString(r.getCustomerName()), card);
            name->setStyleSheet("font-weight: bold; color: #1565C0; font-size: 13px;");
            QLabel* stars = new QLabel(getStarString(r.getRating()), card);
            stars->setStyleSheet("color: #F1C40F; font-size: 14px;");
            QLabel* cmt = new QLabel(QString::fromStdString(r.getComment()), card);
            cmt->setWordWrap(true);
            cmt->setStyleSheet("color: #333; font-size: 13px;");
            l->addWidget(name); l->addWidget(stars); l->addWidget(cmt);
            layout->addWidget(card);
        }
    }
    static_cast<QVBoxLayout*>(layout)->addStretch();
}

void ReviewsWidget::on_btnConfirmReview_clicked() {
    if (!currentProduct) return;
    int rating = ui->spinRating->value();
    string comment = ui->txtComment->toPlainText().toStdString();
    if (comment.empty()) { QMessageBox::warning(this, "Error", "Please write a comment!"); return; }
    Customer* c = system->getCurrentCustomer();
    int custId = c ? c->getUserId() : 0;
    string custName = c ? c->getName() : "Guest";
    int newId = system->getReviews().size() + 1;
    Review newReview(newId, currentProduct->getProductId(), custId, rating, comment, custName);
    system->addReview(newReview);
    FileManager::writeReviews("data/reviews.txt", system->getReviews());
    QMessageBox::information(this, "Success", "Review posted successfully!");
    refreshData();
}

void ReviewsWidget::on_btnBackList_clicked() { ui->reviewStack->setCurrentIndex(0); }
void ReviewsWidget::on_btnBackMenu_clicked() { emit backSignal(); }

void ReviewsWidget::setupStyle() {
    ui->mainCard->setGraphicsEffect(nullptr);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"
        "QWidget#ReviewsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"

        "QFrame#mainCard { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   border: 2px solid #FFFFFF; "
        "}"

        "QLabel#lblTitleList, QLabel#lblProdName { font-size: 22px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#lblRatingInfo { font-size: 14px; font-weight: bold; color: #F39C12; }"
        "QLabel#lblProdDesc { font-size: 13px; color: #555; margin-bottom: 15px; }"
        "QLabel#lblHint { color: #777; font-size: 11px; font-style: italic; }"

        "QLineEdit, QComboBox, QSpinBox, QTextEdit { background-color: #F5F7F9; border: 1px solid #DDD; border-radius: 8px; padding: 8px; color: #333; font-size: 13px; }"
        "QLineEdit:focus, QTextEdit:focus { border: 2px solid #1976D2; background: #FFF; }"
        "QComboBox QAbstractItemView { background: #34495E; color: #FFF; selection-background-color: #1976D2; }"

        "QTableWidget { background-color: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 8px; gridline-color: #F5F5F5; color: #333; selection-background-color: #1976D2; selection-color: #FFF; outline: 0; }"
        "QHeaderView::section { background-color: #F9FAFB; border: none; font-weight: bold; color: #1565C0; padding: 5px; }"

        "QPushButton { background-color: #1976D2; color: white; border-radius: 18px; padding: 10px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1565C0; }"

        "QPushButton#btnBackMenu, QPushButton#btnBackList { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; margin-top: 10px; }"
        "QPushButton#btnBackMenu:hover, QPushButton#btnBackList:hover { background-color: #FFEBEE; }"
        "QTabWidget::pane { border: 1px solid #E0E0E0; border-radius: 5px; top: -1px; }"
        "QTabBar::tab { background: #F5F5F5; color: #555; padding: 8px 20px; margin-right: 4px; border-top-left-radius: 5px; border-top-right-radius: 5px; }"
        "QTabBar::tab:selected { background: #FFF; color: #1976D2; font-weight: bold; border-bottom: 2px solid #1976D2; }"
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
