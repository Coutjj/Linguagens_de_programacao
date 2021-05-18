#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include "catalogo.h"

using namespace std;

Catalogo::Catalogo(){
    lerCatalogoSalvo();
}

Catalogo::Catalogo(vector<Filme> filmesInput){
    filmes = filmesInput;
}

Catalogo Catalogo::operator+=(Filme filmeInput){
    if(int(filmes.size() + 1) > numMaxFilmes){
        cout << "\nNumero maximo de filmes excedido\n";
        Catalogo novoCatalogo(filmes);
        return novoCatalogo;
    }

    insercaoOrdenada(filmeInput);
    Catalogo novoCatalogo(filmes);
    return novoCatalogo;
}

Catalogo Catalogo::operator+=(vector<Filme> filmesInput){

    if(int(filmes.size() + filmesInput.size()) > numMaxFilmes){
        cout << "\nNumero maximo de filmes excedido\n";
        Catalogo novoCatalogo(filmes);
        return novoCatalogo;
    }

    //cada filme do vetor eh adicionado de forma ordenada
    for(auto filme: filmesInput){
        insercaoOrdenada(filme);
    }

    Catalogo novoCatalogo(filmes);
    return novoCatalogo;    
}

// Retorna palavras de uma string divididas em um vetor
// Ex.: "O grande filme" -> {"O", "Grande", "Filme"}
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

    transform(filmeInput.nome.begin(), filmeInput.nome.end(), filmeInput.nome.begin(), ::toupper);
    transform(filmeInput.produtora.begin(), filmeInput.produtora.end(), filmeInput.produtora.begin(), ::toupper);

    if(filmes.size() == 0){
        filmes.push_back(filmeInput);
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
                        posicaoInsercao = index;
                        break;
                        // Se entrar aqui eu achei a posicao
                        // (inserir antes)
                    }
                

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) > 0){
                        break;
                        // Se entrar aqui eu tenho que interromper e continuar busca ate
                        // encontrar posicao como (inserir antes)
                    }

                    if(palavrasFilmeInput[indexInput].compare(palavrasFilmeSalvo[indexInput]) == 0){
                        
                        // Se entrar aqui eu devo procurar ate encontrar status como (inserir antes)
                        // ou verificar se existe proxima palavra no nome do filme que mudaria a sua posicao
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
            }// Se nao entrou em (inserir antes) eh pq so pode entrar na ultima posicao
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

    transform(filmeProcurado.begin(), filmeProcurado.end(), filmeProcurado.begin(), ::toupper);

    for(int index = 0; index < int(filmes.size()); index++){
        if(filmes[index].nome == filmeProcurado){
            return (&filmes[index]);
        }  
    }

    return NULL;
}

Filme *Catalogo::operator()(string nomeBusca, double novaNota){

    transform(nomeBusca.begin(), nomeBusca.end(), nomeBusca.begin(), ::toupper);
    auto it = filmes.begin();

    if((novaNota < 0)){
        cout << "\nEntrada invalida\n";
        exit(-1);
    }

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

    if(!(Catalogo::ehAlphaNumerico(novaProdutora)))
    {
        cout << "\nNomes invalidos\n";
        exit(-1);
    }
    transform(nomeBusca.begin(), nomeBusca.end(), nomeBusca.begin(), ::toupper);
    transform(novaProdutora.begin(), novaProdutora.end(), novaProdutora.begin(), ::toupper);

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
            // Pula a linha de aviso/comentario
            if(linha[0] == '#'){
                continue;
            }
            
            transform(linha.begin(), linha.end(), linha.begin(), ::toupper);
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
            filmeTemp.nota = stod(dadosFilme[2]);
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

    // Forcando o uso do operador sobrecarregado filme1 > filme2
    for(int index = 0; index < int(filmes.size()); index++){
        for(int index2 = 0; index2 < int(filmes.size()); index2++){
            
            if(index != index2){
                if (!(filmes[index] >  filmes[index2])){
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
    // Caso nao exista filme com maior nota, nao existe filme melhor.
}


ostream& operator<<(ostream &out, Catalogo &catalogoInput){
    out << "\nCatalogo de filmes:\n\n";
    out << setw(30) << left << "Nome\t" << setw(30) << left << "Produtora\t" 
        << "Nota\n\n"; 

    for(auto filme: catalogoInput.filmes){
        out << setw(30) << left << filme.nome << "\t" << setw(30) << left 
            << filme.produtora << "\t" << filme.nota << endl;
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

    if(in.fail()){
        cout << "\nEntrada invalida\n";
        exit(-1);
    }

    if(!(Catalogo::ehAlphaNumerico(filmeNovo.nome))
        || !(Catalogo::ehAlphaNumerico(filmeNovo.produtora))){
        cout << "\nNomes invalidos\n";
        exit(-1);
    }

    if(!Catalogo::ehNumerico(&nota[0])){
        cout << "\nEntrada invalida\n";
        exit(-1);
    }

    filmeNovo.nota = stod(nota);
    
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


bool Catalogo::ehAlphaNumerico(string entrada){
    for(auto letra: entrada){
        if(letra != ' '){
            if(!isalnum(letra)){
                return false;
            }
        }
    }

    return true;
}

bool Catalogo::ehNumerico(char *entrada){
    
    char* endptr = 0;
    strtod(entrada, &endptr);
    // se conversao falhar a entrada nao eh valida
    if(*endptr != '\0' || endptr == entrada){
        return false;
    }

    return true;
}