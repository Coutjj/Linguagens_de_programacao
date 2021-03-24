
/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima

*/

#include <iostream>
#include "fibonacci.h"

using namespace std;

int main (){

    int indice;
    cout << "Escolha o indice da serie de fibonacci." << endl;
    cin >> indice;
    
    if (cin.fail()){
        cout << "Entrada invalida." << endl;
        return -1;
    }

    if (indice < 0){
        cout << "Entrada invalida." << endl;
        return -1;
    }

    if (indice > 46){
        cout << "Entrada invalida." << endl;
        return -1;
    }

    cout << "Fibonacci de indice " << indice << " igual a: " << fibonacciRecursivo(indice) << endl;

}