#ifndef LOCAL_H
#define LOCAL_H
#include <string>
#include <vector>
#include "Insumo.h"
#include "EPI.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "Menu.h"

using namespace std;

class Local
{
    public:
        Local();

        void adicionaInsumo(Insumo *ins);
        void adicionaInsumoEstado(int quantidade, Insumo *ins);

        void distribuiInsumo(int tipoIns, int quantidade, Insumo* ins);
        void retiraQuantMS(int quantidade, int lote, int tipoIns);

        string getNome();
        void setNome(string n);

        //vector<Insumo*> getInsumo(int t);
        Insumo* getLote(int tipoIns, int lote);
        vector<Insumo*> getVector(int indice);
        void setVector(int indice, vector<Insumo*> vet);


        void exibeInsumoDesc();
        void exibeInsumo();

    protected:
        string nome;
        int indice;
        vector<Insumo*> insumo[3];
};

#endif // LOCAL_H
