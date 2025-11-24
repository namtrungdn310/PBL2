#ifndef SIZE_H
#define SIZE_H
#include <string>
using namespace std;

class Size {
private:
    int sizeId;
    string sizeName;
    int quantity;

public:
    Size();
    Size(int id, string name, int qty);
    
    int getSizeId() const { return sizeId; }
    string getSizeName() const { return sizeName; }
    int getQuantity() const { return quantity; }
    
    void setSizeId(int id) { sizeId = id; }
    void setSizeName(string name) { sizeName = name; }
    void setQuantity(int qty) { quantity = qty; }
    
    void updateQuantity(int qty); // qty có thể âm để trừ
    bool checkAvailability() const;
};
#endif