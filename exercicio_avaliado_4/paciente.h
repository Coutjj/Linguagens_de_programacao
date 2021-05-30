#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Paciente
{
    private:
        string nome;
        unsigned int idade;
    public:
        Paciente();
        string getNome();
        void inserirNome();
        void setIdade();
        unsigned int getIdade();
        friend ostream& operator<<(ostream &, Paciente &);
};

class PacienteRecuperado: public Paciente{

    private:
        string doencaPrevia;
        void setDoencaPrevia();
    public:
        PacienteRecuperado():Paciente(){
            setDoencaPrevia();
        };

        friend ostream& operator<<(ostream &, PacienteRecuperado &);
        string getDoencaPrevia();
};


#endif // PACIENTE_H
