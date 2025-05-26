#include <string>
#include <iostream>
#include "domain.h"
using namespace std;

// 1.1. 회원가입 출력 함수
inline void printSignUp(ostream& os, const User & user) {
    os << "1.1. 회원가입\n";
    os << "> " << user.getUsername() << " " << user.getPassword() << " " << user.getPhoneNumber() << "\n\n";
}

// 2.1. 로그인 출력 함수
inline void printLogin(ostream& os, const User & user) {
    os << "2.1. 로그인\n";
    os << "> " << user.getUsername() << " " << user.getPassword() << "\n\n";
}

// 2.2. 로그아웃 출력 함수
inline void printLogout(ostream& os, const User & user) {
    os << "2.2. 로그아웃\n";
    os << "> " << user.getUsername() << "\n\n";
}
