#include "EPI.h"

EPI::EPI()
  : Insumo()
{
    tipo = "0";
    descricao = "0";
}

EPI::~EPI(){

}

EPI::EPI(int tipoInsumo)
  : Insumo(tipoInsumo)
{
  tipoInsumo = 3;
}

EPI::EPI(string n, int q, float v, string dv, string fab)
  : Insumo(n, q, v, dv, fab)
{
    tipoInsumo = 3;
}

void EPI::lerAtributos(){
    cout << "Nome: ";
    getline(cin, nome);

    cout << "Quantidade: ";
    cin >> quantidade;
    cin.ignore();

    cout << "Valor unitário: ";
    cin >> valorUnitario;
    cin.ignore();

    cout << "Data de validade: ";
    getline(cin, dataVal);

    cout << "Nome do fabricante: ";
    getline(cin, fabricante);

    cout << "Tipo: ";
    getline(cin, tipo);

    cout << "Descrição: ";
    getline(cin,descricao);
}

void EPI::exibeAtributos(){
  cout << "Tipo: " << getTipo() << endl;
  cout << "Descrição: " << getDescrticao() << endl;
}

string EPI::getTipo(){
  return tipo;
}

string EPI::getDescrticao(){
  return descricao;
}

void EPI::setTipo(string t){
  tipo = t;
}

void EPI::setDescricao(string desc){
  descricao = desc;
}

Insumo* EPI::copia(int quant){
  EPI* e = new EPI();

  e->setNome(nome);
  e->setQuant(quant);
  e->setValor(valorUnitario);
  e->setDataVal(dataVal);
  e->setNomeFab(fabricante);
  e->setTipo(tipo);
  e->setDescricao(descricao);

  return e;
}


void EPI::salvarInsumos(std::ofstream &fp){
    fp << tipo << endl;
    fp << descricao << endl;
}

void EPI::lerInsumos(std::ifstream &fp){
  getline(fp, tipo);
  getline(fp, descricao);
}
