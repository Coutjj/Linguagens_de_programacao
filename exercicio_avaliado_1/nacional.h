#ifndef NACIONAL_H
#define NACIONAL_H

#include <vector>
#include "estadual.h"
#include <string>

using namespace std;

class Nacional
{
    private:
        vector<Estadual> estados;
        vector<float> serieMediaMovel;
        string nome;
        void setNome(string);
        void setEstados(vector<Estadual>);

    public:
        Nacional(string, vector <Estadual>);
        Nacional();
        string getNome();
        vector<Estadual> getEstados();
        void setSerieMediaMovel(vector<float>);
        vector<float> getSerieMediaMovel();
};


#endif // NACIONAL_H