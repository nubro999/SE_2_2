#include <iostream>
#include <vector>
#include <Bicycle.h>
#include <Member.h>
#include <RegisterBicycle.h>

class RentBicycle {
private:
    std::vector<Bicycle> bicycles;
    User *user = nullptr; // 현재 로그인한 사용자
    RegisterBicycle registerBicycle;
public:
    RentBicycle() {
        // 초기 자전거 등록
        registerBicycle.registerBicycle("Mountain Bike", 1);
        registerBicycle.registerBicycle("Road Bike", 2);
        registerBicycle.registerBicycle("Hybrid Bike", 3);
    }

    void rentBicycle(Member* member) {
        if (user == nullptr) {
            std::cout << "로그인 후 이용해주세요." << std::endl;
            return;
        }

        std::cout << "대여 가능한 자전거 목록:" << std::endl;
        registerBicycle.displayBicycles();

        int id;
        std::cout << "대여할 자전거의 ID를 입력하세요: ";
        std::cin >> id;
        for (auto& bicycle : bicycles) {
            if (bicycle.getId() == id) {
                if (bicycle.isRented() == false) {
                    bicycle.setRented(true);
                    std::cout << "자전거 " << bicycle.getModel() << "이(가) 대여되었습니다." << std::endl;
                    member->rentBicycle(bicycle);
                    return;
                } else {
                    std::cout << "해당 자전거는 이미 대여 중입니다." << std::endl;
                    return;
                }
            }
        }

    }
};