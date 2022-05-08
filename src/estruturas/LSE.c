#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

ptLSE* criaLista(){
    return NULL;
}

int tamanho(ptLSE *ptLista){
    if(ptLista == NULL) return 0;
    int tamanho = 0;
    while(ptLista != NULL){
        ptLista = ptLista->proximo;
        tamanho++;
    }
    return tamanho;
}

ptLSE* insereInicio(ptLSE *ptLista, int num){
    ptLSE *novo;
    novo = (ptLSE*) malloc(sizeof(ptLSE));

    novo->numero = num;
    novo->proximo = ptLista;
    ptLista = novo;

    return ptLista;
}

ptLSE* insereMeio(ptLSE *ptLista, int num){
    ptLSE *novo, *ptAux=ptLista;
    
    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero = num;
 
    if (ptLista == NULL){
        novo->proximo = ptLista; // = NULL
        ptLista = novo;
    } else{
        ptLSE *anterior;
        int pontoInsercao = tamanho(ptLista) / 2; // Divisão inteira
        for(int i = 0; i < pontoInsercao; i++){
            anterior = ptAux;
            ptAux = ptAux->proximo;
        }
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    return ptLista;
}

ptLSE* insereFim(ptLSE *ptLista, int num){
    ptLSE *novo, *ptAux=ptLista;
    
    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero = num;
 
    if (ptLista == NULL){
        novo->proximo = ptLista; // = NULL
        ptLista = novo;
    } else{
        while(ptAux->proximo != NULL) ptAux = ptAux->proximo;
    
    ptAux->proximo = novo;
    novo->proximo = NULL;
    }

    return ptLista;
}

void imprime(ptLSE *ptLista){
    if (ptLista == NULL) printf("Lista vazia.");
    else {
        for(ptLSE *ptAux = ptLista; ptAux != NULL; ptAux = ptAux->proximo)
            printf(" %d | ", ptAux->numero);
    }
    printf("\n");
}

ptLSE* destroi(ptLSE *ptLista){
    ptLSE *ptAux;
    while (ptLista != NULL){
        ptAux = ptLista;
        ptLista = ptLista->proximo;
        // printf(" %d | ", ptAux->numero);
        free(ptAux);
    }
    // printf("\n");

    return NULL;
}