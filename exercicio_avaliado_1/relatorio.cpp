#include "relatorio.h"
#include "vector"

using namespace std;

Relatorio::Relatorio(Estado estadoObjInput){
    Relatorio::estadoObjUnico = estadoObjInput;
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

        if (numIterecaoes == 3){
            Relatorio::mediaMovel.push_back(media / 3);
            media = 0;
            numIterecaoes = 0;
        }

        index--;
    }
}

vector<float> Relatorio::getMediaMovel(){
    return Relatorio::mediaMovel;
}