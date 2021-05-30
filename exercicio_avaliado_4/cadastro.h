#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include "arvore.h"
#include "paciente.h"

using namespace std;

template<class T>
class Cadastro
{
    private:
        
    public:
        
        void inserirArvore(Arvore<T> arvoreInput){
            arvoreCadastro = arvoreInput;
        }

        Arvore <T> arvoreCadastro;

        void inserirPaciente(T pacienteInput){
            arvoreCadastro += pacienteInput; 
        };

        void imprime(){
            cout << arvoreCadastro;
        };

        void busca(){
            string nomeInput;

            cout << "\nDigite o nome a ser buscado:\n\n";
            cin >> nomeInput;

            if(cin.fail()){
                cout << "\nOpcao invalida\n";
                exit(-1);
            }

            No<T> *noBusca = arvoreCadastro(nomeInput);
            if(noBusca != NULL){
                cout << "\nDados:\n\n";
                cout << noBusca->dados << endl;
            }
            else{
                cout << "\nA busca nao retornou resultados.\n";
            }
        };
};



#endif // CADASTRO_H