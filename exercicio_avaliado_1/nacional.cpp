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


#include "nacional.h"


Nacional::Nacional(string nomeInput, vector<Estadual> estadosInput){

    Nacional::setNome(nomeInput);
    Nacional::setEstados(estadosInput);
}

Nacional::Nacional(){
    
}

void Nacional::setNome(string nomeInput){
    Nacional::nome = nomeInput;
}

string Nacional::getNome(){
    return Nacional::nome;
}

void Nacional::setEstados(vector<Estadual> estadosInput){

    Nacional::estados = estadosInput;

}

vector<Estadual> Nacional::getEstados(){
    return Nacional::estados;
}

void Nacional::setSerieMediaMovel(vector<float> serieMediaMovelInput){
    Nacional::serieMediaMovel = serieMediaMovelInput;
}

vector<float> Nacional::getSerieMediaMovel(){
    return Nacional::serieMediaMovel;
}