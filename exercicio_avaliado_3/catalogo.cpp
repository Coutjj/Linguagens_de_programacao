#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include "catalogo.h"

using namespace std;

Catalogo::Catalogo(){
    lerCatalogoSalvo();
}

Catalogo::Catalogo(vector<Filme> filmesInput){
    filmes = filmesInput;
}


Catalogo Catalogo::operator+=(Filme filmeInput){
    insercaoOrdenada(filmeInput);
    Catalogo novoCatalogo(filmes);
    return novoCatalogo;
}

Catalogo Catalogo::operator+=(vector<Filme> filmesInput){

    for(auto filme: filmesInput){
        insercaoOrdenada(filme);
    }

    Catalogo novoCatalogo(filmes);
    return novoCatalogo;    
}

//Retorna palavras de uma string divididas em um vetor
vector<string> Catalogo::cortarNome(string nomeInput){

    stringstream itNomeInput(nomeInput);
    vector<string> palavrasNoNome;
    string palavra;
    while (itNomeInput >> palavra)
    {
        palavrasNoNome.push_back(palavra);
    }

    return palavrasNoNome;
}


void Catalogo::insercaoOrdenada(Filme filmeInput){
    int posicaoInsercao = -1;

    if(filmes.size() == 0){
        filmes.push_back(filmeInput);
        // cout << "\nInseri " << filmeInput.nome << " Na pos 1\n";
    }
    else{
        for(int index = 0; index < int(filmes.size()); index++){

            vector<string> palavrasFilmeSalvo = cortarNome(filmes[index].nome);
            vector<string> palavrasFilmeInput = cortarNome(filmeInput.nome);

            if(filmeInput == filmes[index]){
                cout << "\n O filme " << filmeInput.nome
                    << " nao pode ser inserido pois ele ja existe no catalogo\n";
                break;
            }

            for(int indexInput = 0; indexInput < int(palavrasFilmeInput.size()); indexInput++){
                
                if(indexInput < int(palavrasFilmeSalvo.size())){
                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) < 0){
                    //    cout << "Antes " << filmeInput.nome << " - " << filmes[index].nome
                    //        << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        posicaoInsercao = index;
                        break;
                        //Se cair aqui eu achei a posicao
                    }
                

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) > 0){
                        // cout << "Depois " << filmeInput.nome << " - " << filmes[index].nome
                        //     << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        break;
                        //Se cair aqui eu tenho que procurar ate encontrar status como antes
                    }

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) == 0){
                        // cout << "nao sei " << filmeInput.nome << " - " << filmes[index].nome
                        //     << " -> " << palavrasFilmeInput[indexInput]<<  " e " << palavrasFilmeSalvo[indexInput] << endl;
                        //Se cair aqui eu devo procurar ate encontrar status como antes ou se nao tem proxima palavra
                        //entra no lugar do nome original
                        if((int(palavrasFilmeInput.size()) - 1) <= indexInput){
                            posicaoInsercao = index;
                            break;
                        }
                    }
                }
            }

            if ((posicaoInsercao != -1)){
                vector<Filme>::iterator it = filmes.begin() + posicaoInsercao;
                filmes.insert(it, filmeInput);
                break;            
            }
            else if(index == (int(filmes.size()) - 1)){
                filmes.push_back(filmeInput);
                break;
            }

        }
    }

}


Catalogo Catalogo::operator-=(Filme filmeParaRemover){

    vector<Filme> novaColecao;

    for(auto filme: filmes){
        if(!(filme == filmeParaRemover)){
            novaColecao.push_back(filme);
        }
    }

    filmes = novaColecao;
    Catalogo novoCatalogo(novaColecao);
    return novoCatalogo;
}

Filme *Catalogo::operator()(string filmeProcurado){
    for(int index = 0; index < int(filmes.size()); index++){
        if(filmes[index].nome == filmeProcurado){
            return (&filmes[index]);
        }  
    }

    return NULL;
}

Filme *Catalogo::operator()(string nomeBusca, int novaNota){
    auto it = filmes.begin();
    for(int index = 0; index < int(filmes.size()); index++){
        if(nomeBusca == filmes[index].nome){
            it += index;
            Filme filmeAlterado;
            filmeAlterado.nome = nomeBusca;
            filmeAlterado.nota = novaNota;
            filmeAlterado.produtora = filmes[index].produtora;
            filmes.erase(it);
            filmes.insert(it, filmeAlterado);
            return &filmes[index];
        }
    }

    return NULL;
}

Filme *Catalogo::operator()(string nomeBusca, string novaProdutora){

    auto it = filmes.begin();
    for(int index = 0; index < int(filmes.size()); index++){
        if(nomeBusca == filmes[index].nome){
            it += index;
            Filme filmeAlterado;
            filmeAlterado.nome = nomeBusca;
            filmeAlterado.nota = filmes[index].nota;
            filmeAlterado.produtora = novaProdutora;
            filmes.erase(it);
            filmes.insert(it, filmeAlterado);
            return &filmes[index];
        }
    }
    
    return NULL;
}

void Catalogo::lerCatalogoSalvo(){
    fstream input;
    input.open("catalogo.txt", ios::in);
    string linha;

    if(input.is_open()){
        while ( getline(input, linha))
        {
            if(linha[0] == '#'){
                continue;
            }

            stringstream ss(linha);
            string dadosTexto;
            vector<string> dadosFilme;
            while (getline(ss, dadosTexto, ':'))
            {
                dadosFilme.push_back(dadosTexto);
            }
            
            Filme filmeTemp;
   
            filmeTemp.nome = dadosFilme[0];
            filmeTemp.produtora = dadosFilme[1];
            filmeTemp.nota = stoi(dadosFilme[2]);
            insercaoOrdenada(filmeTemp);
        }      
    }

    input.close();
}

void Catalogo::salvarCatalogo(){
    fstream input;
    input.open("catalogo.txt", ios::out);
    input << "# Nao altere o conteudo deste arquivo. Caso seja necessario realizar "
        << "alguma alteracao, faca atraves do programa.";

    string linha;

    for(auto filme: filmes){
        linha = filme.nome + ":" + filme.produtora + ":" + to_string(filme.nota);
        input << "\n" <<linha;
    }

    input.close();
}

void Catalogo::filmeMelhorAvaliado(){
    Filme melhorFilme;
    bool ehMelhorFilme = true;

    //usando operador sobrecarregado >
    for(int index = 0; index < int(filmes.size()); index++){
        for(int index2 = 0; index2 < int(filmes.size()); index2++){
            
            if(index != index2){
                cout << "Comp " << filmes[index].nome << filmes[index].nota << " - " <<filmes[index2].nome << filmes[index2].nota << endl;
                if (!(filmes[index] >  filmes[index2])){
                    cout << "Comp " << filmes[index].nome << filmes[index].nota << " - " <<filmes[index2].nome << filmes[index2].nota << endl;
                    ehMelhorFilme = false;
                }
            }
        }

        if(ehMelhorFilme == true){
            melhorFilme = filmes[index];
            break;
        }

        ehMelhorFilme = true;
    }

    if(melhorFilme.nome != ""){
        cout << "\nMelhor Filme:\n\n";
        cout << melhorFilme;
    }
    else{
        cout << "\nNao existe melhor filme.";
    }
    //Caso nao exista filme com maior nota, nao existe filme melhor.
}


ostream& operator<<(ostream &out, Catalogo &catalogoInput){
    out << "\nCatalogo de filmes:\n\n";
    out << setw(30) << left << "Nome\t" << setw(30) << left << "Produtora\t" << "Nota\n\n"; 

    for(auto filme: catalogoInput.filmes){
        out << setw(30) << left << filme.nome << "\t" << setw(30) << left << filme.produtora << "\t" << filme.nota << endl;
    }

    return out;
}

bool Filme::operator==(Filme filmeInput){

    if(this->nome == filmeInput.nome){
        return true;
    }
    else{
        return false;
    }
}

bool Filme::operator<(Filme filmeInput){
    if(this->nome < filmeInput.nome){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator<<(ostream &out, Filme &filme){
    //out << "\nFilme na tela:\n\n";
    out << setw(30) << left << "Nome\t" << setw(30) << left << "Produtora\t" << "Nota\n\n"; 
    out << setw(30) << left << filme.nome << "\t" << setw(30) << left << filme.produtora << "\t" << filme.nota << endl;
    return out;
}

istream& operator>>(istream &in, Filme &filmeNovo){
    string nota;
    cout << "\nInserir novo filme:\n\n";
    cout << "Nome: ";
    getline(in, filmeNovo.nome);
    cout << "Produtora: ";
    getline(in, filmeNovo.produtora);
    cout << "Nota: ";
    getline(in, nota);
    filmeNovo.nota = stoi(nota);
    
    return in;
}

// retorna true quando filme1 > filme, onde filme1.nota > filme2.nota
bool Filme::operator>(Filme filme){
    if(this->nota > filme.nota){
        return true;
    }
    else{
        return false;
    }
}