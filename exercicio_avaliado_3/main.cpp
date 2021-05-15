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
#include <vector>
#include "catalogo.h"

using namespace std;


int main(){

	Catalogo novoCatalogo;
	cout << novoCatalogo;

	Filme filmeNovo;
	filmeNovo.nome = "O ultimo filme";
	filmeNovo.produtora = "A nova produtora";
	filmeNovo.nota = 10;

	novoCatalogo.salvarCatalogo();

	// Filme filme1, filme2, filme3, filme4, filme5, filme6, filme7, filme8, filme9;
	// filme1.nome = "Filme A";
	// filme2.nome = "Filme";
	// filme3.nome = "Destino C maior";
	// filme4.nome = "O amor do inferno da vida";
	// filme5.nome = "Alem daquilo que tudo";
	// filme6.nome = "Filme";
	// filme7.nome = "So um quadrinho";
	// filme8.nome = "Piada do tanque";
	// filme9.nome = "Mais importante que nunca";

    // Catalogo catalogo;
    // catalogo += filme2;
    // catalogo += filme3;
    // catalogo += filme1;
    // catalogo += filme4;
    // catalogo += filme5;
    // catalogo += filme6;

    // vector<Filme> filmes = {filme7, filme8, filme9};

    // catalogo += filmes;

    // cout << catalogo;

	// catalogo -= filme1;

	// cout << catalogo;

	// Filme *filmeProcurado;
	// filmeProcurado = catalogo("Piada do tanque");

	// if (filmeProcurado != NULL){
	// 	cout << "\nA busca retornou: " << filmeProcurado->nome << endl;
	// }
	// else{
	// 	cout << "\nEh null\n";
	// }

	// filme7.produtora = "Produtora 1";
	// filme7.nota = 3;

	// Filme *filmeEditado;
	// filmeEditado = catalogo("So um quadrinho", 3);

	// if (filmeEditado != NULL){
	// 	cout << "\nA busca retornou: " << filmeEditado->nome 
	// 		<< " " << filmeEditado->produtora << " " 
	// 		<< filmeEditado->nota << endl;
	// }
	// else{
	// 	cout << "\nEh null\n";
	// }

	// filmeEditado = catalogo("So um quadrinho", "Nova Produtora 2");

	// if (filmeEditado != NULL){
	// 	cout << "\nA busca retornou: " << filmeEditado->nome 
	// 		<< " " << filmeEditado->produtora << " " 
	// 		<< filmeEditado->nota << endl;
	// }
	// else{
	// 	cout << "\nEh null\n";
	// }

	// cout << catalogo;
	// cout << filme8;

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