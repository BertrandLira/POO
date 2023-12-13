#include "Vacina.h"

Vacina::Vacina()
  : Insumo()
{
    tipo = "0";
    quantDoses = 0;
    intervalo = "0";
}

Vacina::~Vacina(){

}

Vacina::Vacina(int tipoInsumo)
  : Insumo(tipoInsumo)
{
  tipoInsumo = 1;
}

Vacina::Vacina(string n, int q, float v, string dv, string fab)
  : Insumo(n, q, v, dv, fab)
{
  tipoInsumo = 1;

}

void Vacina::lerAtributos(){
    cout << "Nome: ";
    getline(cin,nome);

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

    cout << "Quantidade de doses: ";
    cin >> quantDoses;
    cin.ignore();

    if(quantDoses > 1){
      cout << "Intervalo entre doses: ";
      getline(cin, intervalo);
    }else
      intervalo = "0";
}

void Vacina::exibeAtributos(){
  cout << "Tipo: " << getTipo() << endl;
  cout << "Quantidade de doses: " << getQuantDoses() << endl;

  if(getQuantDoses() > 1){
    cout << "Intervalo entre doses: " << getIntervaloDoses() << endl;
  }

}

string Vacina::getTipo()
{
  return tipo;
}

int Vacina::getQuantDoses(){
  return quantDoses;
}

string Vacina::getIntervaloDoses(){
  return intervalo;
}

void Vacina::setTipo(string t){
  tipo = t;
}

void Vacina::setQuantDoses(int qd){
  quantDoses = qd;
}

void Vacina::setIntervaloDoses(string id){
  intervalo = id;
}

Insumo* Vacina::copia(int quant){
  Vacina* v = new Vacina();

  v->setNome(nome);
  v->setQuant(quant);
  v->setValor(valorUnitario);
  v->setDataVal(dataVal);
  v->setNomeFab(fabricante);
  v->setTipo(tipo);
  v->setQuantDoses(quantDoses);
  v->setIntervaloDoses(intervalo);

  return v;
}


void Vacina::salvarInsumos(std::ofstream &fp){
  fp << tipo << endl;
  fp << quantDoses << endl;
  fp << intervalo << endl;
}

void Vacina::lerInsumos(std::ifstream &fp){
  getline(fp, tipo);
  fp >> quantDoses;
  fp.ignore();
  getline(fp, intervalo);
}
