#include <stdlib.h>
#include <stdio.h>
#include "cstack.h"

CSTACK* CSTACK_Criar(int alloc_step){
    CSTACK *n;

    n = malloc(sizeof(CSTACK));
    n->alloc_step = alloc_step;
    n->alloc = alloc_step;
    n->sp = 0;
    n->nos = malloc(sizeof(CNOH) * n->alloc);

    return n;
}

void CSTACK_Empilhar(CSTACK *S, char dado){
    S->nos[S->sp].data = dado;
    S->sp++;
    if(S->sp >= S->alloc){
        S->alloc += S->alloc_step;
        S->nos = realloc(S->nos, S->alloc * sizeof(CNOH));

    }
}

char CSTACK_Desempilhar(CSTACK *S){
    if(!CSTACK_Vazia(S)){
        S->sp--;
    }
    return S->nos[S->sp].data;
}

char CSTACK_Topo(CSTACK *S){
    if(!CSTACK_Vazia(S)){
        return S->nos[S->sp-1].data;
    }
    return '\0';
}

int CSTACK_Vazia(CSTACK *S){
    return S->sp == 0 ? 1 : 0;
}

void CSTACK_Imprimir(CSTACK *S){
    int i;
    if(CSTACK_Vazia(S)){
        printf("Pilha vazia!\n");
    }
    else{
        for(i = 0; i < S->sp; i++){
            printf("%c ", S->nos[i].data);
        }
        printf("\n");
    }
}

void CSTACK_Destruir(CSTACK *s){
    free(s->nos);
}
