#include "Medicamento.h"

Medicamento::Medicamento()
  : Insumo()
{
    dosagem = "0";
    administracao = "0";
    disponibilizacao = "0";
}

Medicamento::~Medicamento(){

}

Medicamento::Medicamento(int tipoInsumo)
  : Insumo(tipoInsumo)
{
  tipoInsumo = 2;
}

Medicamento::Medicamento(string n, int q, float v, string dv, string fab)
  : Insumo(n, q, v, dv, fab)
{
  tipoInsumo = 2;

}

void Medicamento::lerAtributos(){
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

    cout << "Dosagem: ";
    getline(cin, dosagem);

    cout << "Administracao: ";
    getline(cin, administracao);

    cout << "Disponibilização: ";
    getline(cin, disponibilizacao);

}

void Medicamento::exibeAtributos(){
  cout << "Dosagem: " << getDosagem() << endl;
  cout << "Administração: " << getAdministracao() << endl;
  cout << "Disponibilização: " << getDisponibilizacao() << endl;

}

string Medicamento::getDosagem(){
  return dosagem;
}

string Medicamento::getAdministracao(){
  return administracao;
}

string Medicamento::getDisponibilizacao(){
  return disponibilizacao;
}

void Medicamento::setDosagem(string dos){
  dosagem = dos;
}

void Medicamento::setAdministracao(string adm){
  administracao = adm;
}

void Medicamento::setDisponibilizacao(string disp){
  disponibilizacao = disp;
}

Insumo* Medicamento::copia(int quant){
  Medicamento* m = new Medicamento();

  m->setNome(nome);
  m->setQuant(quant);
  m->setValor(valorUnitario);
  m->setDataVal(dataVal);
  m->setNomeFab(fabricante);
  m->setDosagem(dosagem);
  m->setAdministracao(administracao);
  m->setDisponibilizacao(disponibilizacao);

  return m;
}


void Medicamento::salvarInsumos(std::ofstream &fp){
    fp << dosagem << endl;
    fp << administracao << endl;
    fp << disponibilizacao << endl;
}

void Medicamento::lerInsumos(std::ifstream &fp){
  getline(fp, dosagem);
  getline(fp, administracao);
  getline(fp, disponibilizacao);
}
