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
        
    public:
        
        void inserirArvore(Arvore<T> arvoreInput){
            arvoreCadastro = arvoreInput;
        }

        Arvore <T> arvoreCadastro;

        void inserirPaciente(T pacienteInput){
            No<T> *noPtr = arvoreCadastro += pacienteInput;
            try
            {
                if(noPtr != NULL){
                    cout << "\nPaciente inserido" << endl;
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