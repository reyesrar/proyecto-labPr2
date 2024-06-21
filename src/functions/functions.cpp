#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"functions.h"
using namespace std;

string getUsername(string username) {
    cout << "Usuario: ";
    cin >> username;
    return username;
}

string getPassword(string password) {
    cout << "Contrasena: ";
    cin >> password;
    return password;
}

bool login(string username, string password) {
    ifstream input("./bin/data/users.csv", ios::in);
    if (!input.is_open()) {
        cout << "No se encontró el archivo" << endl;
        return false;
    } else {
        string line;
        string user, pass;
        while (getline(input, line)) {
            stringstream ss(line);
            getline(ss, user, ',');
            getline(ss, pass, ',');
            if (username == user && password == pass) {
                return true;
            }
        }
    }
    return false;
}

char getUserType(char type) {
    return type;
}