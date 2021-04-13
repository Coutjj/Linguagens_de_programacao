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
#include "estado.h"
#include "relatorio.h"


using namespace std;

int main(){

	vector <int> serieObitosRio = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	Estado rio("Rio de Janeiro", serieObitosRio);
	Relatorio relatorioRio(rio);

	cout << "tamanho: " << relatorioRio.getMediaMovel().size() << endl;
	cout << "tamanho: " << rio.getNome() << endl;
	cout << "tamanho: " << rio.getSerieObitos().size() << endl;
	for(float media: relatorioRio.getMediaMovel()){
		cout << media << endl;
	}

	cout << "Bem-vindo(a) ao relatorio da pandemia de COVID-19.\n"
		<< "Escolha uma das opcoes abaixo ou selecione 0 (zero) para sair." << endl;

	int escolhaUsuarioMenu = -1;
	while (escolhaUsuarioMenu != 0){
	
		cout << "(1) - Evolucao do numero de obitos." << endl;
	  	cout << "(2) - Classificacao dos Estados" << endl;
	  	cout << "(3) - Classificacao dos Estados brasileiros" << endl;

		cin >> escolhaUsuarioMenu;

		switch (escolhaUsuarioMenu)
		{
			case 0:
				cout << "Programa finalizado." << endl;
				return 0;
			case 1:
				cout << "Evolucao do numero de obitos." << endl;
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

		cout << "Escolha outra opcao." << endl;
	}

}