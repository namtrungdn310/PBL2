/********************************************************************************
** Form generated from reading UI file 'ViewCartWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWCARTWIDGET_H
#define UI_VIEWCARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewCartWidget
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
    QTableWidget *tblCart;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QLabel *lblSummaryTitle;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblTotalLabel;
    QLabel *lblTotalMoney;
    QSpacerItem *verticalSpacer;
    QPushButton *btnCheckout;
    QPushButton *btnDecrease;
    QPushButton *btnRemove;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *ViewCartWidget)
    {
        if (ViewCartWidget->objectName().isEmpty())
            ViewCartWidget->setObjectName("ViewCartWidget");
        ViewCartWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(ViewCartWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(ViewCartWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(850, 600));
        mainCard->setMaximumSize(QSize(850, 600));
        mainCard->setFrameShape(QFrame::StyledPanel);
        mainCard->setFrameShadow(QFrame::Raised);
        horizontalLayout_Card = new QHBoxLayout(mainCard);
        horizontalLayout_Card->setSpacing(0);
        horizontalLayout_Card->setObjectName("horizontalLayout_Card");
        horizontalLayout_Card->setContentsMargins(0, 0, 0, 0);
        leftSide = new QWidget(mainCard);
        leftSide->setObjectName("leftSide");
        verticalLayout_Left = new QVBoxLayout(leftSide);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(20, 20, 20, 20);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        tblCart = new QTableWidget(leftSide);
        if (tblCart->columnCount() < 5)
            tblCart->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCart->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblCart->setObjectName("tblCart");
        tblCart->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Left->addWidget(tblCart);


        horizontalLayout_Card->addWidget(leftSide);

        lineSeparator = new QFrame(mainCard);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::Shape::VLine);
        lineSeparator->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_Card->addWidget(lineSeparator);

        rightSide = new QWidget(mainCard);
        rightSide->setObjectName("rightSide");
        rightSide->setMinimumSize(QSize(280, 0));
        rightSide->setMaximumSize(QSize(280, 16777215));
        verticalLayout_Right = new QVBoxLayout(rightSide);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(20, 50, 20, 20);
        lblSummaryTitle = new QLabel(rightSide);
        lblSummaryTitle->setObjectName("lblSummaryTitle");
        lblSummaryTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblSummaryTitle);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer_2);

        lblTotalLabel = new QLabel(rightSide);
        lblTotalLabel->setObjectName("lblTotalLabel");
        lblTotalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblTotalLabel);

        lblTotalMoney = new QLabel(rightSide);
        lblTotalMoney->setObjectName("lblTotalMoney");
        lblTotalMoney->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblTotalMoney);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer);

        btnCheckout = new QPushButton(rightSide);
        btnCheckout->setObjectName("btnCheckout");

        verticalLayout_Right->addWidget(btnCheckout);

        btnDecrease = new QPushButton(rightSide);
        btnDecrease->setObjectName("btnDecrease");

        verticalLayout_Right->addWidget(btnDecrease);

        btnRemove = new QPushButton(rightSide);
        btnRemove->setObjectName("btnRemove");

        verticalLayout_Right->addWidget(btnRemove);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer_3);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(ViewCartWidget);

        QMetaObject::connectSlotsByName(ViewCartWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewCartWidget)
    {
        lblTitle->setText(QCoreApplication::translate("ViewCartWidget", "SHOPPING CART", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblCart->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ViewCartWidget", "Product", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCart->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ViewCartWidget", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCart->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ViewCartWidget", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblCart->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ViewCartWidget", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblCart->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ViewCartWidget", "Total", nullptr));
        lblSummaryTitle->setText(QCoreApplication::translate("ViewCartWidget", "ORDER SUMMARY", nullptr));
        lblTotalLabel->setText(QCoreApplication::translate("ViewCartWidget", "Total Amount", nullptr));
        lblTotalMoney->setText(QCoreApplication::translate("ViewCartWidget", "0 VND", nullptr));
        btnCheckout->setText(QCoreApplication::translate("ViewCartWidget", "CHECKOUT", nullptr));
        btnDecrease->setText(QCoreApplication::translate("ViewCartWidget", "Decrease Qty (-)", nullptr));
        btnRemove->setText(QCoreApplication::translate("ViewCartWidget", "Remove Item", nullptr));
        btnBack->setText(QCoreApplication::translate("ViewCartWidget", "Back", nullptr));
        (void)ViewCartWidget;
    } // retranslateUi

};

namespace Ui {
    class ViewCartWidget: public Ui_ViewCartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWCARTWIDGET_H
