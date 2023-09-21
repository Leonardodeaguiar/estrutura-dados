
typedef int TipoItem;
const TipoItem max_itens = 5;

class Fila
{
private:
    TipoItem tamanho;
    TipoItem *estrutura;

public:
    Fila();
    ~Fila();

    void adiciona_elemento(TipoItem elemento);

    TipoItem remover_elemento();

    void organiza_elementos();

    void imprimir();

    bool fila_cheia();

    bool fila_vazia();
};
