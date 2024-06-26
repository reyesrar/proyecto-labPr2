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
    cout<<"3. Devolver Libro                   "<<endl;
    cout<<"4. Salir                            "<<endl;
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
            if (status == "not_sold") {
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

void withdrawBook(string username, string bookTitle) {
    ifstream input("./bin/data/users.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass, type, withdrawedBook;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, type, ',');
        getline(ss, withdrawedBook, ',');

        if (user == username && withdrawedBook != "none") {
            cout << "Usted ya posee un libro retirado" << endl;
            remove("./bin/data/temp.csv");
            return;
        }
        
        if (user == username && withdrawedBook == "none") {
            withdrawedBook = bookTitle;
            type = 's';
            output << user << "," << pass << "," << type << "," << withdrawedBook << endl;
            found = true;
        } else output << line << endl;
            
    }
    input.close();
    output.close();

    if (!found) {
        cout << "Usuario no encontrado" << endl;
        remove("./bin/data/temp.csv");
    } else {
        remove("./bin/data/users.csv");
        rename("./bin/data/temp.csv", "./bin/data/users.csv");
    }

    ifstream input2("./bin/data/books.csv");
    ofstream output2("./bin/data/temp.csv");
    string line2;
    bool found2 = false;

    while (getline(input2, line2)) {
        stringstream ss2(line2);
        string title2, author2, status2;
        getline(ss2, title2, ',');
        getline(ss2, author2, ',');
        getline(ss2, status2, ',');

        if (title2 == bookTitle) {
            status2 = "withdrawed";
            output2 << title2 << "," << author2 << "," << status2 << endl;
            found2 = true;
        } else {
            output2 << line2 << endl;
        }
    }

    input2.close();
    output2.close();

    if (!found2) {
        cout << "Libro no encontrado" << endl;
        remove("./bin/data/temp.csv");
    } else {
        remove("./bin/data/books.csv");
        rename("./bin/data/temp.csv", "./bin/data/books.csv");
    }
    
    cout<<"\n"<<bookTitle<<" retirado exitosamente"<<endl;   
}

void returnBook(string username) {
    string bookUpdate;

    ifstream input("./bin/data/users.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass, type, withdrawedBook;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, type, ',');
        getline(ss, withdrawedBook, ',');

        if (user == username && withdrawedBook == "none") {
            cout << "Usted no posee libros retirados" << endl;
            remove("./bin/data/temp.csv");
            return;
        } 

        if (user == username && withdrawedBook != "none") {
            type = 'c';
            bookUpdate = withdrawedBook;
            withdrawedBook = "none";
            output << user << "," << pass << "," << type << "," << withdrawedBook << endl;
            found = true;
        } else output << line << endl;
    }
    input.close();
    output.close();
    if (!found) {
        cout << "Usuario no encontrado" << endl;
        remove("./bin/data/temp.csv");
    } else {
        remove("./bin/data/users.csv");
        rename("./bin/data/temp.csv", "./bin/data/users.csv");
    }

    ifstream input2("./bin/data/books.csv");
    ofstream output2("./bin/data/temp.csv");
    string line2;
    bool found2 = false;
    while (getline(input2, line2)) {
        stringstream ss2(line2);
        string title2, author2, status2;
        getline(ss2, title2, ',');
        getline(ss2, author2, ',');
        getline(ss2, status2, ',');

        if (title2 == bookUpdate) {
            status2 = "not_sold";
            output2 << title2 << "," << author2 << "," << status2 << endl;
            found2 = true;
        } else output2 << line2 << endl;
    }
    input2.close();
    output2.close();
    if (!found2) {
        cout << "Libro no encontrado" << endl;
        remove("./bin/data/temp.csv");
    } else {
        remove("./bin/data/books.csv");
        rename("./bin/data/temp.csv", "./bin/data/books.csv");
    }
    cout<<"\n"<<bookUpdate<<" devuelto exitosamente"<<endl;
}

void registerUser(string username, string password) {
    ifstream input("./bin/data/users.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass, type, withdrawedBook;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, type, ',');
        getline(ss, withdrawedBook, ',');
        if (user == username) {
            cout << "El usuario ya existe" << endl;
            remove("./bin/data/temp.csv");
            return;
        }
        output << line << endl;
    }

    output << username << "," << password << "," << 'c' << "," << "none" << endl;
    input.close();
    output.close();
    remove("./bin/data/users.csv");
    rename("./bin/data/temp.csv", "./bin/data/users.csv");

    cout << "Usuario creado exitosamente" << endl;
    
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

void addBook() {
    string title, author;
    cout << "Ingresa el nombre del libro (por favor, separe las palabras con (_): ";
    cin >> title;
    cout << "Ingresa el autor del libro (por favor, separe las palabras con (_): ";
    cin >> author;
    ifstream input("./bin/data/books.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << title << "," << author << "," << "not_sold" << endl;
    input.close();
    output.close();
    remove("./bin/data/books.csv");
    rename("./bin/data/temp.csv", "./bin/data/books.csv");
}

void deleteBook() {
    ifstream input("./bin/data/books.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    string title;
    cout<<"\nIngresa el nombre del libro que deseas eliminar (por favor, separe las palabras con (_): ";
    cin>>title;
    while (getline(input, line)) {
        stringstream ss(line);
        string title2, author, status;
        getline(ss, title2, ',');
        getline(ss, author, ',');
        getline(ss, status, ',');

        if (title == title2) {
            found = true;
        } else output << line << endl;
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
    cout<<"\nLibro eliminado exitosamente"<<endl;
}

void editBook() {
    ifstream input("./bin/data/books.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    string title;
    cout<<"\nIngresa el nombre del libro que deseas modificar (por favor, separe las palabras con (_): ";
    cin>>title;
    while (getline(input, line)) {
        stringstream ss(line);
        string title2, author, status, author2, status2;
        getline(ss, title2, ',');
        getline(ss, author2, ',');
        getline(ss, status2, ',');

        if (title == title2) {
            found = true;
            cout << "Ingresa el nuevo nombre del libro (por favor, separe las palabras con (_): ";
            cin >> title;
            cout << "Ingresa el nuevo autor del libro (por favor, separe las palabras con (_): ";
            cin >> author;
            cout << "Ingresa el nuevo estado del libro (por favor, separe las palabras con (_): ";
            cin >> status;
            output << title << "," << author << "," << status << endl;
        } else output << line << endl;
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
    cout<<"\nLibro modificado exitosamente"<<endl;
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

void registerEmpoyeeAdmin(char type) {
    string username, password;
    cout << "Ingresa el nombre de usuario (por favor, separe las palabras con (_): ";
    cin >> username;
    cout << "Ingresa la contrasena de usuario (por favor, separe las palabras con (_): ";
    cin >> password;
    
    ifstream input("./bin/data/users.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << username << "," << password << "," << type << "," << "none" << endl;
    input.close();
    output.close();
    remove("./bin/data/users.csv");
    rename("./bin/data/temp.csv", "./bin/data/users.csv");
    cout << "Usuario registrado exitosamente" << endl;
}

void showUsers(char type) {
    cout << "\nLista de usuarios: " << endl;
    ifstream input("./bin/data/users.csv");
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string username, password, type2, withdrawedBook;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, type2, ',');
        getline(ss, withdrawedBook, ',');
        if (type == type2[0]) {
            cout << username << endl;
        }
    }
    input.close();
}

void deleteUser() {
    string username;
    cout << "\nIngrese el nombre de usuario del usuario a eliminar: ";
    cin >> username;
    ifstream input("./bin/data/users.csv");
    ofstream output("./bin/data/temp.csv");
    string line;
    bool found = false;
    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass, type, withdrawedBook;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, type, ',');
        getline(ss, withdrawedBook, ',');
        if (user == username) {
            found = true;
        } else output << line << endl;
    }
    input.close();
    output.close();
    if (!found) {
        cout << "Usuario no encontrado" << endl;
        remove("./bin/data/temp.csv");  
    } else {        
        remove("./bin/data/users.csv");
        rename("./bin/data/temp.csv", "./bin/data/users.csv");
    }
}