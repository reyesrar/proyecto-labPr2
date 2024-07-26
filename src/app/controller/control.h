#include<iostream>
using namespace std;

char getUserType(string username, char type);
bool login(string username, string password);
void showBooks();
void showAllBooks();
void buyBook(string bookTitle);
void withdrawBook(string username, string bookTitle);
void returnBook(string username);
void addBook();
void deleteBook();
void editBook();
void registerUser(string username, string password);
void registerEmployeeAdmin(char type);
void showUsers(char type);
void deleteUser(string username);
void suspendUser(string username);