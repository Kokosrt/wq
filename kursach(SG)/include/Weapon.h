#pragma once
#include <iomanip>
#include <iostream>
#include <list>
using namespace std;
class Weapon
{
private:
    int id;
    string nameGun;
    double price;
    string calibr;
public:
    Weapon();
    ~Weapon();

    int get_id() {
        return id;
    }
    void set_id(int value) {
        id = value;
    }

    string get_nameGun() {
        return nameGun;
    }
    void set_nameGun(string value) {
        nameGun = value;
    }

    double get_price() {
        return price;
    }
    void set_price(double value) {
        price = value;
    }

    string get_calibr() {
        return calibr;
    }
    void set_calibr(string value) {
        calibr = value;
    }
    void print_all();
};
