#ifndef MENU_H
#define MENU_H

#include "catalogo.h"

class Menu
{
private:
    Catalogo catalogo;
public:
    Menu();
    void opcoes();
    void inserirFilme();
    void inserirNFilmes();
    void removerFilme();
    void buscarFilme();
    void editarFilme();
};


#endif //MENU_H