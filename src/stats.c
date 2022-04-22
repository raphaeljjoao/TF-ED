#include <stdio.h>
#include <stdlib.h>

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

