#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <QWidget>
#include "include/ShopSystem.h"
#include "ViewProductsWidget.h"
#include "ViewCartWidget.h"
#include "OrderWidget.h"
#include "OrderHistoryWidget.h"
#include "PromotionsWidget.h"
#include "ReviewsWidget.h"
#include "AccountSettingsWidget.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class CustomerDashboard; }

class CustomerDashboard : public QWidget {
    Q_OBJECT

public:
    explicit CustomerDashboard(QWidget *parent = nullptr);
    ~CustomerDashboard();

    void refreshAccountInfo();
    void paintEvent(QPaintEvent *event) override;

signals:
    void logoutSignal();

private slots:
    void on_btnLogout_clicked();
    void on_btnProducts_clicked();
    void on_btnCart_clicked();
    void on_btnOrders_clicked();
    void on_btnPromos_clicked();
    void on_btnReviews_clicked();
    void showOrderPage();
    void showCartPage();
    void on_btnSetting_clicked();
    void goHome();

private:
    Ui::CustomerDashboard *ui;
    ShopSystem* system;
    ViewProductsWidget *m_viewProducts;
    ViewCartWidget *m_viewCart;
    OrderWidget *m_orderWidget;
    OrderHistoryWidget *m_historyWidget;
    PromotionsWidget *m_promotionsWidget;
    ReviewsWidget *m_reviewsWidget;
    AccountSettingsWidget *m_settingsWidget;
};

#endif
