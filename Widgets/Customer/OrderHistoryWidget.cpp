#include "OrderHistoryWidget.h"
#include "ui_OrderHistoryWidget.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QLocale>
#include <QDateTime>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <algorithm>

OrderHistoryWidget::OrderHistoryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryWidget)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("OrderHistoryWidget");

    setupStyle();
}

OrderHistoryWidget::~OrderHistoryWidget() {
    delete ui;
}

void OrderHistoryWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString OrderHistoryWidget::formatMoney(double amount) {
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German);
    return locale.toString(val) + " VND";
}

void OrderHistoryWidget::loadHistory() {
    QLayout* layout = ui->scrollContent->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    Customer* c = system->getCurrentCustomer();
    if (!c) return;

    vector<Order> myOrders;
    for (const auto& o : system->getOrders()) {
        if (o.getCustomerId() == c->getUserId()) {
            myOrders.push_back(o);
        }
    }

    if (myOrders.empty()) {
        QLabel* emptyLabel = new QLabel("You have no orders yet.", ui->scrollContent);
        emptyLabel->setAlignment(Qt::AlignCenter);
        emptyLabel->setStyleSheet("color: #555; font-size: 16px; margin-top: 50px;");
        ui->verticalLayout_Scroll->addWidget(emptyLabel);
        return;
    }

    int sortType = ui->cboSortOrder->currentIndex();
    std::sort(myOrders.begin(), myOrders.end(), [sortType](const Order& a, const Order& b) {
        if (sortType == 0) return a.getOrderDate() > b.getOrderDate();
        if (sortType == 1) return a.getOrderDate() < b.getOrderDate();
        if (sortType == 2) return a.getTotalAmount() < b.getTotalAmount();
        return a.getTotalAmount() > b.getTotalAmount();
    });

    for (const auto& order : myOrders) {
        const Invoice* invFound = nullptr;
        for(const auto& inv : system->getInvoices()) {
            if(inv.getOrderId() == order.getOrderId()) {
                invFound = &inv;
                break;
            }
        }
        addOrderCard(order, invFound);
    }

    static_cast<QVBoxLayout*>(layout)->addStretch();
}

void OrderHistoryWidget::on_cboSortOrder_currentIndexChanged(int index) {
    Q_UNUSED(index);
    loadHistory(); // Load lại khi đổi kiểu sắp xếp
}

void OrderHistoryWidget::addOrderCard(const Order& order, const Invoice* invoice) {
    QFrame* card = new QFrame(ui->scrollContent);
    card->setObjectName("OrderCard");
    card->setStyleSheet(
        "QFrame#OrderCard { "
        "   background-color: #FFFFFF; "
        "   border-radius: 15px; "
        "   border: 1px solid #E0E0E0; "
        "}"
        );

    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(20, 15, 20, 15);

    // Header
    QHBoxLayout* headerRow = new QHBoxLayout();
    QLabel* lblId = new QLabel("ORDER #" + QString::number(order.getOrderId()), card);
    lblId->setStyleSheet("font-size: 16px; font-weight: 800; color: #1565C0;");

    QString dateStr = QDateTime::fromSecsSinceEpoch(order.getOrderDate()).toString("dd/MM/yyyy HH:mm");
    QLabel* lblDate = new QLabel(dateStr, card);
    lblDate->setStyleSheet("color: #777;");

    headerRow->addWidget(lblId);
    headerRow->addStretch();
    headerRow->addWidget(lblDate);
    cardLayout->addLayout(headerRow);

    // Status
    QLabel* lblStatus = new QLabel(card);
    string stRaw = order.getStatus();
    QString statusText;
    QString statusColor;

    if (stRaw == "Pending") { statusText = "PENDING CONFIRMATION"; statusColor = "#F39C12"; }
    else if (stRaw == "Completed") { statusText = "COMPLETED"; statusColor = "#27AE60"; }
    else if (stRaw == "Pending Cancellation") { statusText = "REQUESTING CANCELLATION"; statusColor = "#E67E22"; }
    else if (stRaw == "Cancelled") { statusText = "CANCELLED"; statusColor = "#C0392B"; }
    else { statusText = QString::fromStdString(stRaw); statusColor = "#777"; }

    lblStatus->setText("Status: " + statusText);
    lblStatus->setStyleSheet("font-weight: bold; font-size: 13px; margin-bottom: 5px; color: " + statusColor + ";");
    cardLayout->addWidget(lblStatus);

    if (invoice) {
        QLabel* lblMethod = new QLabel("Payment: " + QString::fromStdString(invoice->getPaymentMethod()), card);
        lblMethod->setStyleSheet("color: #333; margin-bottom: 10px;");
        cardLayout->addWidget(lblMethod);
    }

    // Bảng sản phẩm
    QTableWidget* tbl = new QTableWidget(card);
    tbl->setColumnCount(4);
    tbl->setHorizontalHeaderLabels({"Product", "Price", "Qty", "Total"});
    tbl->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tbl->verticalHeader()->setVisible(false);
    tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tbl->setSelectionMode(QAbstractItemView::NoSelection);
    tbl->setFocusPolicy(Qt::NoFocus);
    tbl->setStyleSheet(
        "QTableWidget { border: 1px solid #EEE; background: #FAFAFA; color: #333; }"
        "QHeaderView::section { background: #F0F0F0; border: none; font-weight: bold; color: #555; }"
        );

    int r = 0;
    for(const auto& item : order.getItems()) {
        tbl->insertRow(r);
        tbl->setItem(r, 0, new QTableWidgetItem(QString::fromStdString(item.getProduct().getName())));
        tbl->setItem(r, 1, new QTableWidgetItem(formatMoney(item.getUnitPrice())));
        tbl->setItem(r, 2, new QTableWidgetItem(QString::number(item.getQuantity())));
        tbl->setItem(r, 3, new QTableWidgetItem(formatMoney(item.getSubtotal())));
        r++;
    }
    int h = 30 + (r * 30) + 5; if(h > 200) h = 200; tbl->setMinimumHeight(h);
    cardLayout->addWidget(tbl);

    QFrame* line = new QFrame(card);
    line->setFrameShape(QFrame::HLine);
    line->setStyleSheet("color: #DDD; margin-top: 10px; margin-bottom: 5px;");
    cardLayout->addWidget(line);

    double rawPromo = order.getPromotionDiscount();
    double roundedPromo = std::round(rawPromo / 1000.0) * 1000.0;
    double displayedTotal = order.getSubtotal() - roundedPromo - order.getPointsDiscount();

    // 3. Hiển thị
    auto addMoneyLine = [&](QString label, double val, QString color) {
        if (val == 0 && label.contains("Discount")) return;
        QHBoxLayout* row = new QHBoxLayout();
        QLabel* l = new QLabel(label, card);
        QLabel* v = new QLabel(formatMoney(val), card);
        v->setStyleSheet("font-weight: bold; color: " + color + ";");
        row->addWidget(l); row->addStretch(); row->addWidget(v);
        cardLayout->addLayout(row);
    };

    addMoneyLine("Subtotal:", order.getSubtotal(), "#555");

    // Hiển thị số đã làm tròn
    addMoneyLine("Promotion Discount:", -roundedPromo, "#27AE60");

    addMoneyLine("Loyalty Points Discount:", -order.getPointsDiscount(), "#27AE60");

    QHBoxLayout* totalRow = new QHBoxLayout();
    QLabel* lblTotalL = new QLabel("TOTAL PAID:", card);
    lblTotalL->setStyleSheet("font-size: 14px; font-weight: bold; color: #333;");

    QLabel* lblTotalV = new QLabel(formatMoney(displayedTotal), card);
    lblTotalV->setStyleSheet("font-size: 18px; font-weight: 800; color: #D32F2F;");

    totalRow->addWidget(lblTotalL);
    totalRow->addStretch();
    totalRow->addWidget(lblTotalV);
    cardLayout->addLayout(totalRow);

    if (stRaw == "Pending" || stRaw == "Completed") {
        QPushButton* btnCancel = new QPushButton("Request Cancel Order", card);
        btnCancel->setCursor(Qt::PointingHandCursor);
        btnCancel->setStyleSheet(
            "QPushButton { background-color: #FFF; border: 1px solid #C0392B; color: #C0392B; "
            "border-radius: 5px; padding: 5px 10px; font-weight: bold; margin-top: 10px; }"
            "QPushButton:hover { background-color: #FFEBEE; }"
            );
        connect(btnCancel, &QPushButton::clicked, [=]() {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Cancel Order",
                                          "Are you sure you want to cancel Order #" + QString::number(order.getOrderId()) + "?",
                                          QMessageBox::Yes|QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                Order* realOrder = system->findOrder(order.getOrderId());
                if (realOrder) {
                    realOrder->setStatus("Pending Cancellation");
                    system->saveAllData();
                }
                QMessageBox::information(this, "Success", "Cancel request sent!");
                loadHistory();
            }
        });
        cardLayout->addWidget(btnCancel);
    }

    ui->verticalLayout_Scroll->addWidget(card);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(card);
    shadow->setBlurRadius(20); shadow->setColor(QColor(0, 0, 0, 30)); shadow->setOffset(0, 5);
    card->setGraphicsEffect(shadow);
}

void OrderHistoryWidget::on_btnBack_clicked() {
    emit backSignal();
}

void OrderHistoryWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->contentContainer->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"
        "QWidget#OrderHistoryWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"

        "QWidget#contentContainer { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"

        "QScrollArea { background-color: #F5F7F9; border: 1px solid #BDC3C7; border-radius: 10px; }"
        "QWidget#scrollContent { background: transparent; }"

        "QScrollBar:vertical { border: none; background: #F0F0F0; width: 8px; margin: 0px; border-radius: 4px; }"
        "QScrollBar::handle:vertical { background: #BDC3C7; min-height: 20px; border-radius: 4px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0px; }"

        "QLabel#lblTitle { font-size: 28px; font-weight: 800; color: #1565C0; margin-bottom: 10px; }"
        "QLabel#label_Sort { font-size: 14px; font-weight: bold; color: #555; }"

        "QComboBox { background-color: #FFFFFF; border: 2px solid #1976D2; border-radius: 8px; padding: 5px 10px; min-width: 150px; color: #333; font-weight: 600; }"
        "QComboBox::drop-down { border: none; }"
        "QComboBox QAbstractItemView { background-color: #FFFFFF; border: 1px solid #1976D2; color: #333333; selection-background-color: #1976D2; selection-color: #FFFFFF; outline: none; }"

        "QPushButton#btnBack { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; border-radius: 20px; padding: 10px 30px; font-weight: bold; margin-top: 10px; }"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"
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
