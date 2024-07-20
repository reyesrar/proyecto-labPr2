#include <iostream>
#include "./controller/class/class.cpp"
using namespace std;

//Guia para funciones en vista

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
    cout<<"3. Devolver Libro                   "<<endl;
    cout<<"4. Salir                            "<<endl;
    cout<<"/**********************************/"<<endl;
    cout<<endl;
}

void eMenu() {
    cout << endl;
    cout << "/**********************************/" << endl;
    cout << "1. Agregar Libro                    " << endl;
    cout << "2. Modificar Libro                  " << endl;
    cout << "3. Eliminar Libro                   " << endl;
    cout << "4. Salir                            " << endl;
    cout << "/**********************************/" << endl;
    cout << endl;
}

void aMenu() {
    cout << endl;
    cout << "/**********************************/" << endl;
    cout << "1. Comprar Libro                    " << endl;
    cout << "2. Retirar Libro                    " << endl;
    cout << "3. Devolver Libro                   " << endl;
    cout << "4. Agregar Libro                    " << endl;
    cout << "5. Eliminar Libro                   " << endl;
    cout << "6. Modificar Libro                  " << endl;
    cout << "7. Agregar Usuario (cliente)        " << endl;
    cout << "8. Agregar Usuario (empleado/admin) " << endl;
    cout << "9. Eliminar Usuario                 " << endl;
    cout << "0. Salir                            " << endl;
    cout << "/**********************************/" << endl;
    cout << endl;
}

void sMenu() {
    cout << endl;
    cout << "/**********************************/" << endl;
    cout << " Su cuenta se encuentra suspendida  " << endl;
    cout << "/**********************************/" << endl;
    cout << endl;
}