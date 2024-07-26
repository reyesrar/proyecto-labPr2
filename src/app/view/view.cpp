#include <iostream>
#include "../controller/control.cpp"
using namespace std;

string username, password, bookTitle;
char type, eType;
int option, cOption;

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
    cout << "10. Suspender Usuario               " << endl;
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

void run(){
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
                if (login(username, password) == true){
                    type = getUserType(username, type);
                }
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
                            showAllBooks();
                            editBook();
                            break;
                        case 3:
                            showAllBooks();
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

                if (type == 'a') {
                    do{
                    aMenu();
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
                            addBook();
                            break;

                        case 5:
                            showAllBooks();
                            editBook();
                            break;

                        case 6:
                            showAllBooks();
                            deleteBook();
                            break;

                        case 7:
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

                        case 8:
                            cout<<"\nTipo de usuario a registar (e: Empleado, a: Administrador): ";
                            cin>>eType;
                            if (eType == 'e' || 'a') registerEmpoyeeAdmin(eType);
                            else cout<<"Opcion invalida!"<<endl;
                            break;
                            
                        case 9:
                            cout << "\nTipo de usuarios a mostrar (e: empleado, c: cliente, s: suspendido): ";
                            cin >> eType;
                            if (eType == 'e' || 'c' || 's'){
                                cout << endl;
                                 showUsers(eType);
                                cout << "\nUsuario a borrar: ";
                                cin >> username; 
                                 deleteUser(username);
                            }else cout << "Opcion invalida!" << endl;
                            break;

                        case 10:
                            cout<<"\nLista de Clientes: "<<endl;
                            showUsers('c');
                            cout<<"\nUsuario a suspender: ";
                            cin>>username;
                            suspendUser(username);
                            break;
                        case 0:
                            cout<<"Hasta pronto!"<<endl;
                            exit(0);
                            break;
                            
                        default:
                            cout<<"Opcion invalida!"<<endl;
                            break;
                        }
                    } while (cOption != 0);
                }

                if (type == 's') {
                    sMenu();
                    break;
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
                    
                case 3:
                    cout<<"Hasta pronto!"<<endl;
                    exit(0);
                    break;
                    
                default:
                    cout<<"Opcion invalida!"<<endl;
                    break;
            }
    } while (option != 3);
    
}