#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include "Size.h"
using namespace std;

class Product {
private:
    int productId;
    string name;
    string description;
    long long price;
    string brand;
    int categoryId;
    vector<Size> sizes;

public:
    Product();
    Product(int id, const string& n, const string& desc, long long p, const string& b, int catId);
    
    int getProductId() const { return productId; }
    const string& getName() const { return name; }
    const string& getDescription() const { return description; }
    long long getPrice() const { return price; }
    const string& getBrand() const { return brand; }
    int getCategoryId() const { return categoryId; }
    const vector<Size>& getSizes() const { return sizes; }
    vector<Size>& getSizes() { return sizes; } // Để có thể sửa đổi size từ bên ngoài
    
    void setProductId(int id) { productId = id; }
    void setName(const string& n) { name = n; }
    void setDescription(const string& desc) { description = desc; }
    void setPrice(long long p) { price = p; }
    void setBrand(const string& b) { brand = b; }
    void setCategoryId(int catId) { categoryId = catId; }

    Size* findSize(const string& sizeName);
    void updateStock(const string& sizeName, int qty);
    void addSize(const Size& size);
    bool hasSize(const string& sizeName) const;
    int getTotalStock() const;
    
    // Xóa save/load riêng lẻ vì FileManager sẽ lo
    void saveToFile(); 
    void loadFromFile();
};
#endif