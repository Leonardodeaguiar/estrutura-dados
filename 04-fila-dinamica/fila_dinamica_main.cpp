#include <iostream>
#include "fila_dinamica.h"

using namespace std;

int main()
{
    TipoItem opcao, item;
    FilaDinamica fila;
    do
    {
        cout << "Digite 0 para fechar o programa" << endl;
        cout << "Digite 1 para adicionar um item" << endl;
        cout << "Digite 2 para remover um item" << endl;
        cout << "Digite 3 para imprimir a fila" << endl;
        cout << "opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite um numero inteiro para a fila: ";
            cin >> item;
            fila.inserir(item);
            break;
        case 2:
            cout << fila.remover();
            break;
        case 3:
            fila.imprimir();
            break;
        default:
            cout << "opcao invalida !";
            break;
        }

    } while (opcao != 0);
    return 0;
}