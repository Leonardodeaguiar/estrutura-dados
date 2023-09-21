// pilha (stack) obedece a ordem lifo: last in, first out
// significa que o ultimo item posto se torna o primeiro a sair

typedef int TipoItem;
const TipoItem max_itens = 100;

class Pilha
{
private:
    int tamanho;
    int *estrutura;

public:
    // contrutor
    Pilha();
    // destructor
    ~Pilha();
    // verifica se a pilha está cheia
    bool estaCheia();
    // verifica se a pilha está vazia
    bool estaVazia();
    // insere um item na lista
    void inserir(TipoItem item); // push
    // remove o item de cima
    TipoItem remover(); // pop()
    // imprime
    void imprimir();
    // tamanho
    TipoItem tamanho_pilha();
};