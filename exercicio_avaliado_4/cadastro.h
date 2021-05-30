/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe para gerenciamento de entradas de tipo geral.
  * Como esta classe faz uso do tipo template, ela foi definida e implementada no arquivo header.
*/


#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include "arvore.h"
#include "paciente.h"
#include "nullPointerException.h"

using namespace std;

template<class T>
class Cadastro
{
    private:
        //Arvore de tipo geral utilizada pelo cadastro.
        Arvore <T> arvoreCadastro;
        
    public:
        //Insere arvore a ser utilizada no cadastro.
        void inserirArvore(Arvore<T> arvoreInput){
            arvoreCadastro = arvoreInput;
        }

        //Insere paciente na arvore e checa excecao de ponteiro nulo.
        void inserirPaciente(T pacienteInput){
            No<T> *noPtr = arvoreCadastro += pacienteInput;
            try
            {
                if(noPtr != NULL){
                    cout << "\nPaciente inserido." << endl;
                }
                else{
                    throw NullPointerException();
                }
                
            }
            catch(NullPointerException& e)
            {
                cout << '\n' << e.what() << '\n';
                cout << "Nao foi possivel inserir o paciente.\n";
            }
        };

        //Imprime todos os nos da arvore utilizando o operador sobrecarregado.
        void imprime(){
            cout << arvoreCadastro;
        };

        //Busca um elemento na arvore e trata excecao de ponteiro nulo.
        void busca(){
            string nomeInput;

            cout << "\nDigite o nome a ser buscado:\n\n";
            cin >> nomeInput;

            if(cin.fail()){
                cout << "\nOpcao invalida\n";
                exit(-1);
            }

            No<T> *noBusca = arvoreCadastro(nomeInput);
       
            try
            {
                cout << "\nDados:\n\n";
                if(noBusca != NULL){
                    cout << noBusca->dados << endl;
                }
                else{
                    throw NullPointerException();
                }
                
            }
            catch(NullPointerException& e)
            {
                cout << '\n' << e.what() << '\n';
                cout << "A busca nao retornou resultados.\n";
            }
            
        };
};



#endif // CADASTRO_H