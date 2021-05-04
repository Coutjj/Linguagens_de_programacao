#ifndef  VERTICE_H
#define VERTICE_H

#include <string>

using namespace std;

class Vertice
{
    private:
        string palavraVertice;
        int recorrenciaVertice;
    public:
        Vertice();
        void setRecorrencia(int);
        void setPalavra(string);
        int getRecorrencia();
        string getPalavra();
};


#endif // VERTICE_H


