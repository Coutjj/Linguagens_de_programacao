/*
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe para a criacao da excecao de acesso a ponteiro nulo.
*/

#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

#include <exception>

using namespace std;

class NullPointerException: public exception {

    public:
        virtual const char *what() const throw (){
            return "Ponteiro nulo.";
        }
};

#endif //NULLPOINTEREXCEPTION_H
