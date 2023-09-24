#include "hash.h"
using namespace std;

// Cria o hash fazendo uso de modulo do ra por maximo de posicoes
int Hash::funcaoHash(Aluno aluno)
{
    return aluno.getRa() % max_pos;
}

// Cria a tabela hash que será usada
Hash::Hash(int tamanho_vetor, int max)
{
    quant_itens = 0;                      // quantidade dos itens
    max_itens = tamanho_vetor;            // tamanho do vetor
    max_pos = max;                        // maximo de posicoes
    estrutura = new Aluno[tamanho_vetor]; // vetor de alunos
}
// destrutor
Hash::~Hash()
{
    delete[] estrutura;
}

// retona true se quanti_itens for igual a max_itens
bool Hash::estaCheio()
{
    return (quant_itens == max_itens);
}

// retorna o tamanho atual da hash
int Hash::tamanhoAtual()
{
    return quant_itens;
}

// insere um aluno novo na lista
void Hash::inserir(Aluno aluno)
{
    int local = funcaoHash(aluno); // faz o hash do aluno
    estrutura[local] = aluno;      // atribui aluno a um espaço no vetor
    quant_itens++;                 // aumenta a quantidade de itens
}
// remove um aluno da lista
void Hash::remover(Aluno aluno)
{
    int local = funcaoHash(aluno);      // faz o hash do aluno
    if (estrutura[local].getRa() != -1) // verifica se é diferente de -1
    {
        estrutura[local] = Aluno(-1, " "); // seta como -1 a localidade caso já não seja
        quant_itens--;                     // reduz o numero de itens
    }
}

// procura um item na lista de alunos
void Hash::buscar(Aluno &aluno, bool &busca)
{
    int local = funcaoHash(aluno);                 // faz o hash do aluno
    Aluno aux = estrutura[local];                  // cria um auxiliar do aluno
    if (aluno.getRa() != estrutura[local].getRa()) // verifica se o ra do aluno é diferente o da estrutura
    {
        busca = false; // seta busca como false caso não de match
    }
    else
    {
        busca = true; // se der match busca recebe true
        aluno = aux;  // aluno recebe o auxiliar
    }
}

// imprime os alunos na hash
void Hash::imprimir()
{
    for (int i = 0; i < max_pos; i++)
    {
        if (estrutura[i].getRa() != -1)
        {
            cout << i << ":" << estrutura[i].getRa() << "\n"
                 << estrutura[i].getNome() << endl;
        }
    }
}
