#ifndef LSE_H_

#define LSE_H_

typedef struct tipoNo LSE;
struct tipoNo{
    int numero;
    LSE *proximo;
};

// Cria uma lista vazia
LSE* criaLista();

// Calcula a quantidade de elementos de uma lista
int tamanho(LSE *ptLista);

// Insere no final da lista
LSE* insereFim(LSE *ptLista, int num, long int *comps);

// Consulta um nó da lista e retorna ele (retorna NULL se não encontrar)
LSE* consultaLSE(LSE *ptLista, int num, long int *comps);

// Retorna se encontrou ou não o valor
int consultaValorLSE(LSE *ptLista, int valor, int *tempo, long int *comparacoes); 

// Imprime todos os itens da lista de forma sequencial
void imprime(LSE *ptLista);

// Destrói uma lista
LSE* destroiLista(LSE *ptLista);

#endif // LSE_H_