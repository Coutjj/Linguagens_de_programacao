#include "cadastro.h"


void Cadastro::inserirPaciente(Paciente pacienteInput){
    arvoreCadastro += pacienteInput;
}

void Cadastro::imprime(){
    printPreorder(arvoreCadastro.raiz);
}

void Cadastro::printPreorder(No<Paciente> * no){
// Stop printing if no node found
    if (no == NULL) 
          return; 
  
     /* first print data of node */
     cout <<  no->dados.getNome() << endl;   
  
     /* then recur on left subtree */
     printPreorder(no->esquerda);   
  
     /* now recur on right subtree */
     printPreorder(no->direita);
}
