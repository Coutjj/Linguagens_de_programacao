#include "cadastro.h"


void Cadastro::inserirPaciente(Paciente pacienteInput){
    No<Paciente> *no;
    no = arvoreCadastro += pacienteInput;
    cout << "\nImprimindo raiz " << no->dados.getNome() << endl;
}