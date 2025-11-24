#ifndef STAFF_H
#define STAFF_H
#include "User.h"

class Staff : public User {
private:
    int staffId;
    string position;
public:
    Staff();
    Staff(int id, const string& n, const string& e, const string& p, int sId, const string& pos);
    int getStaffId() const { return staffId; }
    const string& getPosition() const { return position; }
};
#endif
