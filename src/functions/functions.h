#include<iostream>
using namespace std;

string getUsername(string username);
string getPassword(string password);
bool login(string username, string password);
char getUserType(string username, char type);
void menu();
void cMenu();
void showBooks();
void buyBook(string bookTitle);
void withdrawBook(string username, string bookTitle);
void returnBook(string username);
void registerUser(string username, string password);
void eMenu();
void addBook();
void deleteBook();
void editBook();