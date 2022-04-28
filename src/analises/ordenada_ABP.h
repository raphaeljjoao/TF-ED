#ifndef ORDENADA_ABP_H_

#define ORDENADA_ABP_H_
#include "../arvores/ABP.h"

void analiseOrdenadaABP(int quantidade);
ABP* insereOrdenadoABP(int quantidade);
int consultaValor(ABP *arv, int valor, int *tempo); // Retorna se encontrou ou não o valor
void consultaOrdenadaABP(ABP *arv, int quantidade);

#endif // ORDENADA_ABP_H_
