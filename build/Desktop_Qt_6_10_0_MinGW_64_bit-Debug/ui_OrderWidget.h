/********************************************************************************
** Form generated from reading UI file 'OrderWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERWIDGET_H
#define UI_ORDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *mainCard;
    QHBoxLayout *horizontalLayout_Card;
    QWidget *leftSide;
    QVBoxLayout *verticalLayout_Left;
    QLabel *lblTitle;
    QTableWidget *tblOrderItems;
    QLabel *lblSubtotal;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QLabel *lblPaymentTitle;
    QSpacerItem *vSpacer1;
    QLabel *label_Promo;
    QComboBox *cboPromotions;
    QLabel *lblDiscountVal;
    QSpacerItem *vSpacer2;
    QLabel *label_Points;
    QSpinBox *spinPoints;
    QLabel *lblPointHint;
    QLabel *lblPointDiscountVal;
    QSpacerItem *vSpacer3;
    QLabel *label_Method;
    QComboBox *cboPaymentMethod;
    QSpacerItem *vSpacer4;
    QLabel *lblFinalTotalLabel;
    QLabel *lblFinalTotal;
    QSpacerItem *vSpacer5;
    QPushButton *btnConfirmPay;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *OrderWidget)
    {
        if (OrderWidget->objectName().isEmpty())
            OrderWidget->setObjectName("OrderWidget");
        OrderWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(OrderWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(OrderWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(900, 600));
        mainCard->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_Card = new QHBoxLayout(mainCard);
        horizontalLayout_Card->setSpacing(0);
        horizontalLayout_Card->setObjectName("horizontalLayout_Card");
        horizontalLayout_Card->setContentsMargins(0, 0, 0, 0);
        leftSide = new QWidget(mainCard);
        leftSide->setObjectName("leftSide");
        verticalLayout_Left = new QVBoxLayout(leftSide);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(30, 30, 20, 30);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        tblOrderItems = new QTableWidget(leftSide);
        if (tblOrderItems->columnCount() < 4)
            tblOrderItems->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblOrderItems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblOrderItems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblOrderItems->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblOrderItems->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblOrderItems->setObjectName("tblOrderItems");
        tblOrderItems->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout_Left->addWidget(tblOrderItems);

        lblSubtotal = new QLabel(leftSide);
        lblSubtotal->setObjectName("lblSubtotal");
        lblSubtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_Left->addWidget(lblSubtotal);


        horizontalLayout_Card->addWidget(leftSide);

        lineSeparator = new QFrame(mainCard);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::Shape::VLine);
        lineSeparator->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_Card->addWidget(lineSeparator);

        rightSide = new QWidget(mainCard);
        rightSide->setObjectName("rightSide");
        rightSide->setMinimumSize(QSize(320, 0));
        verticalLayout_Right = new QVBoxLayout(rightSide);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(20, 40, 20, 30);
        lblPaymentTitle = new QLabel(rightSide);
        lblPaymentTitle->setObjectName("lblPaymentTitle");
        lblPaymentTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblPaymentTitle);

        vSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer1);

        label_Promo = new QLabel(rightSide);
        label_Promo->setObjectName("label_Promo");

        verticalLayout_Right->addWidget(label_Promo);

        cboPromotions = new QComboBox(rightSide);
        cboPromotions->setObjectName("cboPromotions");

        verticalLayout_Right->addWidget(cboPromotions);

        lblDiscountVal = new QLabel(rightSide);
        lblDiscountVal->setObjectName("lblDiscountVal");
        lblDiscountVal->setAlignment(Qt::AlignRight);

        verticalLayout_Right->addWidget(lblDiscountVal);

        vSpacer2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer2);

        label_Points = new QLabel(rightSide);
        label_Points->setObjectName("label_Points");

        verticalLayout_Right->addWidget(label_Points);

        spinPoints = new QSpinBox(rightSide);
        spinPoints->setObjectName("spinPoints");
        spinPoints->setSingleStep(10);

        verticalLayout_Right->addWidget(spinPoints);

        lblPointHint = new QLabel(rightSide);
        lblPointHint->setObjectName("lblPointHint");

        verticalLayout_Right->addWidget(lblPointHint);

        lblPointDiscountVal = new QLabel(rightSide);
        lblPointDiscountVal->setObjectName("lblPointDiscountVal");
        lblPointDiscountVal->setAlignment(Qt::AlignRight);

        verticalLayout_Right->addWidget(lblPointDiscountVal);

        vSpacer3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer3);

        label_Method = new QLabel(rightSide);
        label_Method->setObjectName("label_Method");

        verticalLayout_Right->addWidget(label_Method);

        cboPaymentMethod = new QComboBox(rightSide);
        cboPaymentMethod->addItem(QString());
        cboPaymentMethod->addItem(QString());
        cboPaymentMethod->addItem(QString());
        cboPaymentMethod->setObjectName("cboPaymentMethod");

        verticalLayout_Right->addWidget(cboPaymentMethod);

        vSpacer4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer4);

        lblFinalTotalLabel = new QLabel(rightSide);
        lblFinalTotalLabel->setObjectName("lblFinalTotalLabel");
        lblFinalTotalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblFinalTotalLabel);

        lblFinalTotal = new QLabel(rightSide);
        lblFinalTotal->setObjectName("lblFinalTotal");
        lblFinalTotal->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblFinalTotal);

        vSpacer5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer5);

        btnConfirmPay = new QPushButton(rightSide);
        btnConfirmPay->setObjectName("btnConfirmPay");

        verticalLayout_Right->addWidget(btnConfirmPay);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(OrderWidget);

        QMetaObject::connectSlotsByName(OrderWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderWidget)
    {
        lblTitle->setText(QCoreApplication::translate("OrderWidget", "CONFIRM ORDER", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblOrderItems->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("OrderWidget", "Product", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblOrderItems->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("OrderWidget", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblOrderItems->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("OrderWidget", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblOrderItems->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("OrderWidget", "Total", nullptr));
        lblSubtotal->setText(QCoreApplication::translate("OrderWidget", "Subtotal: 0 VND", nullptr));
        lblPaymentTitle->setText(QCoreApplication::translate("OrderWidget", "PAYMENT DETAILS", nullptr));
        label_Promo->setText(QCoreApplication::translate("OrderWidget", "Select Promotion:", nullptr));
        lblDiscountVal->setText(QCoreApplication::translate("OrderWidget", "-0 VND", nullptr));
        lblDiscountVal->setStyleSheet(QCoreApplication::translate("OrderWidget", "color: #2ECC71;", nullptr));
        label_Points->setText(QCoreApplication::translate("OrderWidget", "Use Loyalty Points:", nullptr));
        lblPointHint->setText(QCoreApplication::translate("OrderWidget", "(10 pts = 1000 VND)", nullptr));
        lblPointDiscountVal->setText(QCoreApplication::translate("OrderWidget", "-0 VND", nullptr));
        lblPointDiscountVal->setStyleSheet(QCoreApplication::translate("OrderWidget", "color: #2ECC71;", nullptr));
        label_Method->setText(QCoreApplication::translate("OrderWidget", "Payment Method:", nullptr));
        cboPaymentMethod->setItemText(0, QCoreApplication::translate("OrderWidget", "Cash", nullptr));
        cboPaymentMethod->setItemText(1, QCoreApplication::translate("OrderWidget", "Credit Card", nullptr));
        cboPaymentMethod->setItemText(2, QCoreApplication::translate("OrderWidget", "E-Wallet (Momo/ZaloPay)", nullptr));

        lblFinalTotalLabel->setText(QCoreApplication::translate("OrderWidget", "FINAL TOTAL", nullptr));
        lblFinalTotal->setText(QCoreApplication::translate("OrderWidget", "0 VND", nullptr));
        btnConfirmPay->setText(QCoreApplication::translate("OrderWidget", "CONFIRM PAYMENT", nullptr));
        btnBack->setText(QCoreApplication::translate("OrderWidget", "Cancel", nullptr));
        (void)OrderWidget;
    } // retranslateUi

};

namespace Ui {
    class OrderWidget: public Ui_OrderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERWIDGET_H
