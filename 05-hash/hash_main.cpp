#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
    int tamanho_vetor, max_elementos;
    cout << "gerador de hash \n";
    cout << "digite o tamanho da hash: ";
    cin >> tamanho_vetor;

    cout << "\ndigite o numero máximo de elementos: ";
    cin >> max_elementos;

    cout << "\n o fator de carga é " << (float)max_elementos / (float)tamanho_vetor << endl;

    Hash alunoHash(tamanho_vetor, max_elementos);
    int opcao, ra;
    string nome;
    bool busca;

    do
    {
        cout << "Digite 0 para parar o programa" << endl;
        cout << "Digite 1 para inserir um elemento" << endl;
        cout << "Digite 2 para remover um elemento" << endl;
        cout << "Digite 3 para buscar um elemento" << endl;
        cout << "Digite 4 para imprimir a Hash" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {

            cout << "Digite o RA do aluno: " << endl;
            cin >> ra;

            cout << "Digite o nome do aluno: " << endl;
            cin >> nome;

            alunoHash.inserir(Aluno(ra, nome));
        }
        else if (opcao == 2)
        {

            cout << "Digite o RA do aluno: " << endl;
            cin >> ra;

            alunoHash.remover(Aluno(ra, " "));
        }
        else if (opcao == 3)
        {
            cout << "Digite o RA do aluno: " << endl;
            cin >> ra;
            Aluno aluno(ra, " ");
            alunoHash.buscar(aluno, busca);
            if (busca)
            {
                cout << "Aluno encontrado: " << endl;
                cout << "RA: " << aluno.getRa() << endl;
                cout << "Nome: " << aluno.getNome() << endl;
            }
            else
            {
                cout << "Aluno não encontrado!";
            }
        }
        else if (opcao == 4)
        {
            alunoHash.imprimir();
        }
    } while (opcao != 0);

    return 0;
}