/********************************************************************************
** Form generated from reading UI file 'StartupWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPWIDGET_H
#define UI_STARTUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartupWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QWidget *mainContainer;
    QHBoxLayout *horizontalLayout;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblLogo;
    QLabel *lblSlogan;
    QFrame *frameCard;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_6;
    QLabel *lblTitle;
    QLabel *lblSubtitle;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnCustomer;
    QPushButton *btnStaff;
    QPushButton *btnRegister;
    QPushButton *btnExit;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *StartupWidget)
    {
        if (StartupWidget->objectName().isEmpty())
            StartupWidget->setObjectName("StartupWidget");
        StartupWidget->resize(615, 531);
        gridLayout = new QGridLayout(StartupWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(209, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 126, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        mainContainer = new QWidget(StartupWidget);
        mainContainer->setObjectName("mainContainer");
        horizontalLayout = new QHBoxLayout(mainContainer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPanel = new QWidget(mainContainer);
        leftPanel->setObjectName("leftPanel");
        verticalLayout_2 = new QVBoxLayout(leftPanel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        lblLogo = new QLabel(leftPanel);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMaximumSize(QSize(1677215, 16777215));

        verticalLayout_2->addWidget(lblLogo);

        lblSlogan = new QLabel(leftPanel);
        lblSlogan->setObjectName("lblSlogan");
        lblSlogan->setWordWrap(true);

        verticalLayout_2->addWidget(lblSlogan);


        horizontalLayout->addWidget(leftPanel);

        frameCard = new QFrame(mainContainer);
        frameCard->setObjectName("frameCard");
        frameCard->setFrameShape(QFrame::Shape::StyledPanel);
        frameCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frameCard);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        lblTitle = new QLabel(frameCard);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(lblTitle);

        lblSubtitle = new QLabel(frameCard);
        lblSubtitle->setObjectName("lblSubtitle");
        lblSubtitle->setMaximumSize(QSize(16777215, 1677215));

        verticalLayout->addWidget(lblSubtitle);

        verticalSpacer_3 = new QSpacerItem(20, 70, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        btnCustomer = new QPushButton(frameCard);
        btnCustomer->setObjectName("btnCustomer");

        verticalLayout->addWidget(btnCustomer);

        btnStaff = new QPushButton(frameCard);
        btnStaff->setObjectName("btnStaff");

        verticalLayout->addWidget(btnStaff);

        btnRegister = new QPushButton(frameCard);
        btnRegister->setObjectName("btnRegister");

        verticalLayout->addWidget(btnRegister);

        btnExit = new QPushButton(frameCard);
        btnExit->setObjectName("btnExit");

        verticalLayout->addWidget(btnExit);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addWidget(frameCard);


        gridLayout->addWidget(mainContainer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 126, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(208, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(StartupWidget);

        QMetaObject::connectSlotsByName(StartupWidget);
    } // setupUi

    void retranslateUi(QWidget *StartupWidget)
    {
        StartupWidget->setWindowTitle(QCoreApplication::translate("StartupWidget", "Form", nullptr));
        lblLogo->setText(QCoreApplication::translate("StartupWidget", "TextLabel", nullptr));
        lblSlogan->setText(QCoreApplication::translate("StartupWidget", "Smart Management\n"
"for Modern Shops", nullptr));
        lblTitle->setText(QCoreApplication::translate("StartupWidget", "CLOTHING SHOP", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("StartupWidget", "MANAGEMENT SHOP", nullptr));
        btnCustomer->setText(QCoreApplication::translate("StartupWidget", "Log in as Customer", nullptr));
        btnStaff->setText(QCoreApplication::translate("StartupWidget", "Log in as Staff", nullptr));
        btnRegister->setText(QCoreApplication::translate("StartupWidget", "Register Account", nullptr));
        btnExit->setText(QCoreApplication::translate("StartupWidget", "Exit Program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartupWidget: public Ui_StartupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPWIDGET_H
