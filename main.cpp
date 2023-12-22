#include <iostream>
#include <fstream>
#include "SHA256.h"
using namespace std;
void Pass(string Username, int number) {
    string Password;
    bool yeet1 = false;
    while (!yeet1) {
        cout << "Password: ";
        cin >> Password;
        ifstream Users;
        Users.open("Pass.txt");
        int count = 0;
        if (Users.is_open()) {
            string lines;
            while (getline(Users, lines)) {
                count++;
            }
            Users.close();
            string Passarr[count];
            Users.open("Pass.txt");
            if (Users.is_open()) {
                string line;
                int i = 0;
                while (getline(Users, line)) {
                    Passarr[i] = line;
                    i++;
                }
                for (int j = 0; j < (sizeof(Passarr) / sizeof(*Passarr)); j++) {
                    if (Passarr[j] == Password) {
                        if (j == number) {
                            cout << "Welcome " << Username;
                            yeet1 = true;
                        }
                    }
                }
                if (!yeet1) {
                    cout << "Incorrect Password!\n";
                }
            } else {
                cout << "File failed to open!";
                yeet1 = true;
            }
        }
    };
}
void User(){
    string Username;
    bool yeet = false;
    while(!yeet) {
        cout << "Username: ";
        cin >> Username;
        ifstream Users;
        Users.open("Users.txt");
        int count = 0;
        if (Users.is_open()) {
            string lines;
            while (getline(Users, lines)) {
                count++;
            }
            Users.close();
            string Userarr[count];
            Users.open("Users.txt");
        if (Users.is_open()) {
            string line;
            int i = 0;
            while (getline(Users, line)) {
                Userarr[i] = line;
                i++;
            }
            for(int j = 0;j < (sizeof(Userarr) / sizeof(*Userarr)); j++){
                if(Userarr[j] == Username){
                    Pass(Username, j);
                    yeet = true;
                }
            }
            }
            if(!yeet) {
                cout << "Incorrect Username!\n";
            }
        } else {
            cout << "File failed to open!";
            yeet = true;
        }
    }
};
void Register(){
    string User;
    string Pass;
    cout << "Create a username: ";
    cin >> User;
    cout << "Create your password: ";
    cin >> Pass;
    string Hash = sha256(Pass);
    ofstream writer_user("Users.txt", ios_base::app);
    if(writer_user.is_open()){
        writer_user << User << "\n";
        cout << "Username added!\n";
    }
    writer_user.close();
    ofstream writer_pass("Pass.txt", ios_base::app);
    if(writer_pass.is_open()){
        writer_pass << Hash << "\n";
        cout << "Password added!\n";
    }
    cout << "Account Created!";
}
int main() {
    string choice;
    cout << "Welcome to the Login Page\n Do you want to: \n (1) Login \n (2) Register\n";
    cin >> choice;
    if(choice == "1") {
        User();
    }
    else if(choice == "2"){
        Register();
    }
}
