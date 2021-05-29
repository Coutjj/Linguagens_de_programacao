#ifndef CADASTRO_H
#define CADASTRO_H

#include "arvore.h"
#include "paciente.h"

class Cadastro
{
    private:
        Arvore <Paciente> arvoreCadastro;
        void printPreorder(No<Paciente> *);
    public:
        // Cadastro();
        void inserirPaciente(Paciente );
        void imprime();
        
};



#endif // CADASTRO_H