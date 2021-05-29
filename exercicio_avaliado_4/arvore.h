#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template <class T>
class No{
    public:
        T dados;
        No *esquerda;
        No *direita;
        No *pai;
};

template <class T> 
class Arvore
{
    private:
        
    public:
        No<T> *raiz;
        
        Arvore(){

        };

        No<T> *operator+=(T dadosInput){

            No<T> *novoNo = (No<T> *) malloc(sizeof(No<T>));
            novoNo->dados = dadosInput;
            novoNo->esquerda = NULL;
            novoNo->direita = NULL;
            novoNo->pai = NULL;


            if (raiz == nullptr){
                raiz = novoNo;
                raiz->pai = NULL;
                raiz->esquerda = NULL;
                raiz->direita = NULL;
                return raiz;
            }
            
            No<T> **noAtual = (No<T> **) malloc(sizeof(No<T>));
            *noAtual = raiz;

            No<T> *noAnterior = (No<T> *) malloc(sizeof(No <T>));
            noAnterior = NULL;
            
            cout << "\n" << (*(*noAtual)).dados.getNome() << endl;
            string nomeAtual;
            while((*noAtual) != nullptr){
                noAnterior = *noAtual;
    
                if(dadosInput.getNome().compare((*(*noAtual)).dados.getNome()) > 0){
        
                    nomeAtual = (*(*noAtual)).dados.getNome();
                    cout << nomeAtual << endl;
                    noAtual = &((*noAtual))->esquerda;
                }
                else{
                    noAtual = &((*noAtual))->direita;
                }
            }
            
            if(dadosInput.getNome().compare(nomeAtual) > 0){
                noAnterior->esquerda = novoNo;
                (*novoNo).pai = noAnterior;
                return novoNo;
            }
            else{
                noAnterior->direita = novoNo;
                novoNo->pai = noAnterior;
            }
            
            return NULL;
        };
};

#endif // ARVORE_H
