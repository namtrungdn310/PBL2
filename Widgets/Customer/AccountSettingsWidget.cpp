#include "AccountSettingsWidget.h"
#include "ui_AccountSettingsWidget.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

AccountSettingsWidget::AccountSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountSettingsWidget)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("AccountSettingsWidget");

    setupStyle();
}

AccountSettingsWidget::~AccountSettingsWidget() {
    delete ui;
}

void AccountSettingsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void AccountSettingsWidget::loadUserData() {
    Customer* c = system->getCurrentCustomer();
    if (c) {
        ui->lblCurrentEmail->setText("Email: " + QString::fromStdString(c->getEmail()));
        ui->lblCurrentPhone->setText("Phone: " + QString::fromStdString(c->getPhone()));

        ui->txtFullName->clear();
        ui->txtAddress->clear();
        ui->txtPassword->clear();

        ui->txtFullName->setPlaceholderText(QString::fromStdString(c->getName()));
        ui->txtAddress->setPlaceholderText(QString::fromStdString(c->getAddress()));
    }
}

void AccountSettingsWidget::on_btnConfirm_clicked() {
    Customer* c = system->getCurrentCustomer();
    if (!c) return;

    QString newName = ui->txtFullName->text().trimmed();
    QString newAddr = ui->txtAddress->text().trimmed();
    QString newPass = ui->txtPassword->text();

    if (newName.isEmpty() && newAddr.isEmpty() && newPass.isEmpty()) {
        QMessageBox::information(this, "Info", "No changes were made.");
        return;
    }

    bool updated = false;
    if (!newName.isEmpty()) { c->setName(newName.toStdString()); updated = true; }
    if (!newAddr.isEmpty()) { c->setAddress(newAddr.toStdString()); updated = true; }
    if (!newPass.isEmpty()) { c->setPassword(newPass.toStdString()); updated = true; }

    if (updated) {
        system->saveAllData();
        QMessageBox::information(this, "Success", "Information updated successfully!");
        emit backSignal();
    }
}

void AccountSettingsWidget::on_btnDelete_clicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Account",
                                  "Are you sure you want to delete your account?\nThis action cannot be undone.",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        system->deleteCurrentCustomer();
        QMessageBox::information(this, "Deleted", "Your account has been deleted.");
        emit accountDeleted();
    }
}

void AccountSettingsWidget::on_btnBack_clicked() {
    emit backSignal();
}

void AccountSettingsWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333; font-family: 'Segoe UI'; }"
        "QWidget#AccountSettingsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 20px; border: 1px solid #E0E0E0; }"

        "QLabel#lblTitle { font-size: 24px; font-weight: 800; color: #1565C0; margin-bottom: 5px; }"
        "QLabel#lblSubtitle { font-size: 13px; color: #777; margin-bottom: 20px; }"
        "QLabel#lblCurrentInfoTitle { font-size: 14px; font-weight: bold; color: #555; margin-top: 20px; }"
        "QLabel#lblCurrentEmail, QLabel#lblCurrentPhone { font-size: 13px; color: #333; padding: 5px; background: #F5F7F9; border-radius: 5px; }"

        "QLabel#lblEditInfo { font-size: 18px; font-weight: bold; color: #1565C0; margin-bottom: 15px; }"
        "QLabel { font-size: 13px; font-weight: 600; color: #444; }"

        "QLineEdit { background-color: #F5F7F9; border: 1px solid #E0E0E0; border-radius: 8px; padding: 8px; color: #333; font-size: 13px; }"
        "QLineEdit:focus { border: 2px solid #1976D2; background: #FFF; }"

        "QPushButton {border-radius: 18px; padding: 10px; font-weight: bold; font-size: 13px; }"

        "QPushButton#btnConfirm { background-color: #1976D2; color: white; margin-bottom: 5px; }"
        "QPushButton#btnConfirm:hover { background-color: #1565C0; }"

        "QPushButton#btnDelete { background-color: #D32F2F; color: white; margin-bottom: 5px; }"
        "QPushButton#btnDelete:hover { background-color: #C62828; }"

        "QPushButton#btnBack { background-color: #FFF; border: 2px solid #95A5A6; color: #7F8C8D; }"
        "QPushButton#btnBack:hover { background-color: #F0F0F0; }"

        "Line#lineSeparator { border: 1px solid #EEEEEE; }"
        "QMessageBox { "
        "   background-color: #34495E; "
        "   border: 2px solid #1976D2; "
        "}"
        "QMessageBox QLabel { "
        "   color: #FFFFFF; "
        "   font-size: 14px; "
        "   font-weight: bold; "
        "}"
        "QMessageBox QPushButton { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border-radius: 5px; "
        "   padding: 5px 15px; "
        "   min-width: 60px; "
        "}"
        "QMessageBox QPushButton:hover { "
        "   background-color: #1565C0; "
        "}"
        );
}
