#include <string>
#include <iostream>
#include <vector>
using namespace std;

class User {
public:
    enum class Role { ADMIN, MEMBER }; // enum은 public으로 빼는 게 좋음

protected:
    string username;
    string password;
    string phoneNumber = ""; // 전화번호는 Member 클래스에서만 사용
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
