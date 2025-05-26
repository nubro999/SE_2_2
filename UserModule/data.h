#include <string>
#include <iostream>
#include <vector>
using namespace std;

class User {
public:
    enum class Role { ADMIN, MEMBER }; 

protected:
    string username;
    string password;
    string phoneNumber = ""; 
    Role role;

public:
    User(const string& username, const string& password, const string& phone, Role role = Role::MEMBER)
        : username(username), password(password), phoneNumber(phone), role(role) {}


    virtual ~User() = default;

    const string& getUsername() const { return username; }
    const string& getPassword() const { return password; }
    const string& getPhoneNumber() const { return phoneNumber; }
    Role getRole() const { return role; }
};

class Admin : public User {
public:
    Admin(const string& username, const string& password, const string& phoneNumber)
        : User(username, password, phoneNumber, Role::ADMIN) {}
};

class Member : public User {
public:
    Member(const string& username, const string& password, const string& phoneNumber)
        : User(username, password, phoneNumber, Role::MEMBER){}

};
