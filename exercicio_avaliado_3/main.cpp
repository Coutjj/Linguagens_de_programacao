/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Programa para gerenciar catalogos de um filme.
*/

#include <iostream>
#include "catalogo.h"

using namespace std;


int main(){

    Filme filme1, filme2, filme3;
    filme1.nome = "Filme A";
    filme2.nome = "Filme";
    filme3.nome = "Destino C maior";

    Catalogo catalogo;
    catalogo += filme2;
    catalogo += filme3;
    catalogo += filme1;

    catalogo.exibirFilmes();

    // int escolhaUsuario = 0;

    // while (escolhaUsuario == 0)
    // {
    //     cout << "\n Escolha uma das opcoes abaixo ou digite 0 (zero) para sair.\n\n";
    //     cout << "Inserir novo filme na lista ordenada\n\n";

    //     cin >> escolhaUsuario;

    //     if(cin.fail()){
    //         cout << "Operacao invalida\n";
    //         exit(-1);
    //     }

    //     switch (escolhaUsuario)
    //     {
    //     case 1:
    //         /* code */
    //         break;
        
    //     default:
    //         break;
    //     }

    // }
}