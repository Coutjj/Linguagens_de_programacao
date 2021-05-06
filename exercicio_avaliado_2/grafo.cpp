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
    string palavraAnterior;
    string proximaPalavra;
    
    for(int index = 0; index < int(palavras.size()); index++ ){

        if (palavras[index] != "." && palavras[index] != "," && palavras[index] != ";"){
            palavraAnterior = palavras[index];
        }
        else{
            continue;
        }
        
        if ((index + 1) < int(palavras.size())){
            proximaPalavra = palavras[index + 1];

            if (proximaPalavra != "." && proximaPalavra != "," && proximaPalavra != ";"){
                Vertice verticeAnterior;
                Vertice proximoVertice;
                verticeAnterior.setPalavra(palavraAnterior);
                verticeAnterior.setRecorrencia(retornarRecorrencia(palavraAnterior));
                proximoVertice.setPalavra(proximaPalavra);
                proximoVertice.setRecorrencia(retornarRecorrencia(proximaPalavra));

                Aresta aresta(verticeAnterior, proximoVertice);

                cout << aresta.getVerticeAnterior().getPalavra() << endl;
                cout << aresta.getVerticeAnterior().getRecorrencia();
                cout << aresta.getverticeSeguinte().getPalavra() << endl;    
            }
        }
        

    }
}

void Grafo::montarVertices(){
    Vertice vertice;

    for(string palavra: palavras){
        if(find(begin(caracteres), end(caracteres), palavra) == end(caracteres)){
            vertice.setPalavra(palavra);
            vertice.setRecorrencia(retornarRecorrencia(palavra));
            vertices.push_back(vertice);
        }

    }    

}

void Grafo::palavrasMaisUtilizadas(){

    vector<Vertice> palavrasMaisUtilizadas;
    palavrasMaisUtilizadas = vertices; 
    sort(
        palavrasMaisUtilizadas.begin(),
        palavrasMaisUtilizadas.end(),
        [](Vertice a, Vertice b){return a.getRecorrencia() > b.getRecorrencia();}
    );
    
    // remover duplicatas

    vector<Vertice> copia;
    copia.push_back(palavrasMaisUtilizadas[0]);
    bool existe = false;
    for (Vertice vertice: palavrasMaisUtilizadas){
        for(auto verticeCopia: copia){
            
            if(verticeCopia.getPalavra() == vertice.getPalavra() )
            {
                existe = true;
            }
        }
        
        //copia se nao existe repitido
        if(existe == false){
            copia.push_back(vertice);
        }

        existe = false;
    }

    palavrasMaisUtilizadas = copia;

    for(Vertice vertice: palavrasMaisUtilizadas){
        cout << '[' << vertice.getPalavra() << "] " << vertice.getRecorrencia() << endl;
    } 

}