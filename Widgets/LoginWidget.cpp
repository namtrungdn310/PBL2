#include "LoginWidget.h"
#include "ui_LoginWidget.h"
#include "include/ShopSystem.h"
#include <QGraphicsDropShadowEffect>
#include <QPixmap>
#include <QStyleOption>
#include <QPainter>
#include <QHBoxLayout>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget),
    currentRole(1)
{
    ui->setupUi(this);
    this->setObjectName("LoginScreen");

    int cardWidth = 420;
    int cardHeight = 550;

    auto setSize = [=](QWidget* w) {
        w->setMinimumSize(cardWidth, cardHeight);
        w->setMaximumSize(cardWidth, cardHeight);
    };
    setSize(ui->leftPanel);
    setSize(ui->frameCard);

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

    ui->txtEmail->setPlaceholderText("Enter your Email");
    ui->txtPassword->setPlaceholderText("Enter your Password");
    ui->txtPassword->setEchoMode(QLineEdit::Password);

    ui->containerPass->setStyleSheet(
        "QWidget#containerPass { "
        "   background-color: #F5F7F9; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 10px; "
        "   min-height: 46px; "
        "   max-height: 46px; "
        "   margin-left: 40px; "
        "   margin-right: 40px; "
        "}"
        );

    if (ui->containerPass->layout()) {
        ui->containerPass->layout()->setSpacing(0);
        ui->containerPass->layout()->setContentsMargins(0, 0, 0, 0);
    }

    ui->txtPassword->setStyleSheet(
        "QLineEdit { "
        "   background: transparent; "
        "   border: none; "
        "   padding-left: 15px; "
        "   font-family: 'Segoe UI'; "
        "   font-size: 14px; "
        "   color: #333; "
        "}"
        );

    ui->btnTogglePass->setStyleSheet(
        "QToolButton { "
        "   background: transparent; "
        "   border: none; "
        "   color: #757575; "
        "   font-size: 16px; "
        "   margin-left: 9px; "
        "   padding-top: 5px; "
        "   padding-bottom: 5px; "
        "}"
        "QToolButton:hover { "
        "   background-color: rgba(25, 118, 210, 0.05); "
        "   border-radius: 5px; "
        "}"
        );

    ui->lblError->clear();
    ui->lblError->setAlignment(Qt::AlignCenter);

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
        "QWidget#LoginScreen { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "       stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"

        "QWidget#lblLogo { "
        "   margin-bottom: 11px; "
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
        "   padding-left: 20px; padding-right: 20px; "
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
        "   background: transparent; "
        "}"

        "QLineEdit#txtEmail { "
        "   background-color: #F5F7F9; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 10px; "
        "   padding: 12px 15px; "
        "   font-family: 'Segoe UI'; "
        "   font-size: 14px; "
        "   color: #333; "
        "   margin-left: 40px; "
        "   margin-right: 40px; "
        "   margin-bottom: 15px; "
        "   margin-top: 18px; "
        "}"

        "QLabel#lblError { "
        "   color: #D32F2F; "
        "   font-weight: bold; "
        "   font-size: 13px; "
        "   font-family: 'Segoe UI'; "
        "   qproperty-alignment: AlignCenter; "
        "   margin-bottom: 5px; "
        "   margin-top: 5px; "
        "   min-height: 20px; "
        "   background: transparent; "
        "}"

        "QPushButton#btnConfirm { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border: none; "
        "   border-radius: 22px; "
        "   padding: 12px; "
        "   font-family: 'Segoe UI'; "
        "   font-size: 15px; "
        "   font-weight: 700; "
        "   margin-left: 50px; "
        "   margin-right: 50px; "
        "   margin-top: 80px; "
        "   margin-bottom: 10px; "
        "}"
        "QPushButton#btnConfirm:hover { "
        "   background-color: #1565C0; "
        "}"
        "QPushButton#btnConfirm:pressed { "
        "   background-color: #0D47A1; "
        "}"

        "QPushButton#btnBack { "
        "   background-color: #FFFFFF; "
        "   border: 2px solid #EF5350; "
        "   color: #D32F2F; "
        "   border-radius: 22px; "
        "   padding: 12px; "
        "   font-family: 'Segoe UI'; "
        "   font-size: 15px; "
        "   font-weight: 700; "
        "   margin-left: 50px; "
        "   margin-right: 50px; "
        "   margin-top: 5px; "
        "   margin-bottom: 30px; "
        "}"
        "QPushButton#btnBack:hover { "
        "   background-color: #FFEBEE; "
        "   border-color: #D32F2F; "
        "}"
        "QPushButton#btnBack:pressed { "
        "   background-color: #FFCDD2; "
        "}"
        );
}

LoginWidget::~LoginWidget() { delete ui; }

void LoginWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void LoginWidget::setRole(int role) {
    currentRole = role;

    if (role == 1) {
        ui->lblTitle->setText("CUSTOMER LOGIN");
    } else {
        ui->lblTitle->setText("STAFF LOGIN");
    }

    ui->txtEmail->clear();
    ui->txtPassword->clear();
    ui->lblError->clear();

    ui->btnTogglePass->setChecked(false);
    ui->txtPassword->setEchoMode(QLineEdit::Password);
    ui->btnTogglePass->setText("👁");
}

void LoginWidget::on_btnTogglePass_toggled(bool checked) {
    if (checked) {
        ui->txtPassword->setEchoMode(QLineEdit::Normal);
        ui->btnTogglePass->setText("👁‍🗨");
    } else {
        ui->txtPassword->setEchoMode(QLineEdit::Password);
        ui->btnTogglePass->setText("👁");
    }
}

void LoginWidget::on_btnBack_clicked() {
    ui->txtEmail->clear();
    ui->txtPassword->clear();
    ui->lblError->clear();

    emit backToStartup();
}

void LoginWidget::on_btnConfirm_clicked() {
    QString email = ui->txtEmail->text().trimmed();
    QString pass = ui->txtPassword->text();

    if (email.isEmpty() || pass.isEmpty()) {
        ui->lblError->setText(" Please enter both Email and Password!");
        return;
    }

    ShopSystem* system = ShopSystem::getInstance();
    bool success = false;

    if (currentRole == 1) {
        success = system->loginCustomer(email.toStdString(), pass.toStdString());
    } else {
        success = system->loginStaff(email.toStdString(), pass.toStdString());
    }

    if (success) {
        ui->lblError->clear();
        emit loginSuccess();
    } else {
        ui->lblError->setText(" Incorrect Email or Password. Please try again!");
        ui->txtPassword->clear();
        ui->txtPassword->setFocus();
    }
}
