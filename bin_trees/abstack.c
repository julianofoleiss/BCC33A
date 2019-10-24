#include <stdlib.h>
#include <stdio.h>
#include "abstack.h"

ABSTACK* ABSTACK_Criar(int alloc_step){
    ABSTACK *n;

    n = malloc(sizeof(ABSTACK));
    n->alloc_step = alloc_step;
    n->alloc = alloc_step;
    n->sp = 0;
    n->nos = malloc(sizeof(ABNOH) * n->alloc);

    return n;
}

void ABSTACK_Empilhar(ABSTACK *S, AB dado){
    S->nos[S->sp].data = dado;
    S->sp++;
    if(S->sp >= S->alloc){
        S->alloc += S->alloc_step;
        S->nos = realloc(S->nos, S->alloc * sizeof(ABNOH));

    }
}

AB ABSTACK_Desempilhar(ABSTACK *S){
    if(!ABSTACK_Vazia(S)){
        S->sp--;
    }
    return S->nos[S->sp].data;
}

AB ABSTACK_Topo(ABSTACK *S){
    if(!ABSTACK_Vazia(S)){
        return S->nos[S->sp-1].data;
    }
    return NULL;
}

int ABSTACK_Vazia(ABSTACK *S){
    return S->sp == 0 ? 1 : 0;
}

void ABSTACK_Imprimir(ABSTACK *S){
    int i;
    if(ABSTACK_Vazia(S)){
        printf("Pilha vazia!\n");
    }
    else{
        for(i = 0; i < S->sp; i++){
            printf("%p ", S->nos[i].data);
        }
        printf("\n");
    }
}

void ABSTACK_Destruir(ABSTACK *s){
    free(s->nos);
}
