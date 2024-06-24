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

void menu() {
    cout<<endl;
    cout<<"/**********************************/"<<endl;
    cout<<"1. Iniciar Sesion                   "<<endl;
    cout<<"2. Crear Cuenta                     "<<endl;
    cout<<"3. Salir                            "<<endl;
    cout<<"/**********************************/"<<endl;
    cout<<endl;
}

void cMenu() {
    cout<<endl;
    cout<<"/**********************************/"<<endl;
    cout<<"1. Comprar Libro                    "<<endl;
    cout<<"2. Retirar Libro                    "<<endl;
    cout<<"3. Salir                            "<<endl;
    cout<<"/**********************************/"<<endl;
    cout<<endl;
}

void showBooks() {
    ifstream input("./bin/data/books.csv", ios::in);
    if (!input.is_open()) {
        cout << "No se encontró el archivo" << endl;
    } else {
        string line;
        while (getline(input, line)) {
            stringstream ss(line);
            string title;
            string author;
            string status;
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, status, ',');
            if (status == "not sold") {
                cout<<title<<", "<<author<<endl;
            }
        }
    }
}

void buyBook(string bookTitle) {
    ifstream input("./bin/data/books.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;

    while (getline(input, line)) {
        stringstream ss(line);
        string title, author, status;
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, status, ',');

        if (title == bookTitle) {
            status = "sold";
            output << title << "," << author << "," << status << endl;
            found = true;
        } else {
            output << line << endl;
        }
    }

    input.close();
    output.close();

    if (!found) {
        cout << "Libro no encontrado" << endl;
        remove("./bin/data/temp.csv");
    } else {
        remove("./bin/data/books.csv");
        rename("./bin/data/temp.csv", "./bin/data/books.csv");
    }
    cout<<"\n"<<bookTitle<<" comprado exitosamente"<<endl;
}