#include "aluno.h"

class Hash
{
private:
    int funcaoHash(Aluno aluno);
    int max_itens, max_pos, quant_itens;
    Aluno *estrutura;

public:
    Hash(int tamanho_vetor, int max);
    ~Hash();
    bool estaCheio();
    int tamanhoAtual();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno &aluno, bool &busca);
    void imprimir();
};