#include "Local.h"

Local::Local(){

}

void Local::adicionaInsumo(Insumo *ins){

  if(ins->getTipoInsumo() == 1){
    insumo[0].push_back(ins);

  }else if(ins->getTipoInsumo() == 2){
    insumo[1].push_back(ins);

  }else if(ins->getTipoInsumo() == 3){
    insumo[2].push_back(ins);

  }

}

void Local::adicionaInsumoEstado(int quantidade, Insumo *ins){
  Insumo *copia;

  copia = ins->copia(quantidade);
  copia->setTipoInsumo(ins->getTipoInsumo());

  if(ins->getTipoInsumo() == 1){
    insumo[0].push_back(copia);

  }else if(ins->getTipoInsumo() == 2){
    insumo[1].push_back(copia);

  }else if(ins->getTipoInsumo() == 3){
    insumo[2].push_back(copia);

  }
}

string Local::getNome(){
  return nome;
}

void Local::setNome(string n){
  nome = n;
}

void Local::exibeInsumoDesc(){
  unsigned int um, dois, tres;

  um = insumo[0].size();
  dois = insumo[1].size();
  tres = insumo[2].size();

  if(um == 0 && dois == 0 && tres == 0){
    cout << endl <<"Não têm insumos cadastrados nesse local!" << endl << endl;
    return;
  }

  for(int i = 0; i < 3; i++){
    switch(i){
      case(0):
        if(insumo[0].size() >= 1)
          cout << "--> Vacina: " << endl;
        break;
      case(1):
        if(insumo[1].size() >= 1)
          cout << "--> Medicamento: " << endl;
        break;
      case(2):
        if(insumo[2].size() >= 1)
          cout << "--> EPI: " << endl;
        break;
    }

    for(unsigned int j = 0; j < insumo[i].size(); j ++){
      if(insumo[i][j]->getQuant() > 0){
        cout << endl << "- Lote " << j+1 << ": " << endl;

        cout << "Nome: " << insumo[i][j]->getNome() << endl;
        cout << "Quantidade: " << insumo[i][j]->getQuant() << endl;
        cout << "Valor unitário: " << insumo[i][j]->getValor() << endl;
        cout << "Data de validade: " << insumo[i][j]->getDataVal() << endl;
        cout << "Nome do fabricante: " << insumo[i][j]->getNomeFab() << endl;

        insumo[i][j]->exibeAtributos();
      }


    }
    cout << endl;
  }
}

void Local::exibeInsumo(){
  int total[3] = {0};

  for(int i = 0; i < 3; i++){
    for(unsigned int j = 0; j < insumo[i].size(); j ++){
      total[i] += insumo[i][j]->getQuant();
    }

    if(i == 0){
      cout << "Vacinas: ";
    }else if(i == 1){
      cout << "Medicamentos: ";
    }else if(i == 2){
      cout << "EPI's: ";
    }

    cout << total[i] << endl;
  }

  cout << "Total de insumos: " << total[0] + total[1] + total[2] << endl;
}

void Local::retiraQuantMS(int quantidade, int lote, int tipoIns){
  int quantidadeNoMS;
  int quantidadeTotal;

  quantidadeNoMS = insumo[tipoIns][lote]->getQuant();
  quantidadeTotal = quantidadeNoMS - quantidade;
  insumo[tipoIns][lote]->setQuant(quantidadeTotal);
}

Insumo* Local::getLote(int tipoIns, int lote){

  return insumo[tipoIns][lote];
}

vector<Insumo*> Local::getVector(int indice){
  return insumo[indice];
}

void Local::setVector(int indice, vector<Insumo*> vet){
    insumo[indice] = vet;
}
