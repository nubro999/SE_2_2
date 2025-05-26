#include <iostream>
#include <vector>
#include <Bicycle.h>

class RegisterBicycle {
private:
    std::vector<Bicycle> bicycles;
    int nextId; // 다음 자전거 ID  
public:
    RegisterBicycle() : nextId(1) {}

    void registerBicycle(const std::string& model, const int id) {
        Bicycle newBicycle(model, id);
        bicycles.push_back(newBicycle);
        std::cout << "자전거가 등록되었습니다: ";
        newBicycle.displayInfo();
    }

    void displayBicycles() const {
        if (bicycles.empty()) {
            std::cout << "등록된 자전거가 없습니다." << std::endl;
            return;
        }
        std::cout << "등록된 자전거 목록:" << std::endl;
        for (const auto& bicycle : bicycles) {
            bicycle.displayInfo();
        }
    }
};