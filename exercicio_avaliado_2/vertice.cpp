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

