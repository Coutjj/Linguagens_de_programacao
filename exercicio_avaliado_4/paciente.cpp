/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe que implementa o objeto Paciente e sua classe herdeira (PacienteRecuperado).
*/

#include <string>
#include "paciente.h"

using namespace std;

Paciente::Paciente(){
    inserirNome();
    setIdade();
}

void Paciente::inserirNome(){
    
    string nomeInput;
    cout << "\nEntre com o nome do paciente:\n\n";
    cin >> nomeInput;
    
    if(cin.fail()){
        cout << "\nEntrada invalida.\n";
        exit(-1);
    }
    
    nome = nomeInput;
}

string Paciente::getNome(){
    return nome;
}

void Paciente::setIdade(){
    
    unsigned int idadeInput;
    cout << "\nEntre com a idade do paciente:\n\n";
    cin >> idadeInput;
    
    if(cin.fail() || idadeInput > 110){
        cout << "\nEntrada invalida.\n";
        exit(-1);
    }
    
    idade = idadeInput;
}

unsigned int Paciente::getIdade(){
    return idade;
}

ostream& operator<<(ostream &out, Paciente &pacienteIput){
    out << pacienteIput.getNome();
    out << " - Idade: " << pacienteIput.getIdade();
    return out;
}

void PacienteRecuperado::setDoencaPrevia(){

    string doenca;

    cout << "\nInserir doenca:\n\n";
    cin >> doenca;

    if(cin.fail()){
        cout << "\nEntrada invalida.\n";
        exit(-1);
    }

    doencaPrevia = doenca;
}

string PacienteRecuperado::getDoencaPrevia(){
    return doencaPrevia;
}

ostream& operator<<(ostream &out, PacienteRecuperado &pacienteIput){
    out << pacienteIput.getNome();
    out << " - Idade: " << pacienteIput.getIdade();
    out << " - Recuperado de: " << pacienteIput.getDoencaPrevia();
    return out;
}