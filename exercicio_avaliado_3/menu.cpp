#include <iostream>
#include <string>
#include <limits>
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
        cout << "(3) Editar filme\n";
        cout << "(4) Remover filme\n";
        cout << "(5) Buscar filme\n";
        cout << "(6) Melhor filme\n";
        cout << "(7) Exibir catalogo\n\n";

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
                editarFilme();
                break;
            case 4:
                removerFilme();
                break;
            case 5:
                buscarFilme();
                break;
            case 6:
                catalogo.filmeMelhorAvaliado();
                break;
            case 7:
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> filmeNovo;
    catalogo += filmeNovo;
}

void Menu::inserirNFilmes() {
    
    int numeroFilmes;
    string nota;
    Filme filmeNovo;
    vector<Filme> filmesNovos;

    cout << "\nInserir N filmes:\n\n";
    cout << "\nEscolha o numero de filmes a serem inseridos:\n\n";

    cin >> numeroFilmes;
    
    if(cin.fail()){
        cout << "Opcao invalida\n";
        exit(-1);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int index = 0; index < numeroFilmes; index++){
        cin >> filmeNovo;
        filmesNovos.push_back(filmeNovo);
    }

    catalogo += filmesNovos;
    
}

void Menu::removerFilme(){
    cout << "\nEntre com o nome do filme a ser removido:\n\n";
    string nomeFilme;
    cin.ignore();
    getline(cin, nomeFilme);

    Filme *filmeASerRemovido = catalogo(nomeFilme);

    if(filmeASerRemovido != NULL){
        catalogo -= *filmeASerRemovido;
        cout << "\nFilme removido com sucesso.\n";
    }
    else{
        cout << "\nO filme \"" << nomeFilme << "\" nao existe no catalogo.\n";
    }
}

void Menu::buscarFilme(){
    cout << "\nEntre com o nome do filme a ser buscado:\n\n";
    string nomeFilme;
    cin.ignore();
    getline(cin, nomeFilme);

    Filme *filmeBuscado = catalogo(nomeFilme);

    if(filmeBuscado != NULL){
        cout << *filmeBuscado;
    }
    else{
        cout << "\nO filme \"" << nomeFilme << "\" nao existe no catalogo.\n";
    }
}

void Menu::editarFilme(){
    string nomeFilme;
    int opcao;
    double novaNota;
    string novaProdutora;
    Filme *filmeEditado;

    cout << "\nInsira o nome do filme a ser editado:\n\n";
    cin.ignore();
    getline(cin, nomeFilme);

    if(cin.fail())
    {
        cout << "\nOpcao Invalida\n";
        exit(-1);
    }

    cout << "\nDigite (1) para editar a nota ou (2) para editar a produtora.\n\n";
    cin >> opcao;

    if(cin.fail())
    {
        cout << "\nOpcao Invalida\n";
        exit(-1);
    }

    if(opcao == 1){
        cout << "\nNova nota: ";
        cin >> novaNota;
        if(cin.fail())
        {
            cout << "\nOpcao Invalida\n";
            exit(-1);
        }
        filmeEditado = catalogo(nomeFilme, novaNota);
    }
    else if(opcao == 2){
        cout << "\nNova produtora: ";
        cin.ignore();
        getline(cin, novaProdutora);
        filmeEditado = catalogo(nomeFilme, novaProdutora);
    }
    else{
        cout << "\nOpcao Invalida\n";
        exit(-1);
    }

    if(filmeEditado != NULL){
        cout << "\nFilme Editado:\n\n";
        cout << *filmeEditado;
    }
    else{
        cout << "\nO filme a ser editado nao existe na base\n";
    }

}