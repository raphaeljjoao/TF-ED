#include <stdio.h>
#include <time.h>
#include "../estruturas/LSE.h"
#include "ordenada_LSE.h"
#include "../options.h"
#include "../stats.h"

LSE* insereOrdenadoLSE(int quantidade, long int *comparacoes) {
    LSE *ptLista;
    ptLista = criaLista();

    int aviso = quantidade / NUM_AVISOS;

    int tempoInicio = time(NULL);
    long int comparacoesTotal = 0;

    for (int i = 1; i <= quantidade; i++) {
        long int compTemp; // Comparações temporárias
        ptLista = insereFim(ptLista, i, &compTemp);
        comparacoesTotal += compTemp;
        if (i % aviso == 0 && !SILENT) {
            if (CSVMODE) printf("inseridos,tempo");
            int deltaTempo = time(NULL) - tempoInicio;
            if (CSVMODE) printf("%d,%d\n", i, deltaTempo);
            else printf("LSE: %d/%d dados inseridos em %d segundos.\n", i, quantidade, deltaTempo);
        }
    }

    *comparacoes = comparacoesTotal;
    return ptLista;
}

void analiseOrdenadaLSE(int quantidade) {
    LSE *ptLista;
    long int comparacoes;
    int tempoInicio = time(NULL);
    ptLista = insereOrdenadoLSE(quantidade, &comparacoes);
    int deltaTempo = time(NULL) - tempoInicio;

    consultaOrdenadaLSE(ptLista, quantidade);

    printf("%d dados foram inseridos em %s\n", quantidade, tempoEscrito(deltaTempo));
    printf("Comparacoes realizadas: %d\n", comparacoes);

    ptLista = destroiLista(ptLista);
}


int consultaValorLSE(LSE *ptLista, int valor, int *tempo, long int *comparacoes) {
    long int comps;
    int inicio = time(NULL);
    LSE *consulta = consultaLSE(ptLista, valor, &comps);

    *tempo = time(NULL) - inicio;

    *comparacoes = comps;
    return consulta != NULL;
}

void consultaOrdenadaLSE(LSE *ptLista, int quantidade) {
    int temposConsulta[3];
    long int comparacoes[3];
    int consultaInicio = 1;
    int consultaMeio = quantidade / 2;
    int consultaFim = quantidade;

    int sucessoConsulta;
    // Consulta no início
    sucessoConsulta = consultaValorLSE(ptLista, consultaInicio, &temposConsulta[0], &comparacoes[0]);
    if (sucessoConsulta) printf("Valor %d encontrado na lista.\n", consultaInicio);
    else printf("Valor %d nao encontrado na lista.\n", consultaInicio);

    // Consulta no meio
    sucessoConsulta = consultaValorLSE(ptLista, consultaMeio, &temposConsulta[1], &comparacoes[1]);
    if (sucessoConsulta) printf("Valor %d encontrado na lista.\n", consultaMeio);
    else printf("Valor %d nao encontrado na lista.\n", consultaMeio);

    // Consulta no fim
    sucessoConsulta = consultaValorLSE(ptLista, consultaFim, &temposConsulta[2], &comparacoes[2]);
    if (sucessoConsulta) printf("Valor %d encontrado na lista.\n", consultaFim);
    else printf("Valor %d nao encontrado na lista.\n", consultaFim);

    printf("Comparações: %d, %d, %d\n", comparacoes[0], comparacoes[1], comparacoes[2]);
    printf("Tempos de consulta: %d, %d e %d\n", temposConsulta[0], temposConsulta[1], temposConsulta[2]);
}