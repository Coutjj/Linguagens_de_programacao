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
#include <vector>
#include <random>
#include "estadual.h"
#include "relatorio.h"
#include "nacional.h"

using namespace std;

//funcao para gerar serie historica de obitos
vector<int> vetorObitosAleatorio(){
	int numeroObitos = 15;
	int min = 0;
	int max = 1000;

	random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(min, max);

	vector<int> vetorObitos;
	for (int index = 0; index < numeroObitos; index++){
		vetorObitos.push_back(distr(eng));
	}

	return vetorObitos;
}

int main(){

	Estadual rio("Rio de Janeiro", vetorObitosAleatorio());
	Estadual saoPaulo ("Sao Paulo", vetorObitosAleatorio());
	Estadual minas("Minas Gerais", vetorObitosAleatorio());
	Estadual espiritoSanto("Espirito Santo", vetorObitosAleatorio());

	Nacional brasil("Brasil", {rio, saoPaulo, minas, espiritoSanto});
	int diasMediaMovel;

	cout << "\nBem-vindo(a) ao relatorio da pandemia de COVID-19." << endl;
	cout << "Escolha o numero N de dias para a media movel\n\n";

	cin >> diasMediaMovel;

	if (cin.fail()){
		cout << "\nPrograma abortado\n";
		return -1;
	}

	//Relatorio relatorioRio(rio, diasMediaMovel); //exemplo sobrecarga para estado
	//Relatorio relatorioSP(saoPaulo, diasMediaMovel);
	Relatorio relatorioBrasil(brasil, diasMediaMovel);


	int escolhaUsuarioMenu = -1;
	while (escolhaUsuarioMenu != 0){

		cout << "\nEscolha uma das opcoes abaixo ou selecione 0 (zero) para sair.\n\n";
		cout << "(1) - Evolucao do numero de obitos." << endl;
	  	cout << "(2) - Status dos Estados" << endl;
	  	cout << "(3) - Status Brasil" << endl;
		cout << "(4) - Estado com maior Alta/Baixa" << endl;
		cout << "(5) - Numero acumulado de Obitos\n\n";

		cin >> escolhaUsuarioMenu;

		if (cin.fail()){
			cout << "\nPrograma abortado\n";
			return -1;
		}

		switch (escolhaUsuarioMenu)
		{
			case 0:
				cout << "\nPrograma finalizado." << endl;
				return 0;
			case 1:
				relatorioBrasil.printRelatorioNacional();
				break;
			case 2:
				relatorioBrasil.printStatusEstados();
				break;
			case 3:
				relatorioBrasil.printStatusNacao();
				break;
			case 4:
				relatorioBrasil.printEstadoMaiorAltaBaixa();
				break;
			case 5:
				relatorioBrasil.printObitosAcumulados();
				break;
			default:
				cout << "\nOpcao invalida - digite 0 (zero) para sair ou escolha uma opcao valida\n";
		}
	}

}