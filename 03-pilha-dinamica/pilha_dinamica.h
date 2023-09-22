typedef int TipoItem;

struct No
{
    TipoItem valor;
    No *proximo;
};

class PilhaDinamica
{
private:
    No *NoTopo;

public:
    PilhaDinamica();             // Construtor
    ~PilhaDinamica();            // Destrutor
    bool estaCheio();            // Verifica se está cheio
    bool estaVazio();            // Verifica se está vazio
    void inserir(TipoItem item); // insere item na lista
    TipoItem remover();          // remover o ultimo item da lista
    void imprimir();             // imprime o item da lista
};