#include "../include/Staff.h"

Staff::Staff() : User(), staffId(0), position("") { role = "Staff"; }

Staff::Staff(int id, const string& n, const string& e, const string& p, int sId, const string& pos)
    : User(id, n, e, p, "Staff"), staffId(sId), position(pos) {}
