#include "User.h"
#include <string>
#include <vector>
#include "Bicycle.h"

class Member : public User {

private:
    std::vector<Bicycle> rentedBicycles; // 대여한 자전거 목록
public:
    Member(const std::string& username, const std::string& password, const std::string& phone)
        : User(username, password, phone, Role::MEMBER) {}

    void rentBicycle(const Bicycle& bicycle) {
        rentedBicycles.push_back(bicycle);
    }

    void returnBicycle(int bicycleId) {
        for (auto it = rentedBicycles.begin(); it != rentedBicycles.end(); ++it) {
            if (it->getId() == bicycleId) {
                rentedBicycles.erase(it);
                return;
            }
        }
    }

    void showRentedBicycles() const override {
        if (rentedBicycles.empty()) {
            std::cout << "대여한 자전거가 없습니다." << std::endl;
            return;
        }
        std::cout << "대여한 자전거 목록:" << std::endl;
        for (const auto& bicycle : rentedBicycles) {
            bicycle.displayInfo();
        }
    }
};
