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
#include <stdio.h>
#include <unistd.h>
#include "catalogo.h"
#include "menu.h"

using namespace std;


int main(int argc, char *argv[]){

	Menu menu;

	if(argc == 1){
		menu.opcoes();
	}
	else{

		int opcao;
		while((opcao = getopt(argc, argv, ":i:")) != -1 ){
			switch (opcao)
			{
				case 'i':
					cout << "\nC quer inserir " << optarg;
					break;
				
				default:
					break;
			}
		}
	}
    
}