/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL670 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Avaliacao 1. Programa para gerar relatorio sobre a pandemia de COVID-19
  * Definicoes da classe Nacional. Esta classe promove a abstracao de um pais, possibilitando
  * definicao de metodos e atributos pertinentes ao proposito da avaliacao.
*/


#ifndef NACIONAL_H
#define NACIONAL_H

#include <vector>
#include "estadual.h"
#include <string>

using namespace std;

class Nacional
{
    private:
        vector<Estadual> estados;
        vector<float> serieMediaMovel; //serie historica da media movel
        string nome;
        void setNome(string);
        void setEstados(vector<Estadual>);

    public:
        Nacional(string, vector <Estadual>);
        Nacional();
        string getNome();
        vector<Estadual> getEstados();
        void setSerieMediaMovel(vector<float>);
        vector<float> getSerieMediaMovel();
};


#endif // NACIONAL_H