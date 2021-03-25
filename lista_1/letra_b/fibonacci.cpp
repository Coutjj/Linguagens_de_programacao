#include "fibonacci.h"
        
void Fibonacci::setFibonacci(int valor){
    indice = valor;
    computeFibonacci();
}

int Fibonacci::getFibonnaci(){
    return resultado;
}

void Fibonacci::computeFibonacci(){

    int numAnteriorGrau1 = 1;
    int numAnteriorGrau2 = 1;
    
    for(int contador = 2; contador < indice; contador++){
        resultado = numAnteriorGrau1 + numAnteriorGrau2;
        numAnteriorGrau2 = numAnteriorGrau1;
        numAnteriorGrau1 = resultado;
    }

    
}