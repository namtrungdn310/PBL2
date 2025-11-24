/********************************************************************************
** Form generated from reading UI file 'PromotionsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTIONSWIDGET_H
#define UI_PROMOTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PromotionsWidget
{
public:
    QVBoxLayout *verticalLayout_Main;
    QWidget *centerContainer;
    QHBoxLayout *horizontalLayout_Center;
    QSpacerItem *horizontalSpacer_L;
    QWidget *contentContainer;
    QVBoxLayout *verticalLayout_Content;
    QLabel *lblTitle;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *verticalLayout_Scroll;
    QPushButton *btnBack;
    QSpacerItem *horizontalSpacer_R;

    void setupUi(QWidget *PromotionsWidget)
    {
        if (PromotionsWidget->objectName().isEmpty())
            PromotionsWidget->setObjectName("PromotionsWidget");
        PromotionsWidget->resize(1024, 768);
        verticalLayout_Main = new QVBoxLayout(PromotionsWidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        centerContainer = new QWidget(PromotionsWidget);
        centerContainer->setObjectName("centerContainer");
        horizontalLayout_Center = new QHBoxLayout(centerContainer);
        horizontalLayout_Center->setObjectName("horizontalLayout_Center");
        horizontalSpacer_L = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_L);

        contentContainer = new QWidget(centerContainer);
        contentContainer->setObjectName("contentContainer");
        contentContainer->setMinimumSize(QSize(600, 0));
        contentContainer->setMaximumSize(QSize(800, 16777215));
        verticalLayout_Content = new QVBoxLayout(contentContainer);
        verticalLayout_Content->setObjectName("verticalLayout_Content");
        lblTitle = new QLabel(contentContainer);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_Content->addWidget(lblTitle);

        scrollArea = new QScrollArea(contentContainer);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollContent = new QWidget();
        scrollContent->setObjectName("scrollContent");
        scrollContent->setGeometry(QRect(0, 0, 782, 500));
        verticalLayout_Scroll = new QVBoxLayout(scrollContent);
        verticalLayout_Scroll->setSpacing(15);
        verticalLayout_Scroll->setObjectName("verticalLayout_Scroll");
        scrollArea->setWidget(scrollContent);

        verticalLayout_Content->addWidget(scrollArea);

        btnBack = new QPushButton(contentContainer);
        btnBack->setObjectName("btnBack");

        verticalLayout_Content->addWidget(btnBack);


        horizontalLayout_Center->addWidget(contentContainer);

        horizontalSpacer_R = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Center->addItem(horizontalSpacer_R);


        verticalLayout_Main->addWidget(centerContainer);


        retranslateUi(PromotionsWidget);

        QMetaObject::connectSlotsByName(PromotionsWidget);
    } // setupUi

    void retranslateUi(QWidget *PromotionsWidget)
    {
        lblTitle->setText(QCoreApplication::translate("PromotionsWidget", "AVAILABLE PROMOTIONS", nullptr));
        btnBack->setText(QCoreApplication::translate("PromotionsWidget", "Back to Dashboard", nullptr));
        (void)PromotionsWidget;
    } // retranslateUi

};

namespace Ui {
    class PromotionsWidget: public Ui_PromotionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTIONSWIDGET_H
