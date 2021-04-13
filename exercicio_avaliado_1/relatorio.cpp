#include "relatorio.h"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

Relatorio::Relatorio(Estadual estadoObjInput, int numDiasMediaInput){
    Relatorio::setEstado(estadoObjInput);
    Relatorio::setNumDiasMedia(numDiasMediaInput);
    Relatorio::setMediaMovel(estadoObjInput);
}

Relatorio::Relatorio(Nacional nacionalObjInput, int numDiasMediaInput){
    Relatorio::setNacional(nacionalObjInput);
    Relatorio::setNumDiasMedia(numDiasMediaInput);
    Relatorio::setMediaMovelNacional();
}

void Relatorio::setNacional(Nacional nacionalObjInput){
    Relatorio::nacionalObj = nacionalObjInput;
}


void Relatorio::setEstado(Estadual estadoObjInput){
    Relatorio::estadoObjUnico = estadoObjInput;
}

void Relatorio::setMediaMovel(Estadual estadoObj){
    //estadoObj.setSerieMediaMovel(calcMedia(estadoObj));
    Relatorio::estadoObjUnico.setSerieMediaMovel(calcMedia(estadoObj));
}

vector<float> Relatorio::getMediaMovel(){
    return Relatorio::mediaMovel;
}

void Relatorio::setNumDiasMedia(int numDiasMediaInput){

    if(numDiasMediaInput <= 0){
        cout << "Numero invalido para o calculo da media\n" << "Os calculos considerarao N = 3.";
            Relatorio::numDiasMedia = 3;
    }
    else if(numDiasMediaInput < 3){
        cout << "O numero de dias para media deve ser >= 3.\n" << "Os calculos considerarao N = 3.";
        Relatorio::numDiasMedia = 3;
    }
    else{
        Relatorio::numDiasMedia = numDiasMediaInput;
    }


}

void Relatorio::printRelatorio(){

    cout << "\nResultado media movel:" << endl;
    cout.precision(3);
    for(auto media: Relatorio::estadoObjUnico.getSerieMediaMovel()){
        cout << media << " ";
    }

    cout << endl;
}

void Relatorio::printRelatorioNacional(){

    cout << "\nResultado media movel " << Relatorio::nacionalObj.getNome() << ":" << endl;
    for (auto media: Relatorio::nacionalObj.getSerieMediaMovel()){
        cout << media << " ";
    }
    cout << endl << endl;

    for(auto estado: Relatorio::nacionalObj.getEstados()){

        cout << estado.getNome() << endl;
        for(auto media: estado.getSerieMediaMovel()){
            cout << media << " ";
        }

        cout << endl << endl;
    }

    cout << endl;
}

vector<float> Relatorio::calcMedia(Estadual estadoObj){
    
    vector<int> serieObitos = estadoObj.getSerieObitos();
    float media = 0;
    int numIterecaoes = 0;
    int index = serieObitos.size() - 1;
    vector<float> mediaMovelCalc;
    
    while(index >= 0){
        numIterecaoes++;
        media += serieObitos[index];

        if (numIterecaoes == Relatorio::numDiasMedia){
            mediaMovelCalc.push_back(media / Relatorio::numDiasMedia);
            media = 0;
            numIterecaoes = 0;
        }

        index--;
    }

    reverse(mediaMovelCalc.begin(), mediaMovelCalc.end());
    return mediaMovelCalc;
}

void Relatorio::setMediaMovelNacional(){

    vector<vector<float>> mediasEstaduais;
    vector<Estadual> estadosCalculados;

    for (unsigned int index = 0; index < nacionalObj.getEstados().size(); index++){
        estadosCalculados.push_back(nacionalObj.getEstados()[index]);
        estadosCalculados[index].setSerieMediaMovel(calcMedia(estadosCalculados[index]));
        mediasEstaduais.push_back(estadosCalculados[index].getSerieMediaMovel());
    }

    Nacional nacionalCalculado(nacionalObj.getNome(), estadosCalculados);
    setNacional(nacionalCalculado);
    
    vector<float> mediaMovelNacional(nacionalObj.getEstados()[0].getSerieMediaMovel().size());

    for(auto mediaEstadual: mediasEstaduais){
        transform(mediaEstadual.begin(), mediaEstadual.end(), mediaMovelNacional.begin(), mediaMovelNacional.begin(), plus<float>());
    }

    Relatorio::nacionalObj.setSerieMediaMovel(mediaMovelNacional);
}