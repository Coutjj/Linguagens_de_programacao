/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe que modela um vertice
*/

#include "vertice.h"


Vertice::Vertice(){

}

void Vertice::setPalavra(string palavra){
    palavraVertice = palavra;
}

void Vertice::setRecorrencia(int recorrencia){
    recorrenciaVertice = recorrencia;
}

string Vertice::getPalavra(){
    return palavraVertice;
}

int Vertice::getRecorrencia(){
    return recorrenciaVertice;
}

