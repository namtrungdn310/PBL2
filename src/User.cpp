#include "../include/User.h"

User::User(int id, const string& n, const string& e, const string& p, const string& r) 
    : userId(id), name(n), email(e), password(p), role(r) {}

User::~User() {}

bool User::login(const string& inputEmail, const string& inputPass) {
    return (this->email == inputEmail && this->password == inputPass);
}