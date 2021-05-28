#include <string>
#include "paciente.h"

using namespace std;

Paciente::Paciente(){

}

void Paciente::inserirNome(string nomeInput){
    nome = nomeInput;
}

string Paciente::getNome(){
    return nome;
}