#ifndef REVIEWSWIDGET_H
#define REVIEWSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>

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
    void on_btnFilter_clicked();
    void on_tblProducts_cellDoubleClicked(int row, int column);
    void on_btnBackMenu_clicked();
    void on_btnConfirmReview_clicked();
    void on_btnBackList_clicked();
    void handleDeleteReview(int reviewId);

private:
    Ui::ReviewsWidget *ui;
    ShopSystem* system;
    Product* currentProduct;

    void setupStyle();
    void loadCategories();
    void displayProductList(const vector<Product>& list);
    void showProductDetail(Product* p);
    void loadReviewsForProduct(int prodId);

    pair<double, int> calculateRating(int prodId);
    QString getStarString(int rating);
};

#endif
