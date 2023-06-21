#pragma once
#include <iomanip>
#include <iostream>
#include <list>
using namespace std;

class Order
{
private:
    int id;
    string initialClient;
    string nameGun;
    string nameAuto;
    string dateOrder;
    bool status;
public:
    Order();
    ~Order();

    int get_id() {
        return id;
    }
    void set_id(int value) {
        id = value;
    }

    string get_initials_client() {
        return initialClient;
    }
    void set_initials_client(string value) {
        initialClient = value;
    }

    string get_name_gun() {
        return nameGun;
    }
    void set_name_gun(string value) {
        nameGun = value;
    }

    string get_name_auto() {
        return nameAuto;
    }
    void set_name_auto(string value) {
        nameAuto = value;
    }
    string get_date_order() {
        return dateOrder;
    }
    void set_date_order(string value) {
        dateOrder = value;
    }
    bool get_status() {
        return status;
    }
    void set_status(bool value) {
        status = value;
    }
    void print_all();
};
