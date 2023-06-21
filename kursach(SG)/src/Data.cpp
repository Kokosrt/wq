#include "Data.h"

Data::Data()
{
    initClients();
    initOrders();
    initWeapons();
}

Data::~Data()
{
    clients.clear();
    orders.clear();
    weapons.clear();
}
void Data::deleteWeapon(list<Weapon>::iterator it)
{
    weapons.erase(it);
}
void Data::deleteClient(list<Client>::iterator it)
{
    clients.erase(it);
}

list<Client>::iterator Data::searchClient(string Name)
{
    auto null = clients.begin();
    if (!clients.empty()) {
        for (auto it = clients.begin(); it != clients.end(); it++)
            if (it->get_initials() == Name)
                return it;
        cout << " Client with that id - " << Name << " is not in our db!" << endl;
        return null;
    }
    else {
        cout << " There's no clients!" << endl;
        return null;
    }
}

list<Order>::iterator Data::searchOrder(int id)
{
    auto null = orders.begin();
    if (!orders.empty()) {
        for (auto it = orders.begin(); it != orders.end(); it++)
            if (it->get_id() == id)
                return it;
        cout << " Order with that id - " << id << " is not in our db!" << endl;
        return null;
    }
    else {
        cout << " There's no orders!" << endl;
        return null;
    }
}

list<Weapon>::iterator Data::searchWeapon(string Name)
{
    auto null = weapons.begin();
    if (!weapons.empty()) {
        for (auto it = weapons.begin(); it != weapons.end(); it++)
            if (it->get_nameGun() == Name)
                return it;
        cout << " Weapon with that id - " << Name << " is not in our db!" << endl;
        return null;
    }
    else {
        cout << " There's no weapons!" << endl;
        return null;
    }
}

void Data::printClients()
{

        for (auto it = clients.begin(); it != clients.end(); it++)
            it->print();
}

void Data::changeStatus(list<Order>::const_iterator it)
{
    Order order = *it;
    order.set_status(true);
    orders.insert(it, order);
    orders.erase(it);
}

void Data::printAllOrders()
{
    if (orders.empty())
        cout << " There's no orders!" << std::endl;
    else
        for (auto it = orders.begin(); it != orders.end(); it++)
            it->print_all();
}

void Data::printActiveOrders()
{
    if (orders.empty())
        cout << " There's no orders!" << std::endl;
    else
        for (auto it = orders.begin(); it != orders.end(); it++)
            if (it->get_status() == false)
                it->print_all();
}

void Data::printWeapons()
{
    if (weapons.empty())
        cout << " There's no services!" << std::endl;
    else
        for (auto it = weapons.begin(); it != weapons.end(); it++)
            it->print_all();
}


void Data::saveAll()
{
    saveClients();
    saveOrders();
    saveWeapons();
}


void Data::saveClients()
{
    bool next = false;
    fstream file;
    file.open("TextFiles\\Clients.txt", fstream::out);
    if (!file.is_open())
        cout << "TextFiles\\Clients.txt file closed!" << endl;
    else {
        for (auto it = clients.begin(); it != clients.end(); it++) {
            if (next == true) { file << endl; }
            file << it->get_id();
            file << endl << it->get_initials();
            file << endl << it->get_phone();
            file << endl << it->get_email();

            next = true;
        }
    }
}


void Data::saveOrders()
{

    bool next = false;
    fstream file;
    file.open("TextFiles\\Orders.txt", fstream::out);
    if (!file.is_open())
        cout << "TextFiles\\Orders.txt is closed!" << endl;
    else {
        for (auto it = orders.begin(); it != orders.end(); it++) {
            if (next == true) { file << endl; }
            file << it->get_id();
            file << endl << it->get_initials_client();
            file << endl << it->get_name_gun();
            file << endl << it->get_name_auto();
            file << endl << it->get_date_order();
            file << endl << it->get_status();
            next = true;
        }
    }
}
void Data::saveWeapons()
{
    bool next = false;
    fstream file;
    file.open("TextFiles\\Weapons.txt", fstream::out);
    if (!file.is_open())
        cout << "TextFiles\\Weapons.txt is closed!" << endl;
    else {
        for (auto it = weapons.begin(); it != weapons.end(); it++) {
            if (next == true) { file << endl; }
            file << it->get_id();
            file << endl << it->get_nameGun();
            file << endl << it->get_price();
            file << endl << it->get_calibr();
            next = true;
        }
    }
}


void Data::initClients()
{
    string _string; int _int = 0;
    fstream file;

    file.open("TextFiles\\Clients.txt", fstream::in);
    if (!file.is_open())
        cout << "TextFiles\\Clients.txt is closed!" << endl;
    else {
        Client client;

        while (!file.eof()) {
            file >> _int; file.ignore();
            client.set_id(_int);
            getline(file, _string);
            client.set_initials(_string);
            getline(file, _string);
            client.set_phone(_string);
            getline(file, _string);
            client.set_email(_string);

            clients.push_back(client);
        }
        file.close();
    }
}


void Data::initOrders()
{
    string _string; bool _bool; int _int = 0;
    fstream file;

    file.open("TextFiles\\Orders.txt", fstream::in);
    if (!file.is_open())
        cout << "TextFiles\\Orders.txt file closed!" << endl;
    else {
        Order order;

        while (!file.eof()) {
            file >> _int; file.ignore();
            order.set_id(_int);
            getline(file, _string);
            order.set_initials_client(_string);
            getline(file, _string);
            order.set_name_gun(_string);
            getline(file, _string);
            order.set_name_gun(_string);
            getline(file, _string);
            order.set_date_order(_string);
            file >> _bool;
            order.set_status(_bool);
            orders.push_back(order);
        }
        file.close();
    }
}

void Data::initWeapons()
{
     int _int;   string _string; double _double = 0;
    fstream file;

    file.open("TextFiles\\Weapons.txt", fstream::in);
    if (!file.is_open())
        cout << "TextFiles\\Weapons.txt is closed!" << endl;
    else {
        Weapon weapon;

        while (!file.eof()) {
            file >> _int; file.ignore();
            weapon.set_id(_int);
            getline(file, _string);
            weapon.set_nameGun(_string);
            file >> _double;
            weapon.set_price(_double);
            file >> _string; file.ignore();
            weapon.set_calibr(_string);
            weapons.push_back(weapon);
        }
        file.close();
    }
}
