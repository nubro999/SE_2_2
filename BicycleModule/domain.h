#pragma once
#include "data.h"
#include <vector>
#include <optional>
#include <string>
using namespace std;

// 자전거 등록
inline void registerBicycle(vector<Bicycle>& bicycles, const string& id, const string& model) {
    bicycles.emplace_back(id, model);
}

// 자전거 대여
inline optional<Bicycle*> rentBicycle(vector<Bicycle>& bicycles, const string& id, const string& userId) {
    for (auto& b : bicycles) {
        if (b.getId() == id) {
            b.setRented(true);
            b.setRenterId(userId); // 대여자 ID 기록
            return &b;
        }
    }
    return nullopt;
}

// 자전거 대여 리스트 조회
inline vector<Bicycle*> getUserRentedBicycles(vector<Bicycle>& bicycles, const string& userId) {
    vector<Bicycle*> result;
    for (auto& b : bicycles) {
        if (b.isRented() && b.getRenterId() == userId) {
            result.push_back(&b);
        }
    }
    return result;
}
