#include "../include/Invoice.h"
static int invoiceCounter = 1;
Invoice::Invoice() : invoiceId(invoiceCounter++), date(time(0)), amount(0.0), orderId(0) {}
Invoice::Invoice(int id, double amt, int ordId, string method, time_t d) 
    : invoiceId(id), date(d), amount(amt), orderId(ordId), paymentMethod(method) {
    if (id >= invoiceCounter) invoiceCounter = id + 1;
}