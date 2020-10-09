#include "exprtree.h"
#include <stdlib.h>

ExprTree* ET_Criar(int dado, ExprTree *e, ExprTree *d){
    ExprTree *n;
    
    n = malloc(sizeof(struct ExprTree));
    n->dado = dado;
    n->esq = e;
    n->dir = d;

    return n;
}

void ET_Destruir(ExprTree *A){
    if(A == NULL)
        return;
    ET_Destruir(A->esq);
    ET_Destruir(A->dir);
    free(A);
}
