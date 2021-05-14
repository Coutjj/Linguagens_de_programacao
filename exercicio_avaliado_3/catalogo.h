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
};


class Catalogo
{
    private:
        vector<Filme> filmes;
        vector<string> cortarNome(string );
        
    public:
        Catalogo();
        Catalogo(vector<Filme> );
        Catalogo operator+=(Filme);
        void exibirFilmes();
        
};

#endif // CATALOGO_H