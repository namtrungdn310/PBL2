#ifndef CUSTOMERSMANAGEMENTWIDGET_H
#define CUSTOMERSMANAGEMENTWIDGET_H

#include <QWidget>
#include "include/ShopSystem.h"
#include <QStyleOption>
#include <QPainter>

namespace Ui { class CustomersManagementWidget; }

class CustomersManagementWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomersManagementWidget(QWidget *parent = nullptr);
    ~CustomersManagementWidget();

    void refreshData();
    void paintEvent(QPaintEvent *event) override;

signals:
    void backSignal();

private slots:
    void on_btnBack_clicked();
    void on_tabWidget_currentChanged(int index);

    // Slots cho Tab Database
    void on_txtSearchCust_textChanged(const QString &arg1);
    void on_cboSortCust_currentIndexChanged(int index);
    void on_cboSortOrder_currentIndexChanged(int index);
    void on_tblCustomers_cellClicked(int row, int column);

private:
    Ui::CustomersManagementWidget *ui;
    ShopSystem* system;
    int currentSelectedCustId;

    void setupStyle();
    QString formatMoney(double amount);

    // --- PART 1: MANAGE PENDING ---
    void loadPendingOrders();

    // --- PART 2: DATABASE ---
    void loadCustomerList();
    void loadCustomerOrders(int custId);
    double calculateTotalSpent(int custId); // Chỉ tính đơn Completed

    // Hàm chung để vẽ thẻ đơn hàng
    // isActionable = true (Hiện nút Confirm/Cancel), = false (Chỉ xem)
    void createOrderCard(const Order& order, QWidget* parentLayout, bool isActionable);
};

#endif // CUSTOMERSMANAGEMENTWIDGET_H
