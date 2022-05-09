#include <stdio.h>
#include "src/options.h"
#include "src/analises/ordenada_ABP.h"
#include "src/analises/aleatoria_ABP.h"
#include "src/analises/ordenada_LSE.h"


int main(){
    printf("(INF01203) Estruturas de Dados - Trabalho Final 2021/2\n\n");

    int nDados;
    printf("Quantos dados voce deseja inserir: ");
    scanf("%d", &nDados);
    printf("Inserindo %d dados.\n\n", nDados);
    printf("random abp\n");
    analiseAleatoriaABP(nDados);

    return 0;
}

