// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/catalogo.h"

///////////////////////////////////////////////////////////////////////
//
// Função auxiliar que implementei para tratar exceções da função stod().

double recebeStringDevolveDouble()
{
    double d;
    string s;
    bool stringValida = false;
    while (!stringValida)
    {
        getline(cin, s);
        try 
        {
            d = stod(s);
            stringValida = true;
        }
        catch (invalid_argument const& ) 
        {
            cout << "Essa entrada nao pode ser convertida em um numero." << endl
                << "Tente novamente: ";
        }
    }

    return d;
}

//////////////////////////////////////////////////////////////
// 
// Impressão de filmes e catálogo
//
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
    cout <<  setw(25) << "Filme" << setw(25) << "Produtora" << setw(15) 
        << "Nota" << endl << endl;

    for (Filme filme:_catalogo.getListaFilmes())
    {
        cout << setw(25) << filme.nome << setw(25) << filme.produtora
            << setw(15) << filme.nota << endl;
    }

    cout << "-----------------------------------------------------" << endl;

    return _cout;
}

//////////////////////////////////////////////////////////////
//
// Inicialização de filme.
//
istream & operator>>(istream & _cin, Filme& _filme)
{
    string notaStr;
    cout << "---" << endl;
    cout << "Insira o nome do filme: ";
    getline(_cin,  _filme.nome);
    cout << "Insira o nome da produtora: ";
    getline(_cin, _filme.produtora);
    cout << "Insira a nota do filme: ";
    _filme.nota = recebeStringDevolveDouble();
    while (_filme.nota < 0.0 || _filme.nota > 10.0)
    {
        cout << "Apenas notas entre 0.0 e 10.0 sao permitidas." << endl;
        cout << "Insira a nota novamente: ";
        _filme.nota = recebeStringDevolveDouble();
    }  
    cout << "\nFilme inicializado com sucesso." << endl;
    cout << "---" << endl;
    
    return _cin;
}

//////////////////////////////////////////////////////////////
//
// Operações para comparar filmes.
//
//
bool operator<(Filme _f1, Filme _f2)
{
    string menorNome;
    string maiorNome;
    unsigned long indice = 0;

    if (_f1.nome == _f2.nome)
        return false;

    if (_f1.nome.size() >= _f2.nome.size())
    { 
        menorNome = _f2.nome;
        maiorNome = _f1.nome;
    } 
    else
    {
        menorNome = _f1.nome;
        maiorNome = _f2.nome;
    }

    while (indice < menorNome.size())
    {

        if (_f1.nome[indice] < _f2.nome[indice])
            return true;

        if (_f1.nome[indice] > _f2.nome[indice])
            return false;

        indice++;
    } 
    // Sair do loop significa que a comparação entre os caracteres deu
    // igual até o momento. A desambiguação final é a diferença de tamanhos,
    // ou seja, o menor nome é retornado como anterior na ordem alfabética.
    // P.e.: "Ana" < "Ana Beatriz" --> True.

    if (_f1.nome == menorNome)
        return true;
    return false; 
}

bool operator>(Filme _f1, Filme _f2)
{
    string menorNome;
    string maiorNome;
    unsigned long indice = 0;

    if (_f1.nome == _f2.nome)
        return false;

    if (_f1.nome.size() >= _f2.nome.size())
    { 
        menorNome = _f2.nome;
        maiorNome = _f1.nome;
    } 
    else
    {
        menorNome = _f1.nome;
        maiorNome = _f2.nome;
    }

    while (indice < menorNome.size())
    {
        if (_f1.nome[indice] > _f2.nome[indice])
            return true;

        if (_f1.nome[indice] < _f2.nome[indice])
            return false;

        indice++;
    } 

    if (_f1.nome == maiorNome)
        return true;
    return false; 
}

bool operator==(Filme _f1, Filme _f2)
{
    return (_f1.nome == _f2.nome) ? true : false;

}

bool operator<(Filme _f, double nota) {
    return (_f.nota < nota) ? true : false;
}

bool operator>(Filme _f, double nota){
    return (_f.nota > nota) ? true : false;
}
//////////////////////////////////////////////////////////////
//
// Métodos da classe catálogo.
//
Catalogo::Catalogo(bool inicializarVazio, string _nomeArquivo)
{
    if (!inicializarVazio)
    {
        carregar(_nomeArquivo);
        nomeArquivo = _nomeArquivo;
    }
}

Catalogo::~Catalogo() {
    salvar(nomeArquivo);
}

void Catalogo::operator+=(Filme & _filme) {
    if (filmes.size() >= 20 )
        cout << "O catalogo ja possui o numero maximo de filmes permitido." << endl;
    else {
        filmes.push_back(_filme);
        insertionSort();
    }
}

void Catalogo::operator+=(vector<Filme> & _filmes)
{
    for (Filme filme:_filmes)
        filmes.push_back(filme);
    insertionSort();
}

void Catalogo::operator-=(Filme _filme)
{
    int indice = 0;
    bool acheiFilme = false;
    for (Filme filme:filmes)
    {

        if (filme == _filme)
        {
            filmes.erase(filmes.begin() + indice);
            acheiFilme = true;
        }
        indice++;
    }
    if (!acheiFilme)
        cout << "Este filme nao existe no catalogo. Impossivel remove-lo." << endl; 
}

Filme * Catalogo::operator()(string _nome)
{ 
    for (Filme & filme:filmes)
        if (filme.nome == _nome)
            return &filme; // retorna o endereço da referencia para o filme em quest.
    return NULL;
}

Filme * Catalogo::operator()(string nome, string novaProdutora)
{
    Filme * filmeAlterado;

    filmeAlterado = (*this)(nome); 
    if (!filmeAlterado)
        return NULL;
    
    (*filmeAlterado).produtora = novaProdutora;
    return filmeAlterado;
}

Filme * Catalogo::operator()(string nome, double novaNota)
{
    Filme * filmeAlterado;

    filmeAlterado = (*this)(nome);
    if (!filmeAlterado)
        return NULL;
    
    (*filmeAlterado).nota = novaNota;
    return filmeAlterado;
}

Filme * Catalogo::operator()(string nome, string novaProdutora, double novaNota)
{
    Filme * filmeAlterado;

    filmeAlterado = (*this)(nome);
    if (!filmeAlterado)
        return NULL;
    
    (*filmeAlterado).produtora = novaProdutora;
    (*filmeAlterado).nota = novaNota;
    return filmeAlterado;
}


vector <Filme> Catalogo::getListaFilmes(){
    return filmes;
}

// Créditos: Esta função foi adaptada da Wikipedia, por simplicidade.
void Catalogo::insertionSort()
{
    for (int i = 1; i < static_cast<int>(filmes.size()); i++) 
    {
        Filme escolhido = filmes[i];
        int j = i - 1;
    
        while ((j >= 0) && (filmes[j] > escolhido))
        {
            filmes[j + 1] = filmes[j];
            j--;
        }

        filmes[j + 1] = escolhido;
    }
}

void Catalogo::carregar(string nomeArquivo)
{
    ifstream arquivo;
    string linhaArquivo;
    string nome;
    string produtora;
    string notaStr;
    double nota;
    bool lerArquivo = true;
    int numLinhas=0;

    arquivo.open(nomeArquivo);

    if(!arquivo) {
        cout << "Impedido de abrir arquivo." << endl;
        return ;
    } else if (arquivo.fail()){
        cout << "Arquivo especificado nao existe." << endl;
        return ;
    }

    
    while (lerArquivo)
    {

        getline(arquivo, linhaArquivo);
    
        if (arquivo.eof())
            lerArquivo = false;
        else 
        {    
            nome = linhaArquivo.substr(0, linhaArquivo.find(','));
            
            linhaArquivo = linhaArquivo.erase(0,linhaArquivo.find(',')
                    + 1/*COMPRIMENTO DO DELIMITADOR*/);
            
            produtora = linhaArquivo.substr(0, linhaArquivo.find(','));
            
            notaStr = linhaArquivo.substr(linhaArquivo.find(',')+1,
                                         linhaArquivo.find('\n'));
            nota = stod(notaStr);

            Filme f = {nome, produtora, nota};
            (*this) += f;
            numLinhas++;
            if (numLinhas == 20)
            {
                lerArquivo = false;
                cout << "O catalogo lido possui mais que o limite maximo de filmes "                        << "permitido (" << numMaxFilmes << ")." << endl;
                cout << "Truncando catalogo." << endl;
            }
        }
    }
    
    insertionSort();
    
    arquivo.close();

}

void Catalogo::salvar(string nomeArquivo)
{
    // Fiz essa modificação para deixar o catálogo padrão intacto e facilitar
    // os testes.
    if (nomeArquivo == "catalogo-padrao.txt")
        nomeArquivo = "catalogo-padrao-editado.txt";

    ofstream arquivo;
    arquivo.open (nomeArquivo);
    for (Filme f:filmes)
        arquivo << f.nome << "," << f.produtora << "," << f.nota << endl;
    arquivo.close();
}

bool Catalogo::verificarExistenciaDoFilme(Filme f)
{
    for (Filme filme:filmes)
        if (filme.nome == f.nome)
            return true;
    return false;
    
}
