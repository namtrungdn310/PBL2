#include "CustomersManagementWidget.h"
#include "ui_CustomersManagementWidget.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QLocale>
#include <QScrollBar>
#include <algorithm>
#include <cmath>

CustomersManagementWidget::CustomersManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomersManagementWidget),
    currentSelectedCustId(-1)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("CustomersManagementWidget");

    ui->tblCustomers->setColumnCount(3);
    ui->tblCustomers->setHorizontalHeaderLabels({"ID", "Name", "Total Spent"});
    ui->tblCustomers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed); ui->tblCustomers->setColumnWidth(0, 50);
    ui->tblCustomers->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tblCustomers->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); ui->tblCustomers->setColumnWidth(2, 120);
    ui->tblCustomers->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblCustomers->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblCustomers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tblCustomers->verticalHeader()->setVisible(false);

    setupStyle();
}

CustomersManagementWidget::~CustomersManagementWidget() { delete ui; }

void CustomersManagementWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString CustomersManagementWidget::formatMoney(double amount) {
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German); return locale.toString(val) + " VND";
}

void CustomersManagementWidget::refreshData() {
    ui->tabWidget->setCurrentIndex(0);
    loadPendingOrders();
    loadCustomerList();
    currentSelectedCustId = -1;
    ui->lblSelectedCust->setText("Select a customer to view orders");
    // Xóa list order cũ bên tab database
    QLayout* layout = ui->scrollContentHistory->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) { delete item->widget(); delete item; }
}

void CustomersManagementWidget::on_tabWidget_currentChanged(int index) {
    if (index == 0) loadPendingOrders();
    else loadCustomerList();
}

void CustomersManagementWidget::loadPendingOrders() {
    QLayout* layout = ui->scrollContentPending->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) { delete item->widget(); delete item; }

    vector<Order> pendingOrders;
    for (const auto& o : system->getOrders()) {
        // Lấy đơn Pending hoặc Pending Cancellation
        if (o.getStatus() == "Pending" || o.getStatus() == "Pending Cancellation") {
            pendingOrders.push_back(o);
        }
    }

    if (pendingOrders.empty()) {
        QLabel* empty = new QLabel("No pending orders.", ui->scrollContentPending);
        empty->setAlignment(Qt::AlignCenter);
        empty->setStyleSheet("color: #777; font-size: 16px; margin-top: 50px;");
        layout->addWidget(empty);
    } else {
        std::sort(pendingOrders.begin(), pendingOrders.end(), [](const Order& a, const Order& b) {
            return a.getOrderDate() < b.getOrderDate();
        });

        for (const auto& o : pendingOrders) {
            createOrderCard(o, ui->scrollContentPending, true);
        }
    }
    static_cast<QVBoxLayout*>(layout)->addStretch();
}
double CustomersManagementWidget::calculateTotalSpent(int custId) {
    double total = 0;
    for (const auto& o : system->getOrders()) {
        if (o.getCustomerId() == custId && o.getStatus() == "Completed") {
            total += o.getTotalAmount();
        }
    }
    return total;
}

void CustomersManagementWidget::loadCustomerList() {
    ui->tblCustomers->setRowCount(0);
    string searchKw = ui->txtSearchCust->text().toStdString();
    int sortType = ui->cboSortCust->currentIndex();
    // Tạo danh sách tạm để sort
    struct CustData { Customer c; double spent; };
    vector<CustData> list;
    for (const auto& c : system->getCustomers()) {
        // Lọc tên
        if (!searchKw.empty()) {
            QString name = QString::fromStdString(c.getName());
            if (!name.contains(QString::fromStdString(searchKw), Qt::CaseInsensitive)) continue;
        }
        list.push_back({c, calculateTotalSpent(c.getUserId())});
    }

    std::sort(list.begin(), list.end(), [sortType](const CustData& a, const CustData& b) {
        if (sortType == 0) return a.spent > b.spent;
        if (sortType == 1) return a.spent < b.spent;
        return a.c.getName() < b.c.getName();
    });

    // Hiển thị
    for (const auto& item : list) {
        int r = ui->tblCustomers->rowCount();
        ui->tblCustomers->insertRow(r);

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(item.c.getUserId()));
        idItem->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->setItem(r, 0, idItem);

        ui->tblCustomers->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(item.c.getName())));

        QTableWidgetItem* spentItem = new QTableWidgetItem(formatMoney(item.spent));
        spentItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->tblCustomers->setItem(r, 2, spentItem);
    }
}

void CustomersManagementWidget::on_txtSearchCust_textChanged(const QString &arg1) {
    Q_UNUSED(arg1); loadCustomerList();
}

void CustomersManagementWidget::on_cboSortCust_currentIndexChanged(int index) {
    Q_UNUSED(index); loadCustomerList();
}

void CustomersManagementWidget::on_tblCustomers_cellClicked(int row, int column) {
    Q_UNUSED(column);
    currentSelectedCustId = ui->tblCustomers->item(row, 0)->text().toInt();

    // Tìm tên khách
    QString name = ui->tblCustomers->item(row, 1)->text();
    ui->lblSelectedCust->setText("Orders of: " + name);

    loadCustomerOrders(currentSelectedCustId);
}

void CustomersManagementWidget::on_cboSortOrder_currentIndexChanged(int index) {
    Q_UNUSED(index);
    if (currentSelectedCustId != -1) loadCustomerOrders(currentSelectedCustId);
}

void CustomersManagementWidget::loadCustomerOrders(int custId) {
    QLayout* layout = ui->scrollContentHistory->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) { delete item->widget(); delete item; }

    vector<Order> custOrders;
    for (const auto& o : system->getOrders()) {
        if (o.getCustomerId() == custId) custOrders.push_back(o);
    }

    if (custOrders.empty()) {
        QLabel* empty = new QLabel("No orders found.", ui->scrollContentHistory);
        empty->setAlignment(Qt::AlignCenter);
        empty->setStyleSheet("color: #777; margin-top: 20px;");
        layout->addWidget(empty);
    } else {
        int sortType = ui->cboSortOrder->currentIndex();
        std::sort(custOrders.begin(), custOrders.end(), [sortType](const Order& a, const Order& b) {
            if (sortType == 0) return a.getOrderDate() > b.getOrderDate();
            if (sortType == 1) return a.getOrderDate() < b.getOrderDate();
            if (sortType == 2) return a.getTotalAmount() > b.getTotalAmount();
            return a.getTotalAmount() < b.getTotalAmount();
        });

        for (const auto& o : custOrders) {
            createOrderCard(o, ui->scrollContentHistory, false);
        }
    }
    static_cast<QVBoxLayout*>(layout)->addStretch();
}

void CustomersManagementWidget::createOrderCard(const Order& order, QWidget* parentWidget, bool isActionable) {
    QFrame* card = new QFrame(parentWidget);
    card->setObjectName("OrderCard");
    card->setStyleSheet("QFrame#OrderCard { background-color: #FFFFFF; border: 1px solid #E0E0E0; border-radius: 10px; }");
    QVBoxLayout* l = new QVBoxLayout(card);
    // Header: ID + Date
    QHBoxLayout* h = new QHBoxLayout();
    QLabel* lblId = new QLabel("ORDER #" + QString::number(order.getOrderId()), card);
    lblId->setStyleSheet("font-weight: bold; color: #1565C0; font-size: 14px;");
    QString dateStr = QDateTime::fromSecsSinceEpoch(order.getOrderDate()).toString("dd/MM/yyyy HH:mm");
    QLabel* lblDate = new QLabel(dateStr, card);
    lblDate->setStyleSheet("color: #777;");
    h->addWidget(lblId); h->addStretch(); h->addWidget(lblDate);
    l->addLayout(h);
    // Info: Customer + Status
    Customer* c = system->findCustomer(order.getCustomerId());
    QString custName = c ? QString::fromStdString(c->getName()) : "Unknown";
    QLabel* lblCust = new QLabel("Customer: " + custName, card);
    lblCust->setStyleSheet("font-weight: bold; margin-bottom: 5px;");
    l->addWidget(lblCust);
    QLabel* lblStatus = new QLabel(card);
    QString st = QString::fromStdString(order.getStatus());
    QString color = "#777";
    if (st == "Pending") color = "#F39C12";
    else if (st == "Completed") color = "#27AE60";
    else if (st == "Pending Cancellation") { st = "REQUEST CANCEL"; color = "#E67E22"; }
    else if (st == "Cancelled") color = "#C0392B";
    lblStatus->setText("Status: " + st);
    lblStatus->setStyleSheet("font-weight: bold; color: " + color + ";");
    l->addWidget(lblStatus);
    // Products (Giản lược: chỉ hiện số lượng món)
    QLabel* lblItems = new QLabel("Items: " + QString::number(order.getItems().size()) + " products", card);
    l->addWidget(lblItems);
    // Total
    QLabel* lblTotal = new QLabel("Total: " + formatMoney(order.getTotalAmount()), card);
    lblTotal->setStyleSheet("font-weight: bold; color: #D32F2F; font-size: 14px; margin-top: 5px;");
    l->addWidget(lblTotal);
    if (isActionable) {
        QHBoxLayout* btnLayout = new QHBoxLayout();
        QPushButton* btnConfirm = new QPushButton("Approve Order", card);
        btnConfirm->setStyleSheet("background: #27AE60; color: white; border-radius: 5px; padding: 5px; font-weight: bold;");
        connect(btnConfirm, &QPushButton::clicked, [=]() {
            system->staffConfirmCompleteOrder(order.getOrderId());
            QMessageBox::information(this, "Success", "Order approved & Points added!");
            loadPendingOrders();
        });
        // Nếu khách yêu cầu hủy -> Chữ là "Approve Cancel", còn lại là "Cancel Order"
        QString cancelText = (order.getStatus() == "Pending Cancellation") ? "Approve Cancel" : "Cancel Order";
        QPushButton* btnCancel = new QPushButton(cancelText, card);
        btnCancel->setStyleSheet("background: #C0392B; color: white; border-radius: 5px; padding: 5px; font-weight: bold;");
        connect(btnCancel, &QPushButton::clicked, [=]() {
            if(QMessageBox::Yes == QMessageBox::question(this, "Confirm", "Cancel this order and restock items?", QMessageBox::Yes|QMessageBox::No)) {
                system->staffConfirmCancelOrder(order.getOrderId());
                QMessageBox::information(this, "Success", "Order cancelled & Items restocked!");
                loadPendingOrders();
            }
        });
        btnLayout->addWidget(btnConfirm);
        btnLayout->addWidget(btnCancel);
        l->addLayout(btnLayout);
    }

    parentWidget->layout()->addWidget(card);
}

void CustomersManagementWidget::on_btnBack_clicked() { emit backSignal(); }

void CustomersManagementWidget::setupStyle() {
    this->setAttribute(Qt::WA_StyledBackground, true);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);
    this->setStyleSheet(
        "QWidget { color: #333; font-family: 'Segoe UI'; }"
        "QWidget#CustomersManagementWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"
        "QLabel#lblTitle { font-size: 20px; font-weight: 800; color: #1565C0; }"
        "QLabel#lblPendingHint { color: #555; font-style: italic; margin-bottom: 10px; }"
        "QTabWidget::pane { border: 1px solid #DDD; border-radius: 5px; background: #FAFAFA; }"
        "QTabBar::tab { background: #E0E0E0; color: #555; padding: 10px 20px; border-top-left-radius: 5px; border-top-right-radius: 5px; margin-right: 2px; font-weight: bold; }"
        "QTabBar::tab:selected { background: #FFFFFF; color: #1565C0; border-bottom: 2px solid #1565C0; }"
        "QGroupBox { font-weight: bold; border: 1px solid #DDD; border-radius: 8px; margin-top: 10px; padding-top: 15px; background: #FFFFFF; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #1565C0; }"
        "QLineEdit { background: #FFFFFF; border: 1px solid #DDD; border-radius: 5px; padding: 5px; color: #333; }"
        "QLineEdit:focus { border: 2px solid #1976D2; }"
        "QComboBox { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #DDD; "
        "   border-radius: 5px; "
        "   padding: 5px 10px; "
        "   color: #333333; "
        "}"
        "QComboBox QAbstractItemView { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #DDD; "
        "   selection-background-color: #1976D2; "
        "   selection-color: #FFFFFF; "
        "   color: #333333; "
        "   outline: 0; "
        "}"
        "QTableWidget { "
        "   border: 1px solid #DDD; "
        "   background: #FFFFFF; "
        "   gridline-color: #F0F0F0; "
        "   color: #333; "
        "   outline: 0; "
        "}"
        "QTableWidget::item:selected { "
        "   background-color: #1976D2; "
        "   color: #FFFFFF; "
        "}"
        "QHeaderView::section { background: #F5F7F9; border: none; font-weight: bold; color: #1565C0; padding: 5px; border-bottom: 1px solid #DDD; }"
        "QScrollArea { border: none; background: transparent; }"
        "QWidget#scrollContentPending, QWidget#scrollContentHistory { background: transparent; }"
        "QPushButton#btnBack { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; border-radius: 15px; padding: 5px 15px; font-weight: bold; }"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"
        "QMessageBox QLabel { color: #FFFFFF; font-size: 14px; font-weight: bold; }"
        "QMessageBox QPushButton { background-color: #1976D2; color: white; border-radius: 5px; padding: 5px 15px; min-width: 60px; }"
        "QMessageBox QPushButton:hover { background-color: #1565C0; }"
        );
}
