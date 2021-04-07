#include <cmath>
#include "linha.h"

using namespace std;

Linha::Linha(Ponto ponto0, Ponto ponto1){

    Linha::pontos.push_back(ponto0);
    Linha::pontos.push_back(ponto1);
    Linha::setComprimento();
}


void Linha::setComprimento(){

    float resultado = sqrt(
        pow(Linha::pontos[0].getXYZ('x') - Linha::pontos[1].getXYZ('x'), 2) +
        pow(Linha::pontos[0].getXYZ('y') - Linha::pontos[1].getXYZ('y'), 2) +
        pow(Linha::pontos[0].getXYZ('z') - Linha::pontos[1].getXYZ('z'), 2)
    );

    Linha::comprimento = resultado;
}

float Linha::getComprimento(){
    return Linha::comprimento;
}