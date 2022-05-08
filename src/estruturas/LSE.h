typedef struct tipoNo ptLSE;
struct tipoNo{
    int numero;
    ptLSE *proximo;
};

// Cria uma lista vazia
ptLSE* criaLista();

// Calcula a quantidade de elementos de uma lista
int tamanho(ptLSE *ptLista);

// Insere no início da lista
ptLSE* insereInicio(ptLSE *ptLista, int num);

// Insere no meio da lista
ptLSE* insereMeio(ptLSE *ptLista, int num);

// Insere no final da lista
ptLSE* insereFim(ptLSE *ptLista, int num);

// Imprime todos os itens da lista de forma sequencial
void imprime(ptLSE *ptLista);

// Destrói uma lista
ptLSE* destroi(ptLSE *ptLista);