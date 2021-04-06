/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * programa para calcular o volume de um paralelepipedo
*/

#include <iostream>
#include "paralelepipedo.h"

using namespace std;

void checandoEntradas(int vetor[]){
    
    for(int index = 0; index < 3; index++){

        if (vetor[index] < 0){
            vetor[index] = 1;
        }

    }

}

int main() {

    int dimxyz[3] = {0};

    cout 
        << "Entre com as dimensoes do paralelepipedo.\n"
        << "x: ";
    cin >> dimxyz[0];
    cout << "y: ";
    cin >> dimxyz[1];
    cout << "z: ";
    cin >> dimxyz[2];

    checandoEntradas(dimxyz);

    Paralelepipedo meuParalelepipedo(dimxyz);

    cout << "O volume do paralelepipedo é de: " << meuParalelepipedo.getVolume() << endl;
}