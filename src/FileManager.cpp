#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "DataStructures.h"
#include <filesystem>
#include <string> 

namespace fs = std::filesystem;
using namespace std;

void FileManager::createDataFolder() {
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }
}

void FileManager::initializeDataFiles() {
    createDataFolder();
    string files[] = {
        "data/customers.txt",
        "data/staff.txt",
        "data/products.txt",
        "data/orders.txt",
        "data/promotions.txt",
        "data/reviews.txt",
        "data/invoices.txt",
        "data/inventory_stock.txt",
        "data/categories.txt",
        "data/carts.txt",
        "data/order_items.txt"
    };

    for (const auto& file : files) {
        if (!fs::exists(file)) {
            ofstream f(file);
            f.close();
        }
    }
}

MyMap<int, MyVector<Pair<string, int>>> FileManager::readInventoryStock(string filename) {
    MyMap<int, MyVector<Pair<string, int>>> stockMap;

    ifstream file(filename);
    if (!file.is_open()) return stockMap;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string segment;
        MyVector<string> seglist;

        while(getline(ss, segment, '|')) {
            seglist.push_back(segment);
        }

        if (seglist.size() < 3) continue;

        int prodId = stoi(seglist[0]);
        string size = seglist[1];
        int qty = stoi(seglist[2]);

        Pair<string, int> stockData(size, qty);

        stockMap[prodId].push_back(stockData);
    }
    file.close();
    return stockMap;
}

MyVector<Product> FileManager::readProducts(string filename) {
    MyVector<Product> products;
    ifstream file(filename);
    if (!file.is_open()) return products;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        int id, categoryId;
        double price;
        string name, description, brand, sizesStr;
        
        ss >> id; ss.ignore();
        getline(ss, name, '|');
        getline(ss, description, '|');
        ss >> price; ss.ignore();
        getline(ss, brand, '|');
        ss >> categoryId;
        Product product(id, name, price, description,  brand, categoryId);
        products.push_back(product);
    }
    file.close();
    return products;
}

MyVector<Customer> FileManager::readCustomers(string filename) {
    MyVector<Customer> customers;
    ifstream file(filename);
    if (!file.is_open()) return customers;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        int id, points;
        string name, email, password, address, phone;

        ss >> id; ss.ignore();
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, password, '|');
        getline(ss, address, '|');
        getline(ss, phone, '|');
        ss >> points;

        Customer cust(id, name, email, password, address, phone, points);

        if (ss.peek() == '|') {
            ss.ignore();
            string usedPromosStr;
            getline(ss, usedPromosStr);
            if (!usedPromosStr.empty()) {
                MyVector<int> usedIDs;
                stringstream promoSS(usedPromosStr);
                string promoIdStr;
                while (getline(promoSS, promoIdStr, ',')) {
                    try { usedIDs.push_back(stoi(promoIdStr)); } catch (...) {}
                }
                cust.setUsedPromoIDs(usedIDs);
            }
        }
        customers.push_back(cust);
    }
    file.close();
    return customers;
}

MyVector<Staff> FileManager::readStaff(string filename) {
    MyVector<Staff> staff;
    ifstream file(filename);
    if (!file.is_open()) return staff;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id, staffId;
        string name, email, password, position;
        
        ss >> id; ss.ignore();
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, password, '|');
        ss >> staffId; ss.ignore();
        getline(ss, position, '|');
        
        staff.push_back(Staff(id, name, email, password, staffId, position));
    }
    file.close();
    return staff;
}

MyVector<Order> FileManager::readOrders(string filename) {
    MyVector<Order> orders;
    ifstream file(filename);
    if (!file.is_open()) return orders;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id, customerId;
        double subtotal, promoDiscount, pointsDiscount, totalAmount;
        string status;
        
        ss >> id; ss.ignore();
        ss >> customerId; ss.ignore();
        getline(ss, status, '|');
        ss >> subtotal; ss.ignore();
        ss >> promoDiscount; ss.ignore();
        ss >> pointsDiscount; ss.ignore();
        ss >> totalAmount;
        
        Order order(id, customerId);
        order.setStatus(status);
        order.setSubtotal(subtotal);
        order.setPromotionDiscount(promoDiscount);
        order.setPointsDiscount(pointsDiscount);
        order.setTotalAmount(totalAmount);
        orders.push_back(order);
    }
    file.close();
    return orders;
}

MyVector<Promotion> FileManager::readPromotions(string filename) {
    MyVector<Promotion> promos;
    ifstream file(filename);
    if (!file.is_open()) return promos;
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id;
        double rate, minAmount;
        string name, condition;
        
        ss >> id; ss.ignore();
        getline(ss, name, '|');
        ss >> rate; ss.ignore();
        getline(ss, condition, '|');
        ss >> minAmount;
        
        time_t startDate = time(0);
        time_t endDate = startDate + (30 * 24 * 60 * 60); 
        promos.push_back(Promotion(id, name, rate, condition, minAmount, startDate, endDate));
    }
    file.close();
    return promos;
}

MyVector<Review> FileManager::readReviews(string filename) {
    MyVector<Review> reviews;
    ifstream file(filename);
    if (!file.is_open()) return reviews;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id, prodId, custId, rating;
        string comment, custName;

        ss >> id; ss.ignore();
        ss >> prodId; ss.ignore();
        ss >> custId; ss.ignore();
        ss >> rating; ss.ignore();
        getline(ss, comment, '|');
        getline(ss, custName, '|');
        
        reviews.push_back(Review(id, prodId, custId, rating, comment, custName));
    }
    file.close();
    return reviews;
}

MyVector<Invoice> FileManager::readInvoices(string filename) {
    MyVector<Invoice> invoices;
    ifstream file(filename);
    if (!file.is_open()) return invoices;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id, orderId;
        double amount;
        string method;
        time_t date;

        ss >> id; ss.ignore();
        ss >> orderId; ss.ignore();
        ss >> amount; ss.ignore();
        getline(ss, method, '|');
        ss >> date;
        invoices.push_back(Invoice(id, amount, orderId, method, date));
    }
    file.close();
    return invoices;
}

MyVector<Category> FileManager::readCategories(string filename) {
    MyVector<Category> categories;
    ifstream file(filename);
    if (!file.is_open()) return categories;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int id;
        string name;
        
        ss >> id; ss.ignore(); 
        getline(ss, name);
        
        categories.push_back(Category(id, name));
    }
    file.close();
    return categories;
}

void FileManager::writeInventoryStock(string filename, const MyVector<Product>& products) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    for (const auto& prod : products) {
        for (const auto& size : prod.getSizes()) {
            file << prod.getProductId() << "|"
                 << size.getSizeName() << "|"
                 << size.getQuantity() << "\n";
        }
    }
    file.close();
}

void FileManager::writeProducts(string filename, const MyVector<Product>& products) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    file << fixed << setprecision(0); // Giá tiền không cần số thập phân
    for (const auto& prod : products) {
        file << prod.getProductId() << "|" 
             << prod.getName() << "|" 
             << prod.getDescription() << "|"
             << prod.getPrice() << "|" 
             << prod.getBrand() << "|" 
             << prod.getCategoryId() << "\n";
    }
    file.close();
}

void FileManager::writeCustomers(string filename, const MyVector<Customer>& customers) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    for (const auto& cust : customers) {
        file << cust.getUserId() << "|" << cust.getName() << "|" << cust.getEmail() << "|"
             << cust.getPassword() << "|" << cust.getAddress() << "|" << cust.getPhone() << "|"
             << cust.getLoyaltyPoints();
        
        string promosStr;
        const auto& usedPromos = cust.getUsedPromoIDs();
        for (size_t i = 0; i < usedPromos.size(); ++i) {
            promosStr += to_string(usedPromos[i]);
            if (i < usedPromos.size() - 1) promosStr += ","; 
        }
        file << "|" << promosStr << "\n";
    }
    file.close();
}

void FileManager::writeStaff(string filename, const MyVector<Staff>& staff) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    for (const auto& s : staff) {
        file << s.getUserId() << "|" << s.getName() << "|" << s.getEmail() << "|"
             << s.getPassword() << "|" << s.getStaffId() << "|" << s.getPosition() << "\n";
    }
    file.close();
}

void FileManager::writeOrders(string filename, const MyVector<Order>& orders) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    file << fixed << setprecision(2);
    for (const auto& order : orders) {
        file << order.getOrderId() << "|" 
             << order.getCustomerId() << "|" 
             << order.getStatus() << "|"
             << order.getSubtotal() << "|"
             << order.getPromotionDiscount() << "|"
             << order.getPointsDiscount() << "|"
             << order.getTotalAmount() << "\n";
    }
    file.close();
}

void FileManager::writePromotions(string filename, const MyVector<Promotion>& promos) {
    ofstream file(filename);
    if (!file.is_open()) return;
    
    file << fixed << setprecision(2);
    for (const auto& promo : promos) {
        file << promo.getPromoId() << "|" << promo.getName() << "|" << promo.getDiscountRate() << "|"
             << promo.getCondition() << "|" << promo.getMinOrderAmount() << "\n";
    }
    file.close();
}

void FileManager::writeReviews(string filename, const MyVector<Review>& reviews) {
    ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& review : reviews) {
        file << review.getReviewId() << "|" 
             << review.getProductId() << "|" 
             << review.getCustomerId() << "|" 
             << review.getRating() << "|" 
             << review.getComment() << "|" 
             << review.getCustomerName() << "\n";
    }
    file.close();
}

void FileManager::writeInvoices(string filename, const MyVector<Invoice>& invoices) {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << fixed << setprecision(2);
    for (const auto& inv : invoices) {
        file << inv.getInvoiceId() << "|"
             << inv.getOrderId() << "|"
             << inv.getAmount() << "|"
             << inv.getPaymentMethod() << "|"
             << inv.getDate() << "\n";
    }
    file.close();
}


MyMap<int, MyVector<CartItem>> FileManager::readCarts(string filename, const MyVector<Product>& allProducts) {
    MyMap<int, MyVector<CartItem>> userCarts;
    ifstream file(filename);
    if (!file.is_open()) return userCarts;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string segment;
        MyVector<string> seglist;
        while(getline(ss, segment, '|')) seglist.push_back(segment);

        if (seglist.size() < 4) continue;

        int custId = stoi(seglist[0]);
        int prodId = stoi(seglist[1]);
        string size = seglist[2];
        int qty = stoi(seglist[3]);

        Product foundProd;
        bool prodExists = false;
        for (const auto& p : allProducts) {
            if (p.getProductId() == prodId) {
                foundProd = p;
                prodExists = true;
                break;
            }
        }

        if (prodExists) {
            CartItem item(foundProd, size, qty);
            userCarts[custId].push_back(item);
        }
    }
    file.close();
    return userCarts;
}

void FileManager::writeCarts(string filename, const MyMap<int, MyVector<CartItem>>& userCarts) {
    ofstream file(filename);
    if (!file.is_open()) return;
    for (const auto& entry : userCarts) {
        int custId = entry.first;
        const auto& items = entry.second;

        for (const auto& item : items) {
            file << custId << "|"
                 << item.getProduct().getProductId() << "|"
                 << item.getSelectedSize() << "|"
                 << item.getQuantity() << "\n";
        }
    }
    file.close();
}

void FileManager::writeOrderItems(string filename, const MyVector<Order>& orders) {
    ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& order : orders) {
        for (const auto& item : order.getItems()) {
            file << order.getOrderId() << "|"
                 << item.getProduct().getProductId() << "|"
                 << item.getSelectedSize() << "|"
                 << item.getQuantity() << "|"
                 << (long long)item.getUnitPrice() << "\n";
        }
    }
    file.close();
}

MyMap<int, MyVector<OrderItem>> FileManager::readOrderItems(string filename, const MyVector<Product>& allProducts) {
    MyMap<int, MyVector<OrderItem>> itemsMyMap;
    ifstream file(filename);
    if (!file.is_open()) return itemsMyMap;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string segment;
        MyVector<string> seglist;
        while(getline(ss, segment, '|')) seglist.push_back(segment);

        if (seglist.size() < 5) continue;

        int orderId = stoi(seglist[0]);
        int prodId = stoi(seglist[1]);
        string size = seglist[2];
        int qty = stoi(seglist[3]);
        double price = stod(seglist[4]);

        Product p;
        for(const auto& prod : allProducts) {
            if(prod.getProductId() == prodId) {
                p = prod;
                break;
            }
        }

        OrderItem item(p, size, qty, price);
        itemsMyMap[orderId].push_back(item);
    }
    file.close();
    return itemsMyMap;
}

void FileManager::writeCategories(string filename, const MyVector<Category>& categories) {
    ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& cat : categories) {
        file << cat.getCategoryId() << "|" << cat.getName() << "\n";
    }
    file.close();
}
