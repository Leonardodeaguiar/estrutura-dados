#include <iostream>
#include "fila_dinamica.h"
#include <cstddef>

using namespace std;

FilaDinamica::FilaDinamica()
{
    primeiro = NULL;
    ultimo = NULL;
}
FilaDinamica::~FilaDinamica()
{
    No *NoTemp;
    while (primeiro != NULL)
    {
        NoTemp = primeiro;            // atribui o nó temporario ao do topo
        primeiro = primeiro->proximo; // o do topo recebe o anterior
        delete NoTemp;                // o temporario é deletado e faz continuamente
    }
}
void FilaDinamica::inserir(TipoItem item)
{
    if (primeiro == NULL) // se não existir o primeiro nó
    {
        No *novoNo = new No();   // cria um novo nó
        novoNo->valor = item;    // adiciona o valor de item ao novo nó
        novoNo->anterior = NULL; // diz que o anterior é nulo
        novoNo->proximo = NULL;  // diz que o proximo é nulo
        primeiro = novoNo;       // seta o primeiro como o novo nó
        ultimo = novoNo;         // seta o ultimo também como o novo nó
    }
    else

    {
        No *novoNo = new No();     // cria um novo nó
        novoNo->valor = item;      // adiciona o valor de item ao novo nó
        ultimo->proximo = novoNo;  // diz que o proximo do ultimo é o novo nó
        novoNo->anterior = ultimo; // diz que o nó anterior do novo nó é o atual ultimo
        ultimo = novoNo;           // seta o ultimo nó como o novo nó
        novoNo->proximo = NULL;    // diz que o proximo nó é nulo afinal este é o ultimo
    }
}
TipoItem FilaDinamica::remover()
{
    TipoItem item;
    if (estavazio()) // não achou o novo nó
    {
        cout << "Lista vazia, não foi possivel excluir!";
        return 0;
    }
    else
    {
        No *NoTemp = primeiro;      // nó temporario recebe o primeiro
        item = primeiro->valor;     // o item recebe o valor do primeiro pra exibir
        primeiro = NoTemp->proximo; // o primeiro recebe o proximo da fila
        delete NoTemp;              // deleta a referencia do antigo primeiro nó
        return item;                // retorna o valor do item
    }
    cout << endl;
}

// retorna bad aloc se a memoria estiver cheia
bool FilaDinamica::estaCheio()
{
    No *novoNo;
    try
    {
        novoNo = new No;
        delete novoNo;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// se não existir um primeiro retorna true
bool FilaDinamica::estavazio()
{
    return (primeiro == NULL);
}

// imprime os itens da fila com a funcao proximo
void FilaDinamica::imprimir()
{
    No *NoTemp = primeiro;
    cout << "Fila: [";
    while (NoTemp != NULL)
    {
        cout << NoTemp->valor << ", ";
        NoTemp = NoTemp->proximo;
    }
    cout << "]" << endl;
}