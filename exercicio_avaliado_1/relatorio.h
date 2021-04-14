/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Avaliacao 1. Programa para gerar relatorio sobre a pandemia de COVID-19
  * Definicoes da classe Relatorio. Esta classe concentra todos os metodos e atributos 
  * necessarios para a geracao das informacoes estabelecidas no menu principal.
*/


#ifndef RELATORIO_H
#define RELATORIO_H

#include "estadual.h"
#include "nacional.h"

using namespace std;

class Relatorio
{
    private:
        Estadual estadoObjUnico; //necessario caso a sobrecarga com Estadual seja utilizada
        Nacional nacionalObj;    //necessario caso a sobrecarga com Nacional seja utilizada
        int numDiasMedia;

        void setMediaMovel(Estadual); //(Estadual estadoOBJ) atribui a serie media ao estado
        void setMediaMovelNacional(); //atribui a serie media movel a nacao
        void setNumDiasMedia(int);  //(int rangeMediaMovel) define o numero N de dias que sera considerado no range da media movel
        void setEstado(Estadual);   //define o estado quando sobrecarga Estadual eh utilizada
        void setNacional(Nacional); //define a nacao quando a sobrecarga Nacional eh utilizada
        vector<float> calcMedia(Estadual); //calcula a media historica
    public:
        Relatorio(Estadual, int); //(Estadual estadoOBJ, int rangeMediaMovel)
        Relatorio(Nacional, int); //(Estadual estadoOBJ, int rangeMediaMovel)
        void printRelatorio();  //exibe relatorio para sobrecarga de Estadual
        void printRelatorioNacional(); //exibe relatorio da serie historica da media movel
        void printStatusEstados(); //exibe classificacao dos estados de forma agrupada (Alta/Baixa/Estavel)
        void printStatusNacao(); //exibe classificacao somente para a nacao (Alta/Baixa/Estavel)
        void printEstadoMaiorAltaBaixa(); //exibe os estados com maior alta ou maior baixa
        void printObitosAcumulados(); //exibe o numero acumulado de obitos para estado e nacao
};


#endif // RELATORIO_H


