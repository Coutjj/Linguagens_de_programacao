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
        Paciente();
        void inserirNome(string );
        string getNome();
        friend ostream& operator<<(ostream &, Paciente &);
};



#endif // PACIENTE_H
