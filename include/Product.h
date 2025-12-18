#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "DataStructures.h"
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
    MyVector<Size> sizes;
    int getSizeRank(const string& sizeName) const;

public:
    Product();
    Product(int id, const string& n, long long p, const string& desc, const string& b, int catId);
    
    int getProductId() const { return productId; }
    const string& getName() const { return name; }
    const string& getDescription() const { return description; }
    long long getPrice() const { return price; }
    const string& getBrand() const { return brand; }
    int getCategoryId() const { return categoryId; }
    const MyVector<Size>& getSizes() const { return sizes; }
    MyVector<Size>& getSizes() { return sizes; }
    
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
    void sortSizes();
    int getTotalStock() const;
    
    void saveToFile(); 
    void loadFromFile();
};
#endif
