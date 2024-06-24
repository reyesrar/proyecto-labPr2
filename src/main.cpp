#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"functions/functions.cpp"
using namespace std;

string username, password, bookTitle;
char type;
int option, cOption;

int main() {
    menu();
    cout << "Opcion: ";
    cin >> option;
    if (option == 1) {
        cout<<endl;
        username = getUsername(username);
        password = getPassword(password);
        if (login(username, password) == true) type = getUserType(username, type);
        if (type == 'c') {
            do{
            cMenu();
            cout<<"Opcion: ";
            cin>>cOption;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cOption = 0;
            }
            fflush(stdin);
            switch (cOption){
                case 1:
                    showBooks();
                    cout<<"\nLibro a comprar (por favor, separe las palabras con (_): ";
                    cin>>bookTitle;
                    buyBook(bookTitle);
                    break;
            
                default:
                    break;
                }
            
            }while(cOption != 3);
        }
    }
}