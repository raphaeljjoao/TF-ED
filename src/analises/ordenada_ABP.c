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

    int aviso = quantidade / 25;

    int tempoInicio = time(NULL);

    for (int i = 1; i <= quantidade; i++) {
        insereABP(&arv, i);
        if (i % aviso == 0 && !SILENT) {
            int deltaTempo = time(NULL) - tempoInicio;
            printf("ABP: %d/%d dados inseridos em %d segundos.\n", i, quantidade, deltaTempo);
        }
    }

    return arv;
}

void analiseOrdenadaABP(int quantidade) {
    ABP *arv;
    int ini = time(NULL);
    arv = insereOrdenadoABP(quantidade);
    int decorridoInsere = time(NULL) - ini;

    consultaOrdenadaABP(arv, quantidade);

    printf("%d dados foram inseridos em %s\n", quantidade, tempoEscrito(decorridoInsere));
    printf("Altura da arvore: %d\n", alturaABP(arv));

    arv = destroiABP(arv);
}

void consultaOrdenadaABP(ABP *arv, int quantidade) {
    int temposConsulta[3];
    int consultaInicio = 1;
    int consultaMeio = quantidade /2;
    int consultaFim = quantidade;

    int sucessoConsulta;
    // Consulta no início
    sucessoConsulta = consultaValor(arv, consultaInicio, &temposConsulta[0]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaInicio);
    else printf("Valor %d nao encontrado na arvore.\n", consultaInicio);

    // Consulta no meio
    sucessoConsulta = consultaValor(arv, consultaMeio, &temposConsulta[1]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaMeio);
    else printf("Valor %d nao encontrado na arvore.\n", consultaMeio);

    // Consulta no fim
    sucessoConsulta = consultaValor(arv, consultaFim, &temposConsulta[2]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaFim);
    else printf("Valor %d nao encontrado na arvore.\n", consultaFim);

    printf("Tempos de consulta: %d, %d e %d\n", temposConsulta[0], temposConsulta[1], temposConsulta[2]);
}

int consultaValor(ABP *arv, int valor, int *tempo) {
    int inicio = time(NULL);
    ABP *consulta = consultaABP(arv, valor);
    int fim = time(NULL);

    if (consulta != NULL) *tempo = fim - inicio;
    else *tempo = -1;

    return consulta != NULL;
}
