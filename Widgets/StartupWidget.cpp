#include "StartupWidget.h"
#include "ui_StartupWidget.h"
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QPixmap>

StartupWidget::StartupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartupWidget)
{
    ui->setupUi(this);
    this->setObjectName("StartupScreen");

    int cardWidth = 420;
    int cardHeight = 550;
    ui->leftPanel->setMinimumSize(cardWidth, cardHeight);
    ui->leftPanel->setMaximumSize(cardWidth, cardHeight);
    ui->frameCard->setMinimumSize(cardWidth, cardHeight);
    ui->frameCard->setMaximumSize(cardWidth, cardHeight);

    QPixmap logo(":/assets/products.png");

    if (!logo.isNull()) {
        QPixmap scaledLogo = logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->lblLogo->setPixmap(scaledLogo);
        ui->lblLogo->setAlignment(Qt::AlignCenter);
        ui->lblLogo->setFixedHeight(150);

    } else {
        ui->lblLogo->setText("SHOP LOGO");
        ui->lblLogo->setAlignment(Qt::AlignCenter);
    }

    QGraphicsDropShadowEffect *shadowRight = new QGraphicsDropShadowEffect(this);
    shadowRight->setBlurRadius(50);
    shadowRight->setColor(QColor(176, 190, 197, 150));
    shadowRight->setOffset(0, 10);
    ui->frameCard->setGraphicsEffect(shadowRight);

    QGraphicsDropShadowEffect *shadowLeft = new QGraphicsDropShadowEffect(this);
    shadowLeft->setBlurRadius(30);
    shadowLeft->setColor(QColor(0, 0, 0, 20));
    shadowLeft->setOffset(0, 5);
    ui->leftPanel->setGraphicsEffect(shadowLeft);

    this->setStyleSheet(
        "QWidget#StartupScreen { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "       stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"

        "QWidget#centerContainer { background: transparent; }"

        "QWidget#leftPanel { "
        "   background-color: rgba(255, 255, 255, 120); "
        "   border-radius: 20px; "
        "   margin-right: 5px; "
        "}"

        "QLabel#lblSlogan { "
        "   font-family: 'Segoe UI', sans-serif; "
        "   font-size: 20px; "
        "   font-weight: 500; "
        "   color: #455A64; "
        "   min-height: 50px; "
        "   max-height: 50px; "
        "   padding-top: 5px; "
        "   padding-bottom: 160px; "
        "   padding-left: 20px; padding-right: 20px;"
        "   qproperty-alignment: AlignCenter; "
        "}"

        "QFrame#frameCard { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   margin-left: 5px; "
        "}"

        "QLabel#lblTitle { "
        "   font-family: 'Segoe UI', sans-serif; "
        "   font-size: 30px; "
        "   font-weight: 800; "
        "   color: #1565C0; "
        "   min-height: 40px; "
        "   max-height: 40px; "
        "   qproperty-alignment: AlignCenter; "
        "   margin-bottom: 0px; "
        "   margin-top: 25px; "
        "   padding-bottom: 0px; "
        "   background: transparent;"
        "}"

        "QLabel#lblSubtitle { "
        "   font-family: 'Segoe UI', sans-serif; "
        "   font-size: 13px; "
        "   font-weight: 600; "
        "   color: #B0BEC5; "
        "   letter-spacing: 2px; "
        "   min-height: 20px; "
        "   max-height: 20px; "
        "   qproperty-alignment: AlignCenter; "
        "   margin-top: 0px; "
        "   padding-top: 0px; "
        "   margin-bottom: 0px; "
        "   background: transparent; "
        "}"

        "QPushButton { "
        "   border-radius: 22px; "
        "   padding: 12px; "
        "   font-family: 'Segoe UI', sans-serif; "
        "   font-size: 15px; "
        "   font-weight: 700; "
        "   margin-left: 50px; "
        "   margin-right: 50px; "
        "   margin-bottom: 50px; "
        "   margin-top: 0px; "
        "}"

        "QPushButton#btnCustomer, QPushButton#btnStaff, QPushButton#btnRegister { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border: none; "
        "}"
        "QPushButton#btnCustomer:hover, QPushButton#btnStaff:hover, QPushButton#btnRegister:hover { "
        "   background-color: #1565C0; "
        "   padding-left: 15px; "
        "}"
        "QPushButton#btnCustomer:pressed, QPushButton#btnStaff:pressed, QPushButton#btnRegister:pressed { "
        "   background-color: #0D47A1; "
        "}"

        "QPushButton#btnExit { "
        "   background-color: #FFFFFF; "
        "   border: 2px solid #EF5350; "
        "   color: #D32F2F; "
        "   margin-top: 12px; "
        "}"
        "QPushButton#btnExit:hover { "
        "   background-color: #FFEBEE; "
        "   border-color: #D32F2F; "
        "}"
        );
}

StartupWidget::~StartupWidget() { delete ui; }
void StartupWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void StartupWidget::on_btnCustomer_clicked() { emit goToLogin(1); }
void StartupWidget::on_btnStaff_clicked() { emit goToLogin(2); }
void StartupWidget::on_btnRegister_clicked() { emit goToRegister(); }
void StartupWidget::on_btnExit_clicked() { QApplication::quit(); }
