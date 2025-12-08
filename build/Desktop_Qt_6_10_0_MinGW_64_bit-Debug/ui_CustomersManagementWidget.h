/********************************************************************************
** Form generated from reading UI file 'CustomersManagementWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSMANAGEMENTWIDGET_H
#define UI_CUSTOMERSMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomersManagementWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *mainCard;
    QVBoxLayout *verticalLayout_Card;
    QWidget *headerWidget;
    QHBoxLayout *hlHeader;
    QLabel *lblTitle;
    QSpacerItem *spHeader;
    QPushButton *btnBack;
    QTabWidget *tabWidget;
    QWidget *tabPending;
    QVBoxLayout *vlPending;
    QLabel *lblPendingHint;
    QScrollArea *scrollPending;
    QWidget *scrollContentPending;
    QVBoxLayout *vlScrollPending;
    QWidget *tabDatabase;
    QHBoxLayout *hlDatabase;
    QGroupBox *grpCustList;
    QVBoxLayout *vlCustList;
    QLineEdit *txtSearchCust;
    QHBoxLayout *hlSortCust;
    QLabel *lSort;
    QComboBox *cboSortCust;
    QTableWidget *tblCustomers;
    QGroupBox *grpCustOrders;
    QVBoxLayout *vlCustOrders;
    QHBoxLayout *hlSortOrder;
    QLabel *lblSelectedCust;
    QSpacerItem *spOrder;
    QComboBox *cboSortOrder;
    QScrollArea *scrollHistory;
    QWidget *scrollContentHistory;
    QVBoxLayout *vlScrollHistory;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *CustomersManagementWidget)
    {
        if (CustomersManagementWidget->objectName().isEmpty())
            CustomersManagementWidget->setObjectName("CustomersManagementWidget");
        CustomersManagementWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(CustomersManagementWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(CustomersManagementWidget);
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
        verticalLayout_Card->setContentsMargins(0, 0, 0, 0);
        headerWidget = new QWidget(mainCard);
        headerWidget->setObjectName("headerWidget");
        headerWidget->setMinimumSize(QSize(0, 60));
        hlHeader = new QHBoxLayout(headerWidget);
        hlHeader->setObjectName("hlHeader");
        lblTitle = new QLabel(headerWidget);
        lblTitle->setObjectName("lblTitle");

        hlHeader->addWidget(lblTitle);

        spHeader = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlHeader->addItem(spHeader);

        btnBack = new QPushButton(headerWidget);
        btnBack->setObjectName("btnBack");

        hlHeader->addWidget(btnBack);


        verticalLayout_Card->addWidget(headerWidget);

        tabWidget = new QTabWidget(mainCard);
        tabWidget->setObjectName("tabWidget");
        tabPending = new QWidget();
        tabPending->setObjectName("tabPending");
        vlPending = new QVBoxLayout(tabPending);
        vlPending->setObjectName("vlPending");
        lblPendingHint = new QLabel(tabPending);
        lblPendingHint->setObjectName("lblPendingHint");
        lblPendingHint->setAlignment(Qt::AlignCenter);

        vlPending->addWidget(lblPendingHint);

        scrollPending = new QScrollArea(tabPending);
        scrollPending->setObjectName("scrollPending");
        scrollPending->setWidgetResizable(true);
        scrollContentPending = new QWidget();
        scrollContentPending->setObjectName("scrollContentPending");
        vlScrollPending = new QVBoxLayout(scrollContentPending);
        vlScrollPending->setSpacing(15);
        vlScrollPending->setObjectName("vlScrollPending");
        scrollPending->setWidget(scrollContentPending);

        vlPending->addWidget(scrollPending);

        tabWidget->addTab(tabPending, QString());
        tabDatabase = new QWidget();
        tabDatabase->setObjectName("tabDatabase");
        hlDatabase = new QHBoxLayout(tabDatabase);
        hlDatabase->setObjectName("hlDatabase");
        grpCustList = new QGroupBox(tabDatabase);
        grpCustList->setObjectName("grpCustList");
        grpCustList->setMaximumSize(QSize(400, 16777215));
        vlCustList = new QVBoxLayout(grpCustList);
        vlCustList->setObjectName("vlCustList");
        txtSearchCust = new QLineEdit(grpCustList);
        txtSearchCust->setObjectName("txtSearchCust");

        vlCustList->addWidget(txtSearchCust);

        hlSortCust = new QHBoxLayout();
        hlSortCust->setObjectName("hlSortCust");
        lSort = new QLabel(grpCustList);
        lSort->setObjectName("lSort");

        hlSortCust->addWidget(lSort);

        cboSortCust = new QComboBox(grpCustList);
        cboSortCust->addItem(QString());
        cboSortCust->addItem(QString());
        cboSortCust->addItem(QString());
        cboSortCust->setObjectName("cboSortCust");

        hlSortCust->addWidget(cboSortCust);


        vlCustList->addLayout(hlSortCust);

        tblCustomers = new QTableWidget(grpCustList);
        if (tblCustomers->columnCount() < 3)
            tblCustomers->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCustomers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCustomers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCustomers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblCustomers->setObjectName("tblCustomers");
        tblCustomers->setSelectionBehavior(QAbstractItemView::SelectRows);

        vlCustList->addWidget(tblCustomers);


        hlDatabase->addWidget(grpCustList);

        grpCustOrders = new QGroupBox(tabDatabase);
        grpCustOrders->setObjectName("grpCustOrders");
        vlCustOrders = new QVBoxLayout(grpCustOrders);
        vlCustOrders->setObjectName("vlCustOrders");
        hlSortOrder = new QHBoxLayout();
        hlSortOrder->setObjectName("hlSortOrder");
        lblSelectedCust = new QLabel(grpCustOrders);
        lblSelectedCust->setObjectName("lblSelectedCust");

        hlSortOrder->addWidget(lblSelectedCust);

        spOrder = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlSortOrder->addItem(spOrder);

        cboSortOrder = new QComboBox(grpCustOrders);
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->setObjectName("cboSortOrder");

        hlSortOrder->addWidget(cboSortOrder);


        vlCustOrders->addLayout(hlSortOrder);

        scrollHistory = new QScrollArea(grpCustOrders);
        scrollHistory->setObjectName("scrollHistory");
        scrollHistory->setWidgetResizable(true);
        scrollContentHistory = new QWidget();
        scrollContentHistory->setObjectName("scrollContentHistory");
        vlScrollHistory = new QVBoxLayout(scrollContentHistory);
        vlScrollHistory->setSpacing(15);
        vlScrollHistory->setObjectName("vlScrollHistory");
        scrollHistory->setWidget(scrollContentHistory);

        vlCustOrders->addWidget(scrollHistory);


        hlDatabase->addWidget(grpCustOrders);

        tabWidget->addTab(tabDatabase, QString());

        verticalLayout_Card->addWidget(tabWidget);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(CustomersManagementWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CustomersManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomersManagementWidget)
    {
        lblTitle->setText(QCoreApplication::translate("CustomersManagementWidget", "CUSTOMERS & ORDERS MANAGEMENT", nullptr));
        btnBack->setText(QCoreApplication::translate("CustomersManagementWidget", "Back to Dashboard", nullptr));
        lblPendingHint->setText(QCoreApplication::translate("CustomersManagementWidget", "Orders requiring your confirmation (Sorted: Oldest First)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPending), QCoreApplication::translate("CustomersManagementWidget", "Manage Pending Orders", nullptr));
        grpCustList->setTitle(QCoreApplication::translate("CustomersManagementWidget", "Customer List", nullptr));
        txtSearchCust->setPlaceholderText(QCoreApplication::translate("CustomersManagementWidget", "Search Name...", nullptr));
        lSort->setText(QCoreApplication::translate("CustomersManagementWidget", "Sort:", nullptr));
        cboSortCust->setItemText(0, QCoreApplication::translate("CustomersManagementWidget", "Total Spent: High to Low", nullptr));
        cboSortCust->setItemText(1, QCoreApplication::translate("CustomersManagementWidget", "Total Spent: Low to High", nullptr));
        cboSortCust->setItemText(2, QCoreApplication::translate("CustomersManagementWidget", "Name: A-Z", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tblCustomers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CustomersManagementWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCustomers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CustomersManagementWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCustomers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CustomersManagementWidget", "Total Spent", nullptr));
        grpCustOrders->setTitle(QCoreApplication::translate("CustomersManagementWidget", "Selected Customer Orders", nullptr));
        lblSelectedCust->setText(QCoreApplication::translate("CustomersManagementWidget", "Select a customer to view orders", nullptr));
        cboSortOrder->setItemText(0, QCoreApplication::translate("CustomersManagementWidget", "Date: Newest First", nullptr));
        cboSortOrder->setItemText(1, QCoreApplication::translate("CustomersManagementWidget", "Date: Oldest First", nullptr));
        cboSortOrder->setItemText(2, QCoreApplication::translate("CustomersManagementWidget", "Price: High to Low", nullptr));
        cboSortOrder->setItemText(3, QCoreApplication::translate("CustomersManagementWidget", "Price: Low to High", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabDatabase), QCoreApplication::translate("CustomersManagementWidget", "Customer Database", nullptr));
        (void)CustomersManagementWidget;
    } // retranslateUi

};

namespace Ui {
    class CustomersManagementWidget: public Ui_CustomersManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSMANAGEMENTWIDGET_H
