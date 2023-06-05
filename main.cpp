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
void Register(){
    string User;
    string Pass;
    cout << "Create a username: ";
    cin >> User;
    cout << "Create your password: ";
    cin >> Pass;
    ofstream writer_user("Users.txt", ios_base::app);
    if(writer_user.is_open()){
        writer_user << "\n" << User;
        cout << "Username added!\n";
    }
    writer_user.close();
    ofstream writer_pass("Pass.txt", ios_base::app);
    if(writer_pass.is_open()){
        writer_pass << "\n" << Pass;
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
