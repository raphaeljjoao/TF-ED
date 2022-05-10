#include <stdio.h>
#include <ctype.h>
#include "src/options.h"
#include "src/analises/ordenada_ABP.h"
#include "src/analises/ordenada_LSE.h"
#include "src/analises/aleatoria_ABP.h"
#include "src/analises/aleatoria_LSE.h"

int main(){
    printf("\n(INF01203) Estruturas de Dados - Trabalho Final 2021/2\n\n");

    char continuar;
    do {
        char opcaoQuantidade;
        int quantidade;
        
        do {
            printf("Quantos dados voce deseja inserir?\n");
            printf("A - %d dados\n", TIER_1);
            printf("B - %d dados\n", TIER_2);
            printf("C - %d dados\n", TIER_3);
            printf("D - %d dados\n", TIER_4);
            printf("Entre com sua opcao: ");
            scanf("%c", &opcaoQuantidade); fflush(stdin);
            opcaoQuantidade = toupper(opcaoQuantidade);

            if (opcaoQuantidade != 'A' && opcaoQuantidade != 'B' && opcaoQuantidade != 'C' && opcaoQuantidade != 'D')
                printf("\nOpcao %c invalida.\n\n", opcaoQuantidade);
        } while (opcaoQuantidade != 'A' && opcaoQuantidade != 'B' && opcaoQuantidade != 'C' && opcaoQuantidade != 'D');

        switch (opcaoQuantidade) {
            case 'A':
                quantidade = TIER_1;
                break;
            case 'B':
                quantidade = TIER_2;
                break;
            case 'C':
                quantidade = TIER_3;
                break;
            case 'D':
                quantidade = TIER_4;
                break;
            default:
                quantidade = 0;
        }
        
        printf("\nOpcao escolhida: %c - %d\n\n", opcaoQuantidade, quantidade);

        int opcaoAnalise;
        do {
            printf("Qual analise voce deseja executar?\n");
            printf("1 - Todas\n");
            printf("2 - Ordenadas\n");
            printf("3 - Aleatorias\n");
            printf("4 - LSE Ordenada\n");
            printf("5 - LSE Aleatoria\n");
            printf("6 - ABP Ordenada\n");
            printf("7 - ABP Aleatoria\n");
            printf("Entre com sua opcao:\n");
            scanf("%d", &opcaoAnalise); fflush(stdin);

            if (opcaoAnalise < 1 || opcaoAnalise > 7)
                printf("\nOpcao %d invalida.\n\n", opcaoAnalise);
        } while(opcaoAnalise < 1 || opcaoAnalise > 7);

        switch(opcaoAnalise) {
            case 1:
                printf("\n==================\n");
                printf("Analise Ordenada da LSE\n\n");
                analiseOrdenadaLSE(quantidade);
                printf("\n==================\n");

                printf("\n==================\n");
                printf("Analise Ordenada da ABP\n\n");
                analiseOrdenadaABP(quantidade);
                printf("\n==================\n");

                printf("\n==================\n");
                printf("Analise Aleatoria da LSE\n\n");
                analiseAleatoriaLSE(quantidade);
                printf("\n==================\n");

                printf("\n==================\n");
                printf("Analise Aleatoria da ABP\n\n");
                analiseAleatoriaABP(quantidade);
                printf("\n==================\n");
                break;
            case 2:
                printf("\n==================\n");
                printf("Analise Ordenada da LSE\n\n");
                analiseOrdenadaLSE(quantidade);
                printf("\n==================\n");

                printf("\n==================\n");
                printf("Analise Ordenada da ABP\n\n");
                analiseOrdenadaABP(quantidade);
                printf("\n==================\n");
                break;
            case 3:
                printf("\n==================\n");
                printf("Analise Aleatoria da LSE\n\n");
                analiseAleatoriaLSE(quantidade);
                printf("\n==================\n");

                printf("\n==================\n");
                printf("Analise Aleatoria da ABP\n\n");
                analiseAleatoriaABP(quantidade);
                printf("\n==================\n");
                break;
            case 4:
                printf("\n==================\n");
                printf("Analise Ordenada da LSE\n\n");
                analiseOrdenadaLSE(quantidade);
                printf("\n==================\n");
                break;
            case 5:
                printf("\n==================\n");
                printf("Analise Aleatoria da LSE\n\n");
                analiseAleatoriaLSE(quantidade);
                printf("\n==================\n");
                break;
            case 6:
                printf("\n==================\n");
                printf("Analise Ordenada da ABP\n\n");
                analiseOrdenadaABP(quantidade);
                printf("\n==================\n");
                break;
            case 7:
                printf("\n==================\n");
                printf("Analise Aleatoria da ABP\n\n");
                analiseAleatoriaABP(quantidade);
                printf("\n==================\n");
                break;
            default:
                printf("ERRO!\n");
                break;
        }

        printf("Digite N e confirme para sair ou qualquer outro caractere para continuar.\n");
        scanf("%c", &continuar); fflush(stdin);
    } while (tolower(continuar) != 'n');

    return 0;
}