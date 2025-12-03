#include "../include/Product.h"
#include <algorithm>
#include <cctype>
#include <string>
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
        sortSizes();
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
int Product::getSizeRank(const string& s) const {
    if (s == "XS") return 1;
    if (s == "S")  return 2;
    if (s == "M")  return 3;
    if (s == "L")  return 4;
    if (s == "XL") return 5;
    if (s == "XXL") return 6;
    bool isNumeric = !s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c){ return std::isdigit(c); });
    if (isNumeric) {
        try {
            return 100 + std::stoi(s);
        } catch (...) {
            return 999;
        }
    }
    return 999;
}

void Product::sortSizes() {
    std::sort(sizes.begin(), sizes.end(), [this](const Size& a, const Size& b) {
        return getSizeRank(a.getSizeName()) < getSizeRank(b.getSizeName());
    });
}

void Product::saveToFile() {}
void Product::loadFromFile() {}
