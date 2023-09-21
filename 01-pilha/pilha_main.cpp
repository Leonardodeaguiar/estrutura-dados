#include <iostream>
#include "pilha.h"

using namespace std;

int main()
{
    Pilha pilha;
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

        if (opcao == 1)
        {
            cout << "Digite um numero: ";
            cin >> item;
            pilha.inserir(item);
        }
        else if (opcao == 2)
        {
            item = pilha.remover();
            cout << "Elemento removido: " << item << endl;
        }
        else if (opcao == 3)
        {
            pilha.imprimir();
        }
        else if (opcao == 4)
        {
            pilha.estaCheia();
        }
        else if (opcao == 5)
        {
            pilha.estaVazia();
        }
        else if (opcao == 6)
        {
            system("cls");
        }
        else
        {
            cout << "Opção inexistente!";
        }

    } while (opcao != 0);

    return 0;
}