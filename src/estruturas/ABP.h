#ifndef ABP_H_
#define ABP_H_

typedef struct NodoABP ABP;

struct NodoABP {
    int info;
    ABP *esq;
    ABP *dir;
};

void insereABP(ABP **arv, int num, long int *comparacoes);
ABP* consultaABP(ABP *arv, int chave, long int *comparacoes);
ABP* consultaABP2(ABP *arv, int chave);
ABP* destroiABP(ABP *arv);

// Retorna se encontrou ou não o valor
int consultaValorABP(ABP *arv, int valor, int *tempo, long int *comps); 

// Caminhamentos
void preFixadoEABP(ABP *arv);
void preFixadoDABP(ABP *arv);
void posFixadoEABP(ABP *arv);
void posFixadoDABP(ABP *arv);
void centralEABP(ABP *arv);
void centralDABP(ABP *arv);

int alturaABP(ABP *arv);
int calculaFBABP(ABP *arv);
int fatorABP(ABP *arv);

#endif // ABP_H_
