#ifndef CART_H
#define CART_H

#include <vector>
#include "CartItem.h"
using namespace std;

class Cart {
private:
    int cartId;
    int customerId;
    vector<CartItem> items;

public:
    Cart();
    Cart(int id, int custId);
    
    int getCartId() const { return cartId; }
    int getCustomerId() const { return customerId; }
    const vector<CartItem>& getItems() const { return items; }  
    vector<CartItem>& getItems() { return items; }

    void addItem(int prodId, const string& size, int qty, const Product& product); 
    void removeItem(int itemIndex);
    void updateItemQuantity(int itemIndex, int newQuantity);
    int getQuantityInCart(int prodId, const string& sizeName) const;
    double calculateTotal() const;
    void clearCart();
    bool isEmpty() const { return items.empty(); }
    size_t getItemCount() const { return items.size(); }
};
#endif