#include "CustomerDashboard.h"
#include "ui_CustomerDashboard.h"
#include <QMessageBox>
#include <QPixmap>
#include <QStyleOption>
#include <QPainter>

CustomerDashboard::CustomerDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDashboard)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("CustomerDashboard");

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
        ui->lblLogo_1->setText("SHOP LOGO");
        ui->lblLogo_1->setAlignment(Qt::AlignCenter);
    }

    ui->lblSlogan->setText("Smart Management\nfor Modern Shops");
    ui->lblSlogan->setAlignment(Qt::AlignCenter);
    ui->lblSlogan->setWordWrap(true);

    ui->lblLogo_2->setText("MENU");
    ui->lblLogo_2->setAlignment(Qt::AlignCenter);

    this->setStyleSheet(
        "QWidget#CustomerDashboard { "
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

        "QLabel#lblPoints { "
        "   font-family: 'Segoe UI'; font-size: 15px; font-weight: 700; "
        "   color: #D32F2F; "
        "   background-color: #FFEBEE; "
        "   padding: 5px 15px; border-radius: 15px; margin-left: 10px; "
        "}"

        "QPushButton#btnLogout { "
        "   background-color: transparent; "
        "   border: 2px solid #E74C3C; color: #E74C3C; "
        "   border-radius: 15px; padding: 7px 20px; font-weight: 700; "
        "}"

        "QPushButton#btnLogout:hover { background-color: #E74C3C; color: white; }"

        "QWidget#frameStack { "
        "   background-color: #DEF4FC; "
        "   border-top-left-radius: 20px; "
        "   border-bottom-left-radius: 20px; "
        "   margin: 0px; "
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
        "   border-top: 2px solid #FFFFFF; "
        "   border-bottom: 2px solid #FFFFFF; "
        "   border-left: none; "
        "}"

        "QLabel#lblLogo_2 { "
        "   font-size: 24px; color: #1565C0; font-weight: 800; margin-bottom: 60px;"
        "}"

        "QPushButton#btnProducts, QPushButton#btnCart, QPushButton#btnOrders, QPushButton#btnPromos, QPushButton#btnReviews, QPushButton#btnReviews, QPushButton#btnSetting  { "
        "   background-color: #1976D2; "
        "   color: white; "
        "   border: none; "
        "   border-radius: 22px; "
        "   padding: 12px; "
        "   font-family: 'Segoe UI'; font-size: 15px; font-weight: 700; "
        "   margin-left: 30px; margin-right: 30px; margin-bottom: 27px; "
        "}"

        "QPushButton#btnProducts:hover, QPushButton#btnCart:hover, QPushButton#btnOrders:hover, "
        "QPushButton#btnPromos:hover, QPushButton#btnReviews:hover, QPushButton#btnSetting:hover { "
        "   background-color: #1565C0; "
        "}"

        "QPushButton#btnProducts:pressed, QPushButton#btnCart:pressed, QPushButton#btnOrders:pressed, "
        "QPushButton#btnPromos:pressed, QPushButton#btnReviews:pressed, QPushButton#btnSetting:pressed { "
        "   background-color: #0D47A1; "
        "}"
        );
    m_viewProducts = new ViewProductsWidget(this);
    m_viewCart = new ViewCartWidget(this);
    m_orderWidget = new OrderWidget(this);
    m_historyWidget = new OrderHistoryWidget(this);
    m_promotionsWidget = new PromotionsWidget(this);
    m_reviewsWidget = new ReviewsWidget(this);
    m_settingsWidget = new AccountSettingsWidget(this);

    ui->dashboardStack->addWidget(m_orderWidget);
    ui->dashboardStack->addWidget(m_viewProducts);
    ui->dashboardStack->addWidget(m_viewCart);
    ui->dashboardStack->addWidget(m_historyWidget);
    ui->dashboardStack->addWidget(m_promotionsWidget);
    ui->dashboardStack->addWidget(m_reviewsWidget);
    ui->dashboardStack->addWidget(m_settingsWidget);

    connect(m_viewProducts, &ViewProductsWidget::backSignal, this, &CustomerDashboard::goHome); //kết nối nút back về menu
    connect(m_viewCart, &ViewCartWidget::backSignal, this, &CustomerDashboard::goHome);
    connect(m_viewCart, &ViewCartWidget::goToCheckout, this, &CustomerDashboard::showOrderPage);
    connect(m_orderWidget, &OrderWidget::backSignal, this, &CustomerDashboard::showCartPage);
    connect(m_orderWidget, &OrderWidget::orderCompleted, this, &CustomerDashboard::goHome);
    connect(m_historyWidget, &OrderHistoryWidget::backSignal, this, &CustomerDashboard::goHome);
    connect(m_promotionsWidget, &PromotionsWidget::backSignal, this, &CustomerDashboard::goHome);
    connect(m_reviewsWidget, &ReviewsWidget::backSignal, this, &CustomerDashboard::goHome);
    connect(m_settingsWidget, &AccountSettingsWidget::backSignal, this, &CustomerDashboard::goHome);
    connect(m_settingsWidget, &AccountSettingsWidget::accountDeleted, this, &CustomerDashboard::logoutSignal);

    ui->dashboardStack->setCurrentIndex(0);
}

CustomerDashboard::~CustomerDashboard() { delete ui; }

void CustomerDashboard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CustomerDashboard::refreshAccountInfo() {
    Customer* c = system->getCurrentCustomer();
    if (c) {
        ui->lblWelcome->setText("Hi, " + QString::fromStdString(c->getName()));
        ui->lblPoints->setText(QString::number(c->getLoyaltyPoints()) + " pts");
    }
}

void CustomerDashboard::on_btnLogout_clicked() {
    system->logout();
    emit logoutSignal();
}

void CustomerDashboard::goHome() {
    ui->dashboardStack->setCurrentIndex(0);
    refreshAccountInfo();
}

void CustomerDashboard::on_btnProducts_clicked() {
    m_viewProducts->refreshData();
    ui->dashboardStack->setCurrentWidget(m_viewProducts);
}
void CustomerDashboard::on_btnCart_clicked()     {
        m_viewCart->refreshCart();
        ui->dashboardStack->setCurrentWidget(m_viewCart);
}
void CustomerDashboard::showOrderPage() {
    m_orderWidget->loadOrderData();
    ui->dashboardStack->setCurrentWidget(m_orderWidget);
}

void CustomerDashboard::showCartPage() {
    ui->dashboardStack->setCurrentWidget(m_viewCart);
}
void CustomerDashboard::on_btnOrders_clicked()   {
    m_historyWidget->loadHistory();
    ui->dashboardStack->setCurrentWidget(m_historyWidget);
}
void CustomerDashboard::on_btnPromos_clicked()   {
    m_promotionsWidget->loadPromotions();
    ui->dashboardStack->setCurrentWidget(m_promotionsWidget);
}
void CustomerDashboard::on_btnReviews_clicked()  {
    m_reviewsWidget->refreshData();
    ui->dashboardStack->setCurrentWidget(m_reviewsWidget);
}
void CustomerDashboard::on_btnSetting_clicked()  {
    m_settingsWidget->loadUserData();
    ui->dashboardStack->setCurrentWidget(m_settingsWidget);
}
