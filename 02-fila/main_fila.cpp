#include <iostream>
#include "fila.h"

using namespace std;

int main()
{
    TipoItem opcao, item;
    Fila fila;
    do
    {
        cout << "Digite 0 para fechar o programa" << endl;
        cout << "Digite 1 para adicionar um item" << endl;
        cout << "Digite 2 para remover um item" << endl;
        cout << "Digite 3 para imprimir a fila" << endl;
        cout << "opção: ";
        cin >> opcao;

        if (opcao == 0)
        {
            break;
        }
        else if (opcao == 1)
        {
            cout << "Digite um numero inteiro para a fila: ";
            cin >> item;
            fila.adiciona_elemento(item);
        }
        else if (opcao == 2)
        {
            cout << fila.remover_elemento();
            fila.organiza_elementos();
        }
        else if (opcao == 3)
        {
            fila.imprimir();
        }
        else
        {
            cout << "opcao invalida !";
        }

    } while (opcao != 0);
    return 0;
}