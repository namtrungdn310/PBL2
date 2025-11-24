#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include <map>
#include "Customer.h"
#include "Staff.h"
#include "Product.h"
#include "Order.h"
#include "Promotion.h"
#include "Review.h"
#include "Invoice.h"
#include "Category.h"
#include "CartItem.h"

using namespace std;

class FileManager {
public:
    //helper
    static void createDataFolder();
    static void initializeDataFiles();

    //đọc
    static vector<Customer> readCustomers(string filename);
    static vector<Staff> readStaff(string filename);
    static vector<Product> readProducts(string filename);
    static vector<Order> readOrders(string filename);
    static vector<Promotion> readPromotions(string filename);
    static vector<Review> readReviews(string filename);
    static vector<Invoice> readInvoices(string filename);
    static vector<Category> readCategories(string filename);
    static map<int, vector<CartItem>> readCarts(string filename, const vector<Product>& allProducts);
    static map<int, vector<pair<string, int>>> readInventoryStock(string filename);
    static map<int, vector<OrderItem>> readOrderItems(string filename, const vector<Product>& allProducts);
    
    //viết
    static void writeCustomers(string filename, const vector<Customer>& customers);
    static void writeStaff(string filename, const vector<Staff>& staff);
    static void writeProducts(string filename, const vector<Product>& products);
    static void writeOrders(string filename, const vector<Order>& orders);
    static void writePromotions(string filename, const vector<Promotion>& promos);
    static void writeReviews(string filename, const vector<Review>& reviews);
    static void writeInvoices(string filename, const vector<Invoice>& invoices);
    static void writeCategories(string filename, const vector<Category>& categories);
    static void writeInventoryStock(string filename, const vector<Product>& products);
    static void writeCarts(string filename, const map<int, vector<CartItem>>& userCarts);
    static void writeOrderItems(string filename, const vector<Order>& orders);
};

#endif
