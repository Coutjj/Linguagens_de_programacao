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

	/*A classe Cadastro foi contruida de maneira geral, podendo receber qualquer objeto especificado.
	 Ainda assim, como o PacienteRecuperado eh herdeiro de Paciente, ele poderia ser utilizado na classe
	 Cadastro<Paciente>. */
	Cadastro<Paciente> cadastroPaciente;
	Cadastro<PacienteRecuperado> cadastroPacienteRecuperado;

	/*Cada arvore recebe um objeto distinto, de maneira que possamos visualizar os atributos
	de cada tipo passado. No entanto, caso um objeto PacienteRecuperado fosse adicionado em Arvore<Paciente>,
	a arvore receberia o objeto herdeiro normalmente.*/
	Arvore<Paciente> arvorePaciente;
	Arvore<PacienteRecuperado> arvorePacienteRecuperado;
	
	/*Cadastros recebendo arvores de tipos distintos.*/
	cadastroPaciente.inserirArvore(arvorePaciente);
	cadastroPacienteRecuperado.inserirArvore(arvorePacienteRecuperado);

	while(escolhaUsuario == 0){
		cout << "\nEscolha uma das opcoes abaixo ou  digite 0 (zero) para sair.\n\n";
		cout << "(1) Inserir paciente\n";
		cout << "(2) Inserir paciente recuperado\n";
		cout << "(3) Imprimir cadastro de pacientes\n";
		cout << "(4) Imprimir cadastro de pacientes recuperados\n";
		cout << "(5) Buscar paciente\n";
		cout << "(6) Buscar paciente recuperado\n\n";

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
				cadastroPaciente.inserirPaciente(novoPaciente);
			}
				break;
			case 2:
			{
				PacienteRecuperado novoPacienteRecuperado;
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
			case 5:
			{
				cadastroPaciente.busca();
			}
				break;
			case 6:
			{
				cadastroPacienteRecuperado.busca();
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