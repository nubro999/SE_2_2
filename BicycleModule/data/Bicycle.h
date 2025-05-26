#include <iostream>

class Bicycle {
private:
    std::string model;
    int id;
    bool rented = false; // 자전거가 대여 중인지 여부

public:
    Bicycle(const std::string& model, int id) : model(model), id(id) {}

    void displayInfo() const {
        std::cout << "모델명: " << model << ", 아이디: " << id << std::endl;
    }

    int getId() const {
        return id;
    }

    std::string getModel() const {
        return model;
    }

    bool isRented(){
        return rented;
    }

    void setRented(bool rented) {
        rented = rented;
    }

    ~Bicycle() {
        std::cout << "자전거" << id << "가 삭제되었습니다." << std::endl;
    }
};