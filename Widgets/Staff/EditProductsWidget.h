#ifndef EDITPRODUCTSWIDGET_H
#define EDITPRODUCTSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class EditProductsWidget; }

class EditProductsWidget : public QWidget {
    Q_OBJECT

public:
    explicit EditProductsWidget(QWidget *parent = nullptr);
    ~EditProductsWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_btnFilter_clicked();
    void on_tblProducts_cellDoubleClicked(int row, int column);
    void on_btnAddProduct_clicked();
    void on_btnAddSize_clicked();
    void on_btnRemoveSize_clicked();
    void on_btnConfirm_clicked();
    void on_btnDeleteProduct_clicked();

private:
    Ui::EditProductsWidget *ui;
    ShopSystem* system;
    Product* currentEditingProduct;
    bool isAddMode;
    MyVector<Size> tempSizes;

    void setupStyle();
    void loadCategories();
    void displayProducts(const MyVector<Product>& list);
    void loadProductToForm(Product* p);
    void updateSizeTable();
    void populateSizeCombo();
};

#endif
