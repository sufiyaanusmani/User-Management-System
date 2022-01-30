#include "user.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int main(){
    int choice;
    User *u;
    while(1){
        system("cls");
        cout << "1. Login" << endl;
        cout << "2. Create new Account" << endl;
        cout << "3. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            // case 1:
            //     system("cls");
            //     login();
            //     break;
            case 2:
                system("cls");
                u = new User;
                u->createNewAccount();
                break;
            case 3:
                system("cls");
                cout << "Thankyou for using our service" << endl;
                Sleep(3000);
                break;
            default:
                system("cls");
                cout << "Wrong choice entered, please enter a valid choice" << endl;
                Sleep(4000);
                break;
        }
    }
    return 0;
}