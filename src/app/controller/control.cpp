#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"control.h"
using namespace std;

char getUserType(string username, char type) {
    ifstream input("src/app/model/users.csv", ios::in);
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

bool login(string username, string password) {
    ifstream input("src/app/model/users.csv", ios::in);
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


void showBooks() {
    ifstream input("src/app/model/books.csv", ios::in);
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string title;
        string author;
        string status;
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, status, ',');

        if (status == "not_sold") cout << title << ", " << author << " " << endl;
    }
}

void showAllBooks() {
    ifstream input("src/app/model/books.csv", ios::in);
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string title;
        string author;
        string status;
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, status, ',');

        cout << title << ", " << author << " " << status << endl;
    }
}

void buyBook(string bookTitle) {
    ifstream input("src/app/model/books.csv");
    ofstream output("src/app/model/temp.csv");
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

    if (!found) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/books.csv");
        rename("src/app/model/temp.csv", "src/app/model/books.csv");
    }
}

void withdrawBook(string username, string bookTitle) {
    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv"); 
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
            remove("src/app/model/temp.csv");
            return;
        }
        
        if (user == username && withdrawedBook == "none") {
            withdrawedBook = bookTitle;
            output << user << "," << pass << "," << type << "," << withdrawedBook << endl;
            found = true;
        } else output << line << endl;
            
    }
    input.close();
    output.close();

    if (!found) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/users.csv");
        rename("src/app/model/temp.csv", "src/app/model/users.csv");
    }

    ifstream input2("src/app/model/books.csv");
    ofstream output2("src/app/model/temp.csv");
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

    if (!found2) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/books.csv");
        rename("src/app/model/temp.csv", "src/app/model/books.csv");
    }   
}

void returnBook(string username) {
    string bookUpdate;

    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv");
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
            remove("src/app/model/temp.csv");
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

    if (!found) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/users.csv");
        rename("src/app/model/temp.csv", "src/app/model/users.csv");
    }

    ifstream input2("src/app/model/books.csv");
    ofstream output2("src/app/model/temp.csv");
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

    if (!found2) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/books.csv");
        rename("src/app/model/temp.csv", "src/app/model/books.csv");
    }
}

void registerUser(string username, string password) {
    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv");
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
            remove("src/app/model/temp.csv");
            return;
        }
        output << line << endl;
    }

    output << username << "," << password << "," << 'c' << "," << "none" << endl;
    input.close();
    output.close();
    remove("src/app/model/users.csv");
    rename("src/app/model/temp.csv", "src/app/model/users.csv");
    
}

void addBook() {
    string title, author;
    ifstream input("src/app/model/books.csv");
    ofstream output("src/app/model/temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << title << "," << author << "," << "not_sold" << endl;
    input.close();
    output.close();
    remove("src/app/model/books.csv");
    rename("src/app/model/temp.csv", "src/app/model/books.csv");
}

void deleteBook() {
    ifstream input("src/app/model/books.csv");
    ofstream output("src/app/model/temp.csv");
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

    if (!found) remove("src/app/model/temp.csv");
    else {
        remove("src/app/model/books.csv");
        rename("src/app/model/temp.csv", "src/app/model/books.csv");
    }

}

void editBook() {
    ifstream input("src/app/model/books.csv");
    ofstream output("src/app/model/temp.csv");
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
        remove("src/app/model/temp.csv");
    } else {
        remove("src/app/model/books.csv");
        rename("src/app/model/temp.csv", "src/app/model/books.csv");
    }
}

void registerEmployeeAdmin(char type) {
    string username, password;
    
    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv");
    string line;
    while (getline(input, line)) {
        output << line << endl;
    }
    output << username << "," << password << "," << type << "," << "none" << endl;
    input.close();
    output.close();
    remove("src/app/model/users.csv");
    rename("src/app/model/temp.csv", "src/app/model/users.csv");
}

void showUsers(char type) {
    ifstream input("src/app/model/users.csv");
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string username, password, type2, withdrawedBook;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, type2, ',');
        getline(ss, withdrawedBook, ',');

        if (type == type2[0]) cout << username << endl;
        
    }
    input.close();
}

void deleteUser(string username) {
    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv");
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
    if (!found) remove("src/app/model/temp.csv");  
    else {        
        remove("src/app/model/users.csv");
        rename("src/app/model/temp.csv", "src/app/model/users.csv");
    }
}

void suspendUser(string username) {
    ifstream input("src/app/model/users.csv");
    ofstream output("src/app/model/temp.csv");
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
            output << user << "," << pass << "," << 's' << "," << withdrawedBook << endl;
        } else output << line << endl;
    }
    input.close();
    output.close();
    if (!found) remove("src/app/model/temp.csv");  
    else {        
        remove("src/app/model/users.csv");
        rename("src/app/model/temp.csv", "src/app/model/users.csv");
    }
}