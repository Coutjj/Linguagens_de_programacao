#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(int vetor[]){
    setDim(vetor);
}

void Paralelepipedo::setDim (int vetor[]){

    for(int index = 0; index < 3; index++){
        Paralelepipedo::dimxyz[index] = vetor[index];
    }
}

int Paralelepipedo::getVolume(){
    return computeVolume();
}

int Paralelepipedo::computeVolume(){

    int volume = 1;
    for (int index = 0; index < 3; index++)
    {
        volume *= dimxyz[index];
    }

    return volume;
}