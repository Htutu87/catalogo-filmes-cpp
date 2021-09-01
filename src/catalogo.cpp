// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/catalogo.h"

// Impressão de filmes e catálogo
ostream & operator<<(ostream & _cout, Filme _filme)
{
    _cout << "---\nFilme:" << endl;
    _cout << "\tNome: " << _filme.nome << endl; 
    _cout << "\tProdutora: " << _filme.produtora << endl; 
    _cout << "\tNota: " << _filme.nota << endl; 
    _cout << "---" << endl;

    return _cout;
}

ostream & operator<<(ostream & _cout, Catalogo _catalogo)
{
    cout << "----------------- CATALOGO DE FILMES ----------------" << endl;
    cout <<  setw(25) << "Filme" << setw(25) << "Produtora" << setw(25) 
        << "Nota" << endl << endl;

    for (Filme filme:_catalogo.getListaFilmes())
    {
        cout << setw(25) << filme.nome << setw(25) << filme.produtora
            << setw(25) << filme.nota << endl;
    }

    cout << "-----------------------------------------------------" << endl;

    return _cout;
}


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
    while (_filme.nota < 0.0 || _filme.nota > 10.0)
    {
        cout << "Apenas notas entre 0.0 e 10.0 sao permitidas." << endl;
        cout << "Insira a nota novamente: ";
        getline(_cin, notaStr);
        _filme.nota = stod(notaStr);
    }  
    cout << "\nFilme inicializado com sucesso." << endl;
    cout << "---" << endl;
    
    return _cin;
}

// Operações para comparar filmes.

// Métodos da classe catálogo.
Catalogo::Catalogo(string nomeArquivo)
{
    string a = nomeArquivo;
}

void Catalogo::operator+=(Filme & _filme)
{
    filmes.push_back(_filme);
    // c += _filme;
    // Precisa mesmo retornar o ponteiro para o objeto?
    // Checar se a struct não está inicializada.
}

void Catalogo::operator+=(vector<Filme> & _filmes)
{
    for (Filme filme:_filmes)
        filmes.push_back(filme);
}

vector <Filme> Catalogo::getListaFilmes(){
    return filmes;
}
