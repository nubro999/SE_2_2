#pragma once
#include "domain.h"
#include <vector>
#include <iostream>
using namespace std;

// 3.1. 자전거 등록 출력
inline void printRegisterBicycle(const Bicycle& bicycle) {
    cout << "3.1. 자전거 등록\n";
    cout << "> " << bicycle.getId() << " " << bicycle.getModel() << "\n";
}

// 4.1. 자전거 대여 출력
inline void printRentBicycle(const Bicycle& bicycle) {
    cout << "4.1. 자전거 대여\n";
    cout << "> " << bicycle.getId() << " " << bicycle.getModel() << "\n";
}

// 5.1. 자전거 대여 리스트 출력
inline void printRentedBicycleList(const vector<Bicycle*>& bicycles) {
    cout << "5.1. 자전거 대여 리스트\n";
    for (const auto* b : bicycles) {
        cout << "> " << b->getId() << " " << b->getModel() << "\n";
    }
}

// 6.1. 종료 출력
inline void printExit() {
    cout << "6.1. 종료\n";
}
