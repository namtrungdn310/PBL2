#ifndef STAFFDASHBOARD_H
#define STAFFDASHBOARD_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>
#include "EditCategoriesWidget.h"
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

    // Slots cho 7 nút menu
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
};

#endif // STAFFDASHBOARD_H
