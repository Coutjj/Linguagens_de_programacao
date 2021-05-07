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
        void setRecorrencia(int); //configura recorrencia do vertice
        void setPalavra(string); //configura palavra pertencente ao vertice
        int getRecorrencia(); //retorna a recorrencia do vertice
        string getPalavra(); //retorna a palavra do vertice
};


#endif // VERTICE_H


