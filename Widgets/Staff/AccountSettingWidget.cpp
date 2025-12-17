#include "AccountSettingWidget.h"
#include "ui_AccountSettingWidget.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

AccountSettingWidget::AccountSettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountSettingWidget),
    currentEditingId(-1)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();

    connect(ui->btnBack, &QPushButton::clicked, this, &AccountSettingWidget::backSignal);

    ui->cboEditRole->setEditable(true);

    setupStyle();
}

AccountSettingWidget::~AccountSettingWidget() {
    delete ui;
}

void AccountSettingWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    refreshData();
}

void AccountSettingWidget::refreshData() {
    Staff* s = system->getCurrentStaff();
    if (!s) return;

    ui->lblName->setText(QString::fromStdString(s->getName()));
    ui->lblRole->setText(QString::fromStdString(s->getPosition()));
    QString name = QString::fromStdString(s->getName());
    ui->lblAvatar->setText(name.isEmpty() ? "?" : name.left(1).toUpper());

    ui->txtCurrentPass->clear();
    ui->txtNewPass->clear();
    ui->txtConfirmPass->clear();

    QString position = QString::fromStdString(s->getPosition());
    bool isManager = (position == "Manager" || position == "Admin");

    ui->tabWidget->setTabVisible(1, isManager);

    if (isManager) {
        loadStaffList();
        on_btnAddNew_clicked();
    } else {
        ui->lstStaff->clear();
        ui->txtEditName->clear();
        ui->txtEditEmail->clear();
        ui->lblEditId->setText("Restricted");
    }
}

void AccountSettingWidget::loadStaffList() {
    ui->lstStaff->clear();
    for(const auto& s : system->getStaffList()) {
        QString label = QString::number(s.getUserId()) + " - " + QString::fromStdString(s.getName());
        QListWidgetItem* item = new QListWidgetItem(label);
        item->setData(Qt::UserRole, s.getUserId());
        ui->lstStaff->addItem(item);
    }
}

void AccountSettingWidget::on_btnUpdatePass_clicked() {
    Staff* s = system->getCurrentStaff();
    if (!s) return;

    if (ui->txtCurrentPass->text().toStdString() != s->getPassword()) {
        QMessageBox::warning(this, "Error", "Current password is incorrect.");
        return;
    }
    if (ui->txtNewPass->text().length() < 6) {
        QMessageBox::warning(this, "Error", "New password is too short (minimum 6 characters).");
        return;
    }
    if (ui->txtNewPass->text() != ui->txtConfirmPass->text()) {
        QMessageBox::warning(this, "Error", "Password confirmation does not match.");
        return;
    }

    s->setPassword(ui->txtNewPass->text().toStdString());
    system->saveAllData();
    QMessageBox::information(this, "Success", "Password updated successfully!");

    ui->txtCurrentPass->clear();
    ui->txtNewPass->clear();
    ui->txtConfirmPass->clear();
}

void AccountSettingWidget::on_btnBack_clicked() {
    emit backSignal();
}

void AccountSettingWidget::on_btnAddNew_clicked() {
    currentEditingId = -1;
    ui->lblEditId->setText("ID: [New]");
    ui->txtEditName->clear();
    ui->txtEditEmail->clear();
    ui->txtEditPass->clear();
    ui->txtEditPass->setPlaceholderText("Required for new account");
    ui->cboEditRole->setCurrentIndex(1);

    ui->btnSaveStaff->setText("Create Account");
    ui->btnDeleteStaff->setEnabled(false);
    ui->lstStaff->clearSelection();
}

void AccountSettingWidget::on_lstStaff_itemClicked(QListWidgetItem *item) {
    int id = item->data(Qt::UserRole).toInt();
    currentEditingId = id;

    ui->btnDeleteStaff->setEnabled(true);
    ui->lblEditId->setText("Change ID: " + QString::number(id));
    ui->btnSaveStaff->setText("Update");

    for(const auto& s : system->getStaffList()) {
        if(s.getUserId() == id) {
            ui->txtEditName->setText(QString::fromStdString(s.getName()));
            ui->txtEditEmail->setText(QString::fromStdString(s.getEmail()));
            ui->txtEditPass->clear();
            ui->txtEditPass->setPlaceholderText("Leave empty to keep current password");
            ui->cboEditRole->setCurrentText(QString::fromStdString(s.getPosition()));
            break;
        }
    }
}

int AccountSettingWidget::getNextStaffId() {
    int maxId = 0;
    for(const auto& s : system->getStaffList()) {
        if(s.getUserId() > maxId) maxId = s.getUserId();
    }
    return maxId + 1;
}

void AccountSettingWidget::on_btnSaveStaff_clicked() {
    QString name = ui->txtEditName->text().trimmed();
    QString email = ui->txtEditEmail->text().trimmed();
    QString pass = ui->txtEditPass->text();
    QString position = ui->cboEditRole->currentText().trimmed();
    if(position.isEmpty()) position = "Staff";

    int roleId = (position == "Manager" || position == "Admin") ? 1 : 2;

    if(name.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Name and Email cannot be empty.");
        return;
    }

    if (currentEditingId == -1) {
        if(pass.isEmpty()) {
            QMessageBox::warning(this, "Error", "Password is required for new account.");
            return;
        }
        int newId = getNextStaffId();
        Staff newStaff(newId, name.toStdString(), email.toStdString(), pass.toStdString(), roleId, position.toStdString());
        system->addStaff(newStaff);

        QMessageBox::information(this, "Success", "New account created successfully!");
        loadStaffList();
        currentEditingId = newId;
        for(int i=0; i < ui->lstStaff->count(); ++i) {
            if(ui->lstStaff->item(i)->data(Qt::UserRole).toInt() == newId) {
                ui->lstStaff->setCurrentRow(i);
                on_lstStaff_itemClicked(ui->lstStaff->item(i));
                break;
            }
        }
    } else {
        string finalPass = "";
        for(const auto& s : system->getStaffList()) {
            if(s.getUserId() == currentEditingId) {
                finalPass = s.getPassword();
                break;
            }
        }
        if(!pass.isEmpty()) finalPass = pass.toStdString();

        Staff updatedStaff(currentEditingId, name.toStdString(), email.toStdString(), finalPass, roleId, position.toStdString());
        system->updateStaff(updatedStaff);

        QMessageBox::information(this, "Success", "Account updated successfully!");
        loadStaffList();
        for(int i=0; i < ui->lstStaff->count(); ++i) {
            if(ui->lstStaff->item(i)->data(Qt::UserRole).toInt() == currentEditingId) {
                ui->lstStaff->setCurrentRow(i);
                break;
            }
        }
    }
}

void AccountSettingWidget::on_btnDeleteStaff_clicked() {
    if(currentEditingId == -1) return;
    if(currentEditingId == system->getCurrentStaff()->getUserId()) {
        QMessageBox::warning(this, "Lỗi", "Không thể tự xóa tài khoản đang đăng nhập!");
        return;
    }

    if(QMessageBox::Yes == QMessageBox::question(this, "Xác nhận", "Xóa vĩnh viễn tài khoản này?", QMessageBox::Yes|QMessageBox::No)) {
        system->removeStaff(currentEditingId);
        loadStaffList();
        on_btnAddNew_clicked();
    }
}

void AccountSettingWidget::setupStyle() {
    this->setAttribute(Qt::WA_StyledBackground, true);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40); shadow->setColor(QColor(0, 0, 0, 40)); shadow->setOffset(0, 8);
    ui->mainCard->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { font-family: 'Segoe UI'; font-size: 14px; }"
        "QWidget#AccountSettingWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"
        "QFrame#mainCard { background-color: #FFFFFF; border-radius: 15px; }"

        "QLineEdit, QComboBox { "
        "   background-color: #FFFFFF; border: 1px solid #BDC3C7; border-radius: 8px; padding: 10px; color: #333333; font-size: 14px; "
        "}"
        "QLineEdit:focus, QComboBox:focus { border: 2px solid #1976D2; }"

        "QComboBox::drop-down { border: 0px; }"
        "QComboBox QAbstractItemView { background-color: #FFFFFF; color: #333333; selection-background-color: #E3F2FD; selection-color: #1976D2; outline: 0; }"

        "QLabel { color: #555555; font-weight: 600; }"
        "QLabel#lblEditId { color: #1976D2; font-weight: bold; }"
        "QLabel#lblName { color: #333; font-size: 24px; font-weight: 800; margin-top: 15px; }"

        "QLabel#lblRole { font-size: 16px; font-weight: bold; color: #1976D2; background: #E3F2FD; padding: 8px 15px; border-radius: 15px; }"

        "QPushButton { background-color: #1976D2; color: white; border-radius: 8px; padding: 10px 20px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1565C0; }"

        "QPushButton#btnBack { background-color: transparent; border: none; color: #555; font-size: 15px; font-weight: bold; text-align: left; padding: 0px; }"
        "QPushButton#btnBack:hover { color: #1976D2; }"

        "QPushButton#btnDeleteStaff { background-color: #FFEBEE; color: #C62828; border: 1px solid #EF5350; }"
        "QPushButton#btnDeleteStaff:hover { background-color: #FFCDD2; }"

        "QTabWidget::pane { border: 1px solid #DDD; background: #FFF; border-radius: 10px; }"
        "QTabBar::tab { background: #F8F9FA; color: #666; padding: 10px 20px; border-top-left-radius: 5px; border-top-right-radius: 5px; margin-right: 2px; }"
        "QTabBar::tab:selected { background: #FFF; color: #1976D2; font-weight: bold; border-bottom: 2px solid #1976D2; }"

        "QListWidget { border: 1px solid #DDD; border-radius: 8px; padding: 5px; outline: 0; }"
        "QListWidget::item { padding: 10px; border-radius: 5px; color: #333; margin-bottom: 2px; }"
        "QListWidget::item:selected { background: #E3F2FD; color: #1565C0; font-weight: bold; }"
        "QLabel#lblAvatar { background-color: #1976D2; color: white; font-size: 70px; font-weight: bold; border-radius: 90px; }"
        );
}
