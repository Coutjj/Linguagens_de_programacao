/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Avaliacao 1. Programa para gerar relatorio sobre a pandemia de COVID-19
*/


#include <iostream>
#include "estadual.h"
#include "relatorio.h"
#include "nacional.h"

using namespace std;

int main(){

	Estadual rio("Rio de Janeiro", {2, 7, 11, 21, 2, 20, 70, 80, 90});
	Estadual saoPaulo ("Sao Paulo", {2, 7, 11, 21, 2, 20, 70, 80, 90});
	Nacional brasil("Brasil", {rio, saoPaulo});
	int diasMediaMovel;

	cout << "\nBem-vindo(a) ao relatorio da pandemia de COVID-19." << endl;
	cout << "Escolha o numero N de dias para a media movel\n\n";

	cin >> diasMediaMovel;
	//Relatorio relatorioRio(rio, diasMediaMovel);
	//Relatorio relatorioSP(saoPaulo, diasMediaMovel);
	Relatorio relatorioBrasil(brasil, diasMediaMovel);


	int escolhaUsuarioMenu = -1;
	while (escolhaUsuarioMenu != 0){

		cout << "\nEscolha uma das opcoes abaixo ou selecione 0 (zero) para sair.\n\n";
		cout << "(1) - Evolucao do numero de obitos." << endl;
	  	cout << "(2) - Classificacao dos Estados" << endl;
	  	cout << "(3) - Classificacao dos Estados brasileiros\n\n";

		cin >> escolhaUsuarioMenu;

		switch (escolhaUsuarioMenu)
		{
			case 0:
				cout << "\nPrograma finalizado." << endl;
				return 0;
			case 1:
				relatorioBrasil.printRelatorioNacional();
				break;
			case 2:
				cout << "Classificacao dos Estados" << endl;
				break;
			case 3:
				cout << "Classificacao dos Estados brasileiros" << endl;
				break;
			default:
				cout << "Opcao invalida - digite 0 (zero) para sair" << endl;
		}
	}

}