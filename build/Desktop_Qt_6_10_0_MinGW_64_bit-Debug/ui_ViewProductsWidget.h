/********************************************************************************
** Form generated from reading UI file 'ViewProductsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPRODUCTSWIDGET_H
#define UI_VIEWPRODUCTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewProductsWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *cardFrame;
    QVBoxLayout *verticalLayout_Card;
    QStackedWidget *productStack;
    QWidget *pageList;
    QVBoxLayout *verticalLayout_List;
    QLabel *lblTitleList;
    QLineEdit *txtSearch;
    QHBoxLayout *horizontalLayout_Filter;
    QComboBox *cboCategory;
    QComboBox *cboSort;
    QPushButton *btnFilter;
    QTableWidget *tblProducts;
    QLabel *lblHint;
    QPushButton *btnBackList;
    QWidget *pageDetail;
    QVBoxLayout *verticalLayout_Detail;
    QLabel *lblProdName;
    QLabel *lblProdPrice;
    QLabel *lblProdDesc;
    QFormLayout *formLayout;
    QLabel *label_1;
    QComboBox *cboSize;
    QLabel *label_2;
    QSpinBox *spinQty;
    QLabel *lblStockAvailable;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAddToCart;
    QPushButton *btnBackDetail;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *ViewProductsWidget)
    {
        if (ViewProductsWidget->objectName().isEmpty())
            ViewProductsWidget->setObjectName("ViewProductsWidget");
        ViewProductsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(ViewProductsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(ViewProductsWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        cardFrame = new QFrame(centerContainer);
        cardFrame->setObjectName("cardFrame");
        cardFrame->setMinimumSize(QSize(420, 550));
        cardFrame->setMaximumSize(QSize(420, 550));
        cardFrame->setFrameShape(QFrame::Shape::StyledPanel);
        cardFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_Card = new QVBoxLayout(cardFrame);
        verticalLayout_Card->setSpacing(0);
        verticalLayout_Card->setObjectName("verticalLayout_Card");
        verticalLayout_Card->setContentsMargins(0, 0, 0, 0);
        productStack = new QStackedWidget(cardFrame);
        productStack->setObjectName("productStack");
        pageList = new QWidget();
        pageList->setObjectName("pageList");
        verticalLayout_List = new QVBoxLayout(pageList);
        verticalLayout_List->setObjectName("verticalLayout_List");
        verticalLayout_List->setContentsMargins(20, 20, 20, 20);
        lblTitleList = new QLabel(pageList);
        lblTitleList->setObjectName("lblTitleList");
        lblTitleList->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_List->addWidget(lblTitleList);

        txtSearch = new QLineEdit(pageList);
        txtSearch->setObjectName("txtSearch");

        verticalLayout_List->addWidget(txtSearch);

        horizontalLayout_Filter = new QHBoxLayout();
        horizontalLayout_Filter->setObjectName("horizontalLayout_Filter");
        cboCategory = new QComboBox(pageList);
        cboCategory->setObjectName("cboCategory");

        horizontalLayout_Filter->addWidget(cboCategory);

        cboSort = new QComboBox(pageList);
        cboSort->setObjectName("cboSort");

        horizontalLayout_Filter->addWidget(cboSort);


        verticalLayout_List->addLayout(horizontalLayout_Filter);

        btnFilter = new QPushButton(pageList);
        btnFilter->setObjectName("btnFilter");

        verticalLayout_List->addWidget(btnFilter);

        tblProducts = new QTableWidget(pageList);
        if (tblProducts->columnCount() < 3)
            tblProducts->setColumnCount(3);
        tblProducts->setObjectName("tblProducts");
        tblProducts->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tblProducts->setColumnCount(3);

        verticalLayout_List->addWidget(tblProducts);

        lblHint = new QLabel(pageList);
        lblHint->setObjectName("lblHint");
        lblHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_List->addWidget(lblHint);

        btnBackList = new QPushButton(pageList);
        btnBackList->setObjectName("btnBackList");

        verticalLayout_List->addWidget(btnBackList);

        productStack->addWidget(pageList);
        pageDetail = new QWidget();
        pageDetail->setObjectName("pageDetail");
        verticalLayout_Detail = new QVBoxLayout(pageDetail);
        verticalLayout_Detail->setObjectName("verticalLayout_Detail");
        verticalLayout_Detail->setContentsMargins(30, 30, 30, 30);
        lblProdName = new QLabel(pageDetail);
        lblProdName->setObjectName("lblProdName");
        lblProdName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblProdName->setWordWrap(true);

        verticalLayout_Detail->addWidget(lblProdName);

        lblProdPrice = new QLabel(pageDetail);
        lblProdPrice->setObjectName("lblProdPrice");
        lblProdPrice->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Detail->addWidget(lblProdPrice);

        lblProdDesc = new QLabel(pageDetail);
        lblProdDesc->setObjectName("lblProdDesc");
        lblProdDesc->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        lblProdDesc->setWordWrap(true);

        verticalLayout_Detail->addWidget(lblProdDesc);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_1 = new QLabel(pageDetail);
        label_1->setObjectName("label_1");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_1);

        cboSize = new QComboBox(pageDetail);
        cboSize->setObjectName("cboSize");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, cboSize);

        label_2 = new QLabel(pageDetail);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        spinQty = new QSpinBox(pageDetail);
        spinQty->setObjectName("spinQty");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, spinQty);

        lblStockAvailable = new QLabel(pageDetail);
        lblStockAvailable->setObjectName("lblStockAvailable");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lblStockAvailable);


        verticalLayout_Detail->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Detail->addItem(verticalSpacer);

        btnAddToCart = new QPushButton(pageDetail);
        btnAddToCart->setObjectName("btnAddToCart");

        verticalLayout_Detail->addWidget(btnAddToCart);

        btnBackDetail = new QPushButton(pageDetail);
        btnBackDetail->setObjectName("btnBackDetail");

        verticalLayout_Detail->addWidget(btnBackDetail);

        productStack->addWidget(pageDetail);

        verticalLayout_Card->addWidget(productStack);


        horizontalLayout_Center->addWidget(cardFrame);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(ViewProductsWidget);

        productStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ViewProductsWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewProductsWidget)
    {
        ViewProductsWidget->setWindowTitle(QCoreApplication::translate("ViewProductsWidget", "View Products", nullptr));
        lblTitleList->setText(QCoreApplication::translate("ViewProductsWidget", "PRODUCTS LIST", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("ViewProductsWidget", "Search by name...", nullptr));
        btnFilter->setText(QCoreApplication::translate("ViewProductsWidget", "Apply Filter", nullptr));
        lblHint->setText(QCoreApplication::translate("ViewProductsWidget", "* Double click to view details", nullptr));
        btnBackList->setText(QCoreApplication::translate("ViewProductsWidget", "Back to Dashboard", nullptr));
        lblProdName->setText(QCoreApplication::translate("ViewProductsWidget", "Product Name", nullptr));
        lblProdPrice->setText(QCoreApplication::translate("ViewProductsWidget", "0 VND", nullptr));
        lblProdDesc->setText(QCoreApplication::translate("ViewProductsWidget", "Description here...", nullptr));
        label_1->setText(QCoreApplication::translate("ViewProductsWidget", "Select Size:", nullptr));
        label_2->setText(QCoreApplication::translate("ViewProductsWidget", "Quantity:", nullptr));
        lblStockAvailable->setText(QCoreApplication::translate("ViewProductsWidget", "(Available: 0)", nullptr));
        btnAddToCart->setText(QCoreApplication::translate("ViewProductsWidget", "Add to Cart", nullptr));
        btnBackDetail->setText(QCoreApplication::translate("ViewProductsWidget", "Back to List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewProductsWidget: public Ui_ViewProductsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPRODUCTSWIDGET_H
