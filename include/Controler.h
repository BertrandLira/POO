#ifndef CONTROLER_H
#define CONTROLER_H
#include "Local.h"
#include "Insumo.h"
#include "Persistencia.h"

class Controler{
    public:
        Controler();

        void cadastraInsumosMS();
        void consultaInsumos();
        void consultaInsumosDescricao();
        vector<Insumo*> consultaInsumos(int indice, int tipoInsumo);
        void distribuiInsumo();
        void salvarInsumos();
        void lerInsumos();

    private:
        Local local[28];
};

#endif // CONTROLER_H
