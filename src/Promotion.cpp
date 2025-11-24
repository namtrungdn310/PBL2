#include "../include/Promotion.h"

Promotion::Promotion() : promoId(0), discountRate(0.0), minOrderAmount(0.0), startDate(0), endDate(0) {}
Promotion::Promotion(int id, string n, double rate, string cond, double minAmount, time_t start, time_t end)
    : promoId(id), name(n), discountRate(rate), condition(cond),
    minOrderAmount(minAmount), startDate(start), endDate(end) {}

double Promotion::applyPromotion(double orderTotal) const {
    if (!isValid() || orderTotal < minOrderAmount) {
        return orderTotal;
    }
    double discount = orderTotal * discountRate;
    return orderTotal - discount;
}

bool Promotion::isValid() const {
    time_t now = time(0);
    return (now >= startDate && now <= endDate);
}
