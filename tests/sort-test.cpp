#include <iostream>
#include "../include/catalogo.h"

using namespace std;

int main(int argc, char* argv[])
{
    Catalogo catalogo("arquivo.txt");
    Filme f1 = {"Bastardos inglorios", "MGM", 5.0};
    Filme f2 = {"Rio", "21st Century Fox", 7.0};
    Filme f3 = {"Pulp Fiction", "MGM" , 8.3};
    Filme f4 = {"Madagascar", "DreamWorks", 7.2};
    Filme f5 = {"a", "21st Century Fox", 7.0};
    Filme f6 = {"g", "21st Century Fox", 7.0};
    Filme f7 = {"f", "21st Century Fox", 7.0};
    Filme f8 = {"d", "21st Century Fox", 7.0};
    Filme f9 = {"z", "21st Century Fox", 7.0};
    Filme f10 = {"c", "21st Century Fox", 7.0};
    Filme f11 = {"c", "21st Century Fox", 7.0};
    Filme f12 = {"b", "21st Century Fox", 7.0};

    catalogo += f1;
    catalogo += f2;
    catalogo += f3;
    catalogo += f4;
    catalogo += f5;
    catalogo += f6;
    catalogo += f7;
    catalogo += f8;
    catalogo += f9;
    catalogo += f10;
    catalogo += f11;
    catalogo += f12;
    
    cout << catalogo;

    catalogo.insertionSort();

    cout << catalogo;

    return 0;
}
