#ifndef VIEWPRODUCTSWIDGET_H
#define VIEWPRODUCTSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class ViewProductsWidget; }

class ViewProductsWidget : public QWidget {
    Q_OBJECT

public:
    explicit ViewProductsWidget(QWidget *parent = nullptr);
    ~ViewProductsWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnFilter_clicked();
    void on_btnBackList_clicked();
    void on_tblProducts_cellDoubleClicked(int row, int column);

    void on_btnBackDetail_clicked();
    void on_cboSize_currentIndexChanged(int index); // Khi chọn size thì cập nhật số lượng max
    void on_btnAddToCart_clicked();

private:
    Ui::ViewProductsWidget *ui;
    ShopSystem* system;
    Product* currentSelectedProduct; // Lưu sản phẩm đang xem chi tiết

    void setupStyle();
    void loadCategories();
    void displayProducts(const vector<Product>& list);
    void showProductDetails(Product* p);
};

#endif
