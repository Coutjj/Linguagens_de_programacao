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
            
            No novoNo;
            novoNo.dados = dadosInput;
            novoNo.esquerda = NULL;
            novoNo.direita = NULL;

            if (raiz == nullptr){
                raiz = &novoNo;
                return raiz;
            }
            
            bool noEncontrado = 0;
            No noAtual = *raiz;
            /*E preciso montar uma fila com os nos salvos*/
            cout << "\n" << raiz->dados.getNome() << endl;
            while(noEncontrado == 0){
                
                //adicionar a esquerda
                if(dadosInput.getNome().compare(noAtual.dados.getNome()) > 0){
                    if(noAtual.esquerda == nullptr){
                        noAtual.esquerda = &novoNo;
                        cout << "\n" << dadosInput.getNome() << " Esq " << noAtual.dados.getNome() << endl;
                        return &noAtual;
                    }
                    else{
                        noAtual = *noAtual.esquerda;
                    }
                }


            }

            return NULL;
        };
};


#endif // ARVORE_H
