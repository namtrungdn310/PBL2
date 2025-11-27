/********************************************************************************
** Form generated from reading UI file 'EditProductsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPRODUCTSWIDGET_H
#define UI_EDITPRODUCTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditProductsWidget
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
    QLineEdit *txtSearch;
    QHBoxLayout *hlFilter;
    QComboBox *cboCategoryFilter;
    QPushButton *btnFilter;
    QTableWidget *tblProducts;
    QLabel *lblHint;
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QStackedWidget *stackEdit;
    QWidget *pageEmpty;
    QVBoxLayout *vlEmpty;
    QLabel *lblEmpty;
    QWidget *pageForm;
    QVBoxLayout *vlForm;
    QLabel *lblEditTitle;
    QFormLayout *formLayout;
    QLabel *l1;
    QLineEdit *txtName;
    QLabel *l2;
    QLineEdit *txtPrice;
    QLabel *l3;
    QLineEdit *txtBrand;
    QLabel *l4;
    QComboBox *cboCategoryEdit;
    QLabel *l5;
    QTextEdit *txtDesc;
    QGroupBox *grpSizes;
    QVBoxLayout *vlSize;
    QHBoxLayout *hlSizeInput;
    QComboBox *cboSizeSelect;
    QSpinBox *spinStock;
    QPushButton *btnAddSize;
    QTableWidget *tblSizes;
    QPushButton *btnRemoveSize;
    QHBoxLayout *hlButtons;
    QPushButton *btnDeleteProduct;
    QPushButton *btnConfirm;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *EditProductsWidget)
    {
        if (EditProductsWidget->objectName().isEmpty())
            EditProductsWidget->setObjectName("EditProductsWidget");
        EditProductsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(EditProductsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(EditProductsWidget);
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
        leftSide->setMinimumSize(QSize(350, 0));
        leftSide->setMaximumSize(QSize(350, 16777215));
        verticalLayout_Left = new QVBoxLayout(leftSide);
        verticalLayout_Left->setObjectName("verticalLayout_Left");
        verticalLayout_Left->setContentsMargins(20, 20, 10, 20);
        lblTitle = new QLabel(leftSide);
        lblTitle->setObjectName("lblTitle");

        verticalLayout_Left->addWidget(lblTitle);

        txtSearch = new QLineEdit(leftSide);
        txtSearch->setObjectName("txtSearch");

        verticalLayout_Left->addWidget(txtSearch);

        hlFilter = new QHBoxLayout();
        hlFilter->setObjectName("hlFilter");
        cboCategoryFilter = new QComboBox(leftSide);
        cboCategoryFilter->setObjectName("cboCategoryFilter");

        hlFilter->addWidget(cboCategoryFilter);

        btnFilter = new QPushButton(leftSide);
        btnFilter->setObjectName("btnFilter");

        hlFilter->addWidget(btnFilter);


        verticalLayout_Left->addLayout(hlFilter);

        tblProducts = new QTableWidget(leftSide);
        if (tblProducts->columnCount() < 3)
            tblProducts->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblProducts->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblProducts->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblProducts->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblProducts->setObjectName("tblProducts");
        tblProducts->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_Left->addWidget(tblProducts);

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
        verticalLayout_Right = new QVBoxLayout(rightSide);
        verticalLayout_Right->setObjectName("verticalLayout_Right");
        verticalLayout_Right->setContentsMargins(20, 20, 20, 20);
        stackEdit = new QStackedWidget(rightSide);
        stackEdit->setObjectName("stackEdit");
        pageEmpty = new QWidget();
        pageEmpty->setObjectName("pageEmpty");
        vlEmpty = new QVBoxLayout(pageEmpty);
        vlEmpty->setObjectName("vlEmpty");
        lblEmpty = new QLabel(pageEmpty);
        lblEmpty->setObjectName("lblEmpty");
        lblEmpty->setAlignment(Qt::AlignCenter);

        vlEmpty->addWidget(lblEmpty);

        stackEdit->addWidget(pageEmpty);
        pageForm = new QWidget();
        pageForm->setObjectName("pageForm");
        vlForm = new QVBoxLayout(pageForm);
        vlForm->setObjectName("vlForm");
        lblEditTitle = new QLabel(pageForm);
        lblEditTitle->setObjectName("lblEditTitle");
        lblEditTitle->setAlignment(Qt::AlignCenter);

        vlForm->addWidget(lblEditTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        l1 = new QLabel(pageForm);
        l1->setObjectName("l1");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, l1);

        txtName = new QLineEdit(pageForm);
        txtName->setObjectName("txtName");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, txtName);

        l2 = new QLabel(pageForm);
        l2->setObjectName("l2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, l2);

        txtPrice = new QLineEdit(pageForm);
        txtPrice->setObjectName("txtPrice");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtPrice);

        l3 = new QLabel(pageForm);
        l3->setObjectName("l3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, l3);

        txtBrand = new QLineEdit(pageForm);
        txtBrand->setObjectName("txtBrand");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, txtBrand);

        l4 = new QLabel(pageForm);
        l4->setObjectName("l4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, l4);

        cboCategoryEdit = new QComboBox(pageForm);
        cboCategoryEdit->setObjectName("cboCategoryEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, cboCategoryEdit);

        l5 = new QLabel(pageForm);
        l5->setObjectName("l5");
        l5->setStyleSheet(QString::fromUtf8("margin-top: 5px;"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, l5);

        txtDesc = new QTextEdit(pageForm);
        txtDesc->setObjectName("txtDesc");
        txtDesc->setMaximumHeight(60);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, txtDesc);


        vlForm->addLayout(formLayout);

        grpSizes = new QGroupBox(pageForm);
        grpSizes->setObjectName("grpSizes");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grpSizes->sizePolicy().hasHeightForWidth());
        grpSizes->setSizePolicy(sizePolicy);
        grpSizes->setMinimumSize(QSize(0, 200));
        vlSize = new QVBoxLayout(grpSizes);
        vlSize->setObjectName("vlSize");
        hlSizeInput = new QHBoxLayout();
        hlSizeInput->setObjectName("hlSizeInput");
        cboSizeSelect = new QComboBox(grpSizes);
        cboSizeSelect->setObjectName("cboSizeSelect");
        cboSizeSelect->setEditable(true);

        hlSizeInput->addWidget(cboSizeSelect);

        spinStock = new QSpinBox(grpSizes);
        spinStock->setObjectName("spinStock");
        spinStock->setMaximum(9999);

        hlSizeInput->addWidget(spinStock);

        btnAddSize = new QPushButton(grpSizes);
        btnAddSize->setObjectName("btnAddSize");

        hlSizeInput->addWidget(btnAddSize);


        vlSize->addLayout(hlSizeInput);

        tblSizes = new QTableWidget(grpSizes);
        if (tblSizes->columnCount() < 2)
            tblSizes->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblSizes->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblSizes->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tblSizes->setObjectName("tblSizes");
        tblSizes->setSelectionBehavior(QAbstractItemView::SelectRows);

        vlSize->addWidget(tblSizes);

        btnRemoveSize = new QPushButton(grpSizes);
        btnRemoveSize->setObjectName("btnRemoveSize");

        vlSize->addWidget(btnRemoveSize);


        vlForm->addWidget(grpSizes);

        hlButtons = new QHBoxLayout();
        hlButtons->setObjectName("hlButtons");
        btnDeleteProduct = new QPushButton(pageForm);
        btnDeleteProduct->setObjectName("btnDeleteProduct");

        hlButtons->addWidget(btnDeleteProduct);

        btnConfirm = new QPushButton(pageForm);
        btnConfirm->setObjectName("btnConfirm");

        hlButtons->addWidget(btnConfirm);


        vlForm->addLayout(hlButtons);

        stackEdit->addWidget(pageForm);

        verticalLayout_Right->addWidget(stackEdit);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(EditProductsWidget);

        stackEdit->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(EditProductsWidget);
    } // setupUi

    void retranslateUi(QWidget *EditProductsWidget)
    {
        lblTitle->setText(QCoreApplication::translate("EditProductsWidget", "PRODUCT LIST", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("EditProductsWidget", "Search product...", nullptr));
        btnFilter->setText(QCoreApplication::translate("EditProductsWidget", "Filter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblProducts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EditProductsWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblProducts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EditProductsWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblProducts->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EditProductsWidget", "Price", nullptr));
        lblHint->setText(QCoreApplication::translate("EditProductsWidget", "* Double click to Edit", nullptr));
        lblEmpty->setText(QCoreApplication::translate("EditProductsWidget", "Select a product to edit details", nullptr));
        lblEditTitle->setText(QCoreApplication::translate("EditProductsWidget", "EDIT PRODUCT", nullptr));
        l1->setText(QCoreApplication::translate("EditProductsWidget", "Name:", nullptr));
        l2->setText(QCoreApplication::translate("EditProductsWidget", "Price:", nullptr));
        l3->setText(QCoreApplication::translate("EditProductsWidget", "Brand:", nullptr));
        l4->setText(QCoreApplication::translate("EditProductsWidget", "Category:", nullptr));
        l5->setText(QCoreApplication::translate("EditProductsWidget", "Desc:", nullptr));
        grpSizes->setTitle(QCoreApplication::translate("EditProductsWidget", "Size & Stock Management", nullptr));
        btnAddSize->setText(QCoreApplication::translate("EditProductsWidget", "Update/Add Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblSizes->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EditProductsWidget", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblSizes->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EditProductsWidget", "Quantity", nullptr));
        btnRemoveSize->setText(QCoreApplication::translate("EditProductsWidget", "Remove Selected Size", nullptr));
        btnDeleteProduct->setText(QCoreApplication::translate("EditProductsWidget", "Delete Product", nullptr));
        btnConfirm->setText(QCoreApplication::translate("EditProductsWidget", "Confirm Save", nullptr));
        btnBack->setText(QCoreApplication::translate("EditProductsWidget", "Back to Dashboard", nullptr));
        (void)EditProductsWidget;
    } // retranslateUi

};

namespace Ui {
    class EditProductsWidget: public Ui_EditProductsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPRODUCTSWIDGET_H
