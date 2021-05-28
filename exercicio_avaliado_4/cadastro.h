#ifndef CADASTRO_H
#define CADASTRO_H

#include "arvore.h"
#include "paciente.h"

class Cadastro
{
    private:
        Arvore <Paciente> arvoreCadastro;
    public:
        // Cadastro();
        void inserirPaciente(Paciente );
};



#endif // CADASTRO_H