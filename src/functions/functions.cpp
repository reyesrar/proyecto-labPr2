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

char getUserType(string username, char type) {
    ifstream input("./bin/data/users.csv", ios::in);
    if (!input.is_open()) {
        cout << "No se encontró el archivo" << endl;
    } else {
        string line;
        while (getline(input, line)) {
            stringstream ss(line);
            string user;
            string token;
            char userType;
            getline(ss, user, ',');
            getline(ss, token, ',');
            if (username == user) {
                ss >> userType;
                type = userType;
                return type;
            }

        }
    }
    return 0;
}