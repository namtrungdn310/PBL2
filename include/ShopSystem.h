#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include "DataStructures.h"
#include "Product.h"
#include "Customer.h"
#include "Staff.h"
#include "Order.h"
#include "Promotion.h"
#include "Cart.h"
#include "Category.h"
#include "Review.h"
#include "Invoice.h"

#include <string>

using namespace std;

enum SortOption {
    SORT_DEFAULT = 0,
    PRICE_ASC = 1,
    PRICE_DESC = 2
};

class ShopSystem {
private:
    static ShopSystem* instance;
    MyVector<Product> products;
    MyVector<Customer> customers;
    MyVector<Staff> staffMembers;
    MyVector<Order> orders;
    MyVector<Promotion> promotions;
    MyVector<Category> categories;
    MyVector<Review> reviews;
    MyVector<Invoice> invoices;

    MyMap<int, MyVector<CartItem>> savedUserCarts;

    Customer* currentCustomer;
    Staff* currentStaff;
    Cart currentCart;
    double monthlyRevenueTarget;

    int lastUserId;
    int lastProductId;
    int lastCategoryId;
    int lastOrderId;
    int lastInvoiceId;
    int lastPromoId;
    int lastReviewId;

    ShopSystem();

public:
    ShopSystem(const ShopSystem&) = delete;
    void operator=(const ShopSystem&) = delete;
    ~ShopSystem();

    static ShopSystem* getInstance();

    // Product
    void addProduct(const Product& product);
    void removeProduct(int productId);
    Product* findProduct(int productId);
    MyVector<Product> searchProducts(int categoryId, string keyword, long long minPrice, long long maxPrice, SortOption sortOption);
    MyVector<Product>& getProducts() { return products; }
    int getAvailableStock(int productId, const string& sizeName);
    // User
    void addCustomer(const Customer& c);
    Customer* findCustomer(int userId);
    Customer* findCustomerByEmail(const string& email);
    MyVector<Customer>& getCustomers() { return customers; }
    void deleteCurrentCustomer();

    void addStaff(const Staff& s);
    void removeStaff(int staffId);
    Staff* findStaff(int userId);
    void updateStaff(const Staff& s);
    MyVector<Staff>& getStaffMembers() { return staffMembers; }

    // Order
    void addOrder(const Order& order) { orders.push_back(order); }
    Order* findOrder(int orderId);
    MyVector<Order>& getOrders() { return orders; }
    void staffConfirmCancelOrder(int orderId);
    void staffConfirmCompleteOrder(int orderId);

    // Invoice
    void addInvoice(const Invoice& inv) { invoices.push_back(inv); }
    MyVector<Invoice>& getInvoices() { return invoices; }

    // Category
    void addCategory(const Category& c) { categories.push_back(c); }
    MyVector<Category>& getCategories() { return categories; }
    void removeCategory(int catId);
    string getCategoryName(int catId) const;

    // Promotion
    void addPromotion(const Promotion& p) { promotions.push_back(p); }
    MyVector<Promotion>& getPromotions();
    void removePromotion(int promoId);

    // Review
    void addReview(const Review& r) { reviews.push_back(r); }
    MyVector<Review>& getReviews() { return reviews; }
    void removeReview(int reviewId);
    MyVector<Review> getReviewsForProduct(int productId) const;

    // System
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

    // Stats / Helpers
    int getTotalUsers() const { return customers.size() + staffMembers.size(); }
    int registerNewCustomer(const string& name, const string& email, const string& pass, const string& address, const string& phone);
    int getTotalProducts() const { return products.size(); }
    int countTotalInCarts(int productId, const string& sizeName);
    int getTotalCustomers() const { return customers.size(); }
    int getTotalOrders() const { return orders.size(); }

    int getNewOrderId();
    int getNewUserId();
    int getNewProductId();
    int getNewCategoryId();
    int getNewInvoiceId();
    int getNewPromoId();
    int getNewReviewId();

    double getTotalRevenue() const;
    double getRevenueThisMonth() const;
    double getMonthlyRevenueTarget() const { return monthlyRevenueTarget; }
};

#endif
