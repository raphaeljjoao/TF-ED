#include <stdio.h>
#include "src/arvores/ABP.h"
#include "src/arvores/AVL.h"

int main(){
    printf("(INF01203) Estruturas de Dados - Trabalho Final 2021/2\n\n");

    AVL *arv = NULL;
    int ok;

    arv = insereAVL(arv, 1,&ok);
    arv = insereAVL(arv, 2,&ok);
    arv = insereAVL(arv, 3,&ok);
    arv = insereAVL(arv, 4,&ok);
    arv = insereAVL(arv, 5,&ok);
    arv = insereAVL(arv, 6,&ok);
    arv = insereAVL(arv, 7,&ok);
    arv = insereAVL(arv, 8,&ok);
    arv = insereAVL(arv, 9,&ok);
    arv = insereAVL(arv, 10,&ok);

    printf("\n=========\n");

    printf("Eh AVL? %s\n", isAVL(arv) ? "sim" : "não");
    //centralEAVL(arv); printf("\n");
    preFixadoEAVL(arv);

    return 0;
}
