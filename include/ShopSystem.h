#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include <vector>
#include <map>
#include "Product.h"
#include "Customer.h"
#include "Staff.h"
#include "Order.h"
#include "Promotion.h"
#include "Cart.h"
#include "Category.h"
#include "Review.h"
#include "Invoice.h"

#include <algorithm>
#include <cctype>

using namespace std;

enum SortOption {
    SORT_DEFAULT = 0,
    PRICE_ASC = 1,
    PRICE_DESC = 2
};

class ShopSystem {
private:
    static ShopSystem* instance;
    
    vector<Product> products;
    vector<Customer> customers;
    vector<Staff> staffMembers;
    vector<Order> orders;
    vector<Promotion> promotions;
    vector<Category> categories;
    vector<Review> reviews;
    vector<Invoice> invoices;
    map<int, vector<CartItem>> savedUserCarts;
    
    Customer* currentCustomer;
    Staff* currentStaff;
    Cart currentCart;
    double monthlyRevenueTarget;

    ShopSystem(); 
    
public:
    static ShopSystem* getInstance();
    ShopSystem(const ShopSystem&) = delete;
    ShopSystem& operator=(const ShopSystem&) = delete;
    ~ShopSystem();

    const vector<Product>& getProducts() const { return products; }
    vector<Product>& getProducts() { return products; }
    const vector<Customer>& getCustomers() const { return customers; }
    vector<Customer>& getCustomers() { return customers; }
    const vector<Order>& getOrders() const { return orders; }
    const vector<Promotion>& getPromotions() const { return promotions; }
    const vector<Category>& getCategories() const { return categories; }
    const vector<Review>& getReviews() const { return reviews; }
    const vector<Invoice>& getInvoices() const { return invoices; }

    Product* findProduct(int productId);
    Customer* findCustomer(int userId);
    Customer* findCustomerByEmail(const string& email);
    Staff* findStaff(int userId);
    Order* findOrder(int orderId);
    string getCategoryName(int catId) const;
    vector<Review> getReviewsForProduct(int productId) const;

    int getAvailableStock(int productId, const string& sizeName);
    void addProduct(const Product& product);
    void removeProduct(int productId);
    void addCustomer(const Customer& customer);
    void deleteCurrentCustomer();
    void addStaff(const Staff& staff);
    void addOrder(const Order& order);
    void addInvoice(const Invoice& invoice);
    void addReview(const Review& review);
    void addPromotion(const Promotion& promo);
    void removePromotion(int promoId);
    void addCategory(const Category& category);
    void staffConfirmCancelOrder(int orderId);
    void staffConfirmCompleteOrder(int orderId);
    vector<Product> searchProducts(int categoryId, string keyword, long long minPrice, long long maxPrice, SortOption sortOption);
    static string toLowerStr(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    bool loginCustomer(const string& email, const string& password);
    bool loginStaff(const string& email, const string& password);
    void logout();
    Customer* getCurrentCustomer() { return currentCustomer; }
    Staff* getCurrentStaff() { return currentStaff; }
    
    Cart& getCurrentCart() { return currentCart; }
    void clearCurrentCart() { currentCart.clearCart(); }
    string validateCartStock();

    void loadAllData();
    void saveAllData();

    int getTotalUsers() const { return customers.size() + staffMembers.size(); }
    int registerNewCustomer(const string& name, const string& email, const string& pass, const string& address, const string& phone);
    int getNewOrderId();
    int getNewUserId();
    int getTotalProducts() const { return products.size(); }
    int countTotalInCarts(int productId, const string& sizeName);
    int getTotalCustomers() const { return customers.size(); }
    int getTotalOrders() const { return orders.size(); }

    double getTotalRevenue() const;
    double getRevenueThisMonth() const;
    double getMonthlyRevenueTarget() const { return monthlyRevenueTarget; }
    void setMonthlyRevenueTarget(double target) { monthlyRevenueTarget = target; }  
};
#endif
