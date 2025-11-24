#include "PromotionsWidget.h"
#include "ui_PromotionsWidget.h"
#include <QGraphicsDropShadowEffect>
#include <QLabel>

PromotionsWidget::PromotionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PromotionsWidget)
{
    ui->setupUi(this);
    system = ShopSystem::getInstance();
    this->setObjectName("PromotionsWidget");

    setupStyle();
}

PromotionsWidget::~PromotionsWidget() {
    delete ui;
}

void PromotionsWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QStyleOption opt; opt.initFrom(this); QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void PromotionsWidget::loadPromotions() {
    QLayout* layout = ui->scrollContent->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    Customer* c = system->getCurrentCustomer();
    const auto& promos = system->getPromotions();

    int visibleCount = 0;

    for (const auto& p : promos) {
        bool isNotExpired = p.isValid();
        bool isNotUsed = true;
        if (c) {
            if (c->hasUsedPromo(p.getPromoId())) {
                isNotUsed = false;
            }
        }
        if (isNotExpired && isNotUsed) {
            createPromoCard(p);
            visibleCount++;
        }
    }

    if (visibleCount == 0) {
        QLabel* emptyLbl = new QLabel("No available promotions.\nYou have used them all or they expired.", ui->scrollContent);
        emptyLbl->setAlignment(Qt::AlignCenter);
        emptyLbl->setStyleSheet("font-size: 16px; color: #777; margin-top: 50px;");
        layout->addWidget(emptyLbl);
    }

    static_cast<QVBoxLayout*>(layout)->addStretch();
}

void PromotionsWidget::createPromoCard(const Promotion& promo) {
    QFrame* card = new QFrame(ui->scrollContent);
    card->setObjectName("PromoCard");
    card->setStyleSheet(
        "QFrame#PromoCard { "
        "   background-color: #FFFFFF; "
        "   border: 1px solid #E0E0E0; "
        "   border-radius: 15px; "
        "   border-left: 5px solid #E91E63; "
        "}"
        );

    QHBoxLayout* mainLayout = new QHBoxLayout(card);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(20);

    QLabel* lblPercent = new QLabel(QString::number(promo.getDiscountRate() * 100) + "%", card);
    lblPercent->setStyleSheet(
        "font-size: 32px; font-weight: 900; color: #E91E63;"
        "font-family: 'Segoe UI Black';"
        );
    lblPercent->setAlignment(Qt::AlignCenter);
    lblPercent->setFixedWidth(100);

    QVBoxLayout* infoLayout = new QVBoxLayout();

    QLabel* lblName = new QLabel(QString::fromStdString(promo.getName()), card);
    lblName->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");

    QLabel* lblCond = new QLabel("Condition: " + QString::fromStdString(promo.getCondition()), card);
    lblCond->setStyleSheet("font-size: 14px; color: #666;");
    lblCond->setWordWrap(true);

    infoLayout->addWidget(lblName);
    infoLayout->addWidget(lblCond);

    mainLayout->addWidget(lblPercent);
    mainLayout->addLayout(infoLayout);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(card);
    shadow->setBlurRadius(20);
    shadow->setColor(QColor(0, 0, 0, 30));
    shadow->setOffset(0, 5);
    card->setGraphicsEffect(shadow);

    ui->scrollContent->layout()->addWidget(card);
}

void PromotionsWidget::on_btnBack_clicked() {
    emit backSignal();
}

void PromotionsWidget::setupStyle() {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(40);
    shadow->setColor(QColor(0, 0, 0, 50));
    shadow->setOffset(0, 10);
    ui->contentContainer->setGraphicsEffect(shadow);

    this->setStyleSheet(
        "QWidget { color: #333333; font-family: 'Segoe UI'; }"
        "QWidget#PromotionsWidget { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D6F0FD, stop:1 #B3E5FC); }"

        "QWidget#contentContainer { "
        "   background-color: #FFFFFF; "
        "   border-radius: 20px; "
        "   border: 1px solid #E0E0E0; "
        "}"

        "QLabel#lblTitle { font-size: 28px; font-weight: 800; color: #E91E63; margin-bottom: 10px; margin-top: 10px; }"

        "QScrollArea { background: transparent; border: none; }"
        "QWidget#scrollContent { background: transparent; }"
        "QScrollBar:vertical { border: none; background: #F0F0F0; width: 8px; margin: 0px; border-radius: 4px; }"
        "QScrollBar::handle:vertical { background: #BDC3C7; min-height: 20px; border-radius: 4px; }"

        "QPushButton#btnBack { "
        "   background-color: #FFFFFF; border: 2px solid #E91E63; color: #E91E63; "
        "   border-radius: 20px; padding: 10px 30px; font-weight: bold; margin-top: 10px; margin-bottom: 10px;"
        "}"
        "QPushButton#btnBack:hover { background-color: #FCE4EC; }"
        );
}
