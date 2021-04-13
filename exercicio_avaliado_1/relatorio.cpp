#include "relatorio.h"
#include "vector"
#include <iostream>
#include <algorithm>

using namespace std;

Relatorio::Relatorio(Estadual estadoObjInput, int numDiasMediaInput){
    Relatorio::estadoObjUnico = estadoObjInput;
    Relatorio::setNumDiasMedia(numDiasMediaInput);
    Relatorio::setMediaMovel();
}

void Relatorio::setMediaMovel(){

    vector <int> serieObitos = Relatorio::estadoObjUnico.getSerieObitos();
    
    float media = 0;
    int numIterecaoes = 0;
    int index = serieObitos.size() - 1;

    while(index >= 0){
        numIterecaoes++;
        media += serieObitos[index];

        if (numIterecaoes == Relatorio::numDiasMedia){
            Relatorio::mediaMovel.push_back(media / Relatorio::numDiasMedia);
            media = 0;
            numIterecaoes = 0;
        }

        index--;
    }

    reverse(Relatorio::mediaMovel.begin(), Relatorio::mediaMovel.end());
}

vector<float> Relatorio::getMediaMovel(){
    return Relatorio::mediaMovel;
}

void Relatorio::setNumDiasMedia(int numDiasMediaInput){

    if(numDiasMediaInput <= 0){
        cout << "Numero invalido para o calculo da media\n"
            << "Os calculos considerarao N = 3";
            Relatorio::numDiasMedia = 3;
    }
    else if(numDiasMediaInput < 3){
        cout << "O numero de dias para media deve ser >= 3.\n"
            << "Os calculos considerarao N = 3";
        Relatorio::numDiasMedia = 3;
    }
    else{
        Relatorio::numDiasMedia = numDiasMediaInput;
    }


}

void Relatorio::printRelatorio(){

    cout << "\nResultado media movel:" << endl;
    cout.precision(3);
    for(auto media: Relatorio::getMediaMovel()){
        cout << media << " ";
    }

    cout << endl;
}