#include "../include/OrderItem.h"
OrderItem::OrderItem() : quantity(0), unitPrice(0.0) {}
OrderItem::OrderItem(Product prod, string size, int qty, double price)
    : product(prod), selectedSize(size), quantity(qty), unitPrice(price) {}
double OrderItem::getSubtotal() const { return unitPrice * quantity; }