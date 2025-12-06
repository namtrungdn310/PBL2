/********************************************************************************
** Form generated from reading UI file 'EditReviewsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITREVIEWSWIDGET_H
#define UI_EDITREVIEWSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditReviewsWidget
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
    QFrame *lineSeparator;
    QWidget *rightSide;
    QVBoxLayout *verticalLayout_Right;
    QStackedWidget *stackReviews;
    QWidget *pageEmpty;
    QVBoxLayout *vlEmpty;
    QLabel *lblEmpty;
    QWidget *pageReviews;
    QVBoxLayout *vlReviews;
    QLabel *lblProdName;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Scroll;
    QGroupBox *grpReply;
    QVBoxLayout *vlReply;
    QTextEdit *txtReply;
    QPushButton *btnPostReply;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *EditReviewsWidget)
    {
        if (EditReviewsWidget->objectName().isEmpty())
            EditReviewsWidget->setObjectName("EditReviewsWidget");
        EditReviewsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(EditReviewsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(EditReviewsWidget);
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
        stackReviews = new QStackedWidget(rightSide);
        stackReviews->setObjectName("stackReviews");
        pageEmpty = new QWidget();
        pageEmpty->setObjectName("pageEmpty");
        vlEmpty = new QVBoxLayout(pageEmpty);
        vlEmpty->setObjectName("vlEmpty");
        lblEmpty = new QLabel(pageEmpty);
        lblEmpty->setObjectName("lblEmpty");
        lblEmpty->setAlignment(Qt::AlignCenter);

        vlEmpty->addWidget(lblEmpty);

        stackReviews->addWidget(pageEmpty);
        pageReviews = new QWidget();
        pageReviews->setObjectName("pageReviews");
        vlReviews = new QVBoxLayout(pageReviews);
        vlReviews->setObjectName("vlReviews");
        lblProdName = new QLabel(pageReviews);
        lblProdName->setObjectName("lblProdName");
        lblProdName->setAlignment(Qt::AlignCenter);
        lblProdName->setWordWrap(true);

        vlReviews->addWidget(lblProdName);

        scrollArea = new QScrollArea(pageReviews);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        verticalLayout_Scroll = new QVBoxLayout(scrollContent);
        verticalLayout_Scroll->setSpacing(15);
        verticalLayout_Scroll->setObjectName("verticalLayout_Scroll");
        scrollArea->setWidget(scrollContent);

        vlReviews->addWidget(scrollArea);

        grpReply = new QGroupBox(pageReviews);
        grpReply->setObjectName("grpReply");
        vlReply = new QVBoxLayout(grpReply);
        vlReply->setObjectName("vlReply");
        txtReply = new QTextEdit(grpReply);
        txtReply->setObjectName("txtReply");
        txtReply->setMaximumHeight(80);

        vlReply->addWidget(txtReply);

        btnPostReply = new QPushButton(grpReply);
        btnPostReply->setObjectName("btnPostReply");

        vlReply->addWidget(btnPostReply);


        vlReviews->addWidget(grpReply);

        stackReviews->addWidget(pageReviews);

        verticalLayout_Right->addWidget(stackReviews);

        btnBack = new QPushButton(rightSide);
        btnBack->setObjectName("btnBack");

        verticalLayout_Right->addWidget(btnBack);


        horizontalLayout_Card->addWidget(rightSide);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(EditReviewsWidget);

        stackReviews->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditReviewsWidget);
    } // setupUi

    void retranslateUi(QWidget *EditReviewsWidget)
    {
        lblTitle->setText(QCoreApplication::translate("EditReviewsWidget", "SELECT PRODUCT", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("EditReviewsWidget", "Search product...", nullptr));
        btnFilter->setText(QCoreApplication::translate("EditReviewsWidget", "Filter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblProducts->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EditReviewsWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblProducts->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EditReviewsWidget", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblProducts->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EditReviewsWidget", "Rating", nullptr));
        lblEmpty->setText(QCoreApplication::translate("EditReviewsWidget", "Select a product to manage reviews", nullptr));
        lblProdName->setText(QCoreApplication::translate("EditReviewsWidget", "Product Name", nullptr));
        grpReply->setTitle(QCoreApplication::translate("EditReviewsWidget", "Reply to Customer", nullptr));
        txtReply->setPlaceholderText(QCoreApplication::translate("EditReviewsWidget", "Select a review above to reply, or write a general comment...", nullptr));
        btnPostReply->setText(QCoreApplication::translate("EditReviewsWidget", "Post Reply", nullptr));
        btnBack->setText(QCoreApplication::translate("EditReviewsWidget", "Back to Dashboard", nullptr));
        (void)EditReviewsWidget;
    } // retranslateUi

};

namespace Ui {
    class EditReviewsWidget: public Ui_EditReviewsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITREVIEWSWIDGET_H
