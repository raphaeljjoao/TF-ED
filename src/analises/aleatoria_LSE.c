#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../estruturas/LSE.h"
#include "../utils.h"
#include "../options.h"
#include "aleatoria_LSE.h"

LSE* insereAleatorioLSE(int quantidade, long int *comps) {
    LSE *ptLista = (LSE*) malloc(sizeof(LSE));
    ptLista = NULL;

    int aviso = quantidade / NUM_AVISOS;

    int tempoInicio = time(NULL);
    long int comparacoesTotal = 0;
    
    if (CSVMODE && !SILENT) printf("inseridos,tempo\n");
    for (int i = 1; i <= quantidade; i++) {
        long int compTemp;

        int nAleat = aleatorio(quantidade);
        ptLista = insereFim(ptLista, nAleat, &compTemp);

        comparacoesTotal += compTemp;
        if (i % aviso == 0 && !SILENT) {
            int deltaTempo = time(NULL) - tempoInicio;
            if (CSVMODE) printf("%d,%d\n", i, deltaTempo);
            else printf("LSE: %d/%d dados inseridos em %d segundos.", i, quantidade, deltaTempo);
        }
    }

    *comps = comparacoesTotal;
    return ptLista;
}

void analiseAleatoriaLSE(int quantidade) {
    LSE *ptLista;
    long int comparacoes;

    int tempoInicio = time(NULL);
    ptLista = insereAleatorioLSE(quantidade, &comparacoes);
    int deltaTempo = time(NULL) - tempoInicio;

    printf("\n%d dados foram inseridos em %s\n", quantidade, tempoEscrito(deltaTempo));
    printf("Comparacoes realizadas: %d\n", comparacoes);

    printf("\nConsultas\n");
    consultaAleatoriaLSE(ptLista, quantidade);
    
    ptLista = destroiLista(ptLista);
}

void consultaAleatoriaLSE(LSE *ptLista, int quantidade) {
    int temposConsulta[NUM_CONSULTAS_ALEAT];
    long int comparacoes[NUM_CONSULTAS_ALEAT];

    for (int i = 0; i < NUM_CONSULTAS_ALEAT; i++) {
        int nAleat = aleatorio(quantidade);
        int sucessoConsulta = consultaValorLSE(ptLista, nAleat, &temposConsulta[i], &comparacoes[i]);
        if (sucessoConsulta) printf("Valor %d encontrado na lista.\n", nAleat);
        else printf("Valor %d nao encontrado na lista.\n", nAleat);
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