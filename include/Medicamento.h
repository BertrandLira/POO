#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include "Insumo.h"
#include <string>
#include <fstream>

using namespace std;

class Medicamento : public Insumo{
    public:
        Medicamento();
        ~Medicamento();
        Medicamento(int tipoInsumo);
        Medicamento(string n, int q, float v, string dv, string fab);

        void lerAtributos();
        void exibeAtributos();
        void salvarInsumos(std::ofstream &fp);
        void lerInsumos(std::ifstream &fp);

        string getDosagem();
        string getAdministracao();
        string getDisponibilizacao();
        Insumo* copia(int quant);

        void setDosagem(string dosagem);
        void setAdministracao(string administracao);
        void setDisponibilizacao(string disponibilizacao);

    protected:
        string dosagem;
        string administracao;
        string disponibilizacao;
};

#endif // MEDICAMENTO_H
