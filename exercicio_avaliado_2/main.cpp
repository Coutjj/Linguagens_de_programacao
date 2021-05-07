/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Programa para exibir palavras e squencias de palavras mais utilizadas num texto
*/

#include <iostream>
#include "grafo.h"

using namespace std;


int main(){

    int escolhaUsuario = 0;
    Grafo grafoTexto("paragrafo.txt");

    
    while(escolhaUsuario == 0){
        cout << "\nEscolha uma das opcoes abaixo ou digite 0 (zero) para sair:\n" << endl;
        cout << "(1) Palavras mais utilizadas no texto" << endl;
        cout << "(2) Sequencia de duas palavras mais utilizadas" << endl;
        cout << "(3) Sequencia de N palavras" << endl;
        cout << "(0) Ou digite 0 (zero) para sair\n\n";

        cin >> escolhaUsuario;

        if(cin.fail()){
            cout << "Opcao invalida" << endl;
            exit(-1);
        }


        switch (escolhaUsuario)
        {
            case 1:
                grafoTexto.palavrasMaisUtilizadas();
                break;
            case 2:
                grafoTexto.sequenciade2Termos();
                break;
            case 3:
                grafoTexto.sequenciadeNTermos();
                break;
            case 0:
                exit(0);
            default:
                break;
        }

        escolhaUsuario = 0;
    }
}