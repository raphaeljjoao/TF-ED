#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../estruturas/ABP.h"
#include "../stats.h"
#include "../options.h"
#include "ordenada_ABP.h"

ABP* insereOrdenadoABP(int quantidade, int *comparacoes) {
    ABP *arv = (ABP*) malloc(sizeof(ABP));
    arv = NULL;

    int aviso = quantidade / 25;

    int tempoInicio = time(NULL);

    int comparacoesTotal = 0;

    for (int i = 1; i <= quantidade; i++) {
        int compTemp;
        insereABP(&arv, i, &compTemp);
        comparacoesTotal += compTemp;
        if (CSVMODE) printf("inseridos,tempo");
        if (i % aviso == 0 && !SILENT) {
            int deltaTempo = time(NULL) - tempoInicio;
            if (CSVMODE) printf("%d,%d\n", i, deltaTempo);
            else printf("ABP: %d/%d dados inseridos em %d segundos.\n", i, quantidade, deltaTempo);
        }
    }

    *comparacoes = comparacoesTotal;
    return arv;
}

void analiseOrdenadaABP(int quantidade) {
    ABP *arv;
    int comparacoes;
    int ini = time(NULL);
    arv = insereOrdenadoABP(quantidade, &comparacoes);
    int decorridoInsere = time(NULL) - ini;

    consultaOrdenadaABP(arv, quantidade);

    printf("%d dados foram inseridos em %s\n", quantidade, tempoEscrito(decorridoInsere));
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Altura da arvore: %d\n", alturaABP(arv));

    arv = destroiABP(arv);
}

int consultaValorABP(ABP *arv, int valor, int *tempo, int *comparacoes) {
    int comps;
    int inicio = time(NULL);
    ABP *consulta = consultaABP(arv, valor, &comps);
    int fim = time(NULL);

    if (consulta != NULL) *tempo = fim - inicio;
    else *tempo = -1;

    *comparacoes = comps;
    return consulta != NULL;
}

void consultaOrdenadaABP(ABP *arv, int quantidade) {
    int temposConsulta[3];
    int comparacoes[3];
    int consultaInicio = 1;
    int consultaMeio = quantidade /2;
    int consultaFim = quantidade;

    int sucessoConsulta;
    // Consulta no início
    sucessoConsulta = consultaValorABP(arv, consultaInicio, &temposConsulta[0], &comparacoes[0]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaInicio);
    else printf("Valor %d nao encontrado na arvore.\n", consultaInicio);

    // Consulta no meio
    sucessoConsulta = consultaValorABP(arv, consultaMeio, &temposConsulta[1], &comparacoes[1]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaMeio);
    else printf("Valor %d nao encontrado na arvore.\n", consultaMeio);

    // Consulta no fim
    sucessoConsulta = consultaValorABP(arv, consultaFim, &temposConsulta[2], &comparacoes[2]);
    if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", consultaFim);
    else printf("Valor %d nao encontrado na arvore.\n", consultaFim);

    printf("Comparações: %d, %d, %d\n", comparacoes[0], comparacoes[1], comparacoes[2]);
    printf("Tempos de consulta: %d, %d e %d\n", temposConsulta[0], temposConsulta[1], temposConsulta[2]);
}