
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
#include "arvore.h"
#include "paciente.h"


int main(){

	int escolhaUsuario = 0;

	Cadastro<Paciente> cadastroPaciente;
	Cadastro<PacienteRecuperado> cadastroPacienteRecuperado;

	Arvore<Paciente> arvorePaciente;
	Arvore<PacienteRecuperado> arvorePacienteRecuperado;
	
	cadastroPaciente.inserirArvore(arvorePaciente);
	cadastroPacienteRecuperado.inserirArvore(arvorePacienteRecuperado);

	// Paciente novoPaciente;
	// novoPaciente.inserirNome();
	// cadastroPaciente.inserirPaciente(novoPaciente);

	while(escolhaUsuario == 0){
		cout << "\nEscolha uma das opcoes abaixo ou  digite 0 (zero) para sair.\n\n";
		cout << "(1) Inserir paciente\n";
		cout << "(2) Inserir paciente recuperado\n";
		cout << "(3) Imprimir cadastro de pacientes\n";
		cout << "(4) Imprimir cadastro de pacientes recuperados\n";
		cout << "(2) Buscar paciente\n\n";

		cin >> escolhaUsuario;

		if(cin.fail()){
			cout << "\nEntrada invalida\n";
			exit(-1);
		}
	
		switch (escolhaUsuario)
		{
			case 1:
			{
				Paciente novoPaciente;
				novoPaciente.inserirNome();
				cadastroPaciente.inserirPaciente(novoPaciente);
			}
				break;
			case 2:
			{
				PacienteRecuperado novoPacienteRecuperado;
				novoPacienteRecuperado.setPaciente();
				cadastroPacienteRecuperado.inserirPaciente(novoPacienteRecuperado);
			}
				break;
			case 3:
			{
				cadastroPaciente.imprime();
			}
				break;
			case 4:
			{
				cadastroPacienteRecuperado.imprime();
			}
				break;
			case 0:
				exit(0);
				break;
			default:
				break;
		}

		escolhaUsuario = 0;
	}
	
}