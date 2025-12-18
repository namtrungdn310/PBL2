#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "DataStructures.h"
#include <ctime>
#include "OrderItem.h"
using namespace std;

class Order {
private:
    int orderId;
    time_t orderDate;
    string status;
    double subtotal;          
    double promotionDiscount;  
    double pointsDiscount;     
    double totalAmount;        
    int customerId;
    MyVector<OrderItem> items;

public:
    Order();
    Order(int id, int custId);
    
    int getOrderId() const { return orderId; }
    time_t getOrderDate() const { return orderDate; }
    string getStatus() const { return status; }
    double getTotalAmount() const { return totalAmount; } 
    int getCustomerId() const { return customerId; }
    const MyVector<OrderItem>& getItems() const { return items; }
    double getSubtotal() const { return subtotal; }
    double getPromotionDiscount() const { return promotionDiscount; }
    double getPointsDiscount() const { return pointsDiscount; }

    void setStatus(string st) { status = st; }
    void setTotalAmount(double amount) { totalAmount = amount; }
    void setSubtotal(double amount) { subtotal = amount; }
    void setPromotionDiscount(double amount) { promotionDiscount = amount; }
    void setPointsDiscount(double amount) { pointsDiscount = amount; }
    
    void addOrderItem(const OrderItem& item);
    double calculateTotal(); 
    void updateStatus(string st);
    
    void saveToFile();
    void loadFromFile();
};
#endif
