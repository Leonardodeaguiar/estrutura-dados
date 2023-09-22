#include <iostream>
#include "pilha_dinamica.h"
#include <cstddef>

using namespace std;

// Construtor
PilhaDinamica::PilhaDinamica()
{
    NoTopo = NULL;
}
// Destrutor
PilhaDinamica::~PilhaDinamica()
{
    No *NoTemp;
    while (NoTopo != NULL)
    {
        NoTemp = NoTopo;          // atribui o nó temporario ao do topo
        NoTopo = NoTopo->proximo; // o do topo recebe o anterior
        delete NoTemp;            // o temporario é deletado e faz continuamente
    }
}
// Verifica se está cheio
bool PilhaDinamica::estaCheio()
// verifica se falta memoria, se sim significa cheio se não retorna false
{
    No *NoNovo;
    try
    {
        NoNovo = new No;
        delete NoNovo;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}
// Verifica se está vazio
bool PilhaDinamica::estaVazio()
{
    return (NoTopo == NULL); // se não exitir um nó no topo retorna true
}
// insere item na lista
void PilhaDinamica::inserir(TipoItem item)
{
    if (estaCheio())
    {
        cout << "A pilha está cheia\n";
    }
    else
    {
        No *NoNovo = new No;      // Cria um nó novo
        NoNovo->valor = item;     // o valor do nó aponta pro item
        NoNovo->proximo = NoTopo; // o proximo do no novo recebe o topo
        NoTopo = NoNovo;          // o topo é igual ao no novo
    }
}
// remover o ultimo item da lista
TipoItem PilhaDinamica::remover()
{
    if (estaVazio())
    {
        cout << "A pilha está vazia\n";
        cout << "Não foi possivel remover o item!\n";
        return 0;
    }
    else
    {
        No *NoTemp;                    // variavel temporaria
        NoTemp = NoTopo;               // variavel temporaria recebe o item de cima
        TipoItem item = NoTopo->valor; // item recebe o valor do item no topo
        NoTopo = NoTopo->proximo;      // topo recebe o valor do proximo item
        delete NoTemp;                 // deleta o endereço de notopo guardado em temp
        return item;                   // retorna o item
    }
}
// imprime os itens da lista
void PilhaDinamica::imprimir()
{
    No *NoTemp = NoTopo;
    cout << "Pilha: [";
    while (NoTemp != NULL)
    {
        cout << NoTemp->valor << ", ";
        NoTemp = NoTemp->proximo;
    }
    cout << "]" << endl;
}