#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include "vertice.h"

using namespace std;

class Grafo
{
    private:
        vector<Vertice> vertices;
        vector<string> palavras;
    public:
        Grafo(string ); // string nome_arquivo
        void lerArquivo(string );
        int retornarRecorrencia(string );
        vector<string> cortarString(string);
        void montarVertices();
    
};



#endif // GRAFO_H
