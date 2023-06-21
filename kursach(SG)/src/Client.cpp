#include "Client.h"

Client::Client()
{
    id = 0;
    initials = "none";
    phone = "none";
    email = "none";

}

Client::~Client()
{
}

void Client::print()
{
    cout << setiosflags(ios::left);
    cout << setw(5) << id;
    cout << setw(25) << initials;
    cout << setw(20) << phone;
    cout << setw(20) << email << endl << endl;

    cout << "" << endl;
}
