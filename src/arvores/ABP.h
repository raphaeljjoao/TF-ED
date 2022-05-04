#ifndef ABP_H_
#define ABP_H_

typedef struct NodoABP ABP;

struct NodoABP {
    int info;
    ABP *esq;
    ABP *dir;
};

void insereABP(ABP **arv, int num, int *comparacoes);
ABP* consultaABP(ABP *arv, int chave, int *comparacoes);
ABP* consultaABP2(ABP *arv, int chave);
ABP* destroiABP(ABP *arv);

// Caminhamentos
void preFixadoEABP(ABP *arv);
void preFixadoDABP(ABP *arv);
void posFixadoEABP(ABP *arv);
void posFixadoDABP(ABP *arv);
void centralEABP(ABP *arv);
void centralDABP(ABP *arv);

#endif // ABP_H_
