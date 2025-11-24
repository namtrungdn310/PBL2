/********************************************************************************
** Form generated from reading UI file 'OrderHistoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERHISTORYWIDGET_H
#define UI_ORDERHISTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderHistoryWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QWidget *contentContainer;
    QVBoxLayout *verticalLayout_Content;
    QLabel *lblTitle;
    QHBoxLayout *horizontalLayout_Filter;
    QLabel *label_Sort;
    QComboBox *cboSortOrder;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Scroll;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *OrderHistoryWidget)
    {
        if (OrderHistoryWidget->objectName().isEmpty())
            OrderHistoryWidget->setObjectName("OrderHistoryWidget");
        OrderHistoryWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(OrderHistoryWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(OrderHistoryWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        contentContainer = new QWidget(centerContainer);
        contentContainer->setObjectName("contentContainer");
        contentContainer->setMinimumSize(QSize(800, 0));
        contentContainer->setMaximumSize(QSize(800, 16777215));
        verticalLayout_Content = new QVBoxLayout(contentContainer);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        lblTitle = new QLabel(contentContainer);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_Content->addWidget(lblTitle);

        horizontalLayout_Filter = new QHBoxLayout();
        horizontalLayout_Filter->setObjectName("horizontalLayout_Filter");
        label_Sort = new QLabel(contentContainer);
        label_Sort->setObjectName("label_Sort");

        horizontalLayout_Filter->addWidget(label_Sort);

        cboSortOrder = new QComboBox(contentContainer);
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->addItem(QString());
        cboSortOrder->setObjectName("cboSortOrder");

        horizontalLayout_Filter->addWidget(cboSortOrder);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Filter->addItem(horizontalSpacer);


        verticalLayout_Content->addLayout(horizontalLayout_Filter);

        scrollArea = new QScrollArea(contentContainer);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 782, 500));
        verticalLayout_Scroll = new QVBoxLayout(scrollContent);
        verticalLayout_Scroll->setSpacing(20);
        verticalLayout_Scroll->setObjectName("verticalLayout_Scroll");
        scrollArea->setWidget(scrollContent);

        verticalLayout_Content->addWidget(scrollArea);

        btnBack = new QPushButton(contentContainer);
        btnBack->setObjectName("btnBack");

        verticalLayout_Content->addWidget(btnBack);


        horizontalLayout_Center->addWidget(contentContainer);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(OrderHistoryWidget);

        QMetaObject::connectSlotsByName(OrderHistoryWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderHistoryWidget)
    {
        lblTitle->setText(QCoreApplication::translate("OrderHistoryWidget", "MY ORDER HISTORY", nullptr));
        label_Sort->setText(QCoreApplication::translate("OrderHistoryWidget", "Sort By:", nullptr));
        cboSortOrder->setItemText(0, QCoreApplication::translate("OrderHistoryWidget", "Date: Newest First", nullptr));
        cboSortOrder->setItemText(1, QCoreApplication::translate("OrderHistoryWidget", "Date: Oldest First", nullptr));
        cboSortOrder->setItemText(2, QCoreApplication::translate("OrderHistoryWidget", "Price: Low to High", nullptr));
        cboSortOrder->setItemText(3, QCoreApplication::translate("OrderHistoryWidget", "Price: High to Low", nullptr));

        btnBack->setText(QCoreApplication::translate("OrderHistoryWidget", "Back to Dashboard", nullptr));
        (void)OrderHistoryWidget;
    } // retranslateUi

};

namespace Ui {
    class OrderHistoryWidget: public Ui_OrderHistoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERHISTORYWIDGET_H
