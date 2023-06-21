#include "Console.h"
#pragma warning(disable : 4996)

void Console::console_PrintOrder()
{
  system("cls");
  cout << setiosflags(ios::left);
  cout << "--- Order ---" << endl << setw(5) << "ID" << setw(25) << "Name" << setw(25) << "Price" << setw(20) << "Calibr" << endl;
  cout << "" << endl;
  GUN.printActiveOrders();
  cout << "---" << endl;
}
void Console::changeStatusOrder() {
  int orderid;
  cout <<" --| Change Status Order |--" << endl << endl;

  console_PrintOrder();
  while (true) {
    cout << endl << endl << "| Input  Order ID|" << endl << " -> ";
    cin >> orderid;
    auto it = GUN.searchOrder(orderid);
    if (it->get_id() == orderid) {
      GUN.changeStatus(it);
      cout << "| Status Changed |" << endl;
      break;
    }
    else
      cout << " | There's no order with that id! | ";
  }
}
Console::Console()
{
}

Console::~Console()
{
}

void Console::Start()
{
    int Action;
    while (true) {

        cout
            << "<----------- Console Interface ----------->" << endl << endl
            << "               <--  All Data -->" << endl << endl
            << " (1) - Client list." << endl
            << " (2) - Weapon list. " << endl
            << " (3) - Order list." << endl
//            << " (4) - Active Order list." << endl << endl
            << "               <-- Input new Data -->" << endl << endl
            << " (4) - Client." << endl
            << " (5) - Weapon. " << endl
            << " (6) - Order." << endl << endl
            << "               <-- Search Data -->" << endl << endl
            << " (7) - Search client by name." << endl
            << " (8) - Search Weapon by name. " << endl << endl
            << "               <-- Deleting Data -->" << endl << endl
            << " (9) - Deleting  Client by name." << endl
            << " (10) - Deleting  Weapon by name. " << endl << endl
            << "               <-- Other -->" << endl << endl
            << " (11) - Change order status." << endl
            << " (12) - Exit App. " << endl << endl
            << "-------------------------------------------------------" << endl << endl << endl
            << " [ Input id of function! ] --> ";
        cin >> Action;
        switch (Action) {
        case 1: {
            system("cls");
            console_PrintClients();
            clearConsole();
            break; }
        case 2: {
            system("cls");
            console_PrintWeapons();
            clearConsole();
            break; }
        case 3: {
            system("cls");
            cout << setiosflags(ios::left);
            cout << "--- Orders list ---" << endl
                << setw(5) << "ID" << setw(25) << "Initials" << setw(25)
                << "Weapon Name" << setw(20) << "Gun name" << endl;
            cout << "---" << endl;
            GUN.printAllOrders();
            cout << "---" << endl;
            clearConsole();
            break; }
//        case 4: {
//
//            console_PrintOrder();
//
//            break; }
        case 4: {
            createClient();
            break; }
        case 5: {
            createWeapon();
            break; }
        case 6: {
            createOrder();
            break; }
        case 7: {
            console_PrintClients();
            searchClient();
            break; }
        case 8: {
            searchWeapon();
            break; }
        case 9: {
            system("cls");

            deleteClient();
            break; }
        case 10: {
            system("cls");

            deleteWeapon();
            break; }
        case 11: {
            system("cls");
            changeStatusOrder();
            clearConsole();
            break; }
        case 12: {
            system("cls");
            GUN.saveAll();
            cout << endl << endl << " [- App ended its work -]" << endl << endl;
            return;
            break; }
        }
    }
}
void Console::createClient()
{
    system("cls"); cin.ignore();
    cout << "-----------| Add Client |-----------" << endl << endl;
    string sTmp;
    Client newClient;
    newClient.set_id(GUN.getSizeClients() + 1);
    cout << " [ Input initials ]" << endl << " -> ";
    getline(cin, sTmp);
    newClient.set_initials(sTmp);
    cout << " [ Input phone ] " << endl << " -> ";
    getline(cin, sTmp);
    newClient.set_phone(sTmp);
    cout << " [ Input email ]" << endl << " -> ";
    getline(cin, sTmp);
    newClient.set_email(sTmp);
    GUN.addToClients(newClient);
    clearConsole();

}
void Console::createWeapon()
{
    system("cls"); cin.ignore();
    cout << "-----------| Create Weapon |-----------" << endl << endl;
    string sTmp;  double sDbl; string sInt;
    Weapon newWeapon;
    newWeapon.set_id(GUN.getSizeWeapons() + 1);
    cout << " [ Input Weapon Name ]" << endl << " -> ";
    getline(cin, sTmp);
    newWeapon.set_nameGun(sTmp);
    cout << " [ Input price (only int numbers)]" << endl << " -> ";
    cin >> sDbl;
    newWeapon.set_price(sDbl);
    cout << " [ calibr ]" << endl << " -> ";
    cin >> sInt;
    newWeapon.set_calibr(sInt);
    GUN.addToWeapons(newWeapon);
    clearConsole();
}


void Console::createOrder()
{
    system("cls"); cin.ignore();
    cout << "-----------| Register Order |-----------" << endl << endl;
    string sTmp;  double sDbl; int sInt;
    Order newOrder;
    newOrder.set_id(GUN.getSizeOrders() + 1);
    console_PrintClients();
    while (true) {
        cout << endl << endl << " [ Input name of client ]" << endl << " -> ";
        getline(cin, sTmp);
        Client it = *GUN.searchClient(sTmp);
        if (it.get_initials() == sTmp) {
            newOrder.set_initials_client(sTmp);
            break;
        }
        else
            cout << " [ There's no client with that name!]";
    }
    system("cls");

    console_PrintWeapons();
    while (true) {
        cout << endl << endl << " [ Weapons list ]" << endl << " -> ";
        getline(cin, sTmp);
        Weapon it = *GUN.searchWeapon(sTmp);
        if (it.get_nameGun() == sTmp) {
            newOrder.set_name_gun(sTmp);
            break;
        }
        else
            cout << " [ No weapons with that name!]";
    }
    system("cls");
    cout << endl << " [ Input Weapon name ]" << endl << " -> ";
    getline(cin, sTmp);
    newOrder.set_name_auto(sTmp);
    time_t now = time(0);
    string dt = ctime(&now);
    dt.erase(24, 1);
    newOrder.set_date_order(dt);
    GUN.addToOrders(newOrder);
    cout << endl << endl << " [ Order added! ] " << endl;
    clearConsole();
}




void Console::console_PrintClients()
{

    cout << setiosflags(ios::left);
    cout << "------------------------- Clients --------------------------------" << endl << endl
        << setw(5) << "ID" << setw(25) << "Name" << setw(20)
        << "phone." << setw(20) << "Email" << endl;
    cout << "------------------------------------------------------------------" << endl;
    GUN.printClients();
    cout << "------------------------------------------------------------------" << endl;

}

void Console::console_PrintWeapons()
{
    system("cls");
    cout << setiosflags(ios::left);
    cout << "------------------------- Weapon list ---------------------------------" << endl
        << setw(5) << "ID" << setw(25) << "Name" << setw(15)
        << "Price" << setw(5) << "Calibr" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    GUN.printWeapons();
    cout << "------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------" << endl;
}
void Console::searchClient()
{
    system("cls");
    console_PrintClients();
    cin.ignore();
    string search_name;
    cout << "-------- Search Client by Name  (Full) --------" << endl << endl;
    cout << endl << " [ Input Initials ] -> ";
    cin >> search_name;
    cout << endl << endl;

    Client it = *GUN.searchClient(search_name);
    if (it.get_initials() == search_name)
        it.print();
    clearConsole();
}

void Console::searchWeapon()
{
    system("cls");
    console_PrintWeapons();
    cin.ignore();
    string search_name;
    cout << "-------- Search Weapon by Name --------" << endl << endl;
    cout << endl << " [ Input name ] -> ";
    cin >> search_name;
    cout << endl << endl;
    Weapon it = *GUN.searchWeapon(search_name);
    if (it.get_nameGun() == search_name)
        it.print_all();
    clearConsole();
}

void Console::deleteClient()
{
    cin.ignore();
    string delete_name;
    console_PrintClients();
    cout << "-------- Deleting clients by Names(Full) --------" << endl << endl;
    cout << " [ Input name ] -> ";
    cin >> delete_name;
    GUN.deleteClient(GUN.searchClient(delete_name));
    cout << endl << " [ Client Deleted !] ";
    clearConsole();
}

void Console::deleteWeapon()
{

    cin.ignore();
    string delete_name;
    console_PrintWeapons();
    cout <<"--------Deleting Weapon by name--------" << endl << endl;
    cout << " [ Input name ] -> ";
    cin>> delete_name;
    GUN.deleteWeapon(GUN.searchWeapon(delete_name));
    cout << endl << " [ Weapon Deleted !] ";
    clearConsole();
}
void Console::clearConsole()
{
    cout << endl << endl << " [-> Click any button to leave <-]" << endl;
    getch();
    system("cls");
}
