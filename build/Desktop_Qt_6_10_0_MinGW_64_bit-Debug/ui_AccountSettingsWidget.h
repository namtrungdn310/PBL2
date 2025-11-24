/********************************************************************************
** Form generated from reading UI file 'AccountSettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSETTINGSWIDGET_H
#define UI_ACCOUNTSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountSettingsWidget
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
    QLabel *lblSubtitle;
    QSpacerItem *vSpacer1;
    QLabel *lblCurrentInfoTitle;
    QLabel *lblCurrentEmail;
    QLabel *lblCurrentPhone;
    QSpacerItem *verticalSpacer;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QLabel *lblEditInfo;
    QLabel *l1;
    QLineEdit *txtFullName;
    QLabel *l2;
    QLineEdit *txtAddress;
    QLabel *l3;
    QLineEdit *txtPassword;
    QSpacerItem *vSpacer2;
    QPushButton *btnConfirm;
    QPushButton *btnDelete;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *AccountSettingsWidget)
    {
        if (AccountSettingsWidget->objectName().isEmpty())
            AccountSettingsWidget->setObjectName("AccountSettingsWidget");
        AccountSettingsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(AccountSettingsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(AccountSettingsWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(800, 550));
        mainCard->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_Card = new QHBoxLayout(mainCard);
        horizontalLayout_Card->setSpacing(0);
        horizontalLayout_Card->setObjectName("horizontalLayout_Card");
        horizontalLayout_Card->setContentsMargins(0, 0, 0, 0);
        leftSide = new QWidget(mainCard);
        leftSide->setObjectName("leftSide");
        verticalLayout_Left = new QVBoxLayout(leftSide);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(30, 40, 20, 30);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        lblSubtitle = new QLabel(leftSide);
        lblSubtitle->setObjectName("lblSubtitle");

        verticalLayout_Left->addWidget(lblSubtitle);

        vSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_Left->addItem(vSpacer1);

        lblCurrentInfoTitle = new QLabel(leftSide);
        lblCurrentInfoTitle->setObjectName("lblCurrentInfoTitle");

        verticalLayout_Left->addWidget(lblCurrentInfoTitle);

        lblCurrentEmail = new QLabel(leftSide);
        lblCurrentEmail->setObjectName("lblCurrentEmail");

        verticalLayout_Left->addWidget(lblCurrentEmail);

        lblCurrentPhone = new QLabel(leftSide);
        lblCurrentPhone->setObjectName("lblCurrentPhone");

        verticalLayout_Left->addWidget(lblCurrentPhone);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Left->addItem(verticalSpacer);


        horizontalLayout_Card->addWidget(leftSide);

        lineSeparator = new QFrame(mainCard);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::Shape::VLine);
        lineSeparator->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_Card->addWidget(lineSeparator);

        rightSide = new QWidget(mainCard);
        rightSide->setObjectName("rightSide");
        verticalLayout_Right = new QVBoxLayout(rightSide);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(40, 40, 40, 40);
        lblEditInfo = new QLabel(rightSide);
        lblEditInfo->setObjectName("lblEditInfo");

        verticalLayout_Right->addWidget(lblEditInfo);

        l1 = new QLabel(rightSide);
        l1->setObjectName("l1");

        verticalLayout_Right->addWidget(l1);

        txtFullName = new QLineEdit(rightSide);
        txtFullName->setObjectName("txtFullName");

        verticalLayout_Right->addWidget(txtFullName);

        l2 = new QLabel(rightSide);
        l2->setObjectName("l2");

        verticalLayout_Right->addWidget(l2);

        txtAddress = new QLineEdit(rightSide);
        txtAddress->setObjectName("txtAddress");

        verticalLayout_Right->addWidget(txtAddress);

        l3 = new QLabel(rightSide);
        l3->setObjectName("l3");

        verticalLayout_Right->addWidget(l3);

        txtPassword = new QLineEdit(rightSide);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::Password);

        verticalLayout_Right->addWidget(txtPassword);

        vSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer2);

        btnConfirm = new QPushButton(rightSide);
        btnConfirm->setObjectName("btnConfirm");

        verticalLayout_Right->addWidget(btnConfirm);

        btnDelete = new QPushButton(rightSide);
        btnDelete->setObjectName("btnDelete");

        verticalLayout_Right->addWidget(btnDelete);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(AccountSettingsWidget);

        QMetaObject::connectSlotsByName(AccountSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *AccountSettingsWidget)
    {
        lblTitle->setText(QCoreApplication::translate("AccountSettingsWidget", "ACCOUNT SETTINGS", nullptr));
        lblSubtitle->setText(QCoreApplication::translate("AccountSettingsWidget", "Update your profile info", nullptr));
        lblCurrentInfoTitle->setText(QCoreApplication::translate("AccountSettingsWidget", "Current Account:", nullptr));
        lblCurrentEmail->setText(QCoreApplication::translate("AccountSettingsWidget", "email@example.com", nullptr));
        lblCurrentPhone->setText(QCoreApplication::translate("AccountSettingsWidget", "0909xxx", nullptr));
        lblEditInfo->setText(QCoreApplication::translate("AccountSettingsWidget", "Edit Information", nullptr));
        l1->setText(QCoreApplication::translate("AccountSettingsWidget", "Full Name:", nullptr));
        txtFullName->setPlaceholderText(QCoreApplication::translate("AccountSettingsWidget", "Leave empty to keep current", nullptr));
        l2->setText(QCoreApplication::translate("AccountSettingsWidget", "Address:", nullptr));
        txtAddress->setPlaceholderText(QCoreApplication::translate("AccountSettingsWidget", "Leave empty to keep current", nullptr));
        l3->setText(QCoreApplication::translate("AccountSettingsWidget", "New Password:", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("AccountSettingsWidget", "Leave empty to keep current", nullptr));
        btnConfirm->setText(QCoreApplication::translate("AccountSettingsWidget", "Confirm Changes", nullptr));
        btnDelete->setText(QCoreApplication::translate("AccountSettingsWidget", "Delete Account", nullptr));
        btnBack->setText(QCoreApplication::translate("AccountSettingsWidget", "Back", nullptr));
        (void)AccountSettingsWidget;
    } // retranslateUi

};

namespace Ui {
    class AccountSettingsWidget: public Ui_AccountSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSETTINGSWIDGET_H
