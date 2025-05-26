#pragma once
#include <string>
using namespace std;

class Bicycle {
private:
    string id;
    string model;
    bool rented;
    string renterId; // 대여자 ID 추가

public:
    Bicycle(const string& id, const string& model)
        : id(id), model(model), rented(false), renterId("") {}

    string getId() const { return id; }
    string getModel() const { return model; }
    bool isRented() const { return rented; }
    void setRented(bool value) { rented = value; }
    string getRenterId() const { return renterId; }
    void setRenterId(const string& id) { renterId = id; }
};
