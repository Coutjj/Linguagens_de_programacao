/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * classe que modela um grafo. Possibilita encontrar recorrencia de vertices e arestas e o
  * numero N de termos consecutivos mais utilizados.
*/

#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include "vertice.h"
#include "aresta.h"

using namespace std;

class Grafo
{
    private:
        vector<Vertice> vertices; //modela todo o conjunto de vertices
        vector<string> palavras; //recebe todas as palavras do texto
        vector<Aresta> arestas; //modela o conjunto de todas as arestas
        vector<string> caracteres = {".\0", ",\0", ";\0", "-\0"}; //caracteres considerados para quebra de sequencia
        string stringTexto; //recebe o texto formatado em uma string
    public:
        Grafo(string ); // string nome_arquivo
        int retornarRecorrencia(string ); //retorna a recorrencia de uma string no texto
        int recorrenciaAresta(Aresta );// retorna a recorrencia de uma aresta
        void montarVertices(); //cria os vetores de vertices
        void montarArestas(); //cria os vetores de arestas
        void palavrasMaisUtilizadas(); //exibe as palavras mais utilizadas;
        void sequenciade2Termos(); //exibe a sequencia de 2 termos consecutivos mais utilizados
        void sequenciadeNTermos(); //exibe a sequencia de N termos consecutivos mais utilizados
    
};



#endif // GRAFO_H
