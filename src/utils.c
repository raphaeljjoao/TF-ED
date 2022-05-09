#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* tempoEscrito(int seg) {
    int segundos = seg % 60;

    int minutos = seg / 60;
    int auxMinutos = minutos % 60;
    int horas = minutos / 60;
    minutos = auxMinutos;

    char *resposta = malloc(sizeof(char) * 50);
    sprintf(resposta, "%d horas, %d minutos e %d segundos\n", horas, minutos, segundos);

    return resposta;
}

// Retorna um número aleatório entre 1 e o parâmetro informado
int aleatorio(int max, int last) {
    int randomNumber;
    if (max <= RAND_MAX) 
        randomNumber = rand();
    
    if (max > RAND_MAX)
        return abs(1 + (randomNumber % max) - 0);

    return 1 + (randomNumber % max);
}

