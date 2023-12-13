#include "Insumo.h"

Insumo::Insumo(){
  tipoInsumo = 0;
  nome = "0";
  quantidade = 0;
  valorUnitario = 0;
  dataVal = "0";
  fabricante = "0";
}

Insumo::~Insumo(){

}

Insumo::Insumo(string n, int q, float v, string dv, string fab){
  nome = n;
  quantidade = q;
  valorUnitario = v;
  dataVal = dv;
  fabricante = fab;
}

Insumo::Insumo(int tipoInsumo){
  this->tipoInsumo = tipoInsumo;
}

int Insumo::getTipoInsumo(){
  return tipoInsumo;
}

string Insumo::getNome(){
  return nome;
}

int Insumo::getQuant(){
  return quantidade;
}

float Insumo::getValor(){
  return valorUnitario;
}

string Insumo::getDataVal(){
  return dataVal;
}

string Insumo::getNomeFab(){
  return fabricante;
}

void Insumo::setTipoInsumo(int tp){
  tipoInsumo = tp;
}

void Insumo::setNome(string n){
  nome = n;
}

void Insumo::setQuant(int q){
  quantidade = q;
}

void Insumo::setValor(float v){
  valorUnitario = v;
}

void Insumo::setDataVal(string dv){
  dataVal = dv;
}

void Insumo::setNomeFab(string fab){
  fabricante = fab;
}

ofstream&operator<<(ofstream &output, Insumo &i){
  output << i.getTipoInsumo() << endl;
  output << i.getNome() << endl;
  output << i.getQuant() << endl;
  output << i.getValor() << endl;
  output << i.getDataVal() << endl;
  //output << e.getNomeFab() << endl;
  //output << e.getTipo() << endl;
  //output << e.getDescrticao() << endl;

  return output;
}
