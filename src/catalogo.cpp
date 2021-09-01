// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/catalogo.h"

// Inicialização de filme.
istream & operator>>(istream & _cin, Filme& _filme)
{
    string notaStr;
    cout << "---" << endl;
    cout << "Insira o nome do filme: ";
    getline(_cin,  _filme.nome);
    cout << "Insira o nome da produtora: ";
    getline(_cin, _filme.produtora);
    cout << "Insira a nota do filme: ";
    getline(_cin, notaStr);
    _filme.nota = stod(notaStr);  
    cout << "\nFilme inicializado com sucesso." << endl;
    cout << "---" << endl;
    
    return _cin;
}

// Métodos da classe catálogo.
Catalogo::Catalogo(string nomeArquivo)
{
    string a = nomeArquivo;
}
