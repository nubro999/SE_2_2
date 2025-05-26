#pragma once
#include "data.h"
#include <vector>
#include <string>
using namespace std;

// 회원가입 함수 정의
inline void signUp(vector<User>& users, const string& id, const string& pw, const string& phone) {
    users.push_back(User{id, pw, phone});
}

// 로그인 함수 정의
inline User* login(vector<User>& users, const string& id, const string& pw) {
    for (auto& user : users) {
        if (user.getUsername() == id && user.getPassword() == pw) {
            return &user;
        }
    }
    return nullptr;
}

// 로그아웃 함수 정의
inline void logout(User*& currentUser) {
    currentUser = nullptr;
}
