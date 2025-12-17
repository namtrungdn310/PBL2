#ifndef SHOPANALYSISWIDGET_H
#define SHOPANALYSISWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class ShopAnalysisWidget; }

class ShopAnalysisWidget : public QWidget {
    Q_OBJECT

public:
    explicit ShopAnalysisWidget(QWidget *parent = nullptr);
    ~ShopAnalysisWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_cboFilter_currentIndexChanged(int index);

private:
    Ui::ShopAnalysisWidget *ui;
    ShopSystem* system;

    void setupStyle();
    QString formatMoney(double amount);

    void calculateKPIs();
    void loadProductPerformance();
    void loadCustomerInsights();
    void loadDailyRevenue();

    bool isOrderInPeriod(const Order& o);
};

#endif
