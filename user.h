#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

class User{
    private:
        int ID;
        string firstName;
        string lastName;
        int age;
        string email;
        string contactNumber;
        string password;
        
        int generateAccountNumber();
        int integerInputOnly();

    public:
        User();
        void createNewAccount();
        void showData();
};

User::User(){
    this->ID = generateAccountNumber();
}

int User::generateAccountNumber(){
    int ID, generatedID;
    string firstName;
    string lastName;
    int age;
    string email;
    string contactNumber;
    string password;
    
    srand(time(0));

    ifstream fin;
    fin.open("users.txt");

    while(1){
        while(1){
            generatedID = (rand() % 10000) + 100000;
            if(generatedID >= 100000 && generatedID <= 999999){
                break;
            }
        }

        while(1){
            fin >> ID >> firstName >> lastName >> age >> email >> contactNumber >> password;
            if(ID == generatedID){
                break;
            }else{
                goto generateAccountNumberEnd;
            }
        }
    }
    generateAccountNumberEnd:
        fin.close();
        return generatedID;
}

void User::createNewAccount(){
    system("cls");
    cout << "Enter your full name: ";
    fflush(stdin);
    cin >> this->firstName >> this->lastName;
    system("cls");
    cout << "Enter your age: ";
    this->age = integerInputOnly();
    system("cls");
    cout << "Enter your email: ";
    fflush(stdin);
    cin >> this->email;
    system("cls");
    cout << "Enter your contact number: ";
    fflush(stdin);
    cin >> this->contactNumber;
    system("cls");
    cout << "Enter your password: ";
    fflush(stdin);
    cin >> this->password;
    
    showData();
    cout << endl << "Are you sure you want to create an accout? [y/n] : ";
    char choice;
    choice = getch();
    if(choice == 'y' || choice == 'Y'){
        ofstream fout;
        fout.open("users.txt", ios::app);
        fout << this->ID << " " << this->firstName << " " << this->lastName << " " << this->age << " " << this->email << " " << this->contactNumber << " " << this->password << endl;
        fout.close();
        cout << "Account created successfully, press any key to continue..." << endl;
        getch(); 
    }
}

int User::integerInputOnly(){
    int num;
    num = 0;
    char ch;
    while(1){
        ch = getch();
        if(ch >= '0' && ch <= '9'){
            num = (num*10) + (ch - 48);
            cout << ch;
        }else if(ch == 13){
            break;
        }
    }
    return num;
}

void User::showData(){
    system("cls");
    cout << "ID: " << this->ID << endl;
    cout << "Name: " << this->firstName << " " << this->lastName << endl;
    cout << "Age: " << this->age << endl;
    cout << "Email: " << this->email << endl;
    cout << "Contact Number: " << this->contactNumber << endl;
}

#endif