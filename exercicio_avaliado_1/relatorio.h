/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Avaliacao 1. Programa para gerar relatorio sobre a pandemia de COVID-19
  * Definicoes da classe Relatorio. Esta classe concentra todos os metodos contendo regras
  * para os calculos requeridos.
*/



#ifndef RELATORIO_H
#define RELATORIO_H

#include "estado.h"

using namespace std;

class Relatorio
{
    private:
        vector<float> mediaMovel;
        Estado estadoObjUnico;

        void setMediaMovel();
    public:
        Relatorio(Estado);
        vector<float> getMediaMovel();
};


#endif // RELATORIO_H


