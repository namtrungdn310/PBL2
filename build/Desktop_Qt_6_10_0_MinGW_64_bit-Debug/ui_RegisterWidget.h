/********************************************************************************
** Form generated from reading UI file 'RegisterWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *mainContainer;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftPanel_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_7;
    QLabel *lblLogo_2;
    QLabel *label;
    QFrame *frameCard_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QLabel *lblTitle_2;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *txtFullName;
    QLineEdit *txtEmail_2;
    QLineEdit *txtPassword_2;
    QLineEdit *txtAdress;
    QLineEdit *txtPhoneNumber;
    QPushButton *btnConfirm_2;
    QPushButton *btnBack;
    QLabel *lblError_2;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName("RegisterWidget");
        RegisterWidget->resize(556, 415);
        gridLayout = new QGridLayout(RegisterWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 102, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(198, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        mainContainer = new QWidget(RegisterWidget);
        mainContainer->setObjectName("mainContainer");
        horizontalLayout_3 = new QHBoxLayout(mainContainer);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        leftPanel_2 = new QWidget(mainContainer);
        leftPanel_2->setObjectName("leftPanel_2");
        verticalLayout_4 = new QVBoxLayout(leftPanel_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 190, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);

        lblLogo_2 = new QLabel(leftPanel_2);
        lblLogo_2->setObjectName("lblLogo_2");

        verticalLayout_4->addWidget(lblLogo_2);

        label = new QLabel(leftPanel_2);
        label->setObjectName("label");
        label->setWordWrap(true);

        verticalLayout_4->addWidget(label);


        horizontalLayout_3->addWidget(leftPanel_2);

        frameCard_2 = new QFrame(mainContainer);
        frameCard_2->setObjectName("frameCard_2");
        frameCard_2->setFrameShape(QFrame::Shape::StyledPanel);
        frameCard_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frameCard_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_8 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_8);

        lblTitle_2 = new QLabel(frameCard_2);
        lblTitle_2->setObjectName("lblTitle_2");

        verticalLayout_3->addWidget(lblTitle_2);

        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_9);

        txtFullName = new QLineEdit(frameCard_2);
        txtFullName->setObjectName("txtFullName");

        verticalLayout_3->addWidget(txtFullName);

        txtEmail_2 = new QLineEdit(frameCard_2);
        txtEmail_2->setObjectName("txtEmail_2");

        verticalLayout_3->addWidget(txtEmail_2);

        txtPassword_2 = new QLineEdit(frameCard_2);
        txtPassword_2->setObjectName("txtPassword_2");

        verticalLayout_3->addWidget(txtPassword_2);

        txtAdress = new QLineEdit(frameCard_2);
        txtAdress->setObjectName("txtAdress");

        verticalLayout_3->addWidget(txtAdress);

        txtPhoneNumber = new QLineEdit(frameCard_2);
        txtPhoneNumber->setObjectName("txtPhoneNumber");

        verticalLayout_3->addWidget(txtPhoneNumber);

        btnConfirm_2 = new QPushButton(frameCard_2);
        btnConfirm_2->setObjectName("btnConfirm_2");

        verticalLayout_3->addWidget(btnConfirm_2);

        btnBack = new QPushButton(frameCard_2);
        btnBack->setObjectName("btnBack");

        verticalLayout_3->addWidget(btnBack);

        lblError_2 = new QLabel(frameCard_2);
        lblError_2->setObjectName("lblError_2");

        verticalLayout_3->addWidget(lblError_2);

        verticalSpacer_10 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_10);


        horizontalLayout_3->addWidget(frameCard_2);


        gridLayout->addWidget(mainContainer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(174, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 78, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QCoreApplication::translate("RegisterWidget", "Form", nullptr));
        lblLogo_2->setText(QCoreApplication::translate("RegisterWidget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("RegisterWidget", "Smart Management\n"
"for Modern Shops", nullptr));
        lblTitle_2->setText(QCoreApplication::translate("RegisterWidget", "SIGN UP", nullptr));
        txtFullName->setPlaceholderText(QCoreApplication::translate("RegisterWidget", "Enter your Full Name", nullptr));
        txtEmail_2->setPlaceholderText(QCoreApplication::translate("RegisterWidget", "Enter your Email", nullptr));
        txtPassword_2->setPlaceholderText(QCoreApplication::translate("RegisterWidget", "Enter your Password", nullptr));
        txtAdress->setPlaceholderText(QCoreApplication::translate("RegisterWidget", "Enter your Adress", nullptr));
        txtPhoneNumber->setPlaceholderText(QCoreApplication::translate("RegisterWidget", "Enter your Phone Number", nullptr));
        btnConfirm_2->setText(QCoreApplication::translate("RegisterWidget", "Confirm", nullptr));
        btnBack->setText(QCoreApplication::translate("RegisterWidget", "Back", nullptr));
        lblError_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
