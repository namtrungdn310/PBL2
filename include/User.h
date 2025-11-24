#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    int userId;
    string name;
    string email;
    string password;
    string role;

public:
    User() : userId(0) {}
    User(int id, const string& n, const string& e, const string& p, const string& r);
    virtual ~User();

    int getUserId() const { return userId; }
    const string& getName() const { return name; }
    const string& getEmail() const { return email; }
    const string& getPassword() const { return password; }
    const string& getRole() const { return role; }

    void setUserId(int id) { userId = id; }
    void setName(const string& n) { name = n; }
    void setEmail(const string& e) { email = e; }
    void setPassword(const string& p) { password = p; }
    void setRole(const string& r) { role = r; } // Thêm setter role nếu cần

    virtual bool login(const string& email, const string& pass);
};

#endif
