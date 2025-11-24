#ifndef REVIEWSWIDGET_H
#define REVIEWSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class ReviewsWidget; }

class ReviewsWidget : public QWidget {
    Q_OBJECT

public:
    explicit ReviewsWidget(QWidget *parent = nullptr);
    ~ReviewsWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    // Slots trang danh sách
    void on_btnFilter_clicked();
    void on_tblProducts_cellDoubleClicked(int row, int column);
    void on_btnBackMenu_clicked();

    // Slots trang chi tiết
    void on_btnConfirmReview_clicked();
    void on_btnBackList_clicked();

private:
    Ui::ReviewsWidget *ui;
    ShopSystem* system;
    Product* currentProduct;

    void setupStyle();
    void loadCategories();
    void displayProductList(const vector<Product>& list);
    void showProductDetail(Product* p);
    void loadReviewsForProduct(int prodId);

    // Hàm tính điểm trung bình
    pair<double, int> calculateRating(int prodId); // Trả về {điểm tb, số lượt}
    QString getStarString(int rating); // Chuyển số thành dấu sao (*)
};

#endif
