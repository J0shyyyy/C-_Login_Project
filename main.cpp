#include <iostream>
#include <fstream>
using namespace std;
void Pass(string Username){
    string Password;
    bool yeet1 = false;
    while(!yeet1) {
        cout <<  "Password: ";
        cin >> Password;
        ifstream Users;
        Users.open("Pass.txt");
        if (Users.is_open()) {
            string line;
            while (getline(Users, line)) {
                if (Password == line) {
                    cout << "Welcome " << Username;
                    yeet1 = true;
                }
            }
            if(!yeet1) {
                cout << "Incorrect Password!\n";
            }
        } else {
            cout << "File failed to open!";
            yeet1 = true;
        }
    }
};
void User(){
    string Username;
    bool yeet = false;
    while(!yeet) {
        cout << "Username: ";
        cin >> Username;
        ifstream Users;
        Users.open("Users.txt");
        if (Users.is_open()) {
            string line;
            while (getline(Users, line)) {
                if (Username == line) {
                    Pass(Username);
                    yeet = true;
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
int main() {
    string choice;
    cout << "Welcome to the Login Page\n Do you want to: \n (1) Login \n (2) Register\n";
    cin >> choice;
    if(choice == "1") {
        User();
    }
}
