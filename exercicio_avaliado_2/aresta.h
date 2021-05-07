/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe que modela uma Aresta
*/

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
    void setRecorrencia(int ); //define a reccorencia da aresta
    int getRecorrencia(); // retorna a recorrencia da aresta
    Vertice getVerticeAnterior(); //retorna o primeiro vertice (1) da aresta: (1)--(2)
    Vertice getverticeSeguinte(); //retorna o segundo vertice (2) da aresta: (1)--(2)
    bool CompararVertices(Aresta ); //define a comparacao entre duas arestas
};



#endif // ARESTA_H
