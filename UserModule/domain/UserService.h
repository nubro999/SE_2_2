#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "User.h"
#include "Member.h"
#include "Admin.h"

class UserService {
private:
    std::vector<std::unique_ptr<User>> users;
public:
    UserService() {
        users.push_back(std::make_unique<Admin>("admin", "admin", "000", Role::ADMIN));
    }

    bool isPasswordDuplicate(const std::string& password) const {
        for (const auto& user : users) {
            if (user->getPassword() == password) return true;
        }
        return false;
    }

    void signUp() {
        std::string username, password, roleInput;
        Role role = Role::MEMBER;

        std::cout << "아이디 입력: ";
        std::cin >> username;

        do {
            std::cout << "비밀번호 입력(중복 불가): ";
            std::cin >> password;
            if (isPasswordDuplicate(password)) {
                std::cout << "이미 사용 중인 비밀번호입니다. 다른 비밀번호를 입력하세요.\n";
            }
        } while (isPasswordDuplicate(password));

        if (role == Role::ADMIN) {
            users.push_back(std::make_unique<Admin>(username, password));
        } else {
            users.push_back(std::make_unique<Member>(username, password));
        }
        std::cout << "회원가입이 완료되었습니다!\n";
    }

    User* login() {
        std::string username, password;
        std::cout << "아이디 입력: ";
        std::cin >> username;
        std::cout << "비밀번호 입력: ";
        std::cin >> password;

        for (const auto& user : users) {
            if (user->getUsername() == username && user->getPassword() == password) {
                std::cout << "로그인 성공! (" << (user->getRole() == Role::ADMIN ? "관리자" : "멤버") << ")\n";
                return user.get();
            }
        }
        std::cout << "로그인 실패! 아이디 또는 비밀번호를 확인하세요.\n";
        return nullptr;
    }

    void logout(User* user) {
        if (user) {
            std::cout << user->getUsername() << "님, 로그아웃되었습니다.\n";
        } else {
            std::cout << "로그아웃할 사용자가 없습니다.\n";
        }
    }
};
