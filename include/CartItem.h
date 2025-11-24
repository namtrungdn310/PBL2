#ifndef CARTITEM_H
#define CARTITEM_H
#include "Product.h"

class CartItem {
private:
    Product product;
    string selectedSize;
    int quantity;
public:
    CartItem();
    CartItem(Product prod, string size, int qty);
    
    int getQuantity() const { return quantity; }
    Product getProduct() const { return product; }
    string getSelectedSize() const { return selectedSize; }
    
    void setQuantity(int qty) { quantity = qty; }
    void updateQuantity(int qty);
    double getSubtotal() const;
};
#endif
