#ifndef ORDERITEM_H
#define ORDERITEM_H
#include "Product.h"

class OrderItem {
private:
    Product product;
    string selectedSize;
    int quantity;
    double unitPrice;
public:
    OrderItem();
    OrderItem(Product prod, string size, int qty, double price);
    int getQuantity() const { return quantity; }
    double getUnitPrice() const { return unitPrice; }
    Product getProduct() const { return product; }
    string getSelectedSize() const { return selectedSize; }
    double getSubtotal() const;
};
#endif
