#ifndef __AVL_H__
#define __AVL_H__

typedef struct AAVL {
    struct AAVL *esq;
    struct AAVL *dir;
    int fat_bal;
    int dado;
} *AAVL;

AAVL AAVL_Criar(int dado, AAVL esq, AAVL dir);
void AAVL_Inserir(AAVL *A, int dado);
void AAVL_Imprimir(AAVL A, int nivel, char lado);

AAVL AAVL_Buscar(AAVL A, int dado);
int AAVL_FatorBalanceamento(AAVL A);
int AAVL_Altura(AAVL A);
int AAVL_ImprimirOrdenado(AAVL A);
#endif