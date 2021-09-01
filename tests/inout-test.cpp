
#include <iostream>
#include "../include/catalogo.h"

using namespace std;

int main(int argc, char* argv[])
{
    Catalogo catalogo("Arquivo");
    Filme f;

    vector<Filme> vetorFilmes;
    
    int i =0;
    while (i < 4)
    { 
        cin >> f;
        cout << f;
        vetorFilmes.push_back(f);
        i++;
    }
    catalogo += vetorFilmes;
    cout << catalogo;


    return 0;
}
