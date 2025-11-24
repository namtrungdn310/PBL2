#include "RegisterWidget.h"
#include "ui_RegisterWidget.h"
#include "include/ShopSystem.h"
#include <QGraphicsDropShadowEffect>
#include <QPixmap>
#include <QStyleOption>
#include <QPainter>
#include <QRegularExpression>
#include <QTimer>

RegisterWidget::RegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);
    this->setObjectName("RegisterScreen");

    int cardWidth = 420;
    int cardHeight = 550;

    auto setSize = [=](QWidget* w) {
        w->setMinimumSize(cardWidth, cardHeight);
        w->setMaximumSize(cardWidth, cardHeight);
    };
    setSize(ui->leftPanel_2);
    setSize(ui->frameCard_2);

    QPixmap logo(":/assets/products.png");
    if (!logo.isNull()) {
        QPixmap scaledLogo = logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->lblLogo_2->setPixmap(scaledLogo);
        ui->lblLogo_2->setAlignment(Qt::AlignCenter);
        ui->lblLogo_2->setFixedHeight(150);
    } else {
        ui->lblLogo_2->setText("SHOP LOGO");
        ui->lblLogo_2->setAlignment(Qt::AlignCenter);
    }

    ui->txtFullName->setPlaceholderText("Enter your Full Name");
    ui->txtEmail_2->setPlaceholderText("Enter your Email");
    ui->txtPassword_2->setPlaceholderText("Enter your Password");
    ui->txtAdress->setPlaceholderText("Enter your Address");
    ui->txtPhoneNumber->setPlaceholderText("Enter your Phone Number");

    ui->lblError_2->clear();
    ui->lblError_2->setAlignment(Qt::AlignCenter);

    QGraphicsDropShadowEffect *shadowRight = new QGraphicsDropShadowEffect(this);
    shadowRight->setBlurRadius(50);
    shadowRight->setColor(QColor(176, 190, 197, 150));
    shadowRight->setOffset(0, 10);
    ui->frameCard_2->setGraphicsEffect(shadowRight);

    QGraphicsDropShadowEffect *shadowLeft = new QGraphicsDropShadowEffect(this);
    shadowLeft->setBlurRadius(30);
    shadowLeft->setColor(QColor(0, 0, 0, 20));
    shadowLeft->setOffset(0, 5);
    ui->leftPanel_2->setGraphicsEffect(shadowLeft);

    this->setStyleSheet(
        "QWidget#RegisterScreen { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "       stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"

        "QWidget#mainContainer { background: transparent; }"

        "QWidget#lblLogo_2 { "
        "   margin-bottom: 12px; "
        "}"

        "QWidget#leftPanel_2 { "
        "   background-color: rgba(255, 255, 255, 120); "
        "   border-radius: 20px; "
        "   margin-right: 5px; "
        "}"

        "QLabel#label { "
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

        "QFrame#frameCard_2 { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   margin-left: 5px; "
        "}"

        "QLabel#lblTitle_2 { "
        "   font-family: 'Segoe UI', sans-serif; "
        "   font-size: 30px; "
        "   font-weight: 800; "
        "   color: #1565C0; "
        "   min-height: 40px; "
        "   max-height: 40px; "
        "   qproperty-alignment: AlignCenter; "
        "   margin-bottom: 0px; "
        "   margin-top: 20px; "
        "   padding-bottom: 0px; "
        "   background: transparent; "
        "}"

        "QLineEdit#txtFullName, QLineEdit#txtEmail_2, QLineEdit#txtPassword_2, "
        "QLineEdit#txtAdress, QLineEdit#txtPhoneNumber { "
        "   background-color: #F5F7F9; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 10px; "
        "   padding: 11px 15px; "
        "   font-family: 'Segoe UI'; "
        "   font-size: 14px; "
        "   color: #333; "
        "   margin-left: 40px; "
        "   margin-right: 40px; "
        "   margin-bottom: 10px; "
        "   min-height: 21px; "
        "   max-height: 21px; "
        "}"

        "QLineEdit#txtFullName:focus, QLineEdit#txtEmail_2:focus, "
        "QLineEdit#txtPassword_2:focus, QLineEdit#txtAdress:focus, "
        "QLineEdit#txtPhoneNumber:focus { "
        "   background-color: #FFFFFF; "
        "   border: 2px solid #1976D2; "
        "}"

        "QLineEdit#txtFullName { "
        "   margin-top: 15px; "
        "}"

        "QLabel#lblError_2 { "
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

        "QPushButton#btnConfirm_2 { "
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
        "   margin-top: 10px; "
        "   margin-bottom: 10px; "
        "}"

        "QPushButton#btnConfirm_2:hover { "
        "   background-color: #1565C0; "
        "}"
        "QPushButton#btnConfirm_2:pressed { "
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
        "   margin-bottom: 20px; "
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

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool RegisterWidget::isValidEmail(const QString &email)
{
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

bool RegisterWidget::validateInputs()
{
    QString fullName = ui->txtFullName->text().trimmed();
    QString email    = ui->txtEmail_2->text().trimmed();
    QString password = ui->txtPassword_2->text();
    QString address  = ui->txtAdress->text().trimmed();
    QString phone    = ui->txtPhoneNumber->text().trimmed();

    if (fullName.isEmpty() || email.isEmpty() || password.isEmpty() ||
        address.isEmpty()  || phone.isEmpty())
    {
        ui->lblError_2->setText("Please enter all the information!");
        return false;
    }

    if (!isValidEmail(email)) {
        ui->lblError_2->setText("Please enter a valid Email address!");
        ui->txtEmail_2->setFocus();
        return false;
    }

    if (password.length() < 6) {
        ui->lblError_2->setText("Password must be at least 6 characters!");
        ui->txtPassword_2->setFocus();
        return false;
    }

    QRegularExpression phoneRegex("^[0-9]{8,11}$");
    if (!phoneRegex.match(phone).hasMatch()) {
        ui->lblError_2->setText("Phone number must be 8-11 digits!");
        ui->txtPhoneNumber->setFocus();
        return false;
    }

    return true;
}

void RegisterWidget::clearAllFields()
{
    ui->txtFullName->clear();
    ui->txtEmail_2->clear();
    ui->txtPassword_2->clear();
    ui->txtAdress->clear();
    ui->txtPhoneNumber->clear();
    ui->lblError_2->clear();
}

void RegisterWidget::on_btnConfirm_2_clicked()
{
    if (!validateInputs()) {
        return;
    }

    QString fullName = ui->txtFullName->text().trimmed();
    QString email = ui->txtEmail_2->text().trimmed();
    QString password = ui->txtPassword_2->text();
    QString address = ui->txtAdress->text().trimmed();
    QString phone = ui->txtPhoneNumber->text().trimmed();

    ShopSystem* system = ShopSystem::getInstance();

    int result = system->registerNewCustomer(
        fullName.toStdString(),
        email.toStdString(),
        password.toStdString(),
        address.toStdString(),
        phone.toStdString()
        );

    if (result == 0) {
        clearAllFields();
        ui->lblError_2->setStyleSheet("QLabel { color: #4CAF50; }");
        ui->lblError_2->setText("✓ Registration successful! Redirecting...");

        QTimer::singleShot(1500, this, [this]() {
            ui->lblError_2->setStyleSheet("");
            emit registerSuccess();
        });
    }
    else if (result == 1) {
        ui->lblError_2->setStyleSheet("QLabel { color: #D32F2F; }");
        ui->lblError_2->setText("Error: This Email is already registered!");
        ui->txtEmail_2->setFocus();
    }
    else if (result == 2) {
        ui->lblError_2->setStyleSheet("QLabel { color: #D32F2F; }");
        ui->lblError_2->setText("Error: This Phone Number is already in use!");
        ui->txtPhoneNumber->setFocus();
    }
}

void RegisterWidget::on_btnBack_clicked()
{
    clearAllFields();
    emit backToStartup();
}
