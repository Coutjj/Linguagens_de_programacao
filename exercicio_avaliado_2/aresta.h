#ifndef ARESTA_H
#define ARESTA_H

#include "aresta.h"
#include "vertice.h"

class Aresta
{
private:
    Vertice verticeAnterior;
    Vertice verticeSeguinte;
    int recorrencia;
public:
    Aresta(Vertice, Vertice); //verticeAnterior VerticeSeguinte
    void setRecorrencia(int );
    int getRecorrencia();
    Vertice getVerticeAnterior();
    Vertice getverticeSeguinte();
};



#endif // ARESTA_H
