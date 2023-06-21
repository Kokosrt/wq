#include "Weapon.h"

Weapon::Weapon()
{
    id = 0;
    nameGun = "none";
    price = 300;
    calibr = "none";
}

Weapon::~Weapon()
{
}

void Weapon::print_all()
{
    cout << setiosflags(ios::left);
    cout << setw(5) << id;
    cout << setw(25) << nameGun;
    cout << setw(15) << price;
    cout << setw(5) << calibr << endl << endl;
    cout << "" << endl;
}
