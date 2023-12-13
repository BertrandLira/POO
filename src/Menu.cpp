#include "Menu.h"

using namespace std;

Menu::Menu(){

}

void Menu::exibeMenu(){
  cout << "----------------------------- Menu -----------------------------\n" << endl;
}

void Menu::exibeMenuPrincipal(){ //menu que leva para os outros menus(cadastro ou contulta)
  exibeMenu();
  cout << "Digite o �ndice correspondente � a��o a ser realizada:\n" << endl;
  cout << "1 - Cadastrar/distribuir insumos" << endl;
  cout << "2 - Consultar estoques" << endl;
  cout << "3 - Salvar" << endl;
  cout << "4 - Sair" << endl << endl;
  cout << "----------------------------------------------------------------\n";
 }

void Menu::exibeMenuCadastro(){ //menu dos cadastros
  exibeMenu();
  cout << "1 - Cadastrar novos insumos" << endl;
  cout << "2 - Distribuir insumos para um estado" << endl << endl;
  cout << "----------------------------------------------------------------\n";
}

void Menu::exibeMenuConsulta(){ //menu das consultas
  exibeMenu();
  cout << "1 - Consultar os insumos dispon�veis" << endl;
  cout << "2 - Consultar a descri��o dos insumos dispon�veis" << endl;
  cout << "3 - Consultar os insumos dispon�veis por tipo espec�fico" << endl << endl;
  cout << "----------------------------------------------------------------\n";
}

void Menu::exibeMenuInsumos(){ //menu que exibe os insumos
  cout << "1 - Vacina" << endl;
  cout << "2 - Medicamento" << endl;
  cout << "3 - EPI\n" << endl << endl;
}

void Menu::exibeMenuEstados(){ //menu que exibe os estados
  string locais[28] = {"0 - Minist�rio da Sa�de (MS)", "1 - Acre (AC)", "2 - Alagoas (AL)" , "3 - Amap� (AP)", "4 - Amazonas (AM)", "5 - Bahia (BA)" , "6 - Cear� (CE)" , "7 - Distrito Federal (DF)",  "8 - Esp�rito Santo (ES)" , "9 - Goi�s (GO)", "10 - Maranh�o (MA)",  "11 - Mato Grosso (MT)",  "12 - Mato Grosso do Sul (MS)", "13 - Minas Gerais (MG)", "14 - Par� (PA)", "15 - Para�ba (PB)", "16 - Paran� (PR)", "17 - Pernambuco (PE)", "18 - Piau� (PI)" , "19 - Rio de Janeiro (RJ)", "20 - Rio Grande do Norte (RN)", "21 - Rio Grande do Sul (RS)" ,  "22 - Rond�nia (RO)" ,  "23 - Roraima (RR)" ,  "24 - Santa Catarina (SC)",  "25 - S�o Paulo (SP)" ,  "26 - Sergipe (SE)" ,  "27 - Tocantins (TO)" };
  cout << endl << "Digite o �ndice do estado:" << endl;

  int z = 0;
  for(int i = 0; i < 28; i++){
    cout << locais[i];
    for(int j = 31 - locais[i].length(); j >= 0; j--)
      cout << " ";
    z++;
    if(z == 3){
      z = 0;
      cout << endl;
    }
  }

  cout << endl;

}

void Menu::exibeMenuEstados2(){ //menu que exibe os estados
  string locais[28] = {"0 - Minist�rio da Sa�de (MS)", "1 - Acre (AC)", "2 - Alagoas (AL)" , "3 - Amap� (AP)", "4 - Amazonas (AM)", "5 - Bahia (BA)" , "6 - Cear� (CE)" , "7 - Distrito Federal (DF)",  "8 - Esp�rito Santo (ES)" , "9 - Goi�s (GO)", "10 - Maranh�o (MA)",  "11 - Mato Grosso (MT)",  "12 - Mato Grosso do Sul (MS)", "13 - Minas Gerais (MG)", "14 - Par� (PA)", "15 - Para�ba (PB)", "16 - Paran� (PR)", "17 - Pernambuco (PE)", "18 - Piau� (PI)" , "19 - Rio de Janeiro (RJ)", "20 - Rio Grande do Norte (RN)", "21 - Rio Grande do Sul (RS)" ,  "22 - Rond�nia (RO)" ,  "23 - Roraima (RR)" ,  "24 - Santa Catarina (SC)",  "25 - S�o Paulo (SP)" ,  "26 - Sergipe (SE)" ,  "27 - Tocantins (TO)" };
  cout << endl << "Digite o �ndice do estado:" << endl;

  int z = 0;
  for(int i = 1; i < 28; i++){
    cout << locais[i];
    for(int j = 31 - locais[i].length(); j >= 0; j--)
      cout << " ";
    z++;
    if(z == 3){
      z = 0;
      cout << endl;
    }
  }

  cout << endl;
}
