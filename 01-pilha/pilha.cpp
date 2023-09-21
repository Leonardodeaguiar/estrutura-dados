// pilha obedece a ordem lifo: last in, first out
// significa que o ultimo item posto se torna o primeiro a sair
#include <iostream>
#include "pilha.h"

using namespace std;

typedef int TipoItem;

// contrutor
Pilha::Pilha()
{
    tamanho = 0;
    estrutura = new TipoItem(max_itens);
}

// destructor
Pilha::~Pilha()
{
    delete[] estrutura;
}

// verifica se a pilha está cheia
bool Pilha::estaCheia()
{
    return (tamanho == max_itens);
}

// verifica se a pilha está vazia
bool Pilha::estaVazia()
{
    return (tamanho == 0);
}

// insere um item na lista
void Pilha::inserir(TipoItem item)
{
    if (estaCheia())
    {
        cout << "A pilha está cheia!";
    }
    else
    {
        estrutura[tamanho] = item;
        tamanho++;
    }
} // push

// remove o item de cima
TipoItem Pilha::remover()
{
    if (estaVazia())
    {
        cout << "A pilha está vazia!";
        return 0;
    }
    else
    {
        tamanho--;
        return estrutura[tamanho];
    }
} // pop()

// imprime
void Pilha::imprimir()
{
    cout << "pilha: [";
    for (int i = 0; i < tamanho; i++)
    {
        cout << estrutura[i] << ", ";
    }
    cout << "] \n";
}

// tamanho
TipoItem Pilha::tamanho_pilha()
{
    return this->tamanho;
}
