#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "BicycleModule/presentation.h"
#include "UserModule/presentation.h"
#include "BicycleModule/domain.h"
#include "UserModule/domain.h"
using namespace std;

class FileBoundary {
private:
    ifstream in_fp;

public:
    ofstream out_fp;
    vector<User> users;
    vector<Bicycle> bicycles;

    FileBoundary(const string& inputFile, const string& outputFile)
        : in_fp(inputFile), out_fp(outputFile) {}

    ~FileBoundary() {
        if (in_fp.is_open()) in_fp.close();
        if (out_fp.is_open()) out_fp.close();
    }

    bool readMenu(int& menu1, int& menu2) {
        if (!(in_fp >> menu1 >> menu2)) return false;
        return true;
    }

    // 출력 함수
    void print(const string& s) {
        out_fp << s << endl;
    }

    // 회원가입 정보 읽기
    bool readSignUpInfo(string& username, string& password, string& phoneNumber) {
        if (!(in_fp >> username >> password >> phoneNumber)) return false;
        return true;
    }

    // 로그인 정보 읽기
    bool readLoginInfo(string& username, string& password) {
        if (!(in_fp >> username >> password)) return false;
        return true;
    }

    bool readBicycleInfo(string& id, string& model) {
        if (!(in_fp >> id >> model)) return false;
        return true;
    }

    // 자전거 정보 읽기
    bool readBicycleId(string& id) {
        if (!(in_fp >> id)) return false;
        return true;
    }
};

void doTask(FileBoundary& boundary) {
    int menu1, menu2;
    string username, password, phoneNumber;
    string bicycleId, model;
    User* currentUser = nullptr;

    signUp(boundary.users, "admin", "admin", "010-1234-5678"); // 초기 관리자 계정

    while (boundary.readMenu(menu1, menu2)) {
        switch (menu1) {
            case 1: // 회원 관리
                if (menu2 == 1) { // 회원가입
                    if (boundary.readSignUpInfo(username, password, phoneNumber)) {
                        signUp(boundary.users, username, password, phoneNumber);
                        printSignUp(boundary.out_fp, boundary.users.back());
                    } 
                }
                break;
            case 2: // 로그인/로그아웃
                if (menu2 == 1) { // 로그인
                    if (boundary.readLoginInfo(username, password)) {
                        currentUser = login(boundary.users, username, password);
                        if (currentUser) printLogin(boundary.out_fp, *currentUser);
                    }
                } else if (menu2 == 2) { // 로그아웃
                    if (currentUser) {
                        printLogout(boundary.out_fp, *currentUser);
                        logout(currentUser);
                    }
                }
                break;
            case 3: // 자전거 등록
                if (menu2 == 1) {
                    if (boundary.readBicycleInfo(bicycleId, model)) {
                        registerBicycle(boundary.bicycles, bicycleId, model);
                        printRegisterBicycle(boundary.out_fp, boundary.bicycles.back());
                    }
                }
                break;
           case 4: // 자전거 대여
                if (menu2 == 1) {
                    if (boundary.readBicycleId(bicycleId)) {
                        if (currentUser) {
                            auto result = rentBicycle(boundary.bicycles, bicycleId, currentUser->getUsername());
                            if (result) printRentBicycle(boundary.out_fp, *result.value());
                        }
                    }
                }
                break;
            case 5: // 대여 리스트
                if (menu2 == 1) {
                    if (currentUser) {
                        auto rentedBicycles = getUserRentedBicycles(boundary.bicycles, currentUser->getUsername());
                        printRentedBicycleList(boundary.out_fp, rentedBicycles);
                    } 
                }
                break;
            case 6: // 종료
                if (menu2 == 1) {
                    printExit(boundary.out_fp);
                } else {
                    boundary.out_fp << "6.1. 종료\n";
                }
                break;
            }
        }
    }
