
#include <iostream>
#include "ponto.h"

using namespace std;

Ponto::Ponto(){
    for(int index = 0; index < 3; index++){
        Ponto::coordenadas[index] = 0; 
    }
}


Ponto::Ponto(int entradas[]){
    for(int index = 0; index < 3; index++){
        Ponto::coordenadas[index] = entradas[index]; 
    }

}

void Ponto::printCoordenadas(){
    char letra = 'x';
    for(int index = 0; index < 3; index++){
        cout << letra++ << ": "<< Ponto::coordenadas[index] << endl; 
    }
}

int Ponto::getXYZ(char letra){
    switch (letra)
    {
        case 'x':
            return Ponto::coordenadas[0];
        case 'y':
            return Ponto::coordenadas[1];
        case 'z':
            return Ponto::coordenadas[2];
        default:
            return 0;
    }
}