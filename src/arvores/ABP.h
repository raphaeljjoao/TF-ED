typedef struct NodoABP ABP;

struct NodoABP {
    int info;
    ABP *esq;
    ABP *dir;
};

ABP* insereABP(ABP *arv, int num);
ABP* consultaABP(ABP *arv, int chave);
ABP* consultaABP2(ABP *arv, int chave);
ABP* destroiABP(ABP *arv);

// Caminhamentos
void preFixadoEABP(ABP *arv);
void preFixadoDABP(ABP *arv);
void posFixadoEABP(ABP *arv);
void posFixadoDABP(ABP *arv);
void centralEABP(ABP *arv);
void centralDABP(ABP *arv);





