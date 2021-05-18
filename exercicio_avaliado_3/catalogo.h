/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Definicoes da classe que modela um catalogo de filmes e da struct que modela o filme.
*/

#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>
#include <vector>

using namespace std;

struct Filme
{
    string nome;
    string produtora;
    double nota;
    bool operator==(Filme ); // retorna true se o nome dos dois filmes sao iguais
    bool operator<(Filme ); // retor
    bool operator>(Filme ); //retorna true quando filme1.nota > filme2.nota
    friend ostream& operator<<(ostream &, Filme &); // exibe um filme na linha de commando (cout << filme)
    friend istream& operator>>(istream &, Filme &); // cria um novo filme (cin >> filmeNovo)

};

class Catalogo
{
    private:
        vector<Filme> filmes; // lista de filmes no catalogo
        vector<string> cortarNome(string ); // Retorna palavras de uma string divididas em um vetor
        void insercaoOrdenada(Filme ); // insere um filme de maneira ordenada
        void lerCatalogoSalvo(); //le a persistencia do catalogo em catalogo.txt
        int numMaxFilmes = 10;
        
    public:
        Catalogo();
        Catalogo(vector<Filme>);
        Catalogo operator+=(Filme); // insere um novo filme
        Catalogo operator+=(vector<Filme>); // insere um vetor de novos filmes
        Catalogo operator-=(Filme); // remove um filme 
        Filme *operator()(string); // busca um filme pelo nome
        Filme *operator()(string, double); // altera a nota de um filme especificado pelo nome
        Filme *operator()(string, string); // altera a produtora de um filme especificado pelo nome
        friend ostream& operator<<(ostream &, Catalogo &); // exibe o catalogo completo (cout << catalogo)
        void salvarCatalogo(); // salva o catalogo atual em catalogo.txt
        void filmeMelhorAvaliado(); // exibe o filme com maior nota
        static bool ehAlphaNumerico(string); // chaca se entrada eh alphanumerica
        static bool ehNumerico(char *); // checa se a nota atribuida eh valida
        
};

#endif // CATALOGO_H