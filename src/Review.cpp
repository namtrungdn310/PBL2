#include "../include/Review.h"

static int reviewCounter = 1;

Review::Review() : reviewId(reviewCounter++), productId(0), customerId(0), rating(0) {}

Review::Review(int id, int prodId, int custId, int rate, string cmt, string custName)
    : reviewId(id), productId(prodId), customerId(custId), rating(rate), comment(cmt), customerName(custName) {
    if (id >= reviewCounter) reviewCounter = id + 1;
}