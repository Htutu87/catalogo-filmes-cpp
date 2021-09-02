// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/catalogo.h"

#define DEFAULT_STRING "A"

void printaMenu()
{ 
    cout << "-------------------------------------------- "<< endl;
    cout << "\t[ MENU ] "<< endl << endl;
    cout << "Operacoes disponiveis:" << endl << endl;
    cout << "[1] Exibir catalogo" << endl;
    cout << "[2] Inserir filme(s)" << endl;
    cout << "[3] Remover filme" << endl;
    cout << "[4] Consultar dados de filme" << endl;
    cout << "[5] Editar dados de filme" << endl;
    cout << "[6] Exibir filme mais bem avaliado" << endl << endl;
    cout << "[0] Sair"<< endl << endl;
}


int main()
{
    string op;
    string aux;
    string nomeArquivo = "./data/catalogo-padrao.txt";
    bool executarPrograma = true;
    bool inicializarVazio;
    bool filmeExiste;
    int i = 0;
    double maiorNota;
    string novaProdutora;
    string novaNota;
    Filme f;
    Filme * fPtr;

    cout << endl << "CATALOGO DE FILMES INTERATIVO" << endl << endl;

    cout << "Deseja inicializar um catalogo vazio? [s/n]: ";
    getline(cin, op);
    if (op == "s" || op == "S")
        inicializarVazio = true;
    else
    {
        inicializarVazio = false;
        cout << "Inicializar catalogo padrao? [s/n]: ";
        getline(cin, op);
        if (op == "s" || op == "S")
        {
            nomeArquivo = "./data/catalogo-padrao.txt";
        }
        else
        {
            cout << "Insira o nome do arquivo com o catalogo a ser inicializado: ";
            getline(cin, nomeArquivo);
        }
        cout << "Inicializando catalogo." << endl;
        cout << "Nome do arquivo: " << nomeArquivo << endl;
    }
    Catalogo catalogo(inicializarVazio, nomeArquivo);

    while (executarPrograma) 
    {
        printaMenu();
        cout << "Escolha uma opcao: ";
        getline(cin, op);

        switch(stoi(op))
        {
            case 1:
                cout << catalogo;
                break;
            case 2:
                cin >> f;
                while(!filmeExiste)
                {
                    if (f == catalogo.getListaFilmes()[i])
                        filmeExiste = true;
                    i++;
                }
                if (!filmeExiste) 
                    catalogo += f;
                else
                    cout << "Nao eh possivel adicionar outro filme com esse nome." << endl;
                break;
            case 3:
                // Está dando seg fault //
                cout << "Insira o nome do filme a ser removido: ";
                getline (cin, op);
                fPtr = catalogo(op);
                if (fPtr != NULL)
                    catalogo -= (*fPtr);
                else
                    cout << "-> Este filme nao existe no catalogo." << endl;
                break;
            case 4:
                cout << "Insira o nome do filme para ver seus dados: ";
                getline (cin, op);
                fPtr = catalogo(op);
                if (fPtr != NULL)
                    cout << *fPtr;
                else
                    cout << "-> Este filme nao existe no catalogo." << endl;
                break;
            case 5:
                cout << "Insira o nome do filme para edita-lo: ";
                fPtr = catalogo(aux);
                getline (cin, aux);
                if (fPtr != NULL)
                {
                    catalogo -= (*fPtr);
                    cout << "Editar: \n\t[0] Produtora\n\t[1] Nota\n\t[2] Ambos\n\n";
                    cout << "Digite sua escolha:" ;
                    getline (cin, op);
                    if (op == "0")
                    {   
                        cout << "Insira a nova produtora: ";
                        getline(cin, novaProdutora);
                        catalogo((*fPtr).nome, novaProdutora);
                    }
                    else if (op == "1")
                    {
                        cout << "Insira a nova nota: ";
                        getline(cin, novaNota);
                        catalogo((*fPtr).nome, stod(novaNota));
                    }
                    else if (op == "2")
                    {
                        cout << "Insira a nova produtora: ";
                        getline(cin, novaProdutora);
                        cout << "Insira a nova nota: ";
                        getline(cin, novaNota);
                        catalogo( (*fPtr).nome, novaProdutora, stod(novaNota));
                    }
                    else
                    {
                        cout << "Opcao invalida. Tente novamente." << endl;
                    }
                }
                else
                    cout << "-> Este filme nao existe no catalogo." << endl;
                break;
            case 6:
                maiorNota = 0;
                for (Filme filme:catalogo.getListaFilmes())
                    if (filme > maiorNota)
                    {
                        f = filme;
                        maiorNota = f.nota;
                    }
                cout << "Filme mais bem avaliado:" << endl;
                cout <<  f;
                break;
            case 0:
                cout << "A" << endl;
                executarPrograma = false;
                break;
            default:
                cout << "Operacao invalida, tente novamente." << endl;
                break;
        }
        if(executarPrograma)
        {
            cout << "Aperte [ENTER] para prosseguir. "<< endl;
            getline(cin, op);
        }
    }

    return 0;
}
