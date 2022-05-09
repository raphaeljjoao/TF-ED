#include <stdio.h>
#include "src/options.h"
#include "src/analises/ordenada_ABP.h"
#include "src/analises/ordenada_LSE.h"


int main(){
    printf("(INF01203) Estruturas de Dados - Trabalho Final 2021/2\n\n");

    printf("ABP Ordenada\n");
    // analiseOrdenadaABP(TIER_4 * 1);

    int nDados;
    printf("Quantos dados voce deseja inserir: ");
    scanf("%d", &nDados);
    printf("Inserindo %d dados.\n\n", nDados);
    printf("LSE Ordenada\n");
    analiseOrdenadaLSE(nDados);

    return 0;
}

