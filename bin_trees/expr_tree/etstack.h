#pragma once

#include "exprtree.h"

typedef struct ETNOH{
    ExprTree *data;
} ETNOH;

typedef struct ETSTACK{
    ETNOH *nos;
    int sp;
    int alloc;
    int alloc_step;
} ETSTACK;

ETSTACK* ETSTACK_Criar(int alloc_step);
void ETSTACK_Empilhar(ETSTACK *S, ExprTree *dado);
ExprTree* ETSTACK_Desempilhar(ETSTACK *S);
ExprTree* ETSTACK_Topo(ETSTACK *S);
int ETSTACK_Vazia(ETSTACK *S);
void ETSTACK_Imprimir(ETSTACK *S);
void ETSTACK_Destruir(ETSTACK *s);

