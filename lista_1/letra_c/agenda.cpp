#include "agenda.h"


void Agenda::getNames (){
    cout << "Nomes na agenda:" << endl;

    for (int index = 0; index < 3; index++){
        cout << names[index] <<endl;
    }
}

void Agenda::setNames(){
    string name;

    for (int index = 0; index < 3; index++){
        cout << "Insira o nome " << index << endl;
        getline(cin, name);
        names [index] = checkName(name);
    }
}

string Agenda::checkName(string name) {
    if (name.length() > 10){
        name = name.substr(0, 10);
        cout << "Nome truncado para: " << name << endl;
    }
    return name;
}