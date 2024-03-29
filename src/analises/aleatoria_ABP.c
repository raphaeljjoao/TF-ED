#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../estruturas/ABP.h"
#include "../utils.h"
#include "../options.h"
#include "aleatoria_ABP.h"

ABP* insereAleatorioABP(int quantidade, long int *comps) {
    ABP *arv = (ABP*) malloc(sizeof(ABP));
    arv = NULL;

    int aviso = quantidade / NUM_AVISOS;

    int tempoInicio = time(NULL);
    long int comparacoesTotal = 0;
    
    if (CSVMODE && !SILENT) printf("inseridos,tempo\n");
    for (int i = 1; i <= quantidade; i++) {
        long int compTemp;

        int nAleat = aleatorio(quantidade);
        insereABP(&arv, nAleat, &compTemp);

        comparacoesTotal += compTemp;
        if (i % aviso == 0 && !SILENT) {
            int deltaTempo = time(NULL) - tempoInicio;
            if (CSVMODE) printf("%d,%d\n", i, deltaTempo);
            else printf("ABP: %d/%d dados inseridos em %d segundos.\n", i, quantidade, deltaTempo);
        }
    }

    *comps = comparacoesTotal;
    return arv;
}

void analiseAleatoriaABP(int quantidade) {
    ABP *arv;
    long int comparacoes;

    int tempoInicio = time(NULL);
    arv = insereAleatorioABP(quantidade, &comparacoes);
    int deltaTempo = time(NULL) - tempoInicio;

    printf("\n%d dados foram inseridos em %s\n", quantidade, tempoEscrito(deltaTempo));
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Altura da arvore: %d\n", alturaABP(arv));

    printf("\nConsultas\n");
    consultaAleatoriaABP(arv, quantidade);
    
    arv = destroiABP(arv);
}

void consultaAleatoriaABP(ABP *arv, int quantidade) {
    int temposConsulta[NUM_CONSULTAS_ALEAT];
    long int comparacoes[NUM_CONSULTAS_ALEAT];

    for (int i = 0; i < NUM_CONSULTAS_ALEAT; i++) {
        int nAleat = aleatorio(quantidade);
        int sucessoConsulta = consultaValorABP(arv, nAleat, &temposConsulta[i], &comparacoes[i]);
        if (sucessoConsulta) printf("Valor %d encontrado na arvore.\n", nAleat);
        else printf("Valor %d nao encontrado na arvore.\n", nAleat);
    }

    long int mediaComparacoes = 0;
    printf("Comparacoes: ");
    for (int i = 0; i < NUM_CONSULTAS_ALEAT; i++) {
        long int compAtual = comparacoes[i];
        printf("%d ", compAtual);
        mediaComparacoes += compAtual; 
    }
    mediaComparacoes /= NUM_CONSULTAS_ALEAT;
    printf("(media %d)\n", mediaComparacoes);

    int mediaTempo = 0;
    printf("Tempos de consulta: ");
    for (int i = 0; i < NUM_CONSULTAS_ALEAT; i++) {
        int tempoAtual = temposConsulta[i];
        printf("%d ", tempoAtual);
        mediaTempo += tempoAtual;
    }
    mediaTempo /= NUM_CONSULTAS_ALEAT;
    printf("(media %d)\n", mediaTempo);
}