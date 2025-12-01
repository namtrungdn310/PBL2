/********************************************************************************
** Form generated from reading UI file 'EditPromotionsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROMOTIONSWIDGET_H
#define UI_EDITPROMOTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditPromotionsWidget
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
    QTableWidget *tblPromos;
    QLabel *lblHint;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QLabel *lblManageTitle;
    QGroupBox *grpAdd;
    QVBoxLayout *vlAdd;
    QLineEdit *txtAddName;
    QLineEdit *txtAddCondition;
    QHBoxLayout *hlAddNums;
    QDoubleSpinBox *spinAddRate;
    QLineEdit *txtAddMinAmount;
    QPushButton *btnAdd;
    QSpacerItem *vSpacer;
    QGroupBox *grpEdit;
    QVBoxLayout *vlEdit;
    QLabel *lblSelectedId;
    QLineEdit *txtEditName;
    QLineEdit *txtEditCondition;
    QHBoxLayout *hlEditNums;
    QDoubleSpinBox *spinEditRate;
    QLineEdit *txtEditMinAmount;
    QHBoxLayout *hlEditBtns;
    QPushButton *btnDelete;
    QPushButton *btnSave;
    QSpacerItem *vSpacer2;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *EditPromotionsWidget)
    {
        if (EditPromotionsWidget->objectName().isEmpty())
            EditPromotionsWidget->setObjectName("EditPromotionsWidget");
        EditPromotionsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(EditPromotionsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(EditPromotionsWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(950, 650));
        mainCard->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_Card = new QHBoxLayout(mainCard);
        horizontalLayout_Card->setSpacing(0);
        horizontalLayout_Card->setObjectName("horizontalLayout_Card");
        horizontalLayout_Card->setContentsMargins(0, 0, 0, 0);
        leftSide = new QWidget(mainCard);
        leftSide->setObjectName("leftSide");
        verticalLayout_Left = new QVBoxLayout(leftSide);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(20, 20, 10, 20);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        tblPromos = new QTableWidget(leftSide);
        if (tblPromos->columnCount() < 4)
            tblPromos->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPromos->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPromos->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblPromos->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblPromos->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblPromos->setObjectName("tblPromos");
        tblPromos->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Left->addWidget(tblPromos);

        lblHint = new QLabel(leftSide);
        lblHint->setObjectName("lblHint");

        verticalLayout_Left->addWidget(lblHint);


        horizontalLayout_Card->addWidget(leftSide);

        lineSeparator = new QFrame(mainCard);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::Shape::VLine);
        lineSeparator->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_Card->addWidget(lineSeparator);

        rightSide = new QWidget(mainCard);
        rightSide->setObjectName("rightSide");
        rightSide->setMinimumSize(QSize(350, 0));
        verticalLayout_Right = new QVBoxLayout(rightSide);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(20, 20, 20, 20);
        lblManageTitle = new QLabel(rightSide);
        lblManageTitle->setObjectName("lblManageTitle");
        lblManageTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_Right->addWidget(lblManageTitle);

        grpAdd = new QGroupBox(rightSide);
        grpAdd->setObjectName("grpAdd");
        vlAdd = new QVBoxLayout(grpAdd);
        vlAdd->setObjectName("vlAdd");
        txtAddName = new QLineEdit(grpAdd);
        txtAddName->setObjectName("txtAddName");

        vlAdd->addWidget(txtAddName);

        txtAddCondition = new QLineEdit(grpAdd);
        txtAddCondition->setObjectName("txtAddCondition");

        vlAdd->addWidget(txtAddCondition);

        hlAddNums = new QHBoxLayout();
        hlAddNums->setObjectName("hlAddNums");
        spinAddRate = new QDoubleSpinBox(grpAdd);
        spinAddRate->setObjectName("spinAddRate");
        spinAddRate->setMaximum(100);

        hlAddNums->addWidget(spinAddRate);

        txtAddMinAmount = new QLineEdit(grpAdd);
        txtAddMinAmount->setObjectName("txtAddMinAmount");

        hlAddNums->addWidget(txtAddMinAmount);


        vlAdd->addLayout(hlAddNums);

        btnAdd = new QPushButton(grpAdd);
        btnAdd->setObjectName("btnAdd");

        vlAdd->addWidget(btnAdd);


        verticalLayout_Right->addWidget(grpAdd);

        vSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer);

        grpEdit = new QGroupBox(rightSide);
        grpEdit->setObjectName("grpEdit");
        grpEdit->setEnabled(false);
        vlEdit = new QVBoxLayout(grpEdit);
        vlEdit->setObjectName("vlEdit");
        lblSelectedId = new QLabel(grpEdit);
        lblSelectedId->setObjectName("lblSelectedId");

        vlEdit->addWidget(lblSelectedId);

        txtEditName = new QLineEdit(grpEdit);
        txtEditName->setObjectName("txtEditName");

        vlEdit->addWidget(txtEditName);

        txtEditCondition = new QLineEdit(grpEdit);
        txtEditCondition->setObjectName("txtEditCondition");

        vlEdit->addWidget(txtEditCondition);

        hlEditNums = new QHBoxLayout();
        hlEditNums->setObjectName("hlEditNums");
        spinEditRate = new QDoubleSpinBox(grpEdit);
        spinEditRate->setObjectName("spinEditRate");
        spinEditRate->setMaximum(100);

        hlEditNums->addWidget(spinEditRate);

        txtEditMinAmount = new QLineEdit(grpEdit);
        txtEditMinAmount->setObjectName("txtEditMinAmount");

        hlEditNums->addWidget(txtEditMinAmount);


        vlEdit->addLayout(hlEditNums);

        hlEditBtns = new QHBoxLayout();
        hlEditBtns->setObjectName("hlEditBtns");
        btnDelete = new QPushButton(grpEdit);
        btnDelete->setObjectName("btnDelete");

        hlEditBtns->addWidget(btnDelete);

        btnSave = new QPushButton(grpEdit);
        btnSave->setObjectName("btnSave");

        hlEditBtns->addWidget(btnSave);


        vlEdit->addLayout(hlEditBtns);


        verticalLayout_Right->addWidget(grpEdit);

        vSpacer2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Right->addItem(vSpacer2);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(EditPromotionsWidget);

        QMetaObject::connectSlotsByName(EditPromotionsWidget);
    } // setupUi

    void retranslateUi(QWidget *EditPromotionsWidget)
    {
        lblTitle->setText(QCoreApplication::translate("EditPromotionsWidget", "PROMOTION LIST", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblPromos->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EditPromotionsWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblPromos->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EditPromotionsWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblPromos->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EditPromotionsWidget", "Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblPromos->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EditPromotionsWidget", "Min Order", nullptr));
        lblHint->setText(QCoreApplication::translate("EditPromotionsWidget", "* Select item to Edit or Delete", nullptr));
        lblManageTitle->setText(QCoreApplication::translate("EditPromotionsWidget", "MANAGE PROMOTIONS", nullptr));
        grpAdd->setTitle(QCoreApplication::translate("EditPromotionsWidget", "Add New Promotion", nullptr));
        txtAddName->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Promo Name (e.g. Summer Sale)", nullptr));
        txtAddCondition->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Condition (e.g. Order > 500k)", nullptr));
        spinAddRate->setSuffix(QCoreApplication::translate("EditPromotionsWidget", " %", nullptr));
        txtAddMinAmount->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Min Order (VND)", nullptr));
        btnAdd->setText(QCoreApplication::translate("EditPromotionsWidget", "Add Promotion", nullptr));
        grpEdit->setTitle(QCoreApplication::translate("EditPromotionsWidget", "Edit Selected", nullptr));
        lblSelectedId->setText(QCoreApplication::translate("EditPromotionsWidget", "Selected ID: -", nullptr));
        txtEditName->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Promo Name", nullptr));
        txtEditCondition->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Condition", nullptr));
        spinEditRate->setSuffix(QCoreApplication::translate("EditPromotionsWidget", " %", nullptr));
        txtEditMinAmount->setPlaceholderText(QCoreApplication::translate("EditPromotionsWidget", "Min Order (VND)", nullptr));
        btnDelete->setText(QCoreApplication::translate("EditPromotionsWidget", "Delete", nullptr));
        btnSave->setText(QCoreApplication::translate("EditPromotionsWidget", "Confirm Save", nullptr));
        btnBack->setText(QCoreApplication::translate("EditPromotionsWidget", "Back to Dashboard", nullptr));
        (void)EditPromotionsWidget;
    } // retranslateUi

};

namespace Ui {
    class EditPromotionsWidget: public Ui_EditPromotionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROMOTIONSWIDGET_H
