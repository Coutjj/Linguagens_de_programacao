#ifndef NACIONAL_H
#define NACIONAL_H

#include <vector>
#include "estadual.h"

using namespace std;

class Nacional
{
    private:
        vector<Estadual> estados;
        vector<float> mediaMovel;
    public:
        Nacional();
};


#endif NACIONAL_H // NACIONAL_H