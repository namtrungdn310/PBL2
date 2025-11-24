#include "../include/Order.h"

Order::Order() : orderId(0), orderDate(time(0)), status("Pending"), 
      subtotal(0.0), promotionDiscount(0.0), pointsDiscount(0.0), totalAmount(0.0), customerId(0) {}

Order::Order(int id, int custId) : orderId(id), orderDate(time(0)), status("Pending"), 
      subtotal(0.0), promotionDiscount(0.0), pointsDiscount(0.0), totalAmount(0.0), customerId(custId) {}

void Order::addOrderItem(const OrderItem& item) {
    items.push_back(item);
}

double Order::calculateTotal() {
    subtotal = 0;
    for (const auto& item : items) {
        subtotal += item.getSubtotal();
    }
    // Lưu ý: Promotion và Points sẽ được set từ bên ngoài (Customer/ShopSystem)
    totalAmount = subtotal - promotionDiscount - pointsDiscount;
    return totalAmount; 
}

void Order::updateStatus(string st) { status = st; }
void Order::saveToFile() {}
void Order::loadFromFile() {}