/********************************************************************************
** Form generated from reading UI file 'ReviewsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEWSWIDGET_H
#define UI_REVIEWSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReviewsWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QFrame *mainCard;
    QVBoxLayout *verticalLayout_Card;
    QStackedWidget *reviewStack;
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
    QPushButton *btnBackMenu;
    QWidget *pageDetail;
    QVBoxLayout *verticalLayout_Detail;
    QLabel *lblProdName;
    QLabel *lblRatingInfo;
    QLabel *lblProdDesc;
    QSpacerItem *vSpacer;
    QTabWidget *tabReviews;
    QWidget *tabRead;
    QVBoxLayout *verticalLayout_Read;
    QScrollArea *scrollReviews;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Scroll;
    QWidget *tabWrite;
    QVBoxLayout *verticalLayout_Write;
    QLabel *lblRateTitle;
    QSpinBox *spinRating;
    QLabel *lblCommentTitle;
    QTextEdit *txtComment;
    QPushButton *btnConfirmReview;
    QPushButton *btnBackList;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *ReviewsWidget)
    {
        if (ReviewsWidget->objectName().isEmpty())
            ReviewsWidget->setObjectName("ReviewsWidget");
        ReviewsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(ReviewsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(ReviewsWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        mainCard = new QFrame(centerContainer);
        mainCard->setObjectName("mainCard");
        mainCard->setMinimumSize(QSize(420, 550));
        mainCard->setMaximumSize(QSize(420, 550));
        mainCard->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout_Card = new QVBoxLayout(mainCard);
        verticalLayout_Card->setSpacing(0);
        verticalLayout_Card->setObjectName("verticalLayout_Card");
        verticalLayout_Card->setContentsMargins(0, 0, 0, 0);
        reviewStack = new QStackedWidget(mainCard);
        reviewStack->setObjectName("reviewStack");
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
        if (tblProducts->columnCount() < 2)
            tblProducts->setColumnCount(2);
        tblProducts->setObjectName("tblProducts");
        tblProducts->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tblProducts->setColumnCount(2);

        verticalLayout_List->addWidget(tblProducts);

        lblHint = new QLabel(pageList);
        lblHint->setObjectName("lblHint");
        lblHint->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_List->addWidget(lblHint);

        btnBackMenu = new QPushButton(pageList);
        btnBackMenu->setObjectName("btnBackMenu");

        verticalLayout_List->addWidget(btnBackMenu);

        reviewStack->addWidget(pageList);
        pageDetail = new QWidget();
        pageDetail->setObjectName("pageDetail");
        verticalLayout_Detail = new QVBoxLayout(pageDetail);
        verticalLayout_Detail->setObjectName("verticalLayout_Detail");
        verticalLayout_Detail->setContentsMargins(20, 20, 20, 20);
        lblProdName = new QLabel(pageDetail);
        lblProdName->setObjectName("lblProdName");
        lblProdName->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblProdName->setWordWrap(true);

        verticalLayout_Detail->addWidget(lblProdName);

        lblRatingInfo = new QLabel(pageDetail);
        lblRatingInfo->setObjectName("lblRatingInfo");
        lblRatingInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_Detail->addWidget(lblRatingInfo);

        lblProdDesc = new QLabel(pageDetail);
        lblProdDesc->setObjectName("lblProdDesc");
        lblProdDesc->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblProdDesc->setWordWrap(true);

        verticalLayout_Detail->addWidget(lblProdDesc);

        vSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Detail->addItem(vSpacer);

        tabReviews = new QTabWidget(pageDetail);
        tabReviews->setObjectName("tabReviews");
        tabRead = new QWidget();
        tabRead->setObjectName("tabRead");
        verticalLayout_Read = new QVBoxLayout(tabRead);
        verticalLayout_Read->setObjectName("verticalLayout_Read");
        scrollReviews = new QScrollArea(tabRead);
        scrollReviews->setObjectName("scrollReviews");
        scrollReviews->setWidgetResizable(true);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 360, 270));
        verticalLayout_Scroll = new QVBoxLayout(scrollContent);
        verticalLayout_Scroll->setSpacing(10);
        verticalLayout_Scroll->setObjectName("verticalLayout_Scroll");
        scrollReviews->setWidget(scrollContent);

        verticalLayout_Read->addWidget(scrollReviews);

        tabReviews->addTab(tabRead, QString());
        tabWrite = new QWidget();
        tabWrite->setObjectName("tabWrite");
        verticalLayout_Write = new QVBoxLayout(tabWrite);
        verticalLayout_Write->setObjectName("verticalLayout_Write");
        lblRateTitle = new QLabel(tabWrite);
        lblRateTitle->setObjectName("lblRateTitle");

        verticalLayout_Write->addWidget(lblRateTitle);

        spinRating = new QSpinBox(tabWrite);
        spinRating->setObjectName("spinRating");
        spinRating->setMinimum(1);
        spinRating->setMaximum(5);

        verticalLayout_Write->addWidget(spinRating);

        lblCommentTitle = new QLabel(tabWrite);
        lblCommentTitle->setObjectName("lblCommentTitle");

        verticalLayout_Write->addWidget(lblCommentTitle);

        txtComment = new QTextEdit(tabWrite);
        txtComment->setObjectName("txtComment");

        verticalLayout_Write->addWidget(txtComment);

        btnConfirmReview = new QPushButton(tabWrite);
        btnConfirmReview->setObjectName("btnConfirmReview");

        verticalLayout_Write->addWidget(btnConfirmReview);

        tabReviews->addTab(tabWrite, QString());

        verticalLayout_Detail->addWidget(tabReviews);

        btnBackList = new QPushButton(pageDetail);
        btnBackList->setObjectName("btnBackList");

        verticalLayout_Detail->addWidget(btnBackList);

        reviewStack->addWidget(pageDetail);

        verticalLayout_Card->addWidget(reviewStack);


        horizontalLayout_Center->addWidget(mainCard);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(ReviewsWidget);

        reviewStack->setCurrentIndex(1);
        tabReviews->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ReviewsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReviewsWidget)
    {
        lblTitleList->setText(QCoreApplication::translate("ReviewsWidget", "PRODUCT REVIEWS", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("ReviewsWidget", "Search product...", nullptr));
        btnFilter->setText(QCoreApplication::translate("ReviewsWidget", "Filter", nullptr));
        lblHint->setText(QCoreApplication::translate("ReviewsWidget", "* Double click to view/add reviews", nullptr));
        btnBackMenu->setText(QCoreApplication::translate("ReviewsWidget", "Back to Menu", nullptr));
        lblProdName->setText(QCoreApplication::translate("ReviewsWidget", "Product Name", nullptr));
        lblRatingInfo->setText(QCoreApplication::translate("ReviewsWidget", "4.5 Stars (10 reviews)", nullptr));
        lblProdDesc->setText(QCoreApplication::translate("ReviewsWidget", "Description...", nullptr));
        tabReviews->setTabText(tabReviews->indexOf(tabRead), QCoreApplication::translate("ReviewsWidget", "Read Reviews", nullptr));
        lblRateTitle->setText(QCoreApplication::translate("ReviewsWidget", "Your Rating:", nullptr));
        lblCommentTitle->setText(QCoreApplication::translate("ReviewsWidget", "Your Comment:", nullptr));
        txtComment->setPlaceholderText(QCoreApplication::translate("ReviewsWidget", "Write your experience here...", nullptr));
        btnConfirmReview->setText(QCoreApplication::translate("ReviewsWidget", "Confirm post", nullptr));
        tabReviews->setTabText(tabReviews->indexOf(tabWrite), QCoreApplication::translate("ReviewsWidget", "Write Review", nullptr));
        btnBackList->setText(QCoreApplication::translate("ReviewsWidget", "Back to List", nullptr));
        (void)ReviewsWidget;
    } // retranslateUi

};

namespace Ui {
    class ReviewsWidget: public Ui_ReviewsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEWSWIDGET_H
