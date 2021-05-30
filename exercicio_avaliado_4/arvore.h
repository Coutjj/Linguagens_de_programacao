/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe para gerenciamento da Arvore de tipo geral.
  * Para esta implementacao o tipo T deve ter ao menos o metodo getNome.
  * Como esta classe faz uso do tipo template, ela foi definida e implementada no arquivo header.
*/


#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

//Modelo generico do no da arvore.
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
        //funcao para printar nos das arvores.
        static void printRecursivo(No<T> * no){

            if (no == NULL){
                return;
            }

            //imprime no
            cout <<  no->dados << endl;   

            //busca no na 'subarvore' esquerda.
            printRecursivo(no->esquerda);   

            //busca no na 'subarvore' direita.
            printRecursivo(no->direita);
        };

        //Busca de elementos na arvore
        No<T> *buscaRecursiva(No<T>* no, string nomeInput){
            // Stop printing if no node found.
            if (no == NULL){
                return NULL;
            } //Caso tenha encontrado imprime o no.
            else if(no->dados.getNome() == nomeInput){
                return no;
            }//Se o nome for maior que o atual procura na 'subarvore' esquerda.
            else if(nomeInput.compare(no->dados.getNome()) > 0){
                return buscaRecursiva(no->esquerda, nomeInput);
            }//Se o nome for maior que o atual procura na 'subarvore' direita.
            else {
                return buscaRecursiva(no->direita, nomeInput);
            }
            
        };
        
    public:
        No<T> *raiz;

        Arvore(){
            raiz = NULL;
        };

        //Insere um novo no na arvore.
        No<T> *operator+=(T dadosInput){

            //Retorna null quando entrada eh impropria Ex.: nomes com acento.
            //Forca caso de tratamento de ponteiro.
            for(auto letra: dadosInput.getNome()){
                if(!isalnum(letra)){
                    return NULL;
                }
            }
            
            //cria um novo No
            No<T> *novoNo = (No<T> *) malloc(sizeof(No<T>));
            novoNo->dados = dadosInput;
            novoNo->esquerda = NULL;
            novoNo->direita = NULL;
            novoNo->pai = NULL;

            //Se a raiz for nula a arvore esta vazia e novoNo = raiz.
            if (raiz == nullptr){
                raiz = novoNo;
                raiz->pai = NULL;
                raiz->esquerda = NULL;
                raiz->direita = NULL;
                return raiz;
            }
            
            //Caso a raiz != NULL devemos buscar o no onde novoNo deva ser inserido.
            No<T> **noAtual = (No<T> **) malloc(sizeof(No<T>));
            *noAtual = raiz;

            No<T> *noAnterior = (No<T> *) malloc(sizeof(No <T>));
            noAnterior = NULL;
            
            string nomeAtual;

            //Busca posicao onde o novoNo deve ser inserido.
            while((*noAtual) != nullptr){
                noAnterior = *noAtual;
    
                if(dadosInput.getNome().compare((*(*noAtual)).dados.getNome()) > 0){
        
                    nomeAtual = (*(*noAtual)).dados.getNome();
                    noAtual = &((*noAtual))->esquerda;
                }
                else{
                    nomeAtual = (*(*noAtual)).dados.getNome();
                    noAtual = &((*noAtual))->direita;
                }
            }
            
            //Apos a posicao ser encontrada o novoNo eh adicionado.
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

        //Sobrecarga para imprimir arvore com cout << arvore.
        friend ostream & operator<<(ostream &out, Arvore<T> &arvoreInput){
            out << "\nCadastro:\n\n";
            printRecursivo(arvoreInput.raiz);
            return out;
        };

        //Sobrecarga para realizar busca na arvore.
        No<T> * operator()(string nomeInput){
            return buscaRecursiva(raiz, nomeInput);
        };

};

#endif // ARVORE_H
