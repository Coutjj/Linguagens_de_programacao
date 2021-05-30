/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe que modela o objeto Paciente e sua classe herdeira (PacienteRecuperado).
*/

#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream>

using namespace std;

//Classe pai que modela um paciente.
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
        //Sobrecarga pra a imprimir paciente com cout << Paciente.
        friend ostream& operator<<(ostream &, Paciente &);
};

//Classe que herda a classe Paciente.
class PacienteRecuperado: public Paciente{

    private:
        //Atributos que nao estao presentes na classe Paciente.
        string doencaPrevia;
        void setDoencaPrevia();
    public:
        PacienteRecuperado():Paciente(){
            setDoencaPrevia();
        };

        //Exibe os dados da classe herdeira de maneira diferente.
        friend ostream& operator<<(ostream &, PacienteRecuperado &);
        string getDoencaPrevia();
};


#endif // PACIENTE_H
