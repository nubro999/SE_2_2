#include <string>

enum class Role { MEMBER, ADMIN };

class User {
protected:
    std::string username;
    std::string password;
    std::string phone;
    Role role;
public:
    User(const std::string& username, const std::string& password, const std::string& phone, Role role)
        : username(username), password(password), phone(phone), role(role) {}
    virtual ~User() {}
    virtual void showRentedBicycles() const {}

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getPhone() const { return phone; }
    Role getRole() const { return role; }
};
