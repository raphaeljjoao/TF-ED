#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LSE.h"

LSE* criaLista(){
    return NULL;
}

int tamanho(LSE *ptLista){
    if(ptLista == NULL) return 0;
    int tamanho = 0;
    while(ptLista != NULL){
        ptLista = ptLista->proximo;
        tamanho++;
    }
    return tamanho;
}

LSE* insereFim(LSE *ptLista, int num, long int *comps){
    *comps = 1;
    LSE *novo, *ptAux=ptLista;
    
    novo = (LSE*) malloc(sizeof(LSE));
    novo->numero = num;
 
    (*comps)++;
    if (ptLista == NULL){
        novo->proximo = ptLista; // = NULL
        ptLista = novo;
    } else{
        while(ptAux->proximo != NULL) {
            (*comps)++;
            ptAux = ptAux->proximo;
        }
    
    ptAux->proximo = novo;
    novo->proximo = NULL;
    }

    return ptLista;
}

LSE *consultaLSE(LSE *ptLista, int num, long int *comps) {
    *comps = 2;
    if (ptLista == NULL || ptLista->numero == num) return ptLista;

    while (ptLista != NULL) {
        (*comps)++;
        if (ptLista->numero == num) return ptLista;
        (*comps)++;
        ptLista = ptLista->proximo;
    }

    return NULL;
}

int consultaValorLSE(LSE *ptLista, int valor, int *tempo, long int *comparacoes) {
    long int comps;
    int inicio = time(NULL);
    LSE *consulta = consultaLSE(ptLista, valor, &comps);

    *tempo = time(NULL) - inicio;

    *comparacoes = comps;
    return consulta != NULL;
}

void imprime(LSE *ptLista){
    if (ptLista == NULL) printf("Lista vazia.");
    else {
        for(LSE *ptAux = ptLista; ptAux != NULL; ptAux = ptAux->proximo)
            printf(" %d | ", ptAux->numero);
    }
    printf("\n");
}

LSE* destroiLista(LSE *ptLista){
    LSE *ptAux;
    while (ptLista != NULL){
        ptAux = ptLista;
        ptLista = ptLista->proximo;
        // printf(" %d | ", ptAux->numero);
        free(ptAux);
    }
    // printf("\n");

    return NULL;
}