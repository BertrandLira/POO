#ifndef EPI_H
#define EPI_H
#include "Insumo.h"
#include <string>
#include <fstream>

using namespace std;

class EPI : public Insumo{
    public:
        EPI();
        ~EPI();
        EPI(int tipoInsumo);
        EPI(string n, int q, float v, string dv, string fab);

        void lerAtributos();
        void exibeAtributos();
        void salvarInsumos(std::ofstream &fp);
        void lerInsumos(std::ifstream &fp);

        string getTipo();
        string getDescrticao();
        Insumo* copia(int quant);

        void setTipo(string t);
        void setDescricao(string desc);

    protected:
        string tipo;
        string descricao;
};

#endif // EPI_H
