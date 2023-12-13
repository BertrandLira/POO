#ifndef VACINA_H
#define VACINA_H
#include "Insumo.h"
#include <string>
#include <fstream>

using namespace std;

class Vacina : public Insumo{
    public:
        Vacina();
        ~Vacina();
        Vacina(int tipoInsumo);
        Vacina(string n, int q, float v, string dv, string fab);


        void lerAtributos();
        void exibeAtributos();
        void salvarInsumos(std::ofstream &fp);
        void lerInsumos(std::ifstream &fp);

        string getTipo();
        int getQuantDoses();
        string getIntervaloDoses();
        Insumo* copia(int quant);

        void setTipo(string t);
        void setQuantDoses(int qd);
        void setIntervaloDoses(string id);

    protected:
        string tipo;
        int quantDoses;
        string intervalo;
};

#endif // VACINA_H
