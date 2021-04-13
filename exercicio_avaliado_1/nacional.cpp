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