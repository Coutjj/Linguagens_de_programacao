#include "estado.h"

Estado::Estado(string nome, vector<int> serieObitosInput){
    setNome(nome);
    setSerieObitos(serieObitosInput);

}

Estado::Estado(){

}

vector<int> Estado::getSerieObitos(){
    return Estado::serieObitos;
}

void Estado::setSerieObitos(vector<int> serieObitosInput){
    Estado::serieObitos = serieObitosInput;
}

void Estado::setNome(string nome){
    Estado::nome = nome;
}

string Estado::getNome(){
    return Estado::nome;
}
