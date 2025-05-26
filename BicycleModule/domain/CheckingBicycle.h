#include<iostream>
#include "Bicycle.h"
#include "RegisterBicycle.h"
#include "RentBicycle.h"
#include "UserService.h"
#include "Member.h"

class CheckingBicycle {
private:
    RegisterBicycle registerBicycle;
    RentBicycle rentBicycle;
    UserService userService;
public:
//회원이 대여한 자전거 목록확인
    void checkRentedBicycles(User* member) {
        if (member == nullptr) {
            std::cout << "로그인 후 이용해주세요." << std::endl;
            return;
        }

        std::cout << member->getUsername() << "님이 대여한 자전거 목록:" << std::endl;
        for (const auto& bicycle : member->showRentedBicycles()) {
            bicycle.displayInfo();
        }
    }
};

