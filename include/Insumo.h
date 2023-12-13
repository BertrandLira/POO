#ifndef INSUMO_H
#define INSUMO_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Insumo
{
    friend ofstream&operator<<(ofstream&, const Insumo&);
    friend ifstream&operator>>(ifstream&, const Insumo&);

    public:
        Insumo();
        virtual ~Insumo();
        Insumo(int tipoInsumo);
        Insumo(string n, int q, float v, string dv, string fab);

        virtual void lerAtributos() = 0;
        virtual void exibeAtributos() = 0;
        virtual Insumo* copia(int quant) = 0;
        virtual void salvarInsumos(std::ofstream &fp) = 0;
        virtual void lerInsumos(std::ifstream &fp) = 0;

        virtual int getTipoInsumo();
        virtual string getNome();
        virtual int getQuant();
        virtual float getValor();
        virtual string getDataVal();
        virtual string getNomeFab();

        virtual void setTipoInsumo(int tp);
        virtual void setNome(string n);
        virtual void setQuant(int q);
        virtual void setValor(float v);
        virtual void setDataVal(string dv);
        virtual void setNomeFab(string fab);

    protected:
        string nome;
        int quantidade;
        int valorUnitario;
        string dataVal;
        string fabricante;
        int tipoInsumo;
};

#endif // INSUMO_H
