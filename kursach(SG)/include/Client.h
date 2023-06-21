#pragma once
#include <iomanip>
#include <iostream>
#include <list>
using namespace std;
class Client
{
private:
    int id;
    string initials;
    string phone;
    string email;

public:
    Client();
    ~Client();

    int get_id(){
        return id;
    }
    void set_id(int value) {
        id = value;
    }

    string get_initials() {
        return initials;
    }
    void set_initials(string value) {
        initials = value;
    }

    string get_phone() {
        return phone;
    }
    void set_phone(string value) {
        phone = value;
    }
    string get_email() {
        return email;
    }
    void set_email(string value) {
        email = value;
    }


    void print();
};
