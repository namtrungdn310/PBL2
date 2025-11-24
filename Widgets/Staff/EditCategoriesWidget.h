#ifndef EDITCATEGORIESWIDGET_H
#define EDITCATEGORIESWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class EditCategoriesWidget; }

class EditCategoriesWidget : public QWidget {
    Q_OBJECT

public:
    explicit EditCategoriesWidget(QWidget *parent = nullptr);
    ~EditCategoriesWidget();

    void refreshData(); // Load lại dữ liệu
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_tblCategories_cellClicked(int row, int column);

    void on_btnAdd_clicked();
    void on_btnRename_clicked();
    void on_btnDelete_clicked();

    void on_btnBackToForm_clicked(); // Nút "OK" ở trang cảnh báo

private:
    Ui::EditCategoriesWidget *ui;
    ShopSystem* system;
    int currentSelectedCatId;

    void setupStyle();
    void loadCategoriesTable();
    int countProductsInCategory(int catId); // Hàm đếm số lượng SP
    int getNewCategoryId(); // Hàm tự sinh ID
};

#endif // EDITCATEGORIESWIDGET_H
