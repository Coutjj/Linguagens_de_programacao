#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include "grafo.h"
#include "texto.h"

using namespace std;

Grafo::Grafo(string nomeArquivo){
    Texto texto(nomeArquivo);
    palavras = texto.getPalavras();
    stringTexto = texto.getTexto();
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

void Grafo::sequenciadeNTermos(){

    int nTermos;
    cout << "\nSelecione o numero N de termos na sequencia:\n";
    cin >> nTermos;

    if(cin.fail()){
        cout << "\nOpcao invalida\n";
        exit(-1);
    }


    //agrupando sentencas
    vector<vector<Aresta>> listagrupoSentencas;
    vector<Aresta> grupoArestas;
    for(int index = 0; index < int(arestas.size()); index++){
        
        if((index + 1) < int(arestas.size())){
            if(
                arestas[index].getverticeSeguinte().getPalavra() == 
                arestas[index + 1].getVerticeAnterior().getPalavra()){
                
                grupoArestas.push_back(arestas[index]);
                
            }
            else
            {
                grupoArestas.push_back(arestas[index]);
                listagrupoSentencas.push_back(grupoArestas);
                grupoArestas.clear();
                continue;
            }
        }
        else{
            grupoArestas.push_back(arestas[index]);
            listagrupoSentencas.push_back(grupoArestas);
            grupoArestas.clear();

        }

    }

    // for(auto arestas: listagrupoSentencas){
    //     for(auto aresta: arestas){
    //         cout << aresta.getVerticeAnterior().getPalavra()
    //             << " - " << aresta.getverticeSeguinte().getPalavra() << " - ";
    //     }

    //     cout << "\n";
    // }

    //sentencas em texto
    vector<string> listaSentencas;
    string frase = "";
    for(auto arestas: listagrupoSentencas){
        frase = arestas[0].getVerticeAnterior().getPalavra() + " ";
        for(auto aresta: arestas){
             frase += aresta.getverticeSeguinte().getPalavra() + " ";
        }
        frase[frase.size() - 1] = '\0';
        listaSentencas.push_back(frase);
    }

    int numPalavras = 0; 
    int contador = 0;
    string grupoPalavras = "";
    vector<string> listaGrupoPalavras;
    for (auto frase: listaSentencas){
        istringstream iss(frase);
        string lerIss;
        while(iss){
            iss >> lerIss;
            grupoPalavras = lerIss + " ";
            contador++;
            istringstream iss2(frase);

            int contWhileSacrificio = 0;
            while(contador - contWhileSacrificio > 0){
                string stringSacrificio;
                iss2 >> stringSacrificio;
                contWhileSacrificio++;
            }
            numPalavras = 0;
            while (iss2)
            {
                numPalavras++;
                iss2 >> lerIss;
                grupoPalavras += lerIss + " ";
                if((numPalavras == (nTermos - 1)) && iss2){
                    //cout << grupoPalavras << "\n";
                    grupoPalavras[grupoPalavras.size() - 1] = '\0';
                    listaGrupoPalavras.push_back(grupoPalavras);
                    grupoPalavras = "";
                }
            }
            numPalavras = 0;
        }
        contador = 0;
    }

    int recorrenciaSequencia = 0;
    map<string, int> sequenciasMaisUtilizadas;
    for(auto frase1: listaGrupoPalavras){
        for(auto frase2: listaGrupoPalavras){
            if(frase1 == frase2){
                recorrenciaSequencia++;
            }
            cout << "[" << frase1 << "]" << "[" << frase2 << "]";
            cout << recorrenciaSequencia << endl;
        }

        sequenciasMaisUtilizadas.insert(make_pair(frase1, recorrenciaSequencia));
        recorrenciaSequencia = 0;
    }

    cout << sequenciasMaisUtilizadas.size()<< endl;
    for(auto mapIt = sequenciasMaisUtilizadas.begin(); mapIt != sequenciasMaisUtilizadas.end(); mapIt++){
        string sequencia = mapIt->first;
        int recorrencia = mapIt->second;

        cout << sequencia << " " << recorrencia << endl;
    }

    // for (auto frase: listaGrupoPalavras)
    // {
    //     cout << frase;
    //     cout << endl;
    // }


    // for (auto frase: listaSentencas)
    // {
    //     for(auto palavra: frase){
    //         cout << palavra;
    //     }
    //     cout << endl;
    // }
    
    

    // for(auto arestas: listagrupoPalavras){
    //     for(auto aresta: arestas){
    //         cout << aresta.getVerticeAnterior().getPalavra()
    //             << " - " << aresta.getverticeSeguinte().getPalavra() << " - ";
    //     }

    //     cout << "\n";
    // }

}