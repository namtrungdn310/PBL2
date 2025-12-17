/********************************************************************************
** Form generated from reading UI file 'AccountSettingWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSETTINGWIDGET_H
#define UI_ACCOUNTSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountSettingWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *mainCard;
    QVBoxLayout *vlCard;
    QPushButton *btnBack;
    QTabWidget *tabWidget;
    QWidget *tabProfile;
    QHBoxLayout *hlProfile;
    QWidget *leftPanel;
    QVBoxLayout *vlLeft;
    QSpacerItem *verticalSpacer_Top;
    QHBoxLayout *hlAvatar;
    QSpacerItem *spAvatarL;
    QLabel *lblAvatar;
    QSpacerItem *spAvatarR;
    QHBoxLayout *hlName;
    QSpacerItem *spNameL;
    QLabel *lblName;
    QSpacerItem *spNameR;
    QHBoxLayout *hlRole;
    QSpacerItem *spRoleL;
    QLabel *lblRole;
    QSpacerItem *spRoleR;
    QSpacerItem *verticalSpacer_Bottom;
    QGroupBox *grpPass;
    QVBoxLayout *vlPass;
    QSpacerItem *spPass1;
    QLineEdit *txtCurrentPass;
    QSpacerItem *spPass2;
    QLineEdit *txtNewPass;
    QSpacerItem *spPass3;
    QLineEdit *txtConfirmPass;
    QSpacerItem *spPass4;
    QPushButton *btnUpdatePass;
    QSpacerItem *spPass5;
    QWidget *tabManage;
    QHBoxLayout *hlManage;
    QGroupBox *grpList;
    QVBoxLayout *vlList;
    QListWidget *lstStaff;
    QPushButton *btnAddNew;
    QGroupBox *grpDetails;
    QVBoxLayout *vlDetails;
    QLabel *lblEditId;
    QLabel *l1;
    QLineEdit *txtEditName;
    QLabel *l2;
    QLineEdit *txtEditEmail;
    QLabel *l3;
    QLineEdit *txtEditPass;
    QLabel *l4;
    QComboBox *cboEditRole;
    QHBoxLayout *hlActions;
    QPushButton *btnDeleteStaff;
    QPushButton *btnSaveStaff;
    QSpacerItem *spDetails;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *AccountSettingWidget)
    {
        if (AccountSettingWidget->objectName().isEmpty())
            AccountSettingWidget->setObjectName("AccountSettingWidget");
        AccountSettingWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(AccountSettingWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(AccountSettingWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(950, 650));
        vlCard = new QVBoxLayout(mainCard);
        vlCard->setObjectName("vlCard");
        btnBack = new QPushButton(mainCard);
        btnBack->setObjectName("btnBack");
        btnBack->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBack->setFlat(true);

        vlCard->addWidget(btnBack);

        tabWidget = new QTabWidget(mainCard);
        tabWidget->setObjectName("tabWidget");
        tabProfile = new QWidget();
        tabProfile->setObjectName("tabProfile");
        hlProfile = new QHBoxLayout(tabProfile);
        hlProfile->setObjectName("hlProfile");
        leftPanel = new QWidget(tabProfile);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setMinimumSize(QSize(350, 0));
        vlLeft = new QVBoxLayout(leftPanel);
        vlLeft->setObjectName("vlLeft");
        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlLeft->addItem(verticalSpacer_Top);

        hlAvatar = new QHBoxLayout();
        hlAvatar->setObjectName("hlAvatar");
        spAvatarL = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlAvatar->addItem(spAvatarL);

        lblAvatar = new QLabel(leftPanel);
        lblAvatar->setObjectName("lblAvatar");
        lblAvatar->setMinimumSize(QSize(180, 180));
        lblAvatar->setMaximumSize(QSize(180, 180));
        lblAvatar->setAlignment(Qt::AlignCenter);

        hlAvatar->addWidget(lblAvatar);

        spAvatarR = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlAvatar->addItem(spAvatarR);


        vlLeft->addLayout(hlAvatar);

        hlName = new QHBoxLayout();
        hlName->setObjectName("hlName");
        spNameL = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlName->addItem(spNameL);

        lblName = new QLabel(leftPanel);
        lblName->setObjectName("lblName");
        lblName->setAlignment(Qt::AlignCenter);

        hlName->addWidget(lblName);

        spNameR = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlName->addItem(spNameR);


        vlLeft->addLayout(hlName);

        hlRole = new QHBoxLayout();
        hlRole->setObjectName("hlRole");
        spRoleL = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlRole->addItem(spRoleL);

        lblRole = new QLabel(leftPanel);
        lblRole->setObjectName("lblRole");
        lblRole->setAlignment(Qt::AlignCenter);

        hlRole->addWidget(lblRole);

        spRoleR = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hlRole->addItem(spRoleR);


        vlLeft->addLayout(hlRole);

        verticalSpacer_Bottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlLeft->addItem(verticalSpacer_Bottom);


        hlProfile->addWidget(leftPanel);

        grpPass = new QGroupBox(tabProfile);
        grpPass->setObjectName("grpPass");
        vlPass = new QVBoxLayout(grpPass);
        vlPass->setObjectName("vlPass");
        spPass1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlPass->addItem(spPass1);

        txtCurrentPass = new QLineEdit(grpPass);
        txtCurrentPass->setObjectName("txtCurrentPass");
        txtCurrentPass->setEchoMode(QLineEdit::Password);

        vlPass->addWidget(txtCurrentPass);

        spPass2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlPass->addItem(spPass2);

        txtNewPass = new QLineEdit(grpPass);
        txtNewPass->setObjectName("txtNewPass");
        txtNewPass->setEchoMode(QLineEdit::Password);

        vlPass->addWidget(txtNewPass);

        spPass3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlPass->addItem(spPass3);

        txtConfirmPass = new QLineEdit(grpPass);
        txtConfirmPass->setObjectName("txtConfirmPass");
        txtConfirmPass->setEchoMode(QLineEdit::Password);

        vlPass->addWidget(txtConfirmPass);

        spPass4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlPass->addItem(spPass4);

        btnUpdatePass = new QPushButton(grpPass);
        btnUpdatePass->setObjectName("btnUpdatePass");

        vlPass->addWidget(btnUpdatePass);

        spPass5 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlPass->addItem(spPass5);


        hlProfile->addWidget(grpPass);

        tabWidget->addTab(tabProfile, QString());
        tabManage = new QWidget();
        tabManage->setObjectName("tabManage");
        hlManage = new QHBoxLayout(tabManage);
        hlManage->setObjectName("hlManage");
        grpList = new QGroupBox(tabManage);
        grpList->setObjectName("grpList");
        grpList->setMaximumSize(QSize(350, 16777215));
        vlList = new QVBoxLayout(grpList);
        vlList->setObjectName("vlList");
        lstStaff = new QListWidget(grpList);
        lstStaff->setObjectName("lstStaff");

        vlList->addWidget(lstStaff);

        btnAddNew = new QPushButton(grpList);
        btnAddNew->setObjectName("btnAddNew");

        vlList->addWidget(btnAddNew);


        hlManage->addWidget(grpList);

        grpDetails = new QGroupBox(tabManage);
        grpDetails->setObjectName("grpDetails");
        vlDetails = new QVBoxLayout(grpDetails);
        vlDetails->setObjectName("vlDetails");
        lblEditId = new QLabel(grpDetails);
        lblEditId->setObjectName("lblEditId");

        vlDetails->addWidget(lblEditId);

        l1 = new QLabel(grpDetails);
        l1->setObjectName("l1");

        vlDetails->addWidget(l1);

        txtEditName = new QLineEdit(grpDetails);
        txtEditName->setObjectName("txtEditName");

        vlDetails->addWidget(txtEditName);

        l2 = new QLabel(grpDetails);
        l2->setObjectName("l2");

        vlDetails->addWidget(l2);

        txtEditEmail = new QLineEdit(grpDetails);
        txtEditEmail->setObjectName("txtEditEmail");

        vlDetails->addWidget(txtEditEmail);

        l3 = new QLabel(grpDetails);
        l3->setObjectName("l3");

        vlDetails->addWidget(l3);

        txtEditPass = new QLineEdit(grpDetails);
        txtEditPass->setObjectName("txtEditPass");

        vlDetails->addWidget(txtEditPass);

        l4 = new QLabel(grpDetails);
        l4->setObjectName("l4");

        vlDetails->addWidget(l4);

        cboEditRole = new QComboBox(grpDetails);
        cboEditRole->addItem(QString());
        cboEditRole->addItem(QString());
        cboEditRole->addItem(QString());
        cboEditRole->setObjectName("cboEditRole");

        vlDetails->addWidget(cboEditRole);

        hlActions = new QHBoxLayout();
        hlActions->setObjectName("hlActions");
        btnDeleteStaff = new QPushButton(grpDetails);
        btnDeleteStaff->setObjectName("btnDeleteStaff");

        hlActions->addWidget(btnDeleteStaff);

        btnSaveStaff = new QPushButton(grpDetails);
        btnSaveStaff->setObjectName("btnSaveStaff");

        hlActions->addWidget(btnSaveStaff);


        vlDetails->addLayout(hlActions);

        spDetails = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlDetails->addItem(spDetails);


        hlManage->addWidget(grpDetails);

        tabWidget->addTab(tabManage, QString());

        vlCard->addWidget(tabWidget);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(AccountSettingWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AccountSettingWidget);
    } // setupUi

    void retranslateUi(QWidget *AccountSettingWidget)
    {
        mainCard->setStyleSheet(QCoreApplication::translate("AccountSettingWidget", "QFrame#mainCard { background: #FFF; border-radius: 15px; }", nullptr));
        btnBack->setText(QCoreApplication::translate("AccountSettingWidget", "\342\206\220 Back to Dashboard", nullptr));
        lblAvatar->setText(QCoreApplication::translate("AccountSettingWidget", "A", nullptr));
        lblName->setText(QCoreApplication::translate("AccountSettingWidget", "Name", nullptr));
        lblRole->setText(QCoreApplication::translate("AccountSettingWidget", "Position", nullptr));
        grpPass->setTitle(QCoreApplication::translate("AccountSettingWidget", "Change My Password", nullptr));
        txtCurrentPass->setPlaceholderText(QCoreApplication::translate("AccountSettingWidget", "Current Password", nullptr));
        txtNewPass->setPlaceholderText(QCoreApplication::translate("AccountSettingWidget", "New Password", nullptr));
        txtConfirmPass->setPlaceholderText(QCoreApplication::translate("AccountSettingWidget", "Confirm New Password", nullptr));
        btnUpdatePass->setText(QCoreApplication::translate("AccountSettingWidget", "Update Password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProfile), QCoreApplication::translate("AccountSettingWidget", "My Profile", nullptr));
        grpList->setTitle(QCoreApplication::translate("AccountSettingWidget", "Staff List", nullptr));
        btnAddNew->setText(QCoreApplication::translate("AccountSettingWidget", "+ Add New Staff (Clear Form)", nullptr));
        grpDetails->setTitle(QCoreApplication::translate("AccountSettingWidget", "Account Details", nullptr));
        lblEditId->setText(QCoreApplication::translate("AccountSettingWidget", "ID: [New]", nullptr));
        l1->setText(QCoreApplication::translate("AccountSettingWidget", "Full Name", nullptr));
        l2->setText(QCoreApplication::translate("AccountSettingWidget", "Email", nullptr));
        l3->setText(QCoreApplication::translate("AccountSettingWidget", "Password", nullptr));
        txtEditPass->setPlaceholderText(QCoreApplication::translate("AccountSettingWidget", "Leave empty to keep current password", nullptr));
        l4->setText(QCoreApplication::translate("AccountSettingWidget", "Position / Role", nullptr));
        cboEditRole->setItemText(0, QCoreApplication::translate("AccountSettingWidget", "Manager", nullptr));
        cboEditRole->setItemText(1, QCoreApplication::translate("AccountSettingWidget", "Inventory Staff", nullptr));
        cboEditRole->setItemText(2, QCoreApplication::translate("AccountSettingWidget", "Sales Staff", nullptr));

        btnDeleteStaff->setText(QCoreApplication::translate("AccountSettingWidget", "Delete Account", nullptr));
        btnSaveStaff->setText(QCoreApplication::translate("AccountSettingWidget", "Save / Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabManage), QCoreApplication::translate("AccountSettingWidget", "Staff Management", nullptr));
        (void)AccountSettingWidget;
    } // retranslateUi

};

namespace Ui {
    class AccountSettingWidget: public Ui_AccountSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSETTINGWIDGET_H
