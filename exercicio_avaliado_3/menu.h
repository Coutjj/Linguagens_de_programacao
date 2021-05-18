/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Definicoes da classe que modela um menu.
  * Como o menu deve implementar exemplos de uso dos operadores sobrecarregados,
  * foi escolhido que ele fosse encapsulado em uma classe separada. Assim, a
  * responsabilidade de tratar as entradas sao destinadas a esta classe.
*/


#ifndef MENU_H
#define MENU_H

#include "catalogo.h"

class Menu
{
private:
    Catalogo catalogo;
public:
    Menu();
    void opcoes(); // Exibe as opcoes do menu e espera entrada do usuario
    void inserirFilme(); // Chama funcao para inserir um filme no catalogo
    void inserirNFilmes(); // Chama funcao para inserir um vetor filmes no catalogo
    void removerFilme(); // Chama funcao para remover um filme do catalogo
    void buscarFilme(); // busca um filme no catalogo
    void editarFilme(); // edita um filme no catalogo
};


#endif //MENU_H