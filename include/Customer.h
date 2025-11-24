#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <vector>
#include <string>

class ShopSystem; // Forward declaration

class Customer : public User {
private:
    string address;
    string phone;
    int loyaltyPoints;
    vector<int> usedPromoIDs;

public:
    Customer();
    Customer(int id, const string& n, const string& e, const string& p, 
             const string& addr, const string& ph, int points = 0);
    
    const string& getAddress() const { return address; }
    const string& getPhone() const { return phone; }
    int getLoyaltyPoints() const { return loyaltyPoints; }
    
    void setAddress(const string& addr) { address = addr; }
    void setPhone(const string& ph) { phone = ph; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }
    void addLoyaltyPoints(int points) { loyaltyPoints += points; }
    
    // --- LOGIC MỚI CHO QT ---
    bool updateProfile(const string& name, const string& email, const string& addr, const string& phone);
    
    // Tính toán giảm giá điểm
    double calculatePointDiscount(int pointsToUse);
    void deductPoints(int pointsToUse);

    // Hàm tạo đơn hàng (Thay thế checkout)
    // Trả về OrderID vừa tạo
    int placeOrder(ShopSystem& system, int promoId, int pointsToUse, const string& paymentMethod);

    void addUsedPromo(int promoId);
    bool hasUsedPromo(int promoId) const;
    const vector<int>& getUsedPromoIDs() const { return usedPromoIDs; }
    void setUsedPromoIDs(const vector<int>& promoIDs) { usedPromoIDs = promoIDs; }
};
#endif
