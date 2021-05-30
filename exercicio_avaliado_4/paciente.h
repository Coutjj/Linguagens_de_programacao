#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Paciente
{
    private:
        string nome;
    public:
        // Paciente(string );
        // Paciente();
        string getNome();
        void inserirNome();
        friend ostream& operator<<(ostream &, Paciente &);
};

class PacienteRecuperado: public Paciente{

    private:
        string doencaPrevia;
    public:
        // PacienteRecuperado():Paciente(){
        //     inserirNome();
        //     setDoencaPrevia();
        // };
        void setPaciente();
        friend ostream& operator<<(ostream &, PacienteRecuperado &);
        void setDoencaPrevia();
        string getDoencaPrevia();
};


#endif // PACIENTE_H
