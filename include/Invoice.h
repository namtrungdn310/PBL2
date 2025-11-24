#ifndef INVOICE_H
#define INVOICE_H
#include <string>
#include <ctime>
using namespace std;

class Invoice {
private:
    int invoiceId;
    time_t date;
    double amount; 
    int orderId; 
    string paymentMethod;

public:
    Invoice(); 
    Invoice(int id, double amt, int ordId, string method, time_t d);
    
    int getInvoiceId() const { return invoiceId; }
    time_t getDate() const { return date; } 
    double getAmount() const { return amount; }
    int getOrderId() const { return orderId; }
    string getPaymentMethod() const { return paymentMethod; }
};
#endif