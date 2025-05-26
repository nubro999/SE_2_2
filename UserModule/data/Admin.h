#pragma once
#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password, const std::string& phone)
        : User(username, password, phone, Role::ADMIN) {}
        
};
