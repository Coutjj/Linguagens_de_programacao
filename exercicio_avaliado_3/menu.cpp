#include <iostream>
#include "menu.h"
#include "catalogo.h"


using namespace std;


Menu::Menu(){

}

void Menu::opcoes(){
    int escolhaUsuario = -1;

    while (escolhaUsuario != 0)
    {
        cout << "\nEscolha uma das opcoes abaixo ou digite 0 (zero) para sair.\n\n";
        cout << "(1) Inserir um filme.\n";
        cout << "(2) Exibir catalogo\n\n";

        cin >> escolhaUsuario;

        if(cin.fail()){
            cout << "Operacao invalida\n";
            exit(-1);
        }

        switch (escolhaUsuario)
        {
        case 1:
            inserirFilme();
            break;
        case 2:
            cout << catalogo;
            break;
        case 0:
            catalogo.salvarCatalogo();
            break;
        default:
            break;
        }

    }
}

void Menu::inserirFilme(){
    Filme filmeNovo;
    string nota;
    cin.ignore();
    cout << "Inserir novo filme:\n\n";
    cout << "Nome: ";
    getline(cin, filmeNovo.nome);
    cout << "Produtora: ";
    getline(cin, filmeNovo.produtora);
    cout << "Nota: ";
    getline(cin, nota);

    filmeNovo.nota = stoi(nota);

    catalogo += filmeNovo;

}