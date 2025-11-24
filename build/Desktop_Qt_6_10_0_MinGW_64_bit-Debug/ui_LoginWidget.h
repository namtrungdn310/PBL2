/********************************************************************************
** Form generated from reading UI file 'LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *mainContainer;
    QHBoxLayout *horizontalLayout;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *lblLogo;
    QLabel *lblSlogan;
    QFrame *frameCard;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblTitle;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *txtEmail;
    QWidget *containerPass;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *txtPassword;
    QToolButton *btnTogglePass;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnConfirm;
    QPushButton *btnBack;
    QLabel *lblError;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(562, 488);
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 126, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(184, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(184, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 126, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        mainContainer = new QWidget(LoginWidget);
        mainContainer->setObjectName("mainContainer");
        horizontalLayout = new QHBoxLayout(mainContainer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPanel = new QWidget(mainContainer);
        leftPanel->setObjectName("leftPanel");
        verticalLayout = new QVBoxLayout(leftPanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        lblLogo = new QLabel(leftPanel);
        lblLogo->setObjectName("lblLogo");

        verticalLayout->addWidget(lblLogo);

        lblSlogan = new QLabel(leftPanel);
        lblSlogan->setObjectName("lblSlogan");
        lblSlogan->setWordWrap(true);

        verticalLayout->addWidget(lblSlogan);


        horizontalLayout->addWidget(leftPanel);

        frameCard = new QFrame(mainContainer);
        frameCard->setObjectName("frameCard");
        frameCard->setFrameShape(QFrame::Shape::StyledPanel);
        frameCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frameCard);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        lblTitle = new QLabel(frameCard);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_2->addWidget(lblTitle);

        verticalSpacer_5 = new QSpacerItem(20, 70, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        txtEmail = new QLineEdit(frameCard);
        txtEmail->setObjectName("txtEmail");

        verticalLayout_2->addWidget(txtEmail);

        containerPass = new QWidget(frameCard);
        containerPass->setObjectName("containerPass");
        containerPass->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(containerPass);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        txtPassword = new QLineEdit(containerPass);
        txtPassword->setObjectName("txtPassword");

        horizontalLayout_2->addWidget(txtPassword);

        btnTogglePass = new QToolButton(containerPass);
        btnTogglePass->setObjectName("btnTogglePass");
        btnTogglePass->setCheckable(true);

        horizontalLayout_2->addWidget(btnTogglePass);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(containerPass);

        btnConfirm = new QPushButton(frameCard);
        btnConfirm->setObjectName("btnConfirm");

        verticalLayout_2->addWidget(btnConfirm);

        btnBack = new QPushButton(frameCard);
        btnBack->setObjectName("btnBack");

        verticalLayout_2->addWidget(btnBack);

        lblError = new QLabel(frameCard);
        lblError->setObjectName("lblError");

        verticalLayout_2->addWidget(lblError);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        horizontalLayout->addWidget(frameCard);


        gridLayout->addWidget(mainContainer, 1, 1, 1, 1);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        lblLogo->setText(QCoreApplication::translate("LoginWidget", "TextLabel", nullptr));
        lblSlogan->setText(QCoreApplication::translate("LoginWidget", "Smart Management\n"
"for Modern Shops", nullptr));
        lblTitle->setText(QCoreApplication::translate("LoginWidget", "SIGN IN", nullptr));
        txtEmail->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter your Email", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("LoginWidget", "Enter your Password", nullptr));
        btnTogglePass->setText(QCoreApplication::translate("LoginWidget", "...", nullptr));
        btnConfirm->setText(QCoreApplication::translate("LoginWidget", "Confirm", nullptr));
        btnBack->setText(QCoreApplication::translate("LoginWidget", "Back", nullptr));
        lblError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
