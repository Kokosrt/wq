#pragma once
#include "Data.h"
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
using namespace std;
class Console
{
private:
  Data GUN;
public:
  Console();

  ~Console();

  void Start();

  void console_PrintClients();
  void console_PrintWeapons();
  void console_PrintOrder();

  void createClient();
  void createWeapon();
  void createOrder();

  void searchClient();
  void searchWeapon();

  void deleteClient();
  void deleteWeapon();

  void changeStatusOrder();
  void clearConsole();


  void console_Print();
};
