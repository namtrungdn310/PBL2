/********************************************************************************
** Form generated from reading UI file 'CustomerDashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERDASHBOARD_H
#define UI_CUSTOMERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerDashboard
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblWelcome;
    QLabel *lblPoints;
    QSpacerItem *horizontalSpacer_Header;
    QPushButton *btnLogout;
    QStackedWidget *dashboardStack;
    QWidget *pageMenu;
    QGridLayout *gridLayout_Center;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Cards;
    QSpacerItem *horizontalSpacer_LeftPush;
    QFrame *mainContainer;
    QHBoxLayout *horizontalLayout_Unified;
    QWidget *frameStack;
    QVBoxLayout *verticalLayout_Left;
    QSpacerItem *verticalSpacer_LeftTop;
    QLabel *lblLogo_1;
    QLabel *lblSlogan;
    QFrame *lineSeparator;
    QWidget *frameHome;
    QVBoxLayout *verticalLayout_Right;
    QSpacerItem *verticalSpacer_RightTop;
    QLabel *lblLogo_2;
    QPushButton *btnProducts;
    QPushButton *btnCart;
    QPushButton *btnOrders;
    QPushButton *btnPromos;
    QPushButton *btnReviews;
    QPushButton *btnSetting;
    QSpacerItem *verticalSpacer_RightBot;
    QSpacerItem *horizontalSpacer_RightPush;
    QSpacerItem *verticalSpacer_Top;
    QSpacerItem *verticalSpacer_Bot;
    QWidget *pageProducts;
    QWidget *pageCart;
    QWidget *pageOrders;
    QWidget *pagePromos;
    QWidget *pageReviews;

    void setupUi(QWidget *CustomerDashboard)
    {
        if (CustomerDashboard->objectName().isEmpty())
            CustomerDashboard->setObjectName("CustomerDashboard");
        CustomerDashboard->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(CustomerDashboard);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(CustomerDashboard);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, 10, 20, 10);
        lblWelcome = new QLabel(headerContainer);
        lblWelcome->setObjectName("lblWelcome");

        horizontalLayout_Header->addWidget(lblWelcome);

        lblPoints = new QLabel(headerContainer);
        lblPoints->setObjectName("lblPoints");

        horizontalLayout_Header->addWidget(lblPoints);

        horizontalSpacer_Header = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Header->addItem(horizontalSpacer_Header);

        btnLogout = new QPushButton(headerContainer);
        btnLogout->setObjectName("btnLogout");

        horizontalLayout_Header->addWidget(btnLogout);


        verticalLayout_Main->addWidget(headerContainer);

        dashboardStack = new QStackedWidget(CustomerDashboard);
        dashboardStack->setObjectName("dashboardStack");
        pageMenu = new QWidget();
        pageMenu->setObjectName("pageMenu");
        gridLayout_Center = new QGridLayout(pageMenu);
        gridLayout_Center->setSpacing(0);
        gridLayout_Center->setObjectName("gridLayout_Center");
        gridLayout_Center->setContentsMargins(0, 0, 0, 0);
        centerContainer = new QWidget(pageMenu);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Cards = new QHBoxLayout(centerContainer);
        horizontalLayout_Cards->setSpacing(0);
        horizontalLayout_Cards->setObjectName("horizontalLayout_Cards");
        horizontalLayout_Cards->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_LeftPush = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Cards->addItem(horizontalSpacer_LeftPush);

        mainContainer = new QFrame(centerContainer);
        mainContainer->setObjectName("mainContainer");
        mainContainer->setFrameShape(QFrame::Shape::StyledPanel);
        mainContainer->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_Unified = new QHBoxLayout(mainContainer);
        horizontalLayout_Unified->setSpacing(0);
        horizontalLayout_Unified->setObjectName("horizontalLayout_Unified");
        horizontalLayout_Unified->setContentsMargins(0, 0, 0, 0);
        frameStack = new QWidget(mainContainer);
        frameStack->setObjectName("frameStack");
        frameStack->setMinimumSize(QSize(120, 0));
        frameStack->setMaximumSize(QSize(120, 16777215));
        verticalLayout_Left = new QVBoxLayout(frameStack);
        verticalLayout_Left->setSpacing(0);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_LeftTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Left->addItem(verticalSpacer_LeftTop);

        lblLogo_1 = new QLabel(frameStack);
        lblLogo_1->setObjectName("lblLogo_1");
        lblLogo_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Left->addWidget(lblLogo_1);

        lblSlogan = new QLabel(frameStack);
        lblSlogan->setObjectName("lblSlogan");
        lblSlogan->setWordWrap(true);

        verticalLayout_Left->addWidget(lblSlogan);


        horizontalLayout_Unified->addWidget(frameStack);

        lineSeparator = new QFrame(mainContainer);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::Shape::VLine);
        lineSeparator->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_Unified->addWidget(lineSeparator);

        frameHome = new QWidget(mainContainer);
        frameHome->setObjectName("frameHome");
        verticalLayout_Right = new QVBoxLayout(frameHome);
        verticalLayout_Right->setSpacing(0);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_RightTop = new QSpacerItem(20, 23, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_Right->addItem(verticalSpacer_RightTop);

        lblLogo_2 = new QLabel(frameHome);
        lblLogo_2->setObjectName("lblLogo_2");
        lblLogo_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Right->addWidget(lblLogo_2);

        btnProducts = new QPushButton(frameHome);
        btnProducts->setObjectName("btnProducts");

        verticalLayout_Right->addWidget(btnProducts);

        btnCart = new QPushButton(frameHome);
        btnCart->setObjectName("btnCart");

        verticalLayout_Right->addWidget(btnCart);

        btnOrders = new QPushButton(frameHome);
        btnOrders->setObjectName("btnOrders");

        verticalLayout_Right->addWidget(btnOrders);

        btnPromos = new QPushButton(frameHome);
        btnPromos->setObjectName("btnPromos");

        verticalLayout_Right->addWidget(btnPromos);

        btnReviews = new QPushButton(frameHome);
        btnReviews->setObjectName("btnReviews");

        verticalLayout_Right->addWidget(btnReviews);

        btnSetting = new QPushButton(frameHome);
        btnSetting->setObjectName("btnSetting");

        verticalLayout_Right->addWidget(btnSetting);

        verticalSpacer_RightBot = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer_RightBot);


        horizontalLayout_Unified->addWidget(frameHome);


        horizontalLayout_Cards->addWidget(mainContainer);

        horizontalSpacer_RightPush = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Cards->addItem(horizontalSpacer_RightPush);


        gridLayout_Center->addWidget(centerContainer, 1, 1, 1, 1);

        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Center->addItem(verticalSpacer_Top, 0, 1, 1, 1);

        verticalSpacer_Bot = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Center->addItem(verticalSpacer_Bot, 2, 1, 1, 1);

        dashboardStack->addWidget(pageMenu);
        pageProducts = new QWidget();
        pageProducts->setObjectName("pageProducts");
        dashboardStack->addWidget(pageProducts);
        pageCart = new QWidget();
        pageCart->setObjectName("pageCart");
        dashboardStack->addWidget(pageCart);
        pageOrders = new QWidget();
        pageOrders->setObjectName("pageOrders");
        dashboardStack->addWidget(pageOrders);
        pagePromos = new QWidget();
        pagePromos->setObjectName("pagePromos");
        dashboardStack->addWidget(pagePromos);
        pageReviews = new QWidget();
        pageReviews->setObjectName("pageReviews");
        dashboardStack->addWidget(pageReviews);

        verticalLayout_Main->addWidget(dashboardStack);


        retranslateUi(CustomerDashboard);

        dashboardStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CustomerDashboard);
    } // setupUi

    void retranslateUi(QWidget *CustomerDashboard)
    {
        CustomerDashboard->setWindowTitle(QCoreApplication::translate("CustomerDashboard", "Customer Dashboard", nullptr));
        lblWelcome->setText(QCoreApplication::translate("CustomerDashboard", "Welcome, User", nullptr));
        lblPoints->setText(QCoreApplication::translate("CustomerDashboard", "Points: 0", nullptr));
        btnLogout->setText(QCoreApplication::translate("CustomerDashboard", "Log Out", nullptr));
        lblLogo_1->setText(QCoreApplication::translate("CustomerDashboard", "LOGO", nullptr));
        lblSlogan->setText(QCoreApplication::translate("CustomerDashboard", "Smart Management\n"
"for Modern Shops", nullptr));
        lblLogo_2->setText(QCoreApplication::translate("CustomerDashboard", "MENU", nullptr));
        btnProducts->setText(QCoreApplication::translate("CustomerDashboard", "View Products", nullptr));
        btnCart->setText(QCoreApplication::translate("CustomerDashboard", "My Cart", nullptr));
        btnOrders->setText(QCoreApplication::translate("CustomerDashboard", "Order History", nullptr));
        btnPromos->setText(QCoreApplication::translate("CustomerDashboard", "Promotions", nullptr));
        btnReviews->setText(QCoreApplication::translate("CustomerDashboard", "Reviews", nullptr));
        btnSetting->setText(QCoreApplication::translate("CustomerDashboard", "Account Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDashboard: public Ui_CustomerDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDASHBOARD_H
