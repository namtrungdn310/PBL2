#ifndef REVIEW_H
#define REVIEW_H
#include <string>
using namespace std;

class Review {
private:
    int reviewId;
    int productId;
    int customerId;
    int rating;
    string comment;
    string customerName;

public:
    Review();
    Review(int id, int prodId, int custId, int rate, string cmt, string custName);
    
    int getReviewId() const { return reviewId; }
    int getProductId() const { return productId; }
    int getCustomerId() const { return customerId; }
    int getRating() const { return rating; }
    string getComment() const { return comment; }
    string getCustomerName() const { return customerName; }
    
    void setRating(int r) { rating = r; }
    void setComment(string c) { comment = c; }
};
#endif
