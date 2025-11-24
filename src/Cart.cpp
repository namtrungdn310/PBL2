#include "../include/Cart.h"

Cart::Cart() : cartId(0), customerId(0) {}
Cart::Cart(int id, int custId) : cartId(id), customerId(custId) {}

void Cart::addItem(int prodId, const string& size, int qty, const Product& product) {
    for (auto& item : items) {
        if (item.getProduct().getProductId() == prodId &&
            item.getSelectedSize() == size) { 
            item.updateQuantity(item.getQuantity() + qty);
            return;
        }
    }
    CartItem item(product, size, qty);
    items.push_back(item);
}

void Cart::removeItem(int itemIndex) {
    if (itemIndex >= 0 && static_cast<size_t>(itemIndex) < items.size()) {
        items.erase(items.begin() + itemIndex);
    }
}

void Cart::updateItemQuantity(int itemIndex, int newQuantity) {
    if (itemIndex >= 0 && static_cast<size_t>(itemIndex) < items.size()) {
        if (newQuantity <= 0) removeItem(itemIndex);
        else items[itemIndex].updateQuantity(newQuantity);
    }
}

// Thêm implementation này vào cuối file
int Cart::getQuantityInCart(int prodId, const string& sizeName) const {
    for (const auto& item : items) {
        if (item.getProduct().getProductId() == prodId && 
            item.getSelectedSize() == sizeName) {
            return item.getQuantity();
        }
    }
    return 0;
}

double Cart::calculateTotal() const {
    double total = 0;
    for (const auto& item : items) total += item.getSubtotal();
    return total;
}

void Cart::clearCart() { items.clear(); }
