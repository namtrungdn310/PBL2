#include "../include/Size.h"

Size::Size() : sizeId(0), sizeName(""), quantity(0) {}
Size::Size(int id, string name, int qty) : sizeId(id), sizeName(name), quantity(qty) {}

void Size::updateQuantity(int qty) {
    quantity += qty;
}

bool Size::checkAvailability() const {
    return quantity > 0;
}