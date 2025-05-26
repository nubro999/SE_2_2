#pragma once
#include "data.h"
#include <vector>
#include <optional>
#include <string>
using namespace std;

// 자전거 등록
inline void registerBicycle(vector<Bicycle>& bicycles, int id, const string& model) {
    bicycles.emplace_back(id, model);
}

inline optional<Bicycle*> rentBicycle(vector<Bicycle>& bicycles, int id, const string& userId) {
    for (auto& b : bicycles) {
        if (b.getId() == id && !b.isRented()) {
            b.setRented(true);
            b.setRenterId(userId); // 대여자 ID 기록
            return &b;
        }
    }
    return nullopt;
}


inline vector<Bicycle*> getUserRentedBicycles(vector<Bicycle>& bicycles, const string& userId) {
    vector<Bicycle*> result;
    for (auto& b : bicycles) {
        if (b.isRented() && b.getRenterId() == userId) {
            result.push_back(&b);
        }
    }
    return result;
}
