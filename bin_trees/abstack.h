#ifndef __ABSTACK_H__
#define __ABSTACK_H__

#include "ab.h"

typedef struct ABNOH{
    AB data;
} ABNOH;

typedef struct ABSTACK{
    ABNOH *nos;
    int sp;
    int alloc;
    int alloc_step;
} ABSTACK;

ABSTACK* ABSTACK_Criar(int alloc_step);
void ABSTACK_Empilhar(ABSTACK *S, AB dado);
AB ABSTACK_Desempilhar(ABSTACK *S);
AB ABSTACK_Topo(ABSTACK *S);
int ABSTACK_Vazia(ABSTACK *S);
void ABSTACK_Imprimir(ABSTACK *S);
void ABSTACK_Destruir(ABSTACK *s);
#endif