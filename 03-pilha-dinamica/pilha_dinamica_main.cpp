/*
    pilha dinamica
    pilha com listas encadeadas fazendo uso de ponteiros.
*/

#include <iostream>
#include "pilha_dinamica.h"

using namespace std;

int main()
{
    PilhaDinamica pilha;
    TipoItem item;

    int opcao;
    cout << "programa gerador de pilhas";
    do
    {
        cout << "Digite 0 para encerrar o programa!\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para imprimir a pilha\n";
        cout << "Digite 4 para saber se a pilha está vazia\n";
        cout << "Digite 5 para saber se a pilha está cheia\n";
        cout << "Digite 6 para limpar a tela\n";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite um numero: ";
            cin >> item;
            pilha.inserir(item);
            break;
        case 2:
            item = pilha.remover();
            cout << "Elemento removido: " << item << endl;
            break;
        case 3:
            pilha.imprimir();
            break;
        case 4:
            pilha.estaCheio();
            break;
        case 5:
            pilha.estaVazio();
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Opção inexistente!";
            break;
        }

    } while (opcao != 0);

    return 0;
}