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
    if (primeiro == NULL)
    {
        No *novoNo = new No();
        novoNo->valor = item;
        novoNo->anterior = NULL;
        novoNo->proximo = NULL;
        primeiro = novoNo;
        ultimo = novoNo;
    }
    else

    {
        No *novoNo = new No();
        novoNo->valor = item;
        ultimo->proximo = novoNo;
        novoNo->anterior = ultimo;
        ultimo = novoNo;
        novoNo->proximo = NULL;
    }
}
TipoItem FilaDinamica::remover()
{
    TipoItem item;
    if (estavazio())
    {
        cout << "Lista vazia, não foi possivel excluir!";
        return 0;
    }
    else
    {
        No *NoTemp = primeiro;
        item = primeiro->valor;
        primeiro = NoTemp->proximo;
        delete NoTemp;
        return item;
    }
    cout << endl;
}

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

bool FilaDinamica::estavazio()
{
    return (primeiro == NULL);
}

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