
/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Programa para gereciamento de pacientes.
*/

#include <iostream>
#include "cadastro.h"
#include "paciente.h"

int main(){

	int escolhaUsuario = 0;
	Paciente paciente1, paciente2, paciente3;
	paciente1.inserirNome("Juan");
	paciente2.inserirNome("Luiz");
	paciente3.inserirNome("Manuel");

	Cadastro cadastroHospital;

	cadastroHospital.inserirPaciente(paciente1);
	cadastroHospital.inserirPaciente(paciente2);
	cadastroHospital.inserirPaciente(paciente3);


	while(escolhaUsuario == 0){
		cout << "\nEscolha uma das opcoes abaixo ou  digite 0 (zero) para sair.\n\n";
		cout << "(1) Imprimir cadastro\n";

		cin >> escolhaUsuario;

		if(cin.fail()){
			cout << "\nEntrada errada\n";
			exit(-1);
		}

		switch (escolhaUsuario)
		{
			case 1:
				cadastroHospital.imprime();
				break;
			
			default:
				break;
		}
	}
	
}