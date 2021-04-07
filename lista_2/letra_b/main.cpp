/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * programa para calcular a distancia entre dois pontos usando uma classe
*/

#include <iostream>
#include <vector>
#include "ponto.h"
#include "linha.h"

using namespace std;

int main (){

    int pontos [2][3] = {{0}};
    cout << "Programa para o calculo da distancia entre dois pontos." << endl;

    for(unsigned int index = 0; index < 2; index++){
        cout << "Insira o ponto " << index << endl;
        char letra = 'x';
        for(unsigned int subIndex = 0; subIndex < 3; subIndex++){
            int valor;
            cout << letra++ << ": ";
            cin >> valor;
            pontos[index][subIndex] = valor;
        }
    }

    Ponto ponto0(pontos[0]);
    Ponto ponto1(pontos[1]);

    Linha minhaLinha (ponto0, ponto1);

    // ponto0.printCoordenadas();
    // ponto1.printCoordenadas();

    float comprimento = minhaLinha.getComprimento();

    cout << "O comprimento da linha eh: " << comprimento << endl;


}