#ifndef AVL_H_
#define AVL_H_

typedef struct NodoAVL AVL;

struct NodoAVL {
    int info;
    int fb;
    AVL *esq;
    AVL *dir;
};

AVL* insereArvore(AVL *a, int ch);
int altura(AVL *a);
int calculaFB(AVL *a);
void desenha(AVL *a , int nivel);
int isAVL(AVL *a);
AVL* rotacaoDireita(AVL *pt);
AVL* rotacaoEsquerda(AVL *pt);
AVL* rotacaoDuplaDireita(AVL *pt);
AVL* rotacaoDuplaEsquerda(AVL *pt);
AVL* caso1(AVL *a , int *ok);
AVL* caso2(AVL *a , int *ok);
AVL* insereAVL(AVL *a, int x, int *ok);

AVL* destroiAVL(AVL *arv);

// Caminhamentos

void preFixadoEAVL(AVL *arv);
void preFixadoDAVL(AVL *arv);
void posFixadoEAVL(AVL *arv);
void posFixadoDAVL(AVL *arv);
void centralEAVL(AVL *arv);
void centralDAVL(AVL *arv);

#endif // AVL_H_
