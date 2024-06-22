#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"functions/functions.cpp"
using namespace std;

string username, password;
char type;

int main() {
    username=getUsername(username);
    password=getPassword(password);
    login(username, password);
    if (login(username, password)==true){
        cout<<"login correcto"<<endl;
        type=getUserType(username, type);
        cout<<type<<endl;
    }
    

    return 0;
}