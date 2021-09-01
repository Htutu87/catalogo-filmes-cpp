//Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#define NUM_MAX_FILMES 20

struct Filme 
{
    string nome;
    string produtora;
    double nota;
};

// Declaração antecipada para que as sobrecargas globais conheçam a classe.
class Catalogo;

// ------------------------------------------------
// Sobrecarga de operadores por funções globais.


// Compara os Filmes pelo nome.
// Um Filme menor que o outro vem antes no alfabeto.
// Hipótese: Pelo que vi na internet, se eu chamar o método sort() para um
// vector<filmes>, eles serão ordenados segundo as ordens desse operador.

bool operator<(Filme, Filme);
bool operator>(Filme, Filme);
bool operator==(Filme, Filme);

// Impressão do cátalogo na tela.

ostream & operator<<(ostream &, Catalogo);
ostream & operator<<(ostream &, Filme); //OK!

// Inicialização de atributos de Filme.

istream & operator>>(istream &, Filme&); // OK!

// Comparar nota do Filme com a mais bem avaliada;

bool operator<(Filme, double);
bool operator>(Filme, double);

// ------------------------------------------------

class Catalogo 
{
    public:
        
        // Construtores e destrutores realizam a persistência dos dados.
        // Caso não exista o arquivo, ele o cria em ./data/
        Catalogo(string);

        // Adição de Filmes ao catálogo.
        // Struct do Filme deve ter seus atributos inicialiados previamente.
        // Caso seja inserido um vector de Filmes, utilizar o método insert().

        void operator+=(Filme &);
        void operator+=(vector<Filme> &);

        // Remoção de Filmes do catálogo.
        // Busca um Filme pelo nome e o remove através do método erase().

        Catalogo operator-=(Filme);

        // Busca por Filme.
        // Recebe o nome do Filme e retorna um ponteiro para sua estrutura.
        // Caso não ache, aponta para NULL.
    
        Filme * operator()(string);

        // Edição de Filme no catálogo.
        // A busca pela estrutura é feita pelo, que não pode ser alterado.
        // A edição de um Filme é feita pelas operações de remoção de inserção.
        // Existem três sobrecargas diferentes: Mudar só produtora, só nota,
        // ou ambos.
        
        Filme * operator()(string, string);
        Filme * operator()(string, double);
        Filme * operator()(string, string, double);

        // ---
        
        vector <Filme> getListaFilmes();
       
    private:

        // Implementação da persistência dos dados através de um CSV.
        void carregar(string);
        void salvar(string);

        vector <Filme> filmes;
        unsigned numMaxFilmes = NUM_MAX_FILMES;
};














