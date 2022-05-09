#ifndef ORDENADA_ABP_H_

#define ORDENADA_ABP_H_
#include "../estruturas/ABP.h"

void analiseOrdenadaABP(int quantidade);
ABP* insereOrdenadoABP(int quantidade, long int *comps);

// Retorna se encontrou ou não o valor
int consultaValorABP(ABP *arv, int valor, int *tempo, long int *comps); 

void consultaOrdenadaABP(ABP *arv, int quantidade);

#endif // ORDENADA_ABP_H_
