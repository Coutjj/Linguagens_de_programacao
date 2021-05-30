#include <string>
#include "paciente.h"

using namespace std;

// Paciente::Paciente(string nomeInput){
//     inserirNome(nomeInput);
// }

// Paciente::Paciente(){
//     inserirNome();
// }

void Paciente::inserirNome(){
    
    string nomeInput;
    cout << "\nEntre com o nome do paciente\n";
    cin >> nomeInput;
    
    if(cin.fail()){
        cout << "\nEntrada invalida\n";
        exit(-1);
    }
    
    nome = nomeInput;
}

string Paciente::getNome(){
    return nome;
}


ostream& operator<<(ostream &out, Paciente &pacienteIput){
    out << pacienteIput.getNome();
    return out;
}

void PacienteRecuperado::setDoencaPrevia(){

    string doenca;

    cout << "\n\nInserir doenca:\n\n";
    cin >> doenca;

    if(cin.fail()){
        cout << "\nEntrada invalida\n";
        exit(-1);
    }

    doencaPrevia = doenca;
}

string PacienteRecuperado::getDoencaPrevia(){
    return doencaPrevia;
}

ostream& operator<<(ostream &out, PacienteRecuperado &pacienteIput){
    out << pacienteIput.getNome();
    out << " - " << pacienteIput.getDoencaPrevia();
    return out;
}

void PacienteRecuperado::setPaciente(){
    inserirNome();
    setDoencaPrevia();
}