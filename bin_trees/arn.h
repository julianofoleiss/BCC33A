#ifndef __ARN_H__
#define __ARN_H__

typedef enum {
    C_VERMELHO,
    C_PRETO
} ARN_COR;

typedef struct ARN{
    struct ARN* esq;
    struct ARN* dir;
    ARN_COR cor;
    int dado;
} *ARN;

ARN ARN_Criar(int dado);
void ARN_Inserir(ARN *A, int dado);
void ARN_Imprimir(ARN A, int nivel, char lado);

#endif
