/********************************************************************************
** Form generated from reading UI file 'ShopAnalysisWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPANALYSISWIDGET_H
#define UI_SHOPANALYSISWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopAnalysisWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *mainCard;
    QVBoxLayout *verticalLayout_Card;
    QHBoxLayout *hlHeader;
    QLabel *lblTitle;
    QSpacerItem *spHeader;
    QLabel *lblFilter;
    QComboBox *cboFilter;
    QFrame *kpiContainer;
    QHBoxLayout *hlKPI;
    QFrame *kpi1;
    QVBoxLayout *vlKPI1;
    QLabel *lblKpiTitle1;
    QLabel *lblValRevenue;
    QFrame *kpi2;
    QVBoxLayout *vlKPI2;
    QLabel *lblKpiTitle2;
    QLabel *lblValOrders;
    QFrame *kpi3;
    QVBoxLayout *vlKPI3;
    QLabel *lblKpiTitle3;
    QLabel *lblValItems;
    QFrame *kpi4;
    QVBoxLayout *vlKPI4;
    QLabel *lblKpiTitle4;
    QLabel *lblValCancel;
    QTabWidget *tabAnalysis;
    QWidget *tabProduct;
    QHBoxLayout *hlTabProd;
    QGroupBox *grpBestSeller;
    QVBoxLayout *vlBest;
    QTableWidget *tblBestSellers;
    QGroupBox *grpLowStock;
    QVBoxLayout *vlLow;
    QTableWidget *tblLowStock;
    QWidget *tabCustomer;
    QVBoxLayout *vlCust;
    QGroupBox *grpVip;
    QVBoxLayout *vlVip;
    QTableWidget *tblVIP;
    QWidget *tabFinance;
    QVBoxLayout *vlFin;
    QTableWidget *tblDailyRevenue;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *ShopAnalysisWidget)
    {
        if (ShopAnalysisWidget->objectName().isEmpty())
            ShopAnalysisWidget->setObjectName("ShopAnalysisWidget");
        ShopAnalysisWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(ShopAnalysisWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(ShopAnalysisWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(980, 700));
        mainCard->setFrameShape(QFrame::StyledPanel);
        verticalLayout_Card = new QVBoxLayout(mainCard);
        verticalLayout_Card->setObjectName("verticalLayout_Card");
        verticalLayout_Card->setContentsMargins(20, 20, 20, 20);
        hlHeader = new QHBoxLayout();
        hlHeader->setObjectName("hlHeader");
        lblTitle = new QLabel(mainCard);
        lblTitle->setObjectName("lblTitle");

        hlHeader->addWidget(lblTitle);

        spHeader = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlHeader->addItem(spHeader);

        lblFilter = new QLabel(mainCard);
        lblFilter->setObjectName("lblFilter");

        hlHeader->addWidget(lblFilter);

        cboFilter = new QComboBox(mainCard);
        cboFilter->addItem(QString());
        cboFilter->addItem(QString());
        cboFilter->setObjectName("cboFilter");

        hlHeader->addWidget(cboFilter);


        verticalLayout_Card->addLayout(hlHeader);

        kpiContainer = new QFrame(mainCard);
        kpiContainer->setObjectName("kpiContainer");
        hlKPI = new QHBoxLayout(kpiContainer);
        hlKPI->setSpacing(15);
        hlKPI->setObjectName("hlKPI");
        hlKPI->setContentsMargins(0, 10, 0, 10);
        kpi1 = new QFrame(kpiContainer);
        kpi1->setObjectName("kpi1");
        vlKPI1 = new QVBoxLayout(kpi1);
        vlKPI1->setObjectName("vlKPI1");
        lblKpiTitle1 = new QLabel(kpi1);
        lblKpiTitle1->setObjectName("lblKpiTitle1");
        lblKpiTitle1->setAlignment(Qt::AlignCenter);

        vlKPI1->addWidget(lblKpiTitle1);

        lblValRevenue = new QLabel(kpi1);
        lblValRevenue->setObjectName("lblValRevenue");
        lblValRevenue->setAlignment(Qt::AlignCenter);

        vlKPI1->addWidget(lblValRevenue);


        hlKPI->addWidget(kpi1);

        kpi2 = new QFrame(kpiContainer);
        kpi2->setObjectName("kpi2");
        vlKPI2 = new QVBoxLayout(kpi2);
        vlKPI2->setObjectName("vlKPI2");
        lblKpiTitle2 = new QLabel(kpi2);
        lblKpiTitle2->setObjectName("lblKpiTitle2");
        lblKpiTitle2->setAlignment(Qt::AlignCenter);

        vlKPI2->addWidget(lblKpiTitle2);

        lblValOrders = new QLabel(kpi2);
        lblValOrders->setObjectName("lblValOrders");
        lblValOrders->setAlignment(Qt::AlignCenter);

        vlKPI2->addWidget(lblValOrders);


        hlKPI->addWidget(kpi2);

        kpi3 = new QFrame(kpiContainer);
        kpi3->setObjectName("kpi3");
        vlKPI3 = new QVBoxLayout(kpi3);
        vlKPI3->setObjectName("vlKPI3");
        lblKpiTitle3 = new QLabel(kpi3);
        lblKpiTitle3->setObjectName("lblKpiTitle3");
        lblKpiTitle3->setAlignment(Qt::AlignCenter);

        vlKPI3->addWidget(lblKpiTitle3);

        lblValItems = new QLabel(kpi3);
        lblValItems->setObjectName("lblValItems");
        lblValItems->setAlignment(Qt::AlignCenter);

        vlKPI3->addWidget(lblValItems);


        hlKPI->addWidget(kpi3);

        kpi4 = new QFrame(kpiContainer);
        kpi4->setObjectName("kpi4");
        vlKPI4 = new QVBoxLayout(kpi4);
        vlKPI4->setObjectName("vlKPI4");
        lblKpiTitle4 = new QLabel(kpi4);
        lblKpiTitle4->setObjectName("lblKpiTitle4");
        lblKpiTitle4->setAlignment(Qt::AlignCenter);

        vlKPI4->addWidget(lblKpiTitle4);

        lblValCancel = new QLabel(kpi4);
        lblValCancel->setObjectName("lblValCancel");
        lblValCancel->setAlignment(Qt::AlignCenter);

        vlKPI4->addWidget(lblValCancel);


        hlKPI->addWidget(kpi4);


        verticalLayout_Card->addWidget(kpiContainer);

        tabAnalysis = new QTabWidget(mainCard);
        tabAnalysis->setObjectName("tabAnalysis");
        tabProduct = new QWidget();
        tabProduct->setObjectName("tabProduct");
        hlTabProd = new QHBoxLayout(tabProduct);
        hlTabProd->setObjectName("hlTabProd");
        grpBestSeller = new QGroupBox(tabProduct);
        grpBestSeller->setObjectName("grpBestSeller");
        vlBest = new QVBoxLayout(grpBestSeller);
        vlBest->setObjectName("vlBest");
        tblBestSellers = new QTableWidget(grpBestSeller);
        if (tblBestSellers->columnCount() < 3)
            tblBestSellers->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblBestSellers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblBestSellers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblBestSellers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblBestSellers->setObjectName("tblBestSellers");

        vlBest->addWidget(tblBestSellers);


        hlTabProd->addWidget(grpBestSeller);

        grpLowStock = new QGroupBox(tabProduct);
        grpLowStock->setObjectName("grpLowStock");
        vlLow = new QVBoxLayout(grpLowStock);
        vlLow->setObjectName("vlLow");
        tblLowStock = new QTableWidget(grpLowStock);
        if (tblLowStock->columnCount() < 3)
            tblLowStock->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblLowStock->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblLowStock->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblLowStock->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tblLowStock->setObjectName("tblLowStock");

        vlLow->addWidget(tblLowStock);


        hlTabProd->addWidget(grpLowStock);

        tabAnalysis->addTab(tabProduct, QString());
        tabCustomer = new QWidget();
        tabCustomer->setObjectName("tabCustomer");
        vlCust = new QVBoxLayout(tabCustomer);
        vlCust->setObjectName("vlCust");
        grpVip = new QGroupBox(tabCustomer);
        grpVip->setObjectName("grpVip");
        vlVip = new QVBoxLayout(grpVip);
        vlVip->setObjectName("vlVip");
        tblVIP = new QTableWidget(grpVip);
        if (tblVIP->columnCount() < 4)
            tblVIP->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblVIP->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblVIP->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblVIP->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblVIP->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tblVIP->setObjectName("tblVIP");

        vlVip->addWidget(tblVIP);


        vlCust->addWidget(grpVip);

        tabAnalysis->addTab(tabCustomer, QString());
        tabFinance = new QWidget();
        tabFinance->setObjectName("tabFinance");
        vlFin = new QVBoxLayout(tabFinance);
        vlFin->setObjectName("vlFin");
        tblDailyRevenue = new QTableWidget(tabFinance);
        if (tblDailyRevenue->columnCount() < 3)
            tblDailyRevenue->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblDailyRevenue->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblDailyRevenue->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblDailyRevenue->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        tblDailyRevenue->setObjectName("tblDailyRevenue");

        vlFin->addWidget(tblDailyRevenue);

        tabAnalysis->addTab(tabFinance, QString());

        verticalLayout_Card->addWidget(tabAnalysis);

        btnBack = new QPushButton(mainCard);
        btnBack->setObjectName("btnBack");

        verticalLayout_Card->addWidget(btnBack);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(ShopAnalysisWidget);

        tabAnalysis->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShopAnalysisWidget);
    } // setupUi

    void retranslateUi(QWidget *ShopAnalysisWidget)
    {
        lblTitle->setText(QCoreApplication::translate("ShopAnalysisWidget", "SHOP ANALYTICS DASHBOARD", nullptr));
        lblFilter->setText(QCoreApplication::translate("ShopAnalysisWidget", "Time Period:", nullptr));
        cboFilter->setItemText(0, QCoreApplication::translate("ShopAnalysisWidget", "All Time", nullptr));
        cboFilter->setItemText(1, QCoreApplication::translate("ShopAnalysisWidget", "This Month", nullptr));

        kpi1->setStyleSheet(QCoreApplication::translate("ShopAnalysisWidget", "background-color: #E3F2FD; border-radius: 10px; border: 1px solid #BBDEFB;", nullptr));
        lblKpiTitle1->setText(QCoreApplication::translate("ShopAnalysisWidget", "TOTAL REVENUE", nullptr));
        lblValRevenue->setText(QCoreApplication::translate("ShopAnalysisWidget", "0 VND", nullptr));
        kpi2->setStyleSheet(QCoreApplication::translate("ShopAnalysisWidget", "background-color: #E8F5E9; border-radius: 10px; border: 1px solid #C8E6C9;", nullptr));
        lblKpiTitle2->setText(QCoreApplication::translate("ShopAnalysisWidget", "TOTAL ORDERS", nullptr));
        lblValOrders->setText(QCoreApplication::translate("ShopAnalysisWidget", "0", nullptr));
        kpi3->setStyleSheet(QCoreApplication::translate("ShopAnalysisWidget", "background-color: #FFF3E0; border-radius: 10px; border: 1px solid #FFE0B2;", nullptr));
        lblKpiTitle3->setText(QCoreApplication::translate("ShopAnalysisWidget", "PRODUCTS SOLD", nullptr));
        lblValItems->setText(QCoreApplication::translate("ShopAnalysisWidget", "0", nullptr));
        kpi4->setStyleSheet(QCoreApplication::translate("ShopAnalysisWidget", "background-color: #FFEBEE; border-radius: 10px; border: 1px solid #FFCDD2;", nullptr));
        lblKpiTitle4->setText(QCoreApplication::translate("ShopAnalysisWidget", "CANCEL RATE", nullptr));
        lblValCancel->setText(QCoreApplication::translate("ShopAnalysisWidget", "0%", nullptr));
        grpBestSeller->setTitle(QCoreApplication::translate("ShopAnalysisWidget", "Top Best Sellers (by Quantity)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblBestSellers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShopAnalysisWidget", "Product", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblBestSellers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShopAnalysisWidget", "Sold", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblBestSellers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShopAnalysisWidget", "Revenue", nullptr));
        grpLowStock->setTitle(QCoreApplication::translate("ShopAnalysisWidget", "Low Stock Alert (< 10)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblLowStock->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ShopAnalysisWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblLowStock->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ShopAnalysisWidget", "Product", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblLowStock->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ShopAnalysisWidget", "Stock", nullptr));
        tabAnalysis->setTabText(tabAnalysis->indexOf(tabProduct), QCoreApplication::translate("ShopAnalysisWidget", "Product Performance", nullptr));
        grpVip->setTitle(QCoreApplication::translate("ShopAnalysisWidget", "Top VIP Customers (by Total Spent)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblVIP->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ShopAnalysisWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblVIP->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ShopAnalysisWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblVIP->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ShopAnalysisWidget", "Total Orders", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblVIP->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ShopAnalysisWidget", "Total Spent", nullptr));
        tabAnalysis->setTabText(tabAnalysis->indexOf(tabCustomer), QCoreApplication::translate("ShopAnalysisWidget", "Customer Insights", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblDailyRevenue->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ShopAnalysisWidget", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblDailyRevenue->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ShopAnalysisWidget", "Orders Count", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblDailyRevenue->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ShopAnalysisWidget", "Revenue", nullptr));
        tabAnalysis->setTabText(tabAnalysis->indexOf(tabFinance), QCoreApplication::translate("ShopAnalysisWidget", "Financials (Daily Revenue)", nullptr));
        btnBack->setText(QCoreApplication::translate("ShopAnalysisWidget", "Back to Dashboard", nullptr));
        (void)ShopAnalysisWidget;
    } // retranslateUi

};

namespace Ui {
    class ShopAnalysisWidget: public Ui_ShopAnalysisWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPANALYSISWIDGET_H
