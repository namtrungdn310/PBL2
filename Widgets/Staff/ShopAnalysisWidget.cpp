#include "ShopAnalysisWidget.h"
#include "ui_ShopAnalysisWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QDateTime>
#include <QLocale>
#include <QHeaderView>
#include <algorithm>
#include <map>

using namespace std;

ShopAnalysisWidget::ShopAnalysisWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopAnalysisWidget)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("ShopAnalysisWidget");

    auto setupTable = [](QTableWidget* t) {
        t->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        t->setEditTriggers(QAbstractItemView::NoEditTriggers);
        t->setSelectionBehavior(QAbstractItemView::SelectRows);
        t->verticalHeader()->setVisible(false);
    };

    setupTable(ui->tblBestSellers);
    setupTable(ui->tblLowStock);
    setupTable(ui->tblVIP);
    setupTable(ui->tblDailyRevenue);

    ui->tblLowStock->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tblLowStock->setColumnWidth(0, 50);

    setupStyle();
}

ShopAnalysisWidget::~ShopAnalysisWidget() { delete ui; }

void ShopAnalysisWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event); QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString ShopAnalysisWidget::formatMoney(double amount) {
    long long val = static_cast<long long>(amount);
    QLocale locale(QLocale::German); return locale.toString(val) + " VND";
}

void ShopAnalysisWidget::refreshData() {
    calculateKPIs();
    loadProductPerformance();
    loadCustomerInsights();
    loadDailyRevenue();
}

void ShopAnalysisWidget::on_cboFilter_currentIndexChanged(int index) {
    Q_UNUSED(index);
    refreshData();
}

bool ShopAnalysisWidget::isOrderInPeriod(const Order& o) {
    if (ui->cboFilter->currentText() == "All Time") return true;
    QDate orderDate = QDateTime::fromSecsSinceEpoch(o.getOrderDate()).date();
    QDate current = QDate::currentDate();
    return (orderDate.month() == current.month() && orderDate.year() == current.year());
}

// kpi
void ShopAnalysisWidget::calculateKPIs() {
    double totalRev = 0;
    int totalOrders = 0;
    int itemsSold = 0;
    int cancelled = 0;
    int totalAll = 0;

    for (const auto& o : system->getOrders()) {
        if (!isOrderInPeriod(o)) continue;

        totalAll++;
        if (o.getStatus() == "Completed") {
            totalRev += o.getTotalAmount();
            totalOrders++;
            for(const auto& item : o.getItems()) itemsSold += item.getQuantity();
        }
        else if (o.getStatus() == "Cancelled") {
            cancelled++;
        }
    }

    ui->lblValRevenue->setText(formatMoney(totalRev));
    ui->lblValOrders->setText(QString::number(totalOrders));
    ui->lblValItems->setText(QString::number(itemsSold));

    double rate = (totalAll > 0) ? ((double)cancelled / totalAll * 100.0) : 0.0;
    ui->lblValCancel->setText(QString::number(rate, 'f', 1) + "%");
}

// best seller, low stock
void ShopAnalysisWidget::loadProductPerformance() {
    map<int, int> qtyMap;
    map<int, double> revMap;

    for (const auto& o : system->getOrders()) {
        if (o.getStatus() != "Completed") continue;
        if (!isOrderInPeriod(o)) continue;

        for (const auto& item : o.getItems()) {
            qtyMap[item.getProduct().getProductId()] += item.getQuantity();
            revMap[item.getProduct().getProductId()] += item.getSubtotal();
        }
    }

    struct ProdStat { int id; int qty; double rev; };
    vector<ProdStat> list;
    for(auto const& [id, qty] : qtyMap) {
        list.push_back({id, qty, revMap[id]});
    }

    sort(list.begin(), list.end(), [](const ProdStat& a, const ProdStat& b){
        return a.qty > b.qty;
    });

    ui->tblBestSellers->setRowCount(0);

    int limit = min((int)list.size(), 10);
    for(int i=0; i<limit; ++i) {
        Product* p = system->findProduct(list[i].id);
        QString name = p ? QString::fromStdString(p->getName()) : "Unknown";

        int r = ui->tblBestSellers->rowCount();
        ui->tblBestSellers->insertRow(r);
        ui->tblBestSellers->setItem(r, 0, new QTableWidgetItem(name));
        ui->tblBestSellers->setItem(r, 1, new QTableWidgetItem(QString::number(list[i].qty)));
        ui->tblBestSellers->setItem(r, 2, new QTableWidgetItem(formatMoney(list[i].rev)));
    }

    ui->tblLowStock->setRowCount(0);
    for(const auto& p : system->getProducts()) {
        if (p.getTotalStock() < 10) {
            int r = ui->tblLowStock->rowCount();
            ui->tblLowStock->insertRow(r);
            ui->tblLowStock->setItem(r, 0, new QTableWidgetItem(QString::number(p.getProductId())));
            ui->tblLowStock->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));

            QTableWidgetItem* stockItem = new QTableWidgetItem(QString::number(p.getTotalStock()));
            stockItem->setForeground(QBrush(QColor("#D32F2F")));
            stockItem->setFont(QFont("Segoe UI", 9, QFont::Bold));
            ui->tblLowStock->setItem(r, 2, stockItem);
        }
    }
}

// customer vip (top 20)
void ShopAnalysisWidget::loadCustomerInsights() {
    map<int, double> spentMap;
    map<int, int> orderCountMap;

    for (const auto& o : system->getOrders()) {
        if (o.getStatus() != "Completed") continue;
        if (!isOrderInPeriod(o)) continue;

        spentMap[o.getCustomerId()] += o.getTotalAmount();
        orderCountMap[o.getCustomerId()]++;
    }

    struct CustStat { int id; double spent; int count; };
    vector<CustStat> list;
    for(auto const& [id, val] : spentMap) {
        list.push_back({id, val, orderCountMap[id]});
    }

    sort(list.begin(), list.end(), [](const CustStat& a, const CustStat& b){
        return a.spent > b.spent;
    });

    ui->tblVIP->setRowCount(0);
    int limit = min((int)list.size(), 20);
    for(int i=0; i<limit; ++i) {
        Customer* c = system->findCustomer(list[i].id);
        QString name = c ? QString::fromStdString(c->getName()) : "Unknown";

        int r = ui->tblVIP->rowCount();
        ui->tblVIP->insertRow(r);
        ui->tblVIP->setItem(r, 0, new QTableWidgetItem(QString::number(list[i].id)));
        ui->tblVIP->setItem(r, 1, new QTableWidgetItem(name));
        ui->tblVIP->setItem(r, 2, new QTableWidgetItem(QString::number(list[i].count)));
        ui->tblVIP->setItem(r, 3, new QTableWidgetItem(formatMoney(list[i].spent)));
    }
}

// doanh thu theo ngày
void ShopAnalysisWidget::loadDailyRevenue() {
    map<QString, Pair<double, int>> dailyMap;

    for (const auto& o : system->getOrders()) {
        if (o.getStatus() != "Completed") continue;
        if (!isOrderInPeriod(o)) continue;

        QString key = QDateTime::fromSecsSinceEpoch(o.getOrderDate()).toString("yyyy-MM-dd");
        dailyMap[key].first += o.getTotalAmount();
        dailyMap[key].second++;
    }

    ui->tblDailyRevenue->setRowCount(0);
    for(auto const& [dateRaw, val] : dailyMap) {
        QString dateDisplay = QDate::fromString(dateRaw, "yyyy-MM-dd").toString("dd/MM/yyyy");

        int r = ui->tblDailyRevenue->rowCount();
        ui->tblDailyRevenue->insertRow(r);
        ui->tblDailyRevenue->setItem(r, 0, new QTableWidgetItem(dateDisplay));
        ui->tblDailyRevenue->setItem(r, 1, new QTableWidgetItem(QString::number(val.second)));
        ui->tblDailyRevenue->setItem(r, 2, new QTableWidgetItem(formatMoney(val.first)));
    }
}

void ShopAnalysisWidget::on_btnBack_clicked() { emit backSignal(); }

void ShopAnalysisWidget::setupStyle() {
    this->setAttribute(Qt::WA_StyledBackground, true);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 50)); shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333; font-family: 'Segoe UI'; }"
        "QWidget#ShopAnalysisWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"
        "QLabel#lblTitle { font-size: 22px; font-weight: 900; color: #1565C0; }"
        "QLabel#lblFilter { font-weight: bold; color: #555; }"
        "QLabel#lblKpiTitle1, QLabel#lblKpiTitle2, QLabel#lblKpiTitle3, QLabel#lblKpiTitle4 { font-size: 11px; font-weight: bold; color: #555; margin-bottom: 5px; }"
        "QLabel#lblValRevenue { font-size: 16px; font-weight: 900; color: #1976D2; }"
        "QLabel#lblValOrders { font-size: 20px; font-weight: 900; color: #2E7D32; }"
        "QLabel#lblValItems { font-size: 20px; font-weight: 900; color: #E65100; }"
        "QLabel#lblValCancel { font-size: 20px; font-weight: 900; color: #C62828; }"
        "QTabWidget::pane { border: 1px solid #DDD; border-radius: 5px; background: #FAFAFA; }"
        "QTabBar::tab { background: #E0E0E0; color: #555; padding: 8px 20px; border-top-left-radius: 5px; border-top-right-radius: 5px; margin-right: 2px; font-weight: bold; }"
        "QTabBar::tab:selected { background: #FFFFFF; color: #1565C0; border-bottom: 2px solid #1565C0; }"
        "QTableWidget { border: 1px solid #DDD; background: #FFFFFF; gridline-color: #F0F0F0; color: #333; outline: 0; }"
        "QTableWidget::item:selected { background-color: #E3F2FD; color: #1565C0; }"
        "QHeaderView::section { background: #F5F7F9; border: none; font-weight: bold; color: #1565C0; padding: 5px; border-bottom: 1px solid #DDD; }"
        "QComboBox { background: #FFF; border: 1px solid #DDD; border-radius: 5px; padding: 5px; min-width: 100px; }"
        "QComboBox:focus { border: 2px solid #1976D2; }"
        "QComboBox QAbstractItemView { background: #FFF; selection-background-color: #1976D2; selection-color: #FFF; border: 1px solid #DDD; outline: 0; }"
        "QPushButton#btnBack { background-color: #FFFFFF; border: 2px solid #EF5350; color: #D32F2F; border-radius: 15px; padding: 5px 15px; font-weight: bold; }"
        "QPushButton#btnBack:hover { background-color: #FFEBEE; }"
        "QMessageBox QLabel { color: #FFFFFF; font-size: 14px; font-weight: bold; }"
        "QMessageBox QPushButton { background-color: #1976D2; color: white; border-radius: 5px; padding: 5px 15px; min-width: 60px; }"
        "QMessageBox QPushButton:hover { background-color: #1565C0; }"
        );
}
