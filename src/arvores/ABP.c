#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

ABP* insereABP(ABP *arv, int num) {
    if (arv == NULL) {
        arv =  (ABP*) malloc(sizeof(ABP));
        arv->info = num;
        arv->esq = NULL;
        arv->dir = NULL;
        return arv;
    } else if (num < arv->info) arv->esq = insereABP(arv->esq, num);
    else if (num > arv->info) arv->dir = insereABP(arv->dir, num);

    return arv;
}

void preFixadoEABP(ABP *arv) {
    if (arv != NULL) {
        printf("%d - ", arv->info);
        preFixadoEABP(arv->esq);
        preFixadoEABP(arv->dir);
    }
}

void preFixadoDABP(ABP *arv) {
    if (arv != NULL) {
        printf("%d - ",arv->info);
        preFixadoDABP(arv->dir);
        preFixadoDABP(arv->esq);
    }
}

void posFixadoEABP(ABP *arv) {
    if (arv != NULL) {
        posFixadoEABP(arv->esq);
        posFixadoEABP(arv->dir);
        printf("%d - ",arv->info);
    }
}

void posFixadoDABP(ABP *arv) {
    if (arv != NULL) {
        posFixadoDABP(arv->dir);
        posFixadoDABP(arv->esq);
        printf("%d - ",arv->info);
    }
}

void centralEABP(ABP *arv) {
    if (arv != NULL) {
        centralEABP(arv->esq);
        printf("%d - ",arv->info);
        centralEABP(arv->dir);
    }
}

void centralDABP(ABP *arv) {
    if (arv != NULL) {
        centralDABP(arv->dir);
        printf("%d - ",arv->info);
        centralDABP(arv->esq);
    }
}

ABP* consultaABP(ABP *arv, int chave) {

    while (arv != NULL) {
        if (arv->info == chave) return arv; //achou entao retorna o ponteiro para o nodo
        else if (arv->info > chave) arv = arv->esq;
        else arv = arv->dir;
    }

    return NULL; //se nao achou
}

ABP* consultaABP2(ABP *arv, int chave) {
    if (arv != NULL) {
        if (arv->info == chave) return arv;
        else if (arv->info > chave) return consultaABP2(arv->esq,chave);
        if (arv->info < chave) return consultaABP2(arv->dir,chave);
        else return arv;
    } else return NULL;
}

// Código: https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf
ABP* destroiABP(ABP *arv) {
    if (!destroiABP(arv)) {
        destroiABP(arv->esq);
        destroiABP(arv->dir);
        free(arv);
    }

    return NULL;
}