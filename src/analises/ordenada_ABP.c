#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../arvores/ABP.h"
#include "../utils.h"
#include "../stats.h"
#include "../options.h"
#include "ordenada_ABP.h"

ABP* insereOrdenadoABP(int quantidade) {
    ABP *arv = (ABP*) malloc(sizeof(ABP));
    arv = NULL;

    for (int i = 1; i <= quantidade; i++) {
        arv = insereABP(arv, i);
        if (i % (quantidade / 15) == 0 && !SILENT)
            printf("(ABP) %d/%d dados inseridos.\n", i, quantidade);
    }

    return arv;
}

void analiseOrdenadaABP(int quantidade) {
    ABP *arv;
    int ini = time(NULL);
    arv = insereOrdenadoABP(quantidade);
    int fim = time(NULL);
    int decorridoInsere = fim - ini;

    int temposConsulta[3];
    int decorrido;
    int consultaInicio = 1;
    int consultaMeio = quantidade / 2;
    int consultaFim = quantidade;

    // Consulta no início
    ini = time(NULL);
    ABP *consulta1 = consultaABP(arv, consultaInicio);
    printf("Valor encontrado: %d\n", consulta1->info);
    fim = time(NULL);
    decorrido = fim - ini;
    temposConsulta[0] = (consulta1 != NULL) ? decorrido : -1;

    // Consulta no meio
    ini = time(NULL);
    ABP *consulta2 = consultaABP(arv, consultaMeio);
    printf("Valor encontrado: %d\n", consulta2->info);
    fim = time(NULL);
    decorrido = fim - ini;
    temposConsulta[1] = (consulta2 != NULL) ? decorrido : -1;

    // Consulta no fim
    ini = time(NULL);
    ABP *consulta3 = consultaABP(arv, consultaFim);
    printf("Valor encontrado: %d\n", consulta3->info);
    fim = time(NULL);
    decorrido = fim - ini;
    temposConsulta[2] = (consulta3 != NULL) ? decorrido : -1;

    printf("Tempos de consulta: %d, %d e %d\n", temposConsulta[0], temposConsulta[1], temposConsulta[2]);
    printf("%d dados foram inseridos em %s\n", quantidade, tempoEscrito(decorridoInsere));
    printf("Altura da arvore: %d\n", alturaABP(arv));

    arv = destroiABP(arv);
}
