#include <iostream>
#include <iomanip>
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
                arestas.push_back(aresta);
            }
        }
    }

    for(int index = 0; index < int(arestas.size()); index++){
        arestas[index].setRecorrencia(recorrenciaAresta(arestas[index]));
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

    cout << "\nPalavras com recorrencia maior que 1:\n\n"
         << setw(20) << left << "Palavra"  << "\tRecorrencia\n\n";

    for(Vertice vertice: palavrasMaisUtilizadas){
        if(vertice.getRecorrencia() > 1){
            cout << setw(20) << left << vertice.getPalavra() << "\t"
                 << setw(20) << left << vertice.getRecorrencia() << endl;
        }
    } 

}

int Grafo::recorrenciaAresta(Aresta arestaInput){

    int recorrencia = 0;
    for (int index = 0; index < int(arestas.size()); index++){
        if(arestaInput.CompararVertices(arestas[index]) == true){
            recorrencia++;
        }
    }
    return recorrencia;
}


void Grafo::sequenciade2Termos(){

    int maiorRecorrencia = 0;
    
    for (int index = 0; index < int(arestas.size()); index++){
        if(arestas[index].getRecorrencia() > maiorRecorrencia){
            maiorRecorrencia = arestas[index].getRecorrencia();
        }
    }

    //lista todas as palavras com mesma recorrencia
    vector<Aresta> arestasMaiorRecorrencia;
    bool arestaJaexiste = 0;
    for(auto aresta: arestas){
        if(aresta.getRecorrencia() == maiorRecorrencia){
            
            for(auto arestasListadas: arestasMaiorRecorrencia){
                if(aresta.getVerticeAnterior().getPalavra() == arestasListadas.getVerticeAnterior().getPalavra()){
                    if(aresta.getverticeSeguinte().getPalavra() == arestasListadas.getverticeSeguinte().getPalavra()){
                        arestaJaexiste = true;
                    }
                }
            }
            
            if(arestaJaexiste == false){
                arestasMaiorRecorrencia.push_back(aresta);
            }

            arestaJaexiste = false;
            
        }
    }

    cout << "Sequencia de duas palavras com maior recorrencia:\n\n";

    for(auto aresta: arestasMaiorRecorrencia){
        cout << aresta.getVerticeAnterior().getPalavra()
            << " - " << aresta.getverticeSeguinte().getPalavra()
            << "\nRecorrencia: " << aresta.getRecorrencia() << "\n\n";
    }
    
}