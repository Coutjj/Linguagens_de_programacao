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
        cout << "(2) Inserir N filmes\n";
        cout << "(3) Remover filme\n";
        cout << "(4) Exibir catalogo\n\n";

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
            inserirNFilmes();
            break;
        case 3:
            removerFilme();
            break;
        case 4:
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
    cout << "\nInserir novo filme:\n\n";
    cout << "Nome: ";
    getline(cin, filmeNovo.nome);
    cout << "Produtora: ";
    getline(cin, filmeNovo.produtora);
    cout << "Nota: ";
    getline(cin, nota);

    filmeNovo.nota = stoi(nota);

    catalogo += filmeNovo;
}

void Menu::inserirNFilmes() {
    
    int numeroFilmes;
    string nota;
    Filme filmeNovo;
    vector<Filme> filmesNovos;

    cout << "\nInserir N filmes:\n\n";
    cout << "\nEscolha o numero de filmes a serem inseridos:\n";

    cin >> numeroFilmes;
    
    if(cin.fail()){
        cout << "Opcao invalida\n";
        exit(-1);
    }

    cin.ignore();
    for(int index = 0; index < numeroFilmes; index++){
        cout << "\nInserir novo filme " << index << " :\n\n";
        cout << "Nome: ";
        getline(cin, filmeNovo.nome);
        cout << "Produtora: ";
        getline(cin, filmeNovo.produtora);
        cout << "Nota: ";
        getline(cin, nota);

        filmeNovo.nota = stoi(nota);

        filmesNovos.push_back(filmeNovo);
    }

    catalogo += filmesNovos;
    
}

void Menu::removerFilme(){
    cout << "\nEntre com o nome do filme a ser removido:\n";
    string nomeFilme;
    cin.ignore();
    getline(cin, nomeFilme);

    Filme *filmeASerRemovido = catalogo(nomeFilme);

    if(filmeASerRemovido != NULL){
        catalogo -= *filmeASerRemovido;
        cout << "\nFilme removido com sucesso.\n";
    }
    else{
        cout << "\nO filme " << nomeFilme << " nao existe no catalogo.\n";
    }
}