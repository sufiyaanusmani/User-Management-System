#include "user.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

void login();
string passwordMasking();

User *usr;

int main(){
    int choice;
    
    while(1){
        system("cls");
        cout << "1. Login" << endl;
        cout << "2. Create new Account" << endl;
        cout << "3. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                system("cls");
                login();
                break;
            case 2:
                system("cls");
                usr = new User;
                usr->createNewAccount();
                delete usr;
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

void login(){
    system("cls");
    int ID;
    string firstName;
    string lastName;
    int age;
    string email;
    string contactNumber;
    string password;
    int enteredID;
    string enteredPassword;

    bool idFound = false;
    bool passMatch = false;

    cout << "Enter your ID: ";
    cin >> enteredID;

    ifstream fin;
    fin.open("users.txt");
    while(fin.eof() == 0){
        fin >> ID >> firstName >> lastName >> age >> email >> contactNumber >> password;
        if(enteredID == ID){
            idFound = true;
            break;
        }
    }

    fin.close();

    if(idFound == true){
        cout << "Enter your password: ";
        enteredPassword = passwordMasking();
        fin.open("users.txt");
        while(fin.eof() == 0){
            fin >> ID >> firstName >> lastName >> age >> email >> contactNumber >> password;
            if(enteredPassword == password && ID == enteredID){
                usr = new User;
                usr->setData(ID, firstName, lastName, age, email, contactNumber, password);
                cout << "Welcome " << firstName << " " << lastName;
                Sleep(3000);
                fin.close();
                passMatch = true;
                break;
            }
        }
    }else{
        system("cls");
        cout << "Error, this ID does not exists";
        Sleep(3000);
    }

    if(idFound == true && passMatch == false){
        cout << "Wrong Password, please enter a correct password";
        Sleep(3000);
    }
}

string passwordMasking(){
    char ch;
    int backspaceCount = 0;
    string pass = "";
    while(1){
        ch = getch();
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch >= 33 && ch <= 47))
                {
                    pass = pass + ch;
                    cout << "*";
                    backspaceCount++;
                }else if(ch == 13){
                    break;
                }
    }
    system("cls");
    return pass;
}