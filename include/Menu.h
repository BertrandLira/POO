#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <iostream>
#include <string>


class Menu
{
    public:
        Menu();

        static void exibeMenu();
        static void exibeMenuPrincipal();
        static void exibeMenuCadastro();
        static void exibeMenuConsulta();
        static void exibeMenuInsumos();
        static void exibeMenuEstados();
        static void exibeMenuEstados2();
};

#endif // MENU_H
