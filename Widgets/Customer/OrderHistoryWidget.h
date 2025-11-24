#ifndef ORDERHISTORYWIDGET_H
#define ORDERHISTORYWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class OrderHistoryWidget; }

class OrderHistoryWidget : public QWidget {
    Q_OBJECT

public:
    explicit OrderHistoryWidget(QWidget *parent = nullptr);
    ~OrderHistoryWidget();

    void loadHistory();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_cboSortOrder_currentIndexChanged(int index);

private:
    Ui::OrderHistoryWidget *ui;
    ShopSystem* system;

    void setupStyle();
    QString formatMoney(double amount);

    void addOrderCard(const Order& order, const Invoice* invoice);
};

#endif
