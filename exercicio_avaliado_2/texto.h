#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <vector>

using namespace std;

class Texto
{
    private:
        vector<string> palavras;
    public:
        Texto(string); //string caminho arquivo
        string lerArquivo(string ); //string caminho arquivo
        vector<string> cortarString(string );
        vector<string> getPalavras();
};

#endif //TEXT_H