#include <stdlib.h>
#include <stdio.h>
#include "etstack.h"

ETSTACK* ETSTACK_Criar(int alloc_step){
    ETSTACK *n;

    n = malloc(sizeof(ETSTACK));
    n->alloc_step = alloc_step;
    n->alloc = alloc_step;
    n->sp = 0;
    n->nos = malloc(sizeof(ETNOH) * n->alloc);

    return n;
}

void ETSTACK_Empilhar(ETSTACK *S, ExprTree *dado){
    S->nos[S->sp].data = dado;
    S->sp++;
    if(S->sp >= S->alloc){
        S->alloc += S->alloc_step;
        S->nos = realloc(S->nos, S->alloc * sizeof(ETNOH));

    }
}

ExprTree* ETSTACK_Desempilhar(ETSTACK *S){
    if(!ETSTACK_Vazia(S)){
        S->sp--;
    }
    return S->nos[S->sp].data;
}

ExprTree* ETSTACK_Topo(ETSTACK *S){
    if(!ETSTACK_Vazia(S)){
        return S->nos[S->sp-1].data;
    }
    return NULL;
}

int ETSTACK_Vazia(ETSTACK *S){
    return S->sp == 0 ? 1 : 0;
}

void ETSTACK_Imprimir(ETSTACK *S){
    int i;
    if(ETSTACK_Vazia(S)){
        printf("Pilha vazia!\n");
    }
    else{
        for(i = 0; i < S->sp; i++){
            printf("%p ", S->nos[i].data);
        }
        printf("\n");
    }
}

void ETSTACK_Destruir(ETSTACK *s){
    free(s->nos);
}
