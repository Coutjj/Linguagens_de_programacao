#include <iostream>
#include <fstream>
#include <algorithm>
#include "grafo.h"

using namespace std;

Grafo::Grafo(string nomeArquivo){

    lerArquivo(nomeArquivo);
    montarVertices();
}

void Grafo::lerArquivo(string nomeArquivo){

    fstream input;
    input.open(nomeArquivo, ios::in);
    string linha;
    string conteudoArquivo;

    if(input.is_open()){
        while ( getline(input, linha))
        {
            transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
            conteudoArquivo.append(linha.append(" "));
            
        }      
    }

    
    palavras = cortarString(conteudoArquivo);
    
    input.close();
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


vector<string> Grafo::cortarString(string stringCompleta){
    char vazio = ' ';
    string palavra;
    vector<string> vetorPalavras;
    
    char stringVazia[] = {' ', '\0'};

    for(char letra: stringCompleta){
        
        if(letra == vazio || letra == '.' || letra == ','){
            
            
            if(palavra != ""){
                vetorPalavras.push_back(palavra);
            }
            if (letra != vazio){
                stringVazia[0] = letra;
                vetorPalavras.push_back(stringVazia);
            }

            palavra = "";
        }
        else{
            stringVazia[0] = letra;
            palavra.append(stringVazia);
        }
    }

    return vetorPalavras;

}

void Grafo::montarVertices(){
    Vertice vertice;

    for(string palavra: palavras){
        vertice.setPalavra(palavra);
        vertice.setRecorrencia(retornarRecorrencia(palavra));
        vertices.push_back(vertice);
        cout << vertice.getPalavra() << endl;
    }    

}