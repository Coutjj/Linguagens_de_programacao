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
        // struct No
        // {   
        //     T dados;
        //     struct No *esquerda = NULL;
        //     struct No *direita = NULL;
        // };

        // No * raiz; //(No *) malloc(sizeof(No));
        No<T> *raiz;
    public:
        
        Arvore(){
            //nos.push_back(raiz);
            //raiz = NULL;
            // raiz->esquerda = NULL;
            // raiz->direita = NULL;

        };

        No<T> *operator+=(T dadosInput){

            // No *novoNo = (No *) malloc(sizeof(No));
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

                    // noAtual->esquerda = (No<T> *) malloc(sizeof(No<T>));
                    // noAtual->esquerda = NULL;
                    // cout << "\n" << noAtual->esquerda->dados.getNome() << endl;
                    cout << "\nEntrei\n";
                    nomeAtual = (*(*noAtual)).dados.getNome();
                    cout << nomeAtual << endl;
                    noAtual = &((*noAtual))->esquerda;
                    // cout << "\nEntrei\n";
                    // cout << (*(*noAtual)).dados.getNome();
                    // cout << "\n" << dadosInput.getNome() << " Esq " << (*(*noAtual)).dados.getNome() << endl;
                }
                else{
                    noAtual = &((*noAtual))->direita;
                }
                cout << "\nEntrei ultimo\n";
            }
            
            if(dadosInput.getNome().compare(nomeAtual) > 0){
                cout << "\nEntrei ultimo\n";
                noAnterior->esquerda = novoNo;
                (*novoNo).pai = noAnterior;
                return novoNo;
                // cout << "\n" << dadosInput.getNome() << " Esq " << (*(*noAtual)).dados.getNome() << endl;
            }
            else{
                noAnterior->direita = novoNo;
                novoNo->pai = noAnterior;
                cout << "\n" << dadosInput.getNome() << " Dir " << (*(*noAtual)).dados.getNome() << endl;
            }
            
            return NULL;
        };
};

#endif // ARVORE_H
