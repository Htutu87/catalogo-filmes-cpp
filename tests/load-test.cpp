
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

    string novaProdutora;
    string novaNota;
    Filme* fPtr;

    cout << "Alterar filme por nome: ";
    getline(cin, op);
    fPtr = catalogo(op);
    if(fPtr == NULL) cout << "Este filme nao existe no catalogo." << endl;
    else cout << *fPtr;
    
    cout << "Nova Produtora: ";
    getline(cin, novaProdutora);
    cout << "Nova nota: ";
    getline(cin, novaNota);
    
    
    fPtr = catalogo(op, novaProdutora, stod(novaNota));
    if(fPtr == NULL) cout << "Este filme nao existe no catalogo." << endl;
    else cout << *fPtr;
    return 0;
}
