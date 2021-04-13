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