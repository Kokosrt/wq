#pragma once
#include <conio.h>
#include <ctime>
#include <list>
#include <fstream>
#include <string>


#include "Client.h"
#include "Order.h"
#include "Weapon.h"

class Data
{
private:
    list<Client> clients;
    list<Order> orders;
    list<Weapon> weapons;

    void initClients();
    void initOrders();
    void initWeapons();
public:
  Data();
  ~Data();



    void addToClients(Client client) { clients.push_back(client); }
    void addToOrders(Order order) { orders.push_back(order); }
    void addToWeapons(Weapon weapon) { weapons.push_back(weapon); }



    void deleteWeapon(list<Weapon>::iterator it);
    void deleteClient(list<Client>::iterator it);




    int getSizeClients() { return clients.size(); }
    int getSizeOrders() { return orders.size(); }
    int getSizeWeapons() { return weapons.size(); }



    list<Client>::iterator searchClient(string Name);
    list<Weapon>::iterator searchWeapon(string Name);
    list<Order>::iterator searchOrder(int id);


    void printClients();
    void printAllOrders();
    void printActiveOrders();
    void printWeapons();



    void saveAll();
    void saveClients();
    void saveOrders();
    void saveWeapons();

    void changeStatus(list<Order>::const_iterator iterat);
};
