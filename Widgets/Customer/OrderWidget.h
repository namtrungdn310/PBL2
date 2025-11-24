#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class OrderWidget; }

class OrderWidget : public QWidget {
    Q_OBJECT

public:
    explicit OrderWidget(QWidget *parent = nullptr);
    ~OrderWidget();

    void loadOrderData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void orderCompleted();
    void backSignal();

private slots:
    void on_btnConfirmPay_clicked();
    void on_btnBack_clicked();

    void on_cboPromotions_currentIndexChanged(int index);
    void on_spinPoints_valueChanged(int arg1);
    void on_spinPoints_editingFinished();

private:
    Ui::OrderWidget *ui;
    ShopSystem* system;

    double currentSubtotal;

    void setupStyle();
    void calculateFinalTotal();
    QString formatMoney(double amount);
};

#endif
