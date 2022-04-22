#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int iguaisABP(ABP *arv1, ABP *arv2) {
    if (arv1 == NULL && arv2 == NULL) return 1;
            else if (arv1 != NULL && arv2 != NULL)
                return (arv1->info == arv2->info &&
                        iguaisABP(arv1->esq, arv2->esq)&&
                        iguaisABP(arv1->dir, arv2->dir));
                else return 0;
}

int alturaABP(ABP *arv) {
    int altEsq, altDir;
    if (arv == NULL) return 0;
    else {
        altEsq = alturaABP(arv->esq);
        altDir = alturaABP(arv->dir);
        if (altEsq > altDir) return (1 + altEsq);
        else return (1 + altDir);
    }
}

int calculaFBABP(ABP *arv) {
    return (alturaABP(arv->esq) - alturaABP(arv->dir));
}

int consultaFBABP(ABP *arv, int chave) {
    if (arv == NULL) {
        printf("Chave %d não encontrada na árvore.\n", chave);
        return 404;
    }

    if (arv->info == chave) return calculaFBABP(arv);
    else {
        if (arv->info > chave) return consultaFBABP(arv->esq, chave);
        if (arv->info < chave) return consultaFBABP(arv->dir, chave);
        else return calculaFBABP(arv);
    }
}

int eAVLABP(ABP *arv) {
    int altEsq, altDir;
    if (arv == NULL) return 1;
    else {
        altEsq = alturaABP(arv->esq);
        altDir = alturaABP(arv->dir);
        return (
                   (altEsq - altDir < 2) &&
                   (altDir - altEsq < 2) &&
                   eAVLABP(arv->esq) &&
                   eAVLABP(arv->dir)
               );
    }
}

int fatorABP(ABP *arv) {
    int fator = abs(calculaFBABP(arv));
    int fatorEsq = abs(calculaFBABP(arv->esq));
    int fatorDir = abs(calculaFBABP(arv->dir));

    if (fator > fatorEsq && fator > fatorDir) return fator;
    else if (fatorEsq > fator && fatorEsq > fatorDir) return fatorEsq;
    else if (fatorDir > fator && fatorDir > fatorEsq) return fatorDir;

    return -1; // Erro
}
