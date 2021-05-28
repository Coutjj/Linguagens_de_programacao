#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

using namespace std;

class Paciente
{
    private:
        string nome;
    public:
        Paciente();
        void inserirNome(string );
        string getNome();
};



#endif // PACIENTE_H
