#include "Persistencia.h"
#include <fstream>
#include "Insumo.h"
#include "Vacina.h"
#include "EPI.h"
#include "Medicamento.h"

Persistencia::Persistencia()
{
    //ctor
}

void Persistencia::salvarInsumos(vector<Insumo*> ins, ofstream &fp){

    if(fp.is_open()){
        for(unsigned int i = 0; i < ins.size(); i++){
            fp << ins[i]->getTipoInsumo() << endl;
            fp << ins[i]->getNome() << endl;
            fp << ins[i]->getQuant() << endl;
            fp << ins[i]->getValor() << endl;
            fp << ins[i]->getDataVal() << endl;
            fp << ins[i]->getNomeFab() << endl;
            ins[i]->salvarInsumos(fp);
        }
    }

}

vector<Insumo*> Persistencia::lerInsumos(ifstream &fp, int tipo){
    string n, d, f;//nome, dataVal, fabricante
    int q, v, t;//quantidade, valor, tipoDoInsumo
    vector<Insumo*> vet;
    Insumo* ins;

    while(true){

        fp >> t;

        if(t != tipo)
            break;

        if(fp.eof() || fp.bad())
            break;

        fp.ignore();
        getline(fp, n);

        fp >> q;

        fp >> v;
        fp.ignore();

        getline(fp, d);

        getline(fp, f);

        switch(t){
            case 1:
                ins = new Vacina(n, q, v, d, f);
                break;
            case 2:
                ins = new Medicamento(n, q, v, d, f);
                break;
            case 3:
                ins = new EPI(n, q, v, d, f);
                break;
        }

        ins->lerInsumos(fp);

        vet.push_back(ins);
    }

    return vet;
}
