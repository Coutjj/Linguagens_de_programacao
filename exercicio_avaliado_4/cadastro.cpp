#include "cadastro.h"


void Cadastro::inserirPaciente(Paciente pacienteInput){
    arvoreCadastro += pacienteInput;    
}

void Cadastro::imprime(){
    cout << arvoreCadastro;
}

void Cadastro::busca(){
    
    string nomeInput;

    cout << "\nDigite o nome a ser buscado:\n\n";
    cin >> nomeInput;

    if(cin.fail()){
        cout << "\nOpcao invalida\n";
        exit(-1);
    }

    No<Paciente> *noBusca = arvoreCadastro(nomeInput);
    if(noBusca != NULL){
        cout << "\nDados:\n\n";
        cout << noBusca->dados << endl;
    }
    else{
        cout << "\nA busca nao retornou resultados.\n";
    }
    
}

