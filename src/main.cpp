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
    do{
        menu();
        cout << "Opcion: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            option = 0;
        }
        switch (option){
            
            case 1:
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

                if (type == 'e') {
                    do{
                    eMenu();
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
                            addBook();
                            break;
                        case 2:
                            cout<<"\nLibro a modificar (por favor, separe las palabras con (_): ";
                            cin>>bookTitle;
                            break;
                        case 3:
                            showBooks();
                            deleteBook();
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
                
                break;
            
                case 2:
                    cout<<"\nUsuario (minimo 6 caracteres, no contener caracteres especiales excepto '_'): ";
                    cin>>username;
                    if (username.length() < 6) {
                        cout<<"El usuario es muy corto"<<endl;
                        break;
                    }
                    cout<<"Contrasena (minimo 8 caracteres, no contener caracteres especiales excepto '_'): ";
                    cin>>password;
                    if (password.length() < 8) {
                        cout<<"La contrasena es muy corta"<<endl;
                        break;
                    }
                    registerUser(username, password);
                    cout<<"\nUsuario registrado!"<<endl;
                    break;
            }
    } while (option != 3);
}