#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <stdlib.h>

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
        static void printRecursivo(No<T> * no){
            // Stop printing if no node found
            if (no == NULL){
                return;
            }

            /* first print data of node */
            cout <<  no->dados.getNome() << endl;   

            /* then recur on left subtree */
            printRecursivo(no->esquerda);   

            /* now recur on right subtree */
            printRecursivo(no->direita);
        };

        No<T> *buscaRecursiva(No<T>* no, string nomeInput){
            // Stop printing if no node found
            if (no == NULL){
                return NULL;
            } 
            else if(no->dados.getNome() == nomeInput){
                return no;
            }
            else if(nomeInput.compare(no->dados.getNome()) > 0){
                return buscaRecursiva(no->esquerda, nomeInput);
            }
            else {
                return buscaRecursiva(no->direita, nomeInput);
            }
            
        };
        
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
            
            string nomeAtual;
            while((*noAtual) != nullptr){
                noAnterior = *noAtual;
    
                if(dadosInput.getNome().compare((*(*noAtual)).dados.getNome()) > 0){
        
                    nomeAtual = (*(*noAtual)).dados.getNome();
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
                return novoNo;
            }
            
            return NULL;
        };

        friend ostream & operator<<(ostream &out, Arvore<T> &arvoreInput){
            out << "\nCadastro:\n\n";
            printRecursivo(arvoreInput.raiz);
            return out;
        };

        No<T> * operator()(string nomeInput){
            return buscaRecursiva(raiz, nomeInput);
        };

};

#endif // ARVORE_H
