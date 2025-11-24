/********************************************************************************
** Form generated from reading UI file 'EditCategoriesWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCATEGORIESWIDGET_H
#define UI_EDITCATEGORIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditCategoriesWidget
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
    QTableWidget *tblCategories;
    QLabel *lblHint;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QStackedWidget *stackActions;
    QWidget *pageForms;
    QVBoxLayout *vLayoutForms;
    QLabel *lblManageTitle;
    QSpacerItem *sp1;
    QGroupBox *grpAdd;
    QVBoxLayout *vboxAdd;
    QLineEdit *txtNewName;
    QPushButton *btnAdd;
    QSpacerItem *sp2;
    QGroupBox *grpEdit;
    QVBoxLayout *vboxEdit;
    QLabel *lblSelectedId;
    QLineEdit *txtEditName;
    QPushButton *btnRename;
    QPushButton *btnDelete;
    QSpacerItem *sp3;
    QWidget *pageWarning;
    QVBoxLayout *vLayoutWarn;
    QLabel *lblWarnTitle;
    QLabel *lblWarnMsg;
    QTableWidget *tblBlockingProducts;
    QPushButton *btnBackToForm;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *EditCategoriesWidget)
    {
        if (EditCategoriesWidget->objectName().isEmpty())
            EditCategoriesWidget->setObjectName("EditCategoriesWidget");
        EditCategoriesWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(EditCategoriesWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(EditCategoriesWidget);
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
        verticalLayout_Left->setContentsMargins(20, 20, 10, 20);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        tblCategories = new QTableWidget(leftSide);
        if (tblCategories->columnCount() < 3)
            tblCategories->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCategories->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCategories->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCategories->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblCategories->setObjectName("tblCategories");
        tblCategories->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Left->addWidget(tblCategories);

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
        stackActions = new QStackedWidget(rightSide);
        stackActions->setObjectName("stackActions");
        pageForms = new QWidget();
        pageForms->setObjectName("pageForms");
        vLayoutForms = new QVBoxLayout(pageForms);
        vLayoutForms->setObjectName("vLayoutForms");
        lblManageTitle = new QLabel(pageForms);
        lblManageTitle->setObjectName("lblManageTitle");
        lblManageTitle->setAlignment(Qt::AlignCenter);

        vLayoutForms->addWidget(lblManageTitle);

        sp1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutForms->addItem(sp1);

        grpAdd = new QGroupBox(pageForms);
        grpAdd->setObjectName("grpAdd");
        vboxAdd = new QVBoxLayout(grpAdd);
        vboxAdd->setObjectName("vboxAdd");
        txtNewName = new QLineEdit(grpAdd);
        txtNewName->setObjectName("txtNewName");

        vboxAdd->addWidget(txtNewName);

        btnAdd = new QPushButton(grpAdd);
        btnAdd->setObjectName("btnAdd");

        vboxAdd->addWidget(btnAdd);


        vLayoutForms->addWidget(grpAdd);

        sp2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutForms->addItem(sp2);

        grpEdit = new QGroupBox(pageForms);
        grpEdit->setObjectName("grpEdit");
        vboxEdit = new QVBoxLayout(grpEdit);
        vboxEdit->setObjectName("vboxEdit");
        lblSelectedId = new QLabel(grpEdit);
        lblSelectedId->setObjectName("lblSelectedId");

        vboxEdit->addWidget(lblSelectedId);

        txtEditName = new QLineEdit(grpEdit);
        txtEditName->setObjectName("txtEditName");

        vboxEdit->addWidget(txtEditName);

        btnRename = new QPushButton(grpEdit);
        btnRename->setObjectName("btnRename");

        vboxEdit->addWidget(btnRename);

        btnDelete = new QPushButton(grpEdit);
        btnDelete->setObjectName("btnDelete");

        vboxEdit->addWidget(btnDelete);


        vLayoutForms->addWidget(grpEdit);

        sp3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutForms->addItem(sp3);

        stackActions->addWidget(pageForms);
        pageWarning = new QWidget();
        pageWarning->setObjectName("pageWarning");
        vLayoutWarn = new QVBoxLayout(pageWarning);
        vLayoutWarn->setObjectName("vLayoutWarn");
        lblWarnTitle = new QLabel(pageWarning);
        lblWarnTitle->setObjectName("lblWarnTitle");
        lblWarnTitle->setAlignment(Qt::AlignCenter);

        vLayoutWarn->addWidget(lblWarnTitle);

        lblWarnMsg = new QLabel(pageWarning);
        lblWarnMsg->setObjectName("lblWarnMsg");
        lblWarnMsg->setWordWrap(true);
        lblWarnMsg->setAlignment(Qt::AlignCenter);

        vLayoutWarn->addWidget(lblWarnMsg);

        tblBlockingProducts = new QTableWidget(pageWarning);
        if (tblBlockingProducts->columnCount() < 3)
            tblBlockingProducts->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblBlockingProducts->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblBlockingProducts->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblBlockingProducts->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tblBlockingProducts->setObjectName("tblBlockingProducts");
        tblBlockingProducts->setEditTriggers(QAbstractItemView::NoEditTriggers);

        vLayoutWarn->addWidget(tblBlockingProducts);

        btnBackToForm = new QPushButton(pageWarning);
        btnBackToForm->setObjectName("btnBackToForm");

        vLayoutWarn->addWidget(btnBackToForm);

        stackActions->addWidget(pageWarning);

        verticalLayout_Right->addWidget(stackActions);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(EditCategoriesWidget);

        stackActions->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditCategoriesWidget);
    } // setupUi

    void retranslateUi(QWidget *EditCategoriesWidget)
    {
        lblTitle->setText(QCoreApplication::translate("EditCategoriesWidget", "CATEGORY LIST", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblCategories->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EditCategoriesWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCategories->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EditCategoriesWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCategories->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EditCategoriesWidget", "Products Count", nullptr));
        lblHint->setText(QCoreApplication::translate("EditCategoriesWidget", "* Select a category to Edit or Delete", nullptr));
        lblManageTitle->setText(QCoreApplication::translate("EditCategoriesWidget", "MANAGE CATEGORY", nullptr));
        grpAdd->setTitle(QCoreApplication::translate("EditCategoriesWidget", "Add New Category", nullptr));
        txtNewName->setPlaceholderText(QCoreApplication::translate("EditCategoriesWidget", "Enter new category name...", nullptr));
        btnAdd->setText(QCoreApplication::translate("EditCategoriesWidget", "Add Category", nullptr));
        grpEdit->setTitle(QCoreApplication::translate("EditCategoriesWidget", "Edit Selected", nullptr));
        lblSelectedId->setText(QCoreApplication::translate("EditCategoriesWidget", "Selected ID: -", nullptr));
        txtEditName->setPlaceholderText(QCoreApplication::translate("EditCategoriesWidget", "Select category to rename...", nullptr));
        btnRename->setText(QCoreApplication::translate("EditCategoriesWidget", "Save Rename", nullptr));
        btnDelete->setText(QCoreApplication::translate("EditCategoriesWidget", "Delete Category", nullptr));
        lblWarnTitle->setText(QCoreApplication::translate("EditCategoriesWidget", "CANNOT DELETE!", nullptr));
        lblWarnMsg->setText(QCoreApplication::translate("EditCategoriesWidget", "This category contains products. You must move or delete them first.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblBlockingProducts->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EditCategoriesWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblBlockingProducts->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EditCategoriesWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblBlockingProducts->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("EditCategoriesWidget", "Stock Info", nullptr));
        btnBackToForm->setText(QCoreApplication::translate("EditCategoriesWidget", "OK, I Understand", nullptr));
        btnBack->setText(QCoreApplication::translate("EditCategoriesWidget", "Back to Dashboard", nullptr));
        (void)EditCategoriesWidget;
    } // retranslateUi

};

namespace Ui {
    class EditCategoriesWidget: public Ui_EditCategoriesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCATEGORIESWIDGET_H
