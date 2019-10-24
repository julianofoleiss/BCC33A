#include "ab.h"
#include <stdlib.h>

AB AB_Criar(int dado, AB e, AB d){
    AB n;
    
    n = malloc(sizeof(struct AB));
    n->dado = dado;
    n->esq = e;
    n->dir = d;

    return n;
}

void AB_Destruir(AB A){
    if(A == NULL)
        return;
    AB_Destruir(A->esq);
    AB_Destruir(A->dir);
    free(A);
}
