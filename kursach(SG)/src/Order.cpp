#include "Order.h"

Order::Order()
{
    id = 0;
    initialClient = "none";
    nameGun = "none";
    nameAuto = "none";
    dateOrder = "none";
    status = false;
}

Order::~Order()
{
}

void Order::print_all()
{
    cout << setiosflags(ios::left);
    cout << setw(5) << id;
    cout << setw(25) << initialClient;
    cout << setw(25) << nameGun;
    cout << setw(20) << nameAuto << endl << endl;
    cout << setw(5) << " order date: " << dateOrder;
    cout << setw(5) << " status: " << (status ? "completed" : "in work") << endl;
    cout << "" << endl;
}
