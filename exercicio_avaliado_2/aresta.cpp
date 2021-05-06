#include "aresta.h"

Aresta::Aresta(Vertice verticeAnteriorIput, Vertice verticeSeguinteInput){
    verticeAnterior = verticeAnteriorIput;
    verticeSeguinte = verticeSeguinteInput;
    recorrencia = 0;
}

void Aresta::setRecorrencia(int recorrenciaInput){
    recorrencia = recorrenciaInput;
}

int Aresta::getRecorrencia(){
    return recorrencia;
}

Vertice Aresta::getVerticeAnterior(){
    return verticeAnterior;
}

Vertice Aresta::getverticeSeguinte(){
    return verticeSeguinte;
}

bool Aresta::CompararVertices(Aresta arestaInput){
    if(arestaInput.getVerticeAnterior().getPalavra() == this->verticeAnterior.getPalavra()){
        if(arestaInput.getverticeSeguinte().getPalavra() == this->verticeSeguinte.getPalavra()){
            return true;
        }
    }

    return false;
}