#include "Menu.h"

using namespace std;

Menu::Menu(){

}

void Menu::exibeMenu(){
  cout << "----------------------------- Menu -----------------------------\n" << endl;
}

void Menu::exibeMenuPrincipal(){ //menu que leva para os outros menus(cadastro ou contulta)
  exibeMenu();
  cout << "Digite o índice correspondente à ação a ser realizada:\n" << endl;
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
  cout << "1 - Consultar os insumos disponíveis" << endl;
  cout << "2 - Consultar a descrição dos insumos disponíveis" << endl;
  cout << "3 - Consultar os insumos disponíveis por tipo específico" << endl << endl;
  cout << "----------------------------------------------------------------\n";
}

void Menu::exibeMenuInsumos(){ //menu que exibe os insumos
  cout << "1 - Vacina" << endl;
  cout << "2 - Medicamento" << endl;
  cout << "3 - EPI\n" << endl << endl;
}

void Menu::exibeMenuEstados(){ //menu que exibe os estados
  string locais[28] = {"0 - Ministério da Saúde (MS)", "1 - Acre (AC)", "2 - Alagoas (AL)" , "3 - Amapá (AP)", "4 - Amazonas (AM)", "5 - Bahia (BA)" , "6 - Ceará (CE)" , "7 - Distrito Federal (DF)",  "8 - Espírito Santo (ES)" , "9 - Goiás (GO)", "10 - Maranhão (MA)",  "11 - Mato Grosso (MT)",  "12 - Mato Grosso do Sul (MS)", "13 - Minas Gerais (MG)", "14 - Pará (PA)", "15 - Paraíba (PB)", "16 - Paraná (PR)", "17 - Pernambuco (PE)", "18 - Piauí (PI)" , "19 - Rio de Janeiro (RJ)", "20 - Rio Grande do Norte (RN)", "21 - Rio Grande do Sul (RS)" ,  "22 - Rondônia (RO)" ,  "23 - Roraima (RR)" ,  "24 - Santa Catarina (SC)",  "25 - São Paulo (SP)" ,  "26 - Sergipe (SE)" ,  "27 - Tocantins (TO)" };
  cout << endl << "Digite o índice do estado:" << endl;

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
  string locais[28] = {"0 - Ministério da Saúde (MS)", "1 - Acre (AC)", "2 - Alagoas (AL)" , "3 - Amapá (AP)", "4 - Amazonas (AM)", "5 - Bahia (BA)" , "6 - Ceará (CE)" , "7 - Distrito Federal (DF)",  "8 - Espírito Santo (ES)" , "9 - Goiás (GO)", "10 - Maranhão (MA)",  "11 - Mato Grosso (MT)",  "12 - Mato Grosso do Sul (MS)", "13 - Minas Gerais (MG)", "14 - Pará (PA)", "15 - Paraíba (PB)", "16 - Paraná (PR)", "17 - Pernambuco (PE)", "18 - Piauí (PI)" , "19 - Rio de Janeiro (RJ)", "20 - Rio Grande do Norte (RN)", "21 - Rio Grande do Sul (RS)" ,  "22 - Rondônia (RO)" ,  "23 - Roraima (RR)" ,  "24 - Santa Catarina (SC)",  "25 - São Paulo (SP)" ,  "26 - Sergipe (SE)" ,  "27 - Tocantins (TO)" };
  cout << endl << "Digite o índice do estado:" << endl;

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
