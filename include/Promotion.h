#ifndef PROMOTION_H
#define PROMOTION_H
#include <string>
#include <ctime>
using namespace std;

class Promotion {
private:
    int promoId;
    string name;
    double discountRate;
    string condition;
    double minOrderAmount;
    time_t startDate;
    time_t endDate;
public:
    Promotion();
    Promotion(int id, string n, double rate, string cond, double minAmount, time_t start, time_t end);

    int getPromoId() const { return promoId; }
    string getName() const { return name; }
    double getDiscountRate() const { return discountRate; }
    string getCondition() const { return condition; }
    double getMinOrderAmount() const { return minOrderAmount; }
    
    double applyPromotion(double orderTotal) const;
    bool isValid() const;

    void setName(string n) { name = n; }
    void setDiscountRate(double r) { discountRate = r; }
    void setCondition(string c) { condition = c; }
    void setMinOrderAmount(double m) { minOrderAmount = m; }
};
#endif
