/********************************************************************************
** Form generated from reading UI file 'StaffDashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFFDASHBOARD_H
#define UI_STAFFDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaffDashboard
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblWelcome;
    QSpacerItem *horizontalSpacer_Header;
    QPushButton *btnLogout;
    QStackedWidget *dashboardStack;
    QWidget *pageMenu;
    QGridLayout *gridLayout_Center;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Cards;
    QWidget *frameStack;
    QVBoxLayout *verticalLayout_Left;
    QSpacerItem *verticalSpacer_LeftTop;
    QLabel *lblLogo_1;
    QLabel *lblSlogan;
    QWidget *frameHome;
    QVBoxLayout *verticalLayout_Right;
    QSpacerItem *verticalSpacer_RightTop;
    QLabel *lblLogo_2;
    QPushButton *btnEditCategories;
    QPushButton *btnEditProducts;
    QPushButton *btnEditPromotions;
    QPushButton *btnEditReviews;
    QPushButton *btnCustomers;
    QPushButton *btnAnalysis;
    QPushButton *btnAccountSetting;
    QSpacerItem *verticalSpacer_RightBot;
    QSpacerItem *verticalSpacer_Top;
    QSpacerItem *verticalSpacer_Bot;
    QSpacerItem *horizontalSpacer_Left;
    QSpacerItem *horizontalSpacer_Right;

    void setupUi(QWidget *StaffDashboard)
    {
        if (StaffDashboard->objectName().isEmpty())
            StaffDashboard->setObjectName("StaffDashboard");
        StaffDashboard->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(StaffDashboard);
        verticalLayout_Main->setSpacing(0);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        verticalLayout_Main->setContentsMargins(0, 0, 0, 0);
        headerContainer = new QWidget(StaffDashboard);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 60));
        headerContainer->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        horizontalLayout_Header->setContentsMargins(20, 0, 20, 0);
        lblWelcome = new QLabel(headerContainer);
        lblWelcome->setObjectName("lblWelcome");

        horizontalLayout_Header->addWidget(lblWelcome, 0, Qt::AlignmentFlag::AlignVCenter);

        horizontalSpacer_Header = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Header->addItem(horizontalSpacer_Header);

        btnLogout = new QPushButton(headerContainer);
        btnLogout->setObjectName("btnLogout");

        horizontalLayout_Header->addWidget(btnLogout, 0, Qt::AlignmentFlag::AlignVCenter);


        verticalLayout_Main->addWidget(headerContainer);

        dashboardStack = new QStackedWidget(StaffDashboard);
        dashboardStack->setObjectName("dashboardStack");
        pageMenu = new QWidget();
        pageMenu->setObjectName("pageMenu");
        gridLayout_Center = new QGridLayout(pageMenu);
        gridLayout_Center->setObjectName("gridLayout_Center");
        centerContainer = new QWidget(pageMenu);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Cards = new QHBoxLayout(centerContainer);
        horizontalLayout_Cards->setSpacing(0);
        horizontalLayout_Cards->setObjectName("horizontalLayout_Cards");
        horizontalLayout_Cards->setContentsMargins(0, 0, 0, 0);
        frameStack = new QWidget(centerContainer);
        frameStack->setObjectName("frameStack");
        verticalLayout_Left = new QVBoxLayout(frameStack);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalSpacer_LeftTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Left->addItem(verticalSpacer_LeftTop);

        lblLogo_1 = new QLabel(frameStack);
        lblLogo_1->setObjectName("lblLogo_1");
        lblLogo_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Left->addWidget(lblLogo_1);

        lblSlogan = new QLabel(frameStack);
        lblSlogan->setObjectName("lblSlogan");
        lblSlogan->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Left->addWidget(lblSlogan);


        horizontalLayout_Cards->addWidget(frameStack);

        frameHome = new QWidget(centerContainer);
        frameHome->setObjectName("frameHome");
        verticalLayout_Right = new QVBoxLayout(frameHome);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(40, -1, 40, -1);
        verticalSpacer_RightTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer_RightTop);

        lblLogo_2 = new QLabel(frameHome);
        lblLogo_2->setObjectName("lblLogo_2");
        lblLogo_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Right->addWidget(lblLogo_2);

        btnEditCategories = new QPushButton(frameHome);
        btnEditCategories->setObjectName("btnEditCategories");

        verticalLayout_Right->addWidget(btnEditCategories);

        btnEditProducts = new QPushButton(frameHome);
        btnEditProducts->setObjectName("btnEditProducts");

        verticalLayout_Right->addWidget(btnEditProducts);

        btnEditPromotions = new QPushButton(frameHome);
        btnEditPromotions->setObjectName("btnEditPromotions");

        verticalLayout_Right->addWidget(btnEditPromotions);

        btnEditReviews = new QPushButton(frameHome);
        btnEditReviews->setObjectName("btnEditReviews");

        verticalLayout_Right->addWidget(btnEditReviews);

        btnCustomers = new QPushButton(frameHome);
        btnCustomers->setObjectName("btnCustomers");

        verticalLayout_Right->addWidget(btnCustomers);

        btnAnalysis = new QPushButton(frameHome);
        btnAnalysis->setObjectName("btnAnalysis");

        verticalLayout_Right->addWidget(btnAnalysis);

        btnAccountSetting = new QPushButton(frameHome);
        btnAccountSetting->setObjectName("btnAccountSetting");

        verticalLayout_Right->addWidget(btnAccountSetting);

        verticalSpacer_RightBot = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(verticalSpacer_RightBot);


        horizontalLayout_Cards->addWidget(frameHome);


        gridLayout_Center->addWidget(centerContainer, 1, 1, 1, 1);

        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Center->addItem(verticalSpacer_Top, 0, 1, 1, 1);

        verticalSpacer_Bot = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_Center->addItem(verticalSpacer_Bot, 2, 1, 1, 1);

        horizontalSpacer_Left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Center->addItem(horizontalSpacer_Left, 1, 0, 1, 1);

        horizontalSpacer_Right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_Center->addItem(horizontalSpacer_Right, 1, 2, 1, 1);

        dashboardStack->addWidget(pageMenu);

        verticalLayout_Main->addWidget(dashboardStack);


        retranslateUi(StaffDashboard);

        dashboardStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StaffDashboard);
    } // setupUi

    void retranslateUi(QWidget *StaffDashboard)
    {
        StaffDashboard->setWindowTitle(QCoreApplication::translate("StaffDashboard", "Staff Dashboard", nullptr));
        lblWelcome->setText(QCoreApplication::translate("StaffDashboard", "Welcome, Staff", nullptr));
        btnLogout->setText(QCoreApplication::translate("StaffDashboard", "Log Out", nullptr));
        lblLogo_1->setText(QCoreApplication::translate("StaffDashboard", "LOGO", nullptr));
        lblSlogan->setText(QCoreApplication::translate("StaffDashboard", "Admin Panel", nullptr));
        lblLogo_2->setText(QCoreApplication::translate("StaffDashboard", "ADMIN MENU", nullptr));
        btnEditCategories->setText(QCoreApplication::translate("StaffDashboard", "Edit Categories", nullptr));
        btnEditProducts->setText(QCoreApplication::translate("StaffDashboard", "Edit Products", nullptr));
        btnEditPromotions->setText(QCoreApplication::translate("StaffDashboard", "Edit Promotions", nullptr));
        btnEditReviews->setText(QCoreApplication::translate("StaffDashboard", "Edit Reviews", nullptr));
        btnCustomers->setText(QCoreApplication::translate("StaffDashboard", "Customers Management", nullptr));
        btnAnalysis->setText(QCoreApplication::translate("StaffDashboard", "Shop Analysis", nullptr));
        btnAccountSetting->setText(QCoreApplication::translate("StaffDashboard", "Account Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaffDashboard: public Ui_StaffDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFFDASHBOARD_H
