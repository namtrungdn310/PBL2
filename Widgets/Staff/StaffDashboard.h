#ifndef STAFFDASHBOARD_H
#define STAFFDASHBOARD_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>
#include "EditCategoriesWidget.h"
#include "EditProductsWidget.h"
#include "EditPromotionsWidget.h"
#include "EditReviewsWidget.h"
#include "CustomersManagementWidget.h"
#include "ShopAnalysisWidget.h"
#include "AccountSettingWidget.h"
namespace Ui { class StaffDashboard; }

class StaffDashboard : public QWidget {
    Q_OBJECT

public:
    explicit StaffDashboard(QWidget *parent = nullptr);
    ~StaffDashboard();

    void refreshAccountInfo();
    void paintEvent(QPaintEvent *event) override;

signals:
    void logoutSignal();

private slots:
    void on_btnLogout_clicked();
    void goHome();

    void on_btnEditCategories_clicked();
    void on_btnEditProducts_clicked();
    void on_btnEditPromotions_clicked();
    void on_btnEditReviews_clicked();
    void on_btnCustomers_clicked();
    void on_btnAnalysis_clicked();
    void on_btnAccountSetting_clicked();

private:
    Ui::StaffDashboard *ui;
    ShopSystem* system;
    EditCategoriesWidget *m_editCategories;
    EditProductsWidget *m_editProducts;
    EditPromotionsWidget *m_editPromotions;
    EditReviewsWidget *m_editReviews;
    CustomersManagementWidget *m_customersManagement;
    ShopAnalysisWidget *m_shopAnalysis;
    AccountSettingWidget *m_accountSetting;
};

#endif
