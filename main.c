#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include "src/arvores/ABP.h"
#include "src/arvores/AVL.h"
//#include "src/utils.h"
#include "src/options.h"
//#include "src/stats.h"
#include "src/analises/ordenada_ABP.h"


int main(){
    printf("(INF01203) Estruturas de Dados - Trabalho Final 2021/2\n\n");

    printf("ABP (%d)\n\n", sizeof(ABP));
    analiseOrdenadaABP(TIER_4 * 1);

    return 0;
}
