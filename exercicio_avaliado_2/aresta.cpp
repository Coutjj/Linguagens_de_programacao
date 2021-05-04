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