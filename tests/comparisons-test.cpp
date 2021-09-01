
#include <iostream>
#include "../include/catalogo.h"

using namespace std;

int main(int argc, char* argv[])
{
    Catalogo catalogo("arquivo.txt");

//    Filme f1 = {argv[1], "MGM", 5.3};
//    Filme f2 = {argv[2], "DreamWorks", 7.3};
/*
    Filme fx = {argv[1], "a", 1};
    Filme fy = {argv[2], "a", 1};

    bool a = fx < fy;

    cout << "Resultado:" << a << endl;
    cout << (fx < fy) << endl;*/
//
    Filme f1 = {"Bastardos inglorios", "MGM", 5.0};
    Filme f2 = {"Rio", "21st Century Fox", 7.0};
    Filme f3 = {"Pulp Fiction", "MGM" , 8.3};
    Filme f4 = {"Madagascar", "DreamWorks", 7.2};

    catalogo += f1;
    catalogo += f2;
    catalogo += f3;
    catalogo += f4;


    cout << "TESTE: OPERADOR >" << endl;
    for (Filme _f1:catalogo.getListaFilmes())
        for (Filme _f2:catalogo.getListaFilmes())
            cout << setw(25) << _f1.nome << " > " << setw(25) << _f2.nome
                << " : " << setw(4) <<(_f1 > _f2) << endl; 
    
    for (int i = 0; i < 64; i++){cout << "-";} cout << endl;

    cout << "TESTE: OPERADOR <" << endl;
    for (Filme _f1:catalogo.getListaFilmes())
        for (Filme _f2:catalogo.getListaFilmes())
            cout << setw(25) << _f1.nome << " < " << setw(25) << _f2.nome
                << " : " << setw(4) <<(_f1 < _f2) << endl; 

    for (int i = 0; i < 64; i++){cout << "-";} cout << endl;


    cout << "TESTE: OPERADOR ==" << endl;
    for (Filme _f1:catalogo.getListaFilmes())
        for (Filme _f2:catalogo.getListaFilmes())
            cout << setw(25) << _f1.nome << " == " << setw(25) << _f2.nome
                << " : " << setw(4) <<(_f1 == _f2) << endl; 
  
/*  Testando comparação entre Filme e double.
    cout << ( f1 > 7.0 );
    cout << ( f2 > 7.0 );
    cout << ( f3 > 7.0 );
    cout << ( f4 > 7.0 ) << endl;

    cout << ( f1 < 7.0 );
    cout << ( f2 < 7.0 );
    cout << ( f3 < 7.0 );
    cout << ( f4 < 7.0 ) << endl;
*/


    return 0;
}
