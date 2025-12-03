#ifndef EDITPROMOTIONSWIDGET_H
#define EDITPROMOTIONSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class EditPromotionsWidget; }

class EditPromotionsWidget : public QWidget {
    Q_OBJECT

public:
    explicit EditPromotionsWidget(QWidget *parent = nullptr);
    ~EditPromotionsWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_tblPromos_cellClicked(int row, int column);

    void on_btnAdd_clicked();
    void on_btnSave_clicked();
    void on_btnDelete_clicked();

private:
    Ui::EditPromotionsWidget *ui;
    ShopSystem* system;
    int currentSelectedId;
    void setupStyle();
    void loadTable();
    QString formatMoney(double amount);
};

#endif
