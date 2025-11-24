#ifndef PROMOTIONSWIDGET_H
#define PROMOTIONSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class PromotionsWidget; }

class PromotionsWidget : public QWidget {
    Q_OBJECT

public:
    explicit PromotionsWidget(QWidget *parent = nullptr);
    ~PromotionsWidget();

    void loadPromotions(); // Hàm nạp danh sách
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();

private:
    Ui::PromotionsWidget *ui;
    ShopSystem* system;

    void setupStyle();
    // Hàm tạo thẻ khuyến mãi
    void createPromoCard(const Promotion& promo);
};

#endif
