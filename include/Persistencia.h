#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <vector>
#include "Insumo.h"

class Persistencia
{
    public:
        Persistencia();

        void salvarInsumos(vector<Insumo*> ins,  ofstream &fp);
        vector<Insumo*> lerInsumos(ifstream &fp, int tipo);

};

#endif // PERSISTENCIA_H
