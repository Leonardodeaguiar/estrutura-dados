typedef int TipoItem;

struct No
{
    No *proximo, *anterior;

    TipoItem valor;
};

class FilaDinamica
{
private:
    No *primeiro, *ultimo;

public:
    FilaDinamica();
    ~FilaDinamica();
    void primeiroItem();
    void ultimoItem();
    void inserir(TipoItem item);
    TipoItem remover();
    bool estaCheio();
    bool estavazio();
    void imprimir();
};