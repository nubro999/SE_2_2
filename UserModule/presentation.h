#include <string>
#include <iostream>
#include "domain.h"
using namespace std;

// 1.1. 회원가입 출력 함수
inline void printSignUp(const User & user) {
    cout << "1.1. 회원가입\n";
    cout << "> " << user.getUsername() << " " << user.getPassword() << " " << user.getPhoneNumber() << "\n";
}

// 2.1. 로그인 출력 함수
inline void printLogin(const User & user) {
    cout << "2.1. 로그인\n";
    cout << "> " << user.getUsername() << " " << user.getPassword() << "\n";
}

// 2.2. 로그아웃 출력 함수
inline void printLogout(const User & user) {
    cout << "2.2. 로그아웃\n";
    cout << "> " << user.getUsername() << "\n";
}
