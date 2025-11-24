#ifndef VIEWCARTWIDGET_H
#define VIEWCARTWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class ViewCartWidget; }

class ViewCartWidget : public QWidget {
    Q_OBJECT

public:
    explicit ViewCartWidget(QWidget *parent = nullptr);
    ~ViewCartWidget();

    void refreshCart();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();
    void goToCheckout();

private slots:
    void on_btnRemove_clicked();
    void on_btnDecrease_clicked();
    void on_btnCheckout_clicked();
    void on_btnBack_clicked();

private:
    Ui::ViewCartWidget *ui;
    ShopSystem* system;

    void setupStyle();
    void loadCartTable();
    QString formatMoney(double amount); // Hàm định dạng tiền
};

#endif
