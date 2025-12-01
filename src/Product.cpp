#include "../include/Product.h"
#include <algorithm>

Product::Product() : productId(0), price(0), categoryId(0) {}

Product::Product(int id, const string& n, long long p, const string& desc,  const string& b, int catId)
    : productId(id), name(n), description(desc), price(p), brand(b), categoryId(catId) {}

Size* Product::findSize(const string& sizeName) {
    for (auto& size : sizes) {
        if (size.getSizeName() == sizeName) return &size;
    }
    return nullptr;
}

void Product::updateStock(const string& sizeName, int qty) {
    Size* size = findSize(sizeName);
    if (size) {
        size->updateQuantity(qty);
    }
}

void Product::addSize(const Size& size) {
    if (!hasSize(size.getSizeName())) {
        sizes.push_back(size);
    }
}

bool Product::hasSize(const string& sizeName) const {
    return any_of(sizes.begin(), sizes.end(),
        [&sizeName](const Size& s) { return s.getSizeName() == sizeName; });
}

int Product::getTotalStock() const {
    int total = 0;
    for (const auto& size : sizes) total += size.getQuantity();
    return total;
}

void Product::saveToFile() {}
void Product::loadFromFile() {}
