#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T> 
class Arvore
{
    private:
        struct No
        {   
            T dados;
            struct No *esquerda = NULL;
            struct No *direita = NULL;
        };

        No *raiz = NULL;

    public:
        Arvore(){
        };

        No *operator+=(T dadosInput){
            if (raiz == nullptr){
                No novoNo;
                novoNo.dados = dadosInput;
                novoNo.esquerda = NULL;
                novoNo.direita = NULL;
                raiz = &novoNo;
                return raiz;
            }
            
            bool noEncontrado = 0;
            No noAtual = *raiz;

            cout << "\n" << raiz->dados.getNome() << endl;
            while(noEncontrado == 0){
                
                //adicionar a esquerda
                if((dadosInput.getNome().compare(noAtual) > 0) && noAtual->esquerda == nullptr){
                    noAtual->esquerda = *dadosInput;
                    cout << "\n" << dadosInput.getNome() << " Esq " << noAtual.getNome() << endl;
                    return noAtual; 
                }


            }

            return NULL;
        };
};


#endif // ARVORE_H
