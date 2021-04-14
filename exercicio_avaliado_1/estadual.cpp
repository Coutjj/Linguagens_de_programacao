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


#include "estadual.h"

Estadual::Estadual(string nome, vector<int> serieObitosInput){
    setNome(nome);
    setSerieObitos(serieObitosInput);
}

Estadual::Estadual(){

}

vector<int> Estadual::getSerieObitos(){
    return Estadual::serieObitos;
}

void Estadual::setSerieObitos(vector<int> serieObitosInput){
    Estadual::serieObitos = serieObitosInput;
}

void Estadual::setNome(string nome){
    Estadual::nome = nome;
}

string Estadual::getNome(){
    return Estadual::nome;
}

void Estadual::setSerieMediaMovel(vector<float> serieMediaMovelInput){
    Estadual::serieMediaMovel = serieMediaMovelInput;
}

vector<float> Estadual::getSerieMediaMovel(){
    return Estadual::serieMediaMovel;
}