/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima
  * 
  * Classe que modela um o texto a ser lido. Executa a leitura do texto e devolve
  * palavras separadas como vetores
*/

#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>

using namespace std;

class Texto
{
    private:
        vector<string> palavras; //palavras ou pontuacao do texto
        string texto; //texto original em formato de string
        vector<string> cortarString(string ); //retorna vetor onde cada item eh uma palavra ou pontuacao
    public:
        Texto(string); //string caminho arquivo
        string lerArquivo(string ); //string caminho arquivo
        vector<string> getPalavras(); //retorna vetor de palavras
        string getTexto(); //retorna string com texto original
};

#endif //TEXT_H