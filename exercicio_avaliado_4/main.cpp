
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

	Paciente paciente1, paciente2;
	paciente1.inserirNome("Juan");
	paciente2.inserirNome("Luiz");

	Cadastro cadastroHospital;

	cadastroHospital.inserirPaciente(paciente1);
	cadastroHospital.inserirPaciente(paciente2);

	std::cout << "\nPaciente inserido\n";

	return 0;
}