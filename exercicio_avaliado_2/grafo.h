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
        vector<Vertice> vertices;
        vector<string> palavras;
        vector<Aresta> arestas;
        vector<string> caracteres = {".\0", ",\0" ";\0"};
    public:
        Grafo(string ); // string nome_arquivo
        int retornarRecorrencia(string );
        void montarVertices();
        void montarArestas();
        void palavrasMaisUtilizadas();
    
};



#endif // GRAFO_H
