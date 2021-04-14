#include "relatorio.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

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
    Relatorio::estadoObjUnico.setSerieMediaMovel(calcMedia(estadoObj));
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
        cout << media << "\t";
    }

    cout << endl;
}

void Relatorio::printRelatorioNacional(){

    cout << "\nResultado media movel " << Relatorio::nacionalObj.getNome() << ":" << endl;
    cout.precision(3);
    for (auto media: Relatorio::nacionalObj.getSerieMediaMovel()){
        cout << media << "\t";
    }
    cout << endl << endl;

    for(auto estado: Relatorio::nacionalObj.getEstados()){

        cout << estado.getNome() << endl;
        for(auto media: estado.getSerieMediaMovel()){
            cout << media << "\t";
        }

        cout << endl << endl;
    }

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

void Relatorio::printStatusEstados(){
    vector<Estadual> estadosAlta;
    vector<Estadual> estadosBaixa;
    vector<Estadual> estadosEstavel;
    
    float limiar = 1.15;

    for(auto estado: nacionalObj.getEstados()){
        int ultimoElemento = estado.getSerieMediaMovel().size() - 1;
        
        float status = estado.getSerieMediaMovel()[ultimoElemento] / estado.getSerieMediaMovel()[ultimoElemento - 1];

        if (status > limiar){
            estadosAlta.push_back(estado);
        }
        else if(status < (2 - limiar)){
            estadosBaixa.push_back(estado);
        }
        else{
            estadosEstavel.push_back(estado);
        }
    }

    cout << "\nEstados em Alta:\n\n";
    for (auto estado: estadosAlta){
        cout << estado.getNome() << endl;
    }

    cout << "\nEstados em Baixa:\n\n";
    for (auto estado: estadosBaixa){
        cout << estado.getNome() << endl;
    }

    cout << "\nEstados em equilibrio:\n\n";
    for (auto estado: estadosEstavel){
        cout << estado.getNome() << endl;
    }

}

void Relatorio::printStatusBrasil(){

    int ultimoElemento = nacionalObj.getSerieMediaMovel().size() - 1;
    float status = nacionalObj.getSerieMediaMovel()[ultimoElemento] / nacionalObj.getSerieMediaMovel()[ultimoElemento -1];

    float limiar = 1.15;

    cout << "\nStatus " << nacionalObj.getNome() << ": ";
    if (status > limiar){
        cout << "Alta\n";
    }
    else if(status < (2 - limiar)){
        cout << "Baixa\n";
    }
    else{
        cout << "Estavel\n";
    }

}

void Relatorio::printEstadoMaiorAltaBaixa(){
    
    float maiorAlta = 0.0;
    float maiorBaixa = 1000000.0;
    Estadual estadoMaiorAlta;
    Estadual estadoMaiorBaixa;

    for(auto estado: nacionalObj.getEstados()){
        int ultimoElemento = estado.getSerieMediaMovel().size() -1;
        float status = estado.getSerieMediaMovel()[ultimoElemento] / estado.getSerieMediaMovel()[ultimoElemento - 1];
    
        if (status > maiorAlta){
            estadoMaiorAlta = estado;
            maiorAlta = status;
        }

        if (status < maiorBaixa){
            estadoMaiorBaixa = estado;
            maiorBaixa = status;
        }
    }

    cout << "\nEstado com maior alta: " << estadoMaiorAlta.getNome() << endl;
    cout << "\nEstado com maior baixa: " << estadoMaiorBaixa.getNome() << endl;
}

void Relatorio::printObitosAcumulados(){

    int acumuladoBrasil = 0;
    cout << "\nObitos acumulados:\n\n";

    for(auto estado: nacionalObj.getEstados()){
        cout << estado.getNome() << ": ";
        vector<int> serieObitos = estado.getSerieObitos();
        acumuladoBrasil += accumulate(serieObitos.begin(), serieObitos.end(), 0);
        cout << accumulate(serieObitos.begin(), serieObitos.end(), 0) << endl << endl;

    } 

    cout << "Acumulado " << nacionalObj.getNome() << ": " << acumuladoBrasil << endl;
}