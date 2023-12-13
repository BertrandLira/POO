#include <iostream>
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"
#include "Controler.h"
#include "Menu.h"
#include <vector>
#include <fstream>
#include "Persistencia.h"
#include <locale.h>
//#include <windows.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "Portuguese");
  Controler ctr;
  int func, tipoIns, lugar, loop;
  Menu menu;
  vector<Insumo*> ins;
  Persistencia p;

  ctr.lerInsumos();

  while(true){
    menu.exibeMenuPrincipal();

    cin >> func;


    system("CLS");

    if(func == 4){//sai do laço de repetição
      break;
    }

    switch(func){
      case(1): //funçoes de cadastro
        menu.exibeMenuCadastro();

        cin >> func;

        while(func > 2 || func < 1){
          cout << "Valor Invalido. Digite novamente" << endl;
          cin >> func;
        }
        system("CLS");

        switch(func){

          case(1):
            ctr.cadastraInsumosMS(); //chama a função de cadastrar no MS
            break;

          case(2): //distribui insumo para os estados
            ctr.distribuiInsumo();
            break;
        } //segundo switch case

        break;

      case(2):  //funções de consulta
        menu.exibeMenuConsulta();
        cin >> func;

        while(func > 3 || func < 1){
          cout << "Valor Invalido. Digite novamente" << endl;
          cin >> func;
        }

        system("CLS");

        switch(func){
          case(1):
            ctr.consultaInsumos();
            break;

          case(2):
            ctr.consultaInsumosDescricao();
            break;

          case(3):  //consulta o insumo passado como parametro de um estado tbm passado como parametro
            while(true){
              cout << "Digite o local que deseja consultar: " << endl;

              menu.exibeMenuEstados();

              cin >> lugar;
              cin.ignore();
              system("CLS");

              while(lugar > 28 || lugar < 0){
                cout << "Local inválido. Digite novamente." << endl << endl;
                menu.exibeMenuEstados();
                cin >> lugar;
                cin.ignore();
                system("CLS");
              }

              while(true){
                cout << "Digite o insumo a ser consultado: " << endl;
                menu.exibeMenuInsumos();
                cin >> tipoIns;
                cin.ignore();
                system("CLS");


                while(tipoIns > 3 || tipoIns < 1){
                    cout << "Insumo inválido. Digite novamente." << endl << endl;
                    menu.exibeMenuInsumos();
                    cin >> tipoIns;
                    cin.ignore();
                    system("CLS");
                }


                ins = ctr.consultaInsumos(lugar, tipoIns);


                for(unsigned int i = 0; i < ins.size(); i++){
                  if(ins[i]->getQuant() > 0){
                    cout << endl << "-> Lote = " << i + 1 << endl;
                    cout << "Nome: " << ins[i]->getNome() << endl;
                    cout << "Quantidade: " << ins[i]->getQuant() << endl;
                    cout << "Valor unitário: " << ins[i]->getValor() << endl;
                    cout << "Data de validade: " << ins[i]->getDataVal() << endl;
                    cout << "Nome do Fabricante: " << ins[i]->getNomeFab() << endl;
                    ins[i]->exibeAtributos();
                    cout << endl;
                  }else{
                    cout << "Não foi cadastrado esse insumo nesse local." << endl;
                    break;
                  }
                }

                cout << "\n1 - Consultar outro insumo" << endl;
                cout << "2 - Consultar outro local" << endl;
                cout << "3 - Voltar ao menu" << endl;

                cin >> loop;

                while(loop > 3 || loop < 1){
                  cout << "Valor inválido. Digite novamente" << endl;
                  cin >> loop;
                  getchar();

                }

                system("CLS");

                if(loop == 2 || loop == 3)
                  break;
              }
              if(loop == 3)
                  break;
            }
            break;

        }//switch case das consultas
        break;

      case 3:
        ctr.salvarInsumos();
        cout << "Dados salvos" << endl;
        getchar();
        system("CLS");
        break;

      default:
        cout << endl <<  "Valor inválido. Digite novamente" << endl << endl;
        break;

    }//primeiro switch
  }//while

  return 0;
}
