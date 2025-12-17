/********************************************************************************
** Form generated from reading UI file 'IntroWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROWIDGET_H
#define UI_INTROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblHeader;
    QSpacerItem *verticalSpacer_1;
    QLabel *lblLogo;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblPBL;
    QLabel *lblTopic;
    QSpacerItem *verticalSpacer_3;
    QWidget *infoContainer;
    QGridLayout *gridLayout;
    QLabel *label_svth;
    QLabel *sv1_name;
    QLabel *sv1_class;
    QLabel *sv1_group;
    QLabel *sv2_name;
    QLabel *sv2_class;
    QLabel *sv2_group;
    QLabel *label_gvhd;
    QLabel *gv_name;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblDate;
    QSpacerItem *verticalSpacer_5;
    QLabel *lblPressEnter;

    void setupUi(QWidget *IntroWidget)
    {
        if (IntroWidget->objectName().isEmpty())
            IntroWidget->setObjectName("IntroWidget");
        IntroWidget->resize(1024, 768);
        IntroWidget->setStyleSheet(QString::fromUtf8("background-color: white; font-family: 'Times New Roman'; color: #000000;"));
        verticalLayout = new QVBoxLayout(IntroWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        lblHeader = new QLabel(IntroWidget);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblHeader);

        verticalSpacer_1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_1);

        lblLogo = new QLabel(IntroWidget);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(150, 150));
        lblLogo->setMaximumSize(QSize(150, 150));
        lblLogo->setScaledContents(true);
        lblLogo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblLogo, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lblPBL = new QLabel(IntroWidget);
        lblPBL->setObjectName("lblPBL");
        lblPBL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblPBL);

        lblTopic = new QLabel(IntroWidget);
        lblTopic->setObjectName("lblTopic");
        lblTopic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTopic);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        infoContainer = new QWidget(IntroWidget);
        infoContainer->setObjectName("infoContainer");
        gridLayout = new QGridLayout(infoContainer);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(30);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(100, -1, -1, -1);
        label_svth = new QLabel(infoContainer);
        label_svth->setObjectName("label_svth");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        label_svth->setFont(font);

        gridLayout->addWidget(label_svth, 0, 0, 1, 3);

        sv1_name = new QLabel(infoContainer);
        sv1_name->setObjectName("sv1_name");
        sv1_name->setFont(font);

        gridLayout->addWidget(sv1_name, 1, 0, 1, 1);

        sv1_class = new QLabel(infoContainer);
        sv1_class->setObjectName("sv1_class");
        sv1_class->setFont(font);

        gridLayout->addWidget(sv1_class, 1, 1, 1, 1);

        sv1_group = new QLabel(infoContainer);
        sv1_group->setObjectName("sv1_group");
        sv1_group->setFont(font);

        gridLayout->addWidget(sv1_group, 1, 2, 1, 1);

        sv2_name = new QLabel(infoContainer);
        sv2_name->setObjectName("sv2_name");
        sv2_name->setFont(font);

        gridLayout->addWidget(sv2_name, 2, 0, 1, 1);

        sv2_class = new QLabel(infoContainer);
        sv2_class->setObjectName("sv2_class");
        sv2_class->setFont(font);

        gridLayout->addWidget(sv2_class, 2, 1, 1, 1);

        sv2_group = new QLabel(infoContainer);
        sv2_group->setObjectName("sv2_group");
        sv2_group->setFont(font);

        gridLayout->addWidget(sv2_group, 2, 2, 1, 1);

        label_gvhd = new QLabel(infoContainer);
        label_gvhd->setObjectName("label_gvhd");
        label_gvhd->setFont(font);

        gridLayout->addWidget(label_gvhd, 3, 0, 1, 1);

        gv_name = new QLabel(infoContainer);
        gv_name->setObjectName("gv_name");
        gv_name->setFont(font);

        gridLayout->addWidget(gv_name, 3, 1, 1, 2);


        verticalLayout->addWidget(infoContainer);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        lblDate = new QLabel(IntroWidget);
        lblDate->setObjectName("lblDate");
        lblDate->setAlignment(Qt::AlignCenter);
        lblDate->setFont(font);

        verticalLayout->addWidget(lblDate);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        lblPressEnter = new QLabel(IntroWidget);
        lblPressEnter->setObjectName("lblPressEnter");
        lblPressEnter->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblPressEnter);


        retranslateUi(IntroWidget);

        QMetaObject::connectSlotsByName(IntroWidget);
    } // setupUi

    void retranslateUi(QWidget *IntroWidget)
    {
        IntroWidget->setWindowTitle(QCoreApplication::translate("IntroWidget", "Introduction", nullptr));
        lblHeader->setText(QCoreApplication::translate("IntroWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\304\220\341\272\240I H\341\273\214C \304\220\303\200 N\341\272\264NG</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\304\220\341\272\240I H\341\273\214C B\303\201CH KHOA</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">KHOA C\303\224NG NGH\341\273\206 TH\303\224NG TIN</span></p></body></html>", nullptr));
        lblLogo->setText(QString());
        lblPBL->setText(QCoreApplication::translate("IntroWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">PBL2: D\341\273\260 \303\201N C\306\240 S\341\273\236 L\341\272\254P TR\303\214NH</span></p></body></html>", nullptr));
        lblTopic->setText(QCoreApplication::translate("IntroWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; color:#d32f2f;\">\304\220\341\273\201 t\303\240i : Qu\341\272\243n l\303\275 shop qu\341\272\247n \303\241o</span></p></body></html>", nullptr));
        label_svth->setText(QCoreApplication::translate("IntroWidget", "SINH VI\303\212N TH\341\273\260C HI\341\273\206N:", nullptr));
        sv1_name->setText(QCoreApplication::translate("IntroWidget", "Ch\303\242u Thanh Nam Trung", nullptr));
        sv1_class->setText(QCoreApplication::translate("IntroWidget", "L\341\273\232P: 24T_DT2", nullptr));
        sv1_group->setText(QCoreApplication::translate("IntroWidget", "NH\303\223M: 24.11B", nullptr));
        sv2_name->setText(QCoreApplication::translate("IntroWidget", "L\303\252 Hu\341\273\263nh Thanh Th\341\273\213nh", nullptr));
        sv2_class->setText(QCoreApplication::translate("IntroWidget", "L\341\273\232P: 24T_DT2", nullptr));
        sv2_group->setText(QCoreApplication::translate("IntroWidget", "NH\303\223M: 24.11B", nullptr));
        label_gvhd->setText(QCoreApplication::translate("IntroWidget", "GI\341\272\242NG VI\303\212N H\306\257\341\273\232NG D\341\272\252N:", nullptr));
        label_gvhd->setStyleSheet(QCoreApplication::translate("IntroWidget", "margin-top: 20px;", nullptr));
        gv_name->setText(QCoreApplication::translate("IntroWidget", "\304\220\341\273\227 Th\341\273\213 Tuy\341\272\277t Hoa", nullptr));
        gv_name->setStyleSheet(QCoreApplication::translate("IntroWidget", "margin-top: 20px;", nullptr));
        lblDate->setText(QCoreApplication::translate("IntroWidget", "\304\220\303\240 N\341\272\265ng 12-2025", nullptr));
        lblPressEnter->setText(QCoreApplication::translate("IntroWidget", "- Press Enter to Continue -", nullptr));
        lblPressEnter->setStyleSheet(QCoreApplication::translate("IntroWidget", "color: #555; font-style: italic; font-size: 14px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntroWidget: public Ui_IntroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWIDGET_H
