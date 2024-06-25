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

                case 2:
                    showBooks();
                    cout<<"\nLibro a retirar (por favor, separe las palabras con (_): ";
                    cin>>bookTitle;                    
                    withdrawBook(username, bookTitle);
                    break;

                case 3:
                    returnBook(username);
                    break;

                case 4:
                    cout<<"Hasta pronto!"<<endl;
                    exit(0);
                    break;
                default:
                    cout<<"Opcion invalida!"<<endl;
                    break;
                }
            
            }while(cOption != 4);
        }
    }
}