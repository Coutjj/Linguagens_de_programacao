#ifndef MENU_H
#define MENU_H

#include "catalogo.h"

class Menu
{
private:
    void inserirFilme();
    void inserirNFilmes();
    void removerFilme();
    void buscarFilme();
    Catalogo catalogo;
public:
    Menu();
    void opcoes();
};


#endif //MENU_H