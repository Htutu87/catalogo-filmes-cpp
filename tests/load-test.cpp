
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

    while (op == "s"){
        cin >> f; 
        catalogo += f;
        cout << catalogo;
        cout << "Inserir filme? [s/n]: ";
        getline(cin, op);
    }

    return 0;
}
