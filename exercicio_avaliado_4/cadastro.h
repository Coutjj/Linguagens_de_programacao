#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include "arvore.h"
#include "paciente.h"

using namespace std;

class Cadastro
{
    private:
        
    public:
        // Cadastro(){};
        Arvore <Paciente> arvoreCadastro;
        void inserirPaciente(Paciente );
        void imprime();
        void busca();
};



#endif // CADASTRO_H