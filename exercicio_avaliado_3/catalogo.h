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
    bool operator==(Filme );
    bool operator<(Filme );
    friend ostream& operator<<(ostream &, Filme &);
    
};

//Filme operator==(Filme& filme);

class Catalogo
{
    private:
        vector<Filme> filmes;
        vector<string> cortarNome(string );
        void insercaoOrdenada(Filme );
        int teste;
        void lerCatalogoSalvo();
        
    public:
        Catalogo();
        Catalogo(vector<Filme>);
        Catalogo operator+=(Filme);
        Catalogo operator+=(vector<Filme>);
        Catalogo operator-=(Filme);
        Filme *operator()(string);
        Filme *operator()(string, int);
        Filme *operator()(string, string);
        friend ostream& operator<<(ostream &, Catalogo &);
        void salvarCatalogo();
        
};

#endif // CATALOGO_H