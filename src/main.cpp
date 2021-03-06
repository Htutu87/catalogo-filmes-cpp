// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 03
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/catalogo.h"

#define DEFAULT_STRING "A"

///////////////////////////////////////////////////////////////////////
//
// Funcionalidades do menu //

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

void pressEnter(){
    string aux;
    cout << "Aperte [ENTER] para prosseguir. "<< endl;
    getline(cin, aux);
}

///////////////////////////////////////////////////////////////////////
//
// Função principal //

int main()
{
    // Strings que o progrma utiliza //
    string opString;
    string aux;
    string nomeArquivo = "./data/catalogo-padrao.txt";
    string novaProdutora;
    string novaNota;
    
    // Variáveis booleanas, para controle de fluxo do código //
    bool executarPrograma = true;
    bool inicializarVazio;
    bool filmeExiste;
    bool auxBool;
    
    // Variáveis numéricas //
    long unsigned i = 0;
    double maiorNota;
    double opDouble;
    
    // Variáveis relativas a Filmes, que armazenam temporariamente informações
    // sobre eles. "Dummy variables".
    Filme f;
    Filme * fPtr;


//////////////////////////////////////////////////////////////////////
//
// Interação inicial  -> Pergunta para o usuário qual catálogo ele  //
// gostaria de inicializar no programa                              //

    cout << endl << "CATALOGO DE FILMES INTERATIVO" << endl << endl;
    cout << "Deseja inicializar um catalogo vazio? [s/n]: ";
    getline(cin, opString);

    if (opString == "s" || opString == "S")
    {
        inicializarVazio = true;
        cout << "--> Catalogo vazio inicializado." << endl;
    }
    else
    { 
        inicializarVazio = false;
    
        cout << "Inicializar catalogo padrao? [s/n]: ";
        getline(cin, opString);
    
        if (opString == "s" || opString == "S")
        {
            nomeArquivo = "./data/catalogo-padrao.txt";
            cout << "--> Catalogo padrao inicializado." << endl;
            cout << "Nome do arquivo: " << nomeArquivo << endl;
        }
        else
        {
            cout << "Insira o CAMINHO RELATIVO ao arquivo com o catalogo a " 
                << "ser inicializado: ";
            getline(cin, nomeArquivo);

            // Breve verificação da existência do arquivo passado.
            // Caso não existe, inicializa um catálogo vazio.
            ifstream arquivo(nomeArquivo);

            if (arquivo.fail())
            {
                cout << "--> Este arquivo nao existe. Inicializando catalogo vazio."
                    << endl;
                inicializarVazio = true;
                arquivo.close();
            } 
            else 
            {
                cout << "--> Inicializando catalogo." << endl;
                cout << "Nome do arquivo: " << nomeArquivo << endl;
            }
        }
    }

    // Inicialização do catálogo -> Vazio ou a partir de arquivo CSV escolhido
    // pelo usuário.
    //
    Catalogo catalogo(inicializarVazio, nomeArquivo);

    pressEnter();

    // LoopString principal do programa
    //
    while (executarPrograma) 
    {
        printaMenu();
        cout << "Escolha uma opcao: ";
        opDouble = recebeStringDevolveDouble();

        switch(static_cast<int>(opDouble))
        {
            case 1:

                // Só printa o catálogo caso ele não seja vazio.
                if (catalogo.getListaFilmes().size() != 0)
                    cout << catalogo;
                else
                    cout << "---\nCatalogo Vazio, nao ha nada para mostrar.\n---"
                        << endl;
                break;
            
            case 2:

                cin >> f;
                filmeExiste = false;

                // Percorre lista de filmes do catálogo. Só adiciona o filme caso
                // ele não exista
                //
                if (catalogo.getListaFilmes().size() != 0)
                    while (!filmeExiste)
                    {
                        if  (f == catalogo.getListaFilmes()[i])
                            filmeExiste = true;
                        
                        // Se o indice é igual ao tamanho do catálogo,    
                        // quebra o loopString.
                        //
                        if (i == catalogo.getListaFilmes().size() - 1) 
                            break;
                        
                        i++;
                    }

                if (!filmeExiste) 
                    catalogo += f;
                
                else
                    cout << "Nao eh possivel adicionar outro filme" 
                        << "com esse nome." << endl;
                break;

            case 3:
                
                cout << "Insira o nome do filme a ser removido: ";
                getline (cin, opString);
                
                // O ponteiro "dummy" recebe o endereço do filme a ser removido.
                //
                fPtr = catalogo(opString);
                
                // Se o endereço recebido não for nulo (i.e., filme existe), ele
                // é removido através do opStringerador -=.
                //
                if (fPtr != NULL)
                    catalogo -= (*fPtr);
                else
                    cout << "-> Este filme nao existe no catalogo." << endl;
                break;

            case 4:

                cout << "Insira o nome do filme para ver seus dados: ";
                getline (cin, opString);
                
                fPtr = catalogo(opString);
                
                if (fPtr != NULL)
                    cout << *fPtr;
                else
                    cout << "-> Este filme nao existe no catalogo." << endl;
                break;

            case 5:

                Filme * auxPtr;

                cout << "Insira o nome do filme para edita-lo: ";
                getline (cin, aux);

                auxPtr = catalogo(aux);
                
                if (auxPtr != NULL)
                {
                    // Isto é, é válido editar o filme.
                    
                    cout << "Filme a ser removido: "<< endl; 
                    cout << *auxPtr << endl;
                
                    cout << "Editar: \n\t[0] Produtora\n\t[1] Nota\n\t[2] Ambos\n\n";
                    cout << "Digite sua escolha:" ;
                    getline (cin, opString);
                    
                    if (opString != "0" && opString != "1" && opString != "2" )
                    {
                        cout << "Opcao invalida. Tente novamente." << endl;
                    }
                    else
                    {
                        if (opString == "0")
                        {
                            cout << "Insira a nova produtora: ";
                            getline(cin, novaProdutora);

                            fPtr = catalogo(aux, novaProdutora);
                            
                        }
                        else if (opString == "1")
                        {
                            cout << "Insira a nova nota: ";
                            auxBool = true;
                            while (auxBool){
                                opDouble = recebeStringDevolveDouble();
                                if (opDouble > 0.0 && opDouble < 10.0)
                                    auxBool = false;
                                else
                                    cout << "Insira uma nota entre 0 e 10." << endl;
                            }

                            fPtr = catalogo(aux, opDouble);
                        }
                        else if (opString == "2")
                        {
                            cout << "Insira a nova produtora: ";
                            getline(cin, novaProdutora);
                            
                            cout << "Insira a nova nota: ";
                            
                            auxBool = true;
                            while (auxBool){
                                opDouble = recebeStringDevolveDouble();
                                if (opDouble > 0.0 && opDouble < 10.0)
                                    auxBool = false;
                                else
                                    cout << "Insira uma nota entre 0 e 10." << endl;
                            }

                            fPtr = catalogo(aux, novaProdutora, opDouble);

                        }
                    
                        catalogo += *fPtr;
                        catalogo -= *auxPtr;         
                        
                    }
                                    
                }
                else 
                {
                    cout << "-> Este filme nao existe no catalogo." << endl; 
                } 
                
                break;
           
            case 6:
                
                // Breve algoritmo de obter o máximo dentro deuma lista
                //
                
                if (catalogo.getListaFilmes().size() != 0)
                {
                    maiorNota = 0;
                    for (Filme filme:catalogo.getListaFilmes())
                        if (filme > maiorNota)
                        {
                            f = filme;
                            maiorNota = f.nota;
                        }
                    cout << "Filme mais bem avaliado:" << endl;
                    cout <<  f;
                }
                else
                    cout << "---\nCatalogo Vazio, nao ha nada para mostrar.\n---"
                        << endl;
                break;

            case 0:
           
                executarPrograma = false;
                break;
           
            default:
           
                cout << "Operacao invalida, tente novamente." << endl;
                break;
        }
        
        if(executarPrograma)
            pressEnter();
    }

    return 0;
}
