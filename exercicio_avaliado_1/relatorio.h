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

#include "estadual.h"
#include "nacional.h"

using namespace std;

class Relatorio
{
    private:
        Estadual estadoObjUnico;
        Nacional nacionalObj;
        int numDiasMedia;

        void setMediaMovel(Estadual);
        void setMediaMovelNacional();
        void setNumDiasMedia(int);
        void setEstado(Estadual);
        void setNacional(Nacional);
        vector<float> calcMedia(Estadual);
    public:
        Relatorio(Estadual, int);
        Relatorio(Nacional, int);
        void printRelatorio();
        void printRelatorioNacional();
        void printStatusEstados();
        void printStatusBrasil();
        void printEstadoMaiorAltaBaixa();
        void printObitosAcumulados();
};


#endif // RELATORIO_H


