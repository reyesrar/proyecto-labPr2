#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//Guia para funciones en modulo

bool login(string username, string password) {
    ifstream input("users.csv", ios::in);
    if (!input.is_open()) return false;
    else {
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
    ifstream input("users.csv", ios::in);
    if (!input.is_open()) return 0;
    else {
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

void showBooks() { //Implementar algoritmo para imprimir libros
    ifstream input("books.csv", ios::in);
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string title;
        string author;
        string status;
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, status, ',');
    }
}

void buyBook(string bookTitle) {
    ifstream input("books.csv");
    ofstream output("temp.csv");
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

    if (!found) remove("temp.csv");
    else {
        remove("books.csv");
        rename("temp.csv", "books.csv");
    }
}

void withdrawBook(string username, string bookTitle) {
    ifstream input("users.csv");
    ofstream output("temp.csv");
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
            remove("temp.csv");
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

    if (!found) remove("temp.csv");
    else {
        remove("users.csv");
        rename("temp.csv", "users.csv");
    }

    ifstream input2("books.csv");
    ofstream output2("temp.csv");
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

    if (!found2) remove("temp.csv");
    else {
        remove("books.csv");
        rename("temp.csv", "books.csv");
    }   
}

void returnBook(string username) {
    string bookUpdate;

    ifstream input("users.csv");
    ofstream output("temp.csv");
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
            remove("temp.csv");
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

    if (!found) remove("temp.csv");
    else {
        remove("users.csv");
        rename("temp.csv", "users.csv");
    }

    ifstream input2("books.csv");
    ofstream output2("temp.csv");
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

    if (!found2) remove("./bin/data/temp.csv");
    else {
        remove("books.csv");
        rename("temp.csv", "books.csv");
    }
}

void registerUser(string username, string password) {
    ifstream input("users.csv");
    ofstream output("temp.csv");
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
            remove("temp.csv");
            return;
        }
        output << line << endl;
    }

    output << username << "," << password << "," << 'c' << "," << "none" << endl;
    input.close();
    output.close();
    remove("users.csv");
    rename("temp.csv", "users.csv");
    
}

void addBook() {
    string title, author;
    ifstream input("books.csv");
    ofstream output("temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << title << "," << author << "," << "not_sold" << endl;
    input.close();
    output.close();
    remove("books.csv");
    rename("temp.csv", "books.csv");
}

void deleteBook() {
    ifstream input("books.csv");
    ofstream output("temp.csv");
    string line;
    bool found = false;
    string title;
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

    if (!found) remove("temp.csv");
    else {
        remove("books.csv");
        rename("\temp.csv", "books.csv");
    }

}

void editBook() {
    ifstream input("books.csv");
    ofstream output("temp.csv");
    string line;
    bool found = false;
    string title;
    while (getline(input, line)) {
        stringstream ss(line);
        string title2, author, status, author2, status2;
        getline(ss, title2, ',');
        getline(ss, author2, ',');
        getline(ss, status2, ',');

        if (title == title2) {
            found = true;
            output << title << "," << author << "," << status << endl;
        } else output << line << endl;
    }
    input.close();
    output.close();
    if (!found) {
        cout << "Libro no encontrado" << endl;
        remove("temp.csv");
    } else {
        remove("books.csv");
        rename("temp.csv", ".books.csv");
    }
}

void registerEmpoyeeAdmin(char type) {
    string username, password;
    
    ifstream input("users.csv");
    ofstream output("temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << username << "," << password << "," << type << "," << "none" << endl;
    input.close();
    output.close();
    remove("users.csv");
    rename("temp.csv", "users.csv");
}

void showUsers(char type) {
    ifstream input("users.csv");
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string username, password, type2, withdrawedBook;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, type2, ',');
        getline(ss, withdrawedBook, ',');
    }
    input.close();
}

void deleteUser() {
    string username;
    ifstream input("users.csv");
    ofstream output("temp.csv");
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
    if (!found) remove("temp.csv");  
    else {        
        remove("users.csv");
        rename("temp.csv", "users.csv");
    }
}
