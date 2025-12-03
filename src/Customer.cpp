#include "../include/Customer.h"
#include "../include/ShopSystem.h"
#include "../include/Order.h"
#include "../include/Invoice.h"

Customer::Customer() : User(), address(""), phone(""), loyaltyPoints(0) { role = "Customer"; }

Customer::Customer(int id, const string& n, const string& e, const string& p, const string& addr, const string& ph, int points) 
    : User(id, n, e, p, "Customer"), address(addr), phone(ph), loyaltyPoints(points) {}

bool Customer::updateProfile(const string& n, const string& e, const string& addr, const string& ph) {
    if (n.empty() || e.empty()) return false;
    this->name = n;
    this->email = e;
    this->address = addr;
    this->phone = ph;
    return true;
}

double Customer::calculatePointDiscount(int pointsToUse) {
    if (pointsToUse <= 0 || pointsToUse > loyaltyPoints) return 0.0;
    return pointsToUse * 100.0; // 1 điểm = 100 VND
}

void Customer::deductPoints(int pointsToUse) {
    if (pointsToUse > 0 && pointsToUse <= loyaltyPoints) {
        loyaltyPoints -= pointsToUse;
    }
}

int Customer::placeOrder(ShopSystem& system, int promoId, int pointsToUse, const string& paymentMethod) {
    Cart& cart = system.getCurrentCart();
    if (cart.isEmpty()) return -1;
    int newOrderId = system.getNewOrderId();

    Order newOrder(newOrderId, this->userId);
    
    for (const auto& cartItem : cart.getItems()) {
        Product* originalProduct = system.findProduct(cartItem.getProduct().getProductId());
        if (originalProduct) {
            originalProduct->updateStock(cartItem.getSelectedSize(), -cartItem.getQuantity());
        }
        OrderItem orderItem(cartItem.getProduct(), cartItem.getSelectedSize(), cartItem.getQuantity(), cartItem.getProduct().getPrice());
        newOrder.addOrderItem(orderItem);
    }

    double subtotal = newOrder.calculateTotal();
    double promoDiscount = 0;
    double pointDiscount = 0;
    double tempTotal = subtotal;

    if (promoId != -1) {
        for (const auto& promo : system.getPromotions()) {
            if (promo.getPromoId() == promoId) {
                double afterPromo = promo.applyPromotion(subtotal);
                promoDiscount = subtotal - afterPromo;
                addUsedPromo(promoId);
                tempTotal = afterPromo;
                break;
            }
        }
    }

    if (pointsToUse > loyaltyPoints) {
        pointsToUse = loyaltyPoints;
    }
    
    int maxPointsAllowedByBill = static_cast<int>(tempTotal / 100.0);
    if (pointsToUse > maxPointsAllowedByBill) {
        pointsToUse = maxPointsAllowedByBill;
    }

    pointDiscount = pointsToUse * 100.0;
    deductPoints(pointsToUse);

    newOrder.setSubtotal(subtotal);
    newOrder.setPromotionDiscount(promoDiscount);
    newOrder.setPointsDiscount(pointDiscount);
    newOrder.setTotalAmount(subtotal - promoDiscount - pointDiscount);
    newOrder.updateStatus("Pending");

    system.addOrder(newOrder);
    
    int newInvoiceId = system.getNewInvoiceId();
    Invoice newInvoice(newInvoiceId, newOrder.getTotalAmount(), newOrderId, paymentMethod, time(0));
    system.addInvoice(newInvoice);

    cart.clearCart();
    return newOrderId;
}

void Customer::addUsedPromo(int promoId) {
    if (!hasUsedPromo(promoId)) usedPromoIDs.push_back(promoId);
}

bool Customer::hasUsedPromo(int promoId) const {
    for (int id : usedPromoIDs) if (id == promoId) return true;
    return false;
}
