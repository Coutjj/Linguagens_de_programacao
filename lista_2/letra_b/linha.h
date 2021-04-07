#include "ponto.h"
#include <vector>

class Linha
{
    private:
        float comprimento;
        std::vector <Ponto> pontos;
        void setComprimento();
    public:
        Linha(Ponto, Ponto);
        float getComprimento();
};
