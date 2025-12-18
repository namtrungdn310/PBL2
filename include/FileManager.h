#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "DataStructures.h"
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
    static MyVector<Customer> readCustomers(string filename);
    static MyVector<Staff> readStaff(string filename);
    static MyVector<Product> readProducts(string filename);
    static MyVector<Order> readOrders(string filename);
    static MyVector<Promotion> readPromotions(string filename);
    static MyVector<Review> readReviews(string filename);
    static MyVector<Invoice> readInvoices(string filename);
    static MyVector<Category> readCategories(string filename);
    static MyMap<int, MyVector<CartItem>> readCarts(string filename, const MyVector<Product>& allProducts);
    static MyMap<int, MyVector<Pair<string, int>>> readInventoryStock(string filename);
    static MyMap<int, MyVector<OrderItem>> readOrderItems(string filename, const MyVector<Product>& allProducts);
    
    //viết
    static void writeCustomers(string filename, const MyVector<Customer>& customers);
    static void writeStaff(string filename, const MyVector<Staff>& staff);
    static void writeProducts(string filename, const MyVector<Product>& products);
    static void writeOrders(string filename, const MyVector<Order>& orders);
    static void writePromotions(string filename, const MyVector<Promotion>& promos);
    static void writeReviews(string filename, const MyVector<Review>& reviews);
    static void writeInvoices(string filename, const MyVector<Invoice>& invoices);
    static void writeCategories(string filename, const MyVector<Category>& categories);
    static void writeInventoryStock(string filename, const MyVector<Product>& products);
    static void writeCarts(string filename, const MyMap<int, MyVector<CartItem>>& userCarts);
    static void writeOrderItems(string filename, const MyVector<Order>& orders);
};

#endif
