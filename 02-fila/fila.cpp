/*
    Implementação da estrutura de dados fila em C++
*/

#include <iostream>
#include "fila.h"

using namespace std;

// Type definition
typedef int TipoItem;

// Contrutor da fila
// inicia com tamanho 0 e max_itens em 5 por padrão
Fila::Fila()
{
    estrutura = new TipoItem(max_itens);
    tamanho = 0;
}

// Destrutor
Fila::~Fila()
{
    delete[] estrutura;
}

// Adiciona um elemento do tipo inteiro a fila
// e checa se está cheia antes
void Fila::adiciona_elemento(TipoItem elemento)
{
    if (fila_cheia())
    {
        cout << "A fila está cheia!\n";
    }
    else
    {

        estrutura[tamanho] = elemento;
        tamanho++;
    }
}
// Remove um elemento do tipo inteiro a fila
// e checa se está vazia antes
TipoItem Fila::remover_elemento()
{
    if (fila_vazia())
    {
        cout << "Não existem elementos na fila!\n";
        return 0;
    }
    tamanho--;
    return estrutura[0];
}

// Organiza os elementos na fila
void Fila::organiza_elementos()
{
    for (int i = 0; i < tamanho; i++)
    {
        estrutura[i] = estrutura[i + 1];
    }
}

// Imprime os elementos na fila
void Fila::imprimir()
{
    cout << "Fila: [";
    for (int i = 0; i < tamanho; i++)
    {
        cout << estrutura[i] << ", ";
    }
    cout << "] \n";
}

// Verifica se a fila está cheia
bool Fila::fila_cheia()
{
    return (tamanho == max_itens) ? true : false;
}

// Verifica se a fila está vazia
bool Fila::fila_vazia()
{
    return (tamanho == 0) ? true : false;
}