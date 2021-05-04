#include <iostream>
#include <fstream>
#include <algorithm>
#include "grafo.h"
#include "texto.h"

using namespace std;

Grafo::Grafo(string nomeArquivo){
    Texto texto(nomeArquivo);
    palavras = texto.getPalavras();
    montarVertices();
    montarArestas();
}


int Grafo::retornarRecorrencia(string palavra){

    int contadorPalavra = 0;

    for (string palavraArmazenada: palavras){
        if (palavraArmazenada == palavra){
            contadorPalavra++;
        }
    }

    return contadorPalavra;

}

void Grafo::montarArestas(){
    for(int index = 0; index < int(palavras.size()); index++ ){
        string palavraAnterior;
        string proximaPalavra;

        if (palavras[index] != "." && palavras[index] != "," && palavras[index] != ";"){
        palavraAnterior = palavras[index];
        }
        
        if ((index + 1) < int(palavras.size())){
            proximaPalavra = palavras[index + 1];

            if (proximaPalavra != "." && proximaPalavra != "," && proximaPalavra != ";"){
                Vertice verticeAnterior;
                Vertice proximoVertice;
                verticeAnterior.setPalavra(palavraAnterior);
                proximoVertice.setPalavra(proximaPalavra);

                Aresta aresta(verticeAnterior, proximoVertice);

                cout << aresta.getVerticeAnterior().getPalavra() << endl;
                cout << aresta.getverticeSeguinte().getPalavra() << endl;    
            }
        }
        

    }
}

void Grafo::montarVertices(){
    Vertice vertice;

    for(string palavra: palavras){
        vertice.setPalavra(palavra);
        vertice.setRecorrencia(retornarRecorrencia(palavra));
        vertices.push_back(vertice);
        //cout << vertice.getPalavra() << endl;
    }    

}