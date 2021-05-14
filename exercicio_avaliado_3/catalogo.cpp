#include <iostream>
#include <sstream>
#include "catalogo.h"

Catalogo::Catalogo(){

}

Catalogo::Catalogo(vector<Filme> filmesInput){
    filmes = filmesInput;
}


Catalogo Catalogo::operator+=(Filme filmeInput){
    insercaoOrdenada(filmeInput);
    Catalogo novoCatalogo(filmes);
    return novoCatalogo;
}

//Retorna palavras de uma string divididas em um vetor
vector<string> Catalogo::cortarNome(string nomeInput){

    stringstream itNomeInput(nomeInput);
    vector<string> palavrasNoNome;
    string palavra;
    while (itNomeInput >> palavra)
    {
        palavrasNoNome.push_back(palavra);
        cout << "[" << palavra << "]\n";
    }

    return palavrasNoNome;
    

}

void Catalogo::exibirFilmes(){
    for(auto filme: filmes){
        cout << filme.nome << endl;
    }
}



void Catalogo::insercaoOrdenada(Filme filmeInput){
    int posicaoInsercao = -1;

    if(filmes.size() == 0){
        filmes.push_back(filmeInput);
        //cout << "\nInseri " << filmeInput.nome << " Na pos 1\n";
    }
    else{
        for(int index = 0; index < int(filmes.size()); index++){

            vector<string> palavrasFilmeSalvo = cortarNome(filmes[index].nome);
            vector<string> palavrasFilmeInput = cortarNome(filmeInput.nome);

            for(int indexInput = 0; indexInput < int(palavrasFilmeInput.size()); indexInput++){
                
                if(indexInput < int(palavrasFilmeSalvo.size())){
                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) < 0){
                       // cout << "Antes " << filmeInput.nome << " - " << filmes[index].nome
                        //    << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        posicaoInsercao = index;
                        break;
                        //Se cair aqui eu achei a posicao
                    }
                

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) > 0){
                        cout << "Depois " << filmeInput.nome << " - " << filmes[index].nome
                            << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        break;
                        //Se cair aqui eu tenho que procurar ate encontrar status como antes
                    }

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) == 0){
                        cout << "nao sei " << filmeInput.nome << " - " << filmes[index].nome
                            << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        //Se cair aqui eu devo procurar ate encontrar status como antes ou se nao tem proxima palavra
                        //entra no lugar do nome original
                        if((int(palavrasFilmeInput.size()) - 1) <= indexInput){
                            posicaoInsercao = index;
                            break;
                        }
                    }
                }
            }

            cout << posicaoInsercao << endl;
            if ((posicaoInsercao != -1)){
                vector<Filme>::iterator it = filmes.begin() + posicaoInsercao;
                filmes.insert(it, filmeInput);
                break;            
            }
            else if(index == (int(filmes.size()) - 1)){
                filmes.push_back(filmeInput);
                break;
            }

        }
    }

}