#include <fstream>
#include <algorithm>
#include "texto.h"


Texto::Texto(string nomeArquivo){
    string stringTexto = lerArquivo(nomeArquivo);
    palavras = cortarString(stringTexto);
}

string Texto::lerArquivo(string nomeArquivo){

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

    return conteudoArquivo; 
}


vector<string> Texto::cortarString(string stringCompleta){
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

vector<string> Texto::getPalavras(){
    return palavras;
}