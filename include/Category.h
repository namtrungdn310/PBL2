#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
using namespace std;

class Category {
private:
    int categoryId;
    string name;

public:
    Category();
    Category(int id, string n);
    
    int getCategoryId() const { return categoryId; }
    string getName() const { return name; }
    
    void setCategoryId(int id) { categoryId = id; }
    void setName(string n) { name = n; }
};

#endif