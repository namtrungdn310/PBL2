#include "StaffDashboard.h"
#include "ui_StaffDashboard.h"
#include <QMessageBox>
#include <QPixmap>
#include <QStyleOption>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

StaffDashboard::StaffDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StaffDashboard)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("StaffDashboard");

    int cardWidth = 420;
    int cardHeight = 550;

    auto setSize = [=](QWidget* w) {
        w->setMinimumSize(cardWidth, cardHeight);
        w->setMaximumSize(cardWidth, cardHeight);
    };
    setSize(ui->frameStack);
    setSize(ui->frameHome);

    if (ui->centerContainer->layout()) {
        ui->centerContainer->layout()->setSpacing(0);
        ui->centerContainer->layout()->setContentsMargins(0, 0, 0, 0);
    }

    QPixmap logo(":/assets/store.png");
    if (!logo.isNull()) {
        QPixmap scaledLogo = logo.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->lblLogo_1->setPixmap(scaledLogo);
        ui->lblLogo_1->setAlignment(Qt::AlignCenter);
        ui->lblLogo_1->setFixedHeight(150);
    } else {
        ui->lblLogo_1->setText("ADMIN LOGO");
        ui->lblLogo_1->setAlignment(Qt::AlignCenter);
    }

    ui->lblSlogan->setText("System Management\nfor Modern Shops");
    ui->lblSlogan->setAlignment(Qt::AlignCenter);
    ui->lblSlogan->setWordWrap(true);

    ui->lblLogo_2->setText("ADMIN MENU");
    ui->lblLogo_2->setAlignment(Qt::AlignCenter);

    QGraphicsDropShadowEffect *shadowRight = new QGraphicsDropShadowEffect(this);
    shadowRight->setBlurRadius(50);
    shadowRight->setColor(QColor(176, 190, 197, 150));
    shadowRight->setOffset(0, 10);
    ui->frameHome->setGraphicsEffect(shadowRight);

    QGraphicsDropShadowEffect *shadowLeft = new QGraphicsDropShadowEffect(this);
    shadowLeft->setBlurRadius(30);
    shadowLeft->setColor(QColor(0, 0, 0, 20));
    shadowLeft->setOffset(0, 5);
    ui->frameStack->setGraphicsEffect(shadowLeft);

    this->setStyleSheet(
        "QWidget#StaffDashboard { "
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
        "       stop:0 #D6F0FD, stop:1 #B3E5FC); "
        "}"
        "QWidget#mainContainer { "
        "   border-radius: 20px; "
        "}"
        "QWidget#headerContainer { "
        "   background-color: rgba(255, 255, 255, 0.95); "
        "   border-bottom: 1px solid #E0E0E0; "
        "}"
        "QLabel#lblWelcome { font-family: 'Segoe UI'; font-size: 16px; font-weight: bold; color: #1565C0; }"
        "QPushButton#btnLogout { "
        "   background-color: transparent; "
        "   border: 1px solid #E74C3C; color: #E74C3C; "
        "   border-radius: 15px; padding: 7px 20px; font-weight: 700; "
        "}"
        "QPushButton#btnLogout:hover { background-color: #E74C3C; color: white; }"
        "QWidget#frameStack { "
        "   background-color: #DEF4FC; "
        "   border-top-left-radius: 20px; "
        "   border-bottom-left-radius: 20px; "
        "   margin: 0px; "

        "   border-right: 2px solid #333333; "
        "}"
        "QWidget#lblLogo_1 { "
        "   margin-bottom: 11px; "
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
        "QWidget#frameHome { "
        "   background-color: #FFFFFF; "
        "   border-top-right-radius: 20px; "
        "   border-bottom-right-radius: 20px; "
        "   margin: 0px; "
        "   border-right: 2px solid #FFFFFF; "
        "   border-top: 2px solid #FFFFFF; "
        "   border-bottom: 2px solid #FFFFFF; "
        "   border-left: none; "
        "}"
        "QLabel#lblLogo_2 { "
        "   font-size: 24px; color: #1565C0; font-weight: 800; "
        "   margin-bottom: 20px;"
        "}"
        "QPushButton#btnEditCategories, QPushButton#btnEditProducts, QPushButton#btnEditPromotions, "
        "QPushButton#btnEditReviews, QPushButton#btnCustomers, QPushButton#btnAnalysis, QPushButton#btnAccountSetting { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border: none; "
        "   border-radius: 22px; "
        "   padding: 12px; "
        "   font-family: 'Segoe UI'; font-size: 15px; font-weight: 700; "
        "   margin-left: 30px; margin-right: 30px; "

        "   margin-bottom: 15px; "
        "}"
        "QPushButton#btnEditCategories:hover, QPushButton#btnEditProducts:hover, QPushButton#btnEditPromotions:hover, "
        "QPushButton#btnEditReviews:hover, QPushButton#btnCustomers:hover, QPushButton#btnAnalysis:hover, QPushButton#btnAccountSetting:hover { "
        "   background-color: #1565C0; "
        "}"
        "QPushButton#btnEditCategories:pressed, QPushButton#btnEditProducts:pressed, QPushButton#btnEditPromotions:pressed, "
        "QPushButton#btnEditReviews:pressed, QPushButton#btnCustomers:pressed, QPushButton#btnAnalysis:pressed, QPushButton#btnAccountSetting:pressed { "
        "   background-color: #0D47A1; "
        "}"
        );

    m_editCategories = new EditCategoriesWidget(this);
    m_editProducts = new EditProductsWidget(this);
    m_editPromotions = new EditPromotionsWidget(this);
    ui->dashboardStack->addWidget(m_editCategories);
    ui->dashboardStack->addWidget(m_editProducts);
    ui->dashboardStack->addWidget(m_editPromotions);
    connect(m_editCategories, &EditCategoriesWidget::backSignal, this, &StaffDashboard::goHome);
    connect(m_editProducts, &EditProductsWidget::backSignal, this, &StaffDashboard::goHome);
    connect(m_editPromotions, &EditPromotionsWidget::backSignal, this, &StaffDashboard::goHome);
    ui->dashboardStack->setCurrentIndex(0);
}

StaffDashboard::~StaffDashboard() {
    delete ui;
}

void StaffDashboard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void StaffDashboard::refreshAccountInfo() {
    Staff* s = system->getCurrentStaff();
    if (s) {
        ui->lblWelcome->setText("Hi, " + QString::fromStdString(s->getName()) +
                                " (" + QString::fromStdString(s->getPosition()) + ")");
    }
}

void StaffDashboard::on_btnLogout_clicked() {
    system->logout();
    emit logoutSignal();
}

void StaffDashboard::goHome() {
    ui->dashboardStack->setCurrentIndex(0);
}

void StaffDashboard::on_btnEditCategories_clicked() {
    m_editCategories->refreshData();
    ui->dashboardStack->setCurrentWidget(m_editCategories);
}

void StaffDashboard::on_btnEditProducts_clicked()   {
    m_editProducts->refreshData();
    ui->dashboardStack->setCurrentWidget(m_editProducts);
}

void StaffDashboard::on_btnEditPromotions_clicked() {
    m_editPromotions->refreshData();
    ui->dashboardStack->setCurrentWidget(m_editPromotions);
}
void StaffDashboard::on_btnEditReviews_clicked()    { QMessageBox::information(this, "Admin", "Edit Reviews"); }
void StaffDashboard::on_btnCustomers_clicked()      { QMessageBox::information(this, "Admin", "Customers Management"); }
void StaffDashboard::on_btnAnalysis_clicked()       { QMessageBox::information(this, "Admin", "Shop Analysis"); }
void StaffDashboard::on_btnAccountSetting_clicked() { QMessageBox::information(this, "Admin", "Account Setting"); }
