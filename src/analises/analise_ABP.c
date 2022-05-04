#include <stdio.h>
#include <time.h>
#include "../arvores/ABP.h"
#include "analise_ABP.h"

int consultaValorABP(ABP *arv, int valor, int *tempo, int *comparacoes) {
    int comps;
    int inicio = time(NULL);
    ABP *consulta = consultaABP(arv, valor, &comps);
    int fim = time(NULL);

    if (consulta != NULL) *tempo = fim - inicio;
    else *tempo = -1;

    *comparacoes = comps;
    printf("!!! // Encontrei o valor %d com %d comps\n\n", consulta->info, *comparacoes);
    return consulta != NULL;
}