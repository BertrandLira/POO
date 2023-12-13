#include "Controler.h"

Controler::Controler(){

  local[0].setNome("Ministério da Saúde");
  local[1].setNome("Acre");
  local[2].setNome("Alagoas");
  local[3].setNome("Amapá");
  local[4].setNome("Amazonas");
  local[5].setNome("Bahia");
  local[6].setNome("Ceará");
  local[7].setNome("Distrito Federal");
  local[8].setNome("Espírito Santo");
  local[9].setNome("Goiás");
  local[10].setNome("Maranhão");
  local[11].setNome("Mato Grosso");
  local[12].setNome("Mato Grosso do Sul");
  local[13].setNome("Minas Gerais");
  local[14].setNome("Pará");
  local[15].setNome("Paraíba");
  local[16].setNome("Paraná");
  local[17].setNome("Pernambuco");
  local[18].setNome("Piauí");
  local[19].setNome("Rio de Janeiro");
  local[20].setNome("Rio Grande do Norte");
  local[21].setNome("Rio Grande do Sul");
  local[22].setNome("Rondônia");
  local[23].setNome("Roraima");
  local[24].setNome("Santa Catarina");
  local[25].setNome("São Paulo");
  local[26].setNome("Sergipe");
  local[27].setNome("Tocantis");
}



void Controler::cadastraInsumosMS(){
  Menu menu;
  int loop;
  int tipoIns;
  Insumo *insumo;

  while(true){

    cout << "Digite o insumo a ser cadastrado: " << endl;
    menu.exibeMenuInsumos();

    cin >> tipoIns;
    cin.ignore();
    system("CLS");

    while(tipoIns > 3 || tipoIns < 1){
        cout << "Insumo inválido. Digite novamente: ";
        cin >> tipoIns;
        cin.ignore();
        system("CLS");
      }

    while(true){
      switch(tipoIns){
      case(1):
      insumo = new Vacina(1);
      break;

      case(2):
      insumo = new Medicamento(2);
      break;

      case(3):
      insumo = new EPI(3);
      break;

      }

      insumo->setTipoInsumo(tipoIns);

      insumo->lerAtributos();

      local[0].adicionaInsumo(insumo);

      cout << endl << "Cadastrado com sucesso!!" << endl << endl;
      system("CLS");

      cout << "1 - Cadatrar o mesmo insumo novamente" << endl;
      cout << "2 - Cadastrar outro insumo" << endl;
      cout << "3 - Voltar ao menu" << endl << endl;

      cin >> loop;
      getchar();
      system("CLS");
      while(loop > 3 || loop < 1){
        cout << endl << "Valor inválido. Digite novamente: " << endl;
        cin >> loop;
        getchar();
        system("CLS");
      }
      if(loop == 2 || loop == 3)
        break;
    }
    if(loop == 3)
      break;
  }

  system("CLS");
}

void Controler::consultaInsumos(){//consulta os insumos no local indicado, apenas a quantidade
  int indice;
  Menu menu;
  int loop;

  while(true){
    cout << endl << "Digite o local que deseja consultar: " << endl;

    menu.exibeMenuEstados();

    cin >> indice;
    cin.ignore();
    system("CLS");


    while(indice > 28 || indice < 0){
    cout << "Local inválido. Digite novamente." << endl << endl;
    menu.exibeMenuEstados();
    cin >> indice;
    cin.ignore();
    system("CLS");
  }

    cout << endl << local[indice].getNome() << ": " << endl << endl;

    local[indice].exibeInsumo();

    cout << endl << "1 - Consultar outro local" << endl;
    cout << "2 - Voltar ao menu" << endl;

    cin >> loop;
    getchar();
    system("CLS");
    if(loop == 2)
      break;
  }

  system("CLS");
}

void Controler::consultaInsumosDescricao(){//consulta a descrição dos insumos no local indicado
  int indice;
  int loop;
  Menu menu;

  while(true){
  cout << "Digite o local que deseja consultar: " << endl;

  menu.exibeMenuEstados();

  cin >> indice;
  cin.ignore();
  system("CLS");

  while(indice > 28 || indice < 0){
      cout << "Local inválido. Digite novamente." << endl << endl;
      menu.exibeMenuEstados();
      cin >> indice;
      cin.ignore();
      system("CLS");
    }

  cout << local[indice].getNome() << ": " << endl;

  local[indice].exibeInsumoDesc();

  cout << "1 - Consultar outro local" << endl;
  cout << "2 - Voltar ao menu" << endl;

  cin >> loop;
  system("CLS");
  if(loop == 2)
    break;
  }

  system("CLS");
}


vector<Insumo*> Controler::consultaInsumos(int indice, int tipoInsumo){
  vector<Insumo*> ins;

  cout << endl << local[indice].getNome()<< endl;

  ins = local[indice].getVector(tipoInsumo-1); //getInsumo retorna um ponteiro de insumo

  return ins;
}

void Controler::distribuiInsumo(){
  Insumo* ins;
  Menu menu;
  int indice;
  int tipoIns;
  int lote;
  int quantidade;
  int loop;

  while(true){
    cout << "Digite o local que deseja distribuir: ";
    menu.exibeMenuEstados2();
    cin >> indice;
    cin.ignore();

    while(indice > 28 || indice < 0){
        cout << "Estado inválido. Digite novamente: ";
        cin >> indice;
        cin.ignore();
      }

    while(true){
      cout << "Digite o insumo a ser distribuido: " << endl;
      menu.exibeMenuInsumos();
      cin >> tipoIns;
      cin.ignore();

      while(tipoIns > 3 || tipoIns < 1){
        cout << "Insumo inválido. Digite novamente: ";
        cin >> tipoIns;
        cin.ignore();
      }

      cout << "Lotes disponíveis: " << endl;
      for(unsigned int i = 0; i < local[0].getVector(tipoIns-1).size(); i++){
        if(local[0].getLote(tipoIns-1, i)->getQuant() > 0){
          cout << "->" << i+1 << endl;
        }
      }

      cout << endl;

      while(true){
      cout << "Digite o lote: ";
      cin >> lote;
      cin.ignore();

      ins = local[0].getLote(tipoIns-1, lote-1);

      cout << "Digite a quantidade a ser distribuida(máx de " << local[0].getLote(tipoIns-1, lote-1)->getQuant() << "): ";
      cin >> quantidade;
      cin.ignore();

      while(quantidade > local[0].getLote(tipoIns-1, lote-1)->getQuant() || quantidade <= 0){
        cout << "Quantidade inválida. Digite novamente: ";
        cin >> quantidade;
        cin.ignore();
      }

      local[indice].adicionaInsumoEstado(quantidade, ins);
      local[0].retiraQuantMS(quantidade, lote-1, tipoIns-1);

      cout << endl << "Distribuido com sucesso!!" << endl << endl;

      cout << "1 - Distribuir o mesmo insumo novamente" << endl;
      cout << "2 - Distribuir outro insumo" << endl;
      cout << "3 - Distribuir para outro estado" << endl;
      cout << "4 - Voltar ao menu" << endl;

      cin >> loop;
      while(loop > 4 || loop < 1){
        cout << "Valor inválido. Digite novamente: " << endl;
        cin >> loop;
        getchar();
      }
      if(loop == 2 || loop == 3 || loop == 4)
        break;
      }
    if(loop == 3 || loop == 4)
      break;
    }
  if(loop == 4)
    break;
  }

}

void Controler::salvarInsumos(){
    Persistencia p;

    for(int i = 0; i < 28; i++){
        ofstream fp;
          for(int j = 0; j < 3; j++){
            ofstream fp;
            fp.open(local[i].getNome()+std::to_string(j), ios::out);
            if(fp.is_open()){
                p.salvarInsumos(local[i].getVector(j), fp);
            }
            fp.close();

          }
    }
}

void Controler::lerInsumos(){
    Persistencia p;
    vector<Insumo*> vet;
    ifstream fp;

    for(int i = 0; i < 28; i++){
        for(int j = 0; j < 3; j++){
            fp.open(local[i].getNome()+std::to_string(j), ios::in);
            if(fp.is_open()){
                vet = p.lerInsumos(fp, j+1);
                local[i].setVector(j, vet);
            }
            fp.close();

        }
    }

}

