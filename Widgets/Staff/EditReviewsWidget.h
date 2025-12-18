#ifndef EDITREVIEWSWIDGET_H
#define EDITREVIEWSWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class EditReviewsWidget; }

class EditReviewsWidget : public QWidget {
    Q_OBJECT

public:
    explicit EditReviewsWidget(QWidget *parent = nullptr);
    ~EditReviewsWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_btnFilter_clicked();
    void on_tblProducts_cellClicked(int row, int column);
    void on_btnPostReply_clicked();

private:
    Ui::EditReviewsWidget *ui;
    ShopSystem* system;
    Product* currentProduct;

    void setupStyle();
    void loadCategories();
    void displayProducts(const MyVector<Product>& list);

    void loadReviewsForProduct(int prodId);

    void createReviewCard(const Review& review);

    Pair<double, int> calculateRating(int prodId);
    QString getStarString(int rating);
};

#endif
