#ifndef __CSTACK_H__
#define __CSTACK_H__

typedef struct CNOH{
    char data;
} CNOH;

typedef struct CSTACK{
    CNOH *nos;
    int sp;
    int alloc;
    int alloc_step;
} CSTACK;

CSTACK* CSTACK_Criar(int alloc_step);
void CSTACK_Empilhar(CSTACK *S, char dado);
char CSTACK_Desempilhar(CSTACK *S);
char CSTACK_Topo(CSTACK *S);
int CSTACK_Vazia(CSTACK *S);
void CSTACK_Imprimir(CSTACK *S);
void CSTACK_Destruir(CSTACK *s);
#endif