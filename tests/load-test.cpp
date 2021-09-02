
#include <iostream>
#include "../include/catalogo.h"

using namespace std;

int main(int argc, char* argv[])
{
    string nomeArquivo = "../data/catalogo.txt";
    Catalogo catalogo(nomeArquivo);
    Filme f;
    string op;

    cout << catalogo;
   
    cout << "Inserir filme? [s/n]: ";
    getline(cin, op);

    Filme removido;

    while (op == "s"){
        cin >> f; 
        catalogo += f;
        cout << catalogo;
        cout << "Inserir filme? [s/n]: ";
        getline(cin, op);
    }

    cout << catalogo;
    
    catalogo -= f ;

    cout << catalogo;

    return 0;
}
