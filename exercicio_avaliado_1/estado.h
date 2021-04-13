/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Avaliacao 1. Programa para gerar relatorio sobre a pandemia de COVID-19
  * Definicoes da classe Estado. Esta classe condensa todos os atributos referentes a um estado,
  * alem de fornecer metodos para que estas informacoes sejam acessadas e configuradas.
*/

#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <vector>

using namespace std;

class Estado
{
    private:
        string nome;
        vector <int> serieObitos;
    
    public:

        Estado(string nome, vector <int> serieObitos);
        Estado();
        void setNome(string);
        void setSerieObitos(vector <int>);
        string getNome();
        vector <int> getSerieObitos();
};


#endif // ESTADO_H


