#ifndef ORDENADA_LSE_H_

#define ORDENADA_LSE_H_
#include "../estruturas/LSE.h"

LSE* insereOrdenadoLSE(int quantidade, long int *comparacoes);
void analiseOrdenadaLSE(int quantidade);

// Retorna se encontrou ou não o valor
int consultaValorLSE(LSE *ptLista, int valor, int *tempo, long int *comparacoes); 

void consultaOrdenadaLSE(LSE *ptLista, int quantidade);

#endif // ORDENADA_LSE_H_
