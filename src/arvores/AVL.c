#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

AVL* insereArvore(AVL *a, int ch) {
    if (a == NULL) {
        a = (AVL*) malloc(sizeof(AVL));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
        a->fb = 0; // o nodo é sempre inserido como folha então seu fator de balanceamento é 0
    } else if (ch < (a->info))
        a->esq = insereArvore(a->esq,ch);
    else {
        a->dir = insereArvore(a->dir,ch);
        return a;
    }
}

int altura(AVL *a) {
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
        return 0;
    else {
        Alt_Esq = altura (a->esq);
        Alt_Dir = altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}

int calculaFB(AVL *a) {
    return (altura(a->esq) - altura(a->dir));
}

void desenha(AVL *a, int nivel) {
    int x;

    if (a !=NULL) {
        for (x=1; x<=nivel; x++)
            //printf("=");
            //printf("%d FB= %d\n", a->info, calculaFB(a));
            if (a->esq != NULL) desenha(a->esq, (nivel+1));
        if (a->dir != NULL) desenha(a->dir, (nivel+1));
    }
}

int isAVL(AVL *a) {
    int alt_esq, alt_dir;

    if (a!=NULL) {
        alt_esq = altura(a->esq);
        alt_dir = altura(a->dir);
        return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (isAVL(a->esq)) && (isAVL(a->dir)) );
    } else
        return 1;
}


AVL* rotacaoDireita(AVL *pt) {
    AVL* ptu;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->fb = 0;
    pt = ptu;
    return pt;
}

AVL* rotacaoEsquerda(AVL *pt) {
    AVL* ptu;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->fb = 0;
    pt = ptu;
    return pt;
}

AVL* rotacaoDuplaDireita(AVL *pt) {
    AVL* ptu, *ptv;

    ptu = pt->esq;
    ptv = ptu->dir;
    ptu->dir = ptv->esq;
    ptv->esq = ptu;
    pt->esq = ptv->dir;
    ptv->dir = pt;
    if (ptv->fb == 1)   pt->fb = -1;
    else pt->fb = 0;
    if (ptv->fb == -1)  ptu->fb = 1;
    else ptu->fb = 0;
    pt = ptv;
    return pt;
}

AVL* rotacaoDuplaEsquerda(AVL *pt) {
    AVL *ptu, *ptv;

    ptu = pt->dir;
    ptv = ptu->esq;
    ptu->esq = ptv->dir;
    ptv->dir = ptu;
    pt->dir = ptv->esq;
    ptv->esq = pt;
    if (ptv->fb == -1) pt->fb = 1;
    else pt->fb = 0;
    if (ptv->fb == 1) ptu->fb = -1;
    else ptu->fb = 0;
    pt = ptv;
    return pt;
}


AVL* caso1(AVL *a, int *ok) {
    AVL *ptu;

    ptu = a->esq;
    if (ptu->fb == 1) {
        //printf("fazendo rotacao direita em %d\n",a->info);
        a = rotacaoDireita(a);
    } else {
        //printf("fazendo rotacao dupla direita em %d\n",a->info);
        a = rotacaoDuplaDireita(a);
    }

    a->fb = 0;
    *ok = 0;
    return a;
}

AVL* caso2(AVL *a, int *ok) {
    AVL *ptu;

    ptu = a->dir;
    if (ptu->fb == -1) {
        desenha(a,1);
        //printf("fazendo rotacao esquerda em %d\n",a->info);
        a= rotacaoEsquerda(a);
    } else {
        desenha(a,1);
        //printf("fazendo rotacao dupla esquerda em %d\n",a->info);
        a=rotacaoDuplaEsquerda(a);
    }
    a->fb = 0;
    *ok = 0;
    return a;
}

AVL* insereAVL(AVL *a, int x, int *ok) {
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
      x, a chave a ser inserida e h a altura da árvore */

    if (a == NULL) {
        a = (AVL*) malloc(sizeof(AVL));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->fb = 0;
        *ok = 1;
    } else if (x < a->info) {
        a->esq = insereAVL(a->esq,x,ok);
        if (*ok) {
            switch (a->fb) {
            case -1:
                a->fb = 0;
                *ok = 0;
                break;
            case  0:
                a->fb = 1;
                break;
            case  1:
                a=caso1(a,ok);
                break;
            }
        }
    } else {
        a->dir = insereAVL(a->dir,x,ok);
        if (*ok) {
            switch (a->fb) {
            case  1:
                a->fb = 0;
                *ok = 0;
                break;
            case  0:
                a->fb = -1;
                break;
            case -1:
                a = caso2(a,ok);
                break;
            }
        }
    }
    return a;
}

AVL* destroiAVL(AVL *arv) {
    if (arv == NULL) return;

    destroiAVL(arv->esq);
    destroiAVL(arv->dir);
    free(arv);
    arv = NULL;

    return arv;
}

void preFixadoEAVL(AVL *arv) {
    if (arv != NULL) {
        printf("%d - ", arv->info);
        preFixadoEAVL(arv->esq);
        preFixadoEAVL(arv->dir);
    }
}

void preFixadoDAVL(AVL *arv) {
    if (arv != NULL) {
        printf("%d - ",arv->info);
        preFixadoDAVL(arv->dir);
        preFixadoDAVL(arv->esq);
    }
}

void posFixadoEAVL(AVL *arv) {
    if (arv != NULL) {
        posFixadoEAVL(arv->esq);
        posFixadoEAVL(arv->dir);
        printf("%d - ",arv->info);
    }
}

void posFixadoDAVL(AVL *arv) {
    if (arv != NULL) {
        posFixadoDAVL(arv->dir);
        posFixadoDAVL(arv->esq);
        printf("%d - ",arv->info);
    }
}

void centralEAVL(AVL *arv) {
    if (arv != NULL) {
        centralEAVL(arv->esq);
        printf("%d - ",arv->info);
        centralEAVL(arv->dir);
    }
}

void centralDAVL(AVL *arv) {
    if (arv != NULL) {
        centralDAVL(arv->dir);
        printf("%d - ",arv->info);
        centralDAVL(arv->esq);
    }
}
