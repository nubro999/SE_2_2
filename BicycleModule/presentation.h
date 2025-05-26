#pragma once
#include "domain.h"
#include <vector>
#include <iostream>
using namespace std;

// 3.1. 자전거 등록 출력
inline void printRegisterBicycle(ostream& os, const Bicycle& bicycle) {
    os << "3.1. 자전거 등록\n";
    os << "> " << bicycle.getId() << " " << bicycle.getModel() << "\n\n";
}

// 4.1. 자전거 대여 출력
inline void printRentBicycle(ostream& os, const Bicycle& bicycle) {
    os << "4.1. 자전거 대여\n";
    os << "> " << bicycle.getId() << " " << bicycle.getModel() << "\n\n";
}

// 5.1. 자전거 대여 리스트 출력
inline void printRentedBicycleList(ostream& os, const vector<Bicycle*>& bicycles) {
    os << "5.1. 자전거 대여 리스트\n";
    for (const auto* b : bicycles) {
        os << "> " << b->getId() << " " << b->getModel() << "\n";
    }
    os << "\n";
}

// 6.1. 종료 출력
inline void printExit(ostream& os) {
    os << "6.1. 종료\n";
}
