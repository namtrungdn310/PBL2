#include "../include/CartItem.h"

CartItem::CartItem() : selectedSize(""), quantity(0) {}
CartItem::CartItem(Product prod, string size, int qty) 
    : product(prod), selectedSize(size), quantity(qty)  {}

void CartItem::updateQuantity(int qty) { quantity = qty; }
double CartItem::getSubtotal() const { return product.getPrice() * quantity; }
