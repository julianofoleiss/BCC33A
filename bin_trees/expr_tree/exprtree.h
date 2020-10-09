#pragma once

typedef struct ExprTree{
    struct ExprTree *esq;
    struct ExprTree *dir;
    int dado;
}ExprTree;

ExprTree* ET_Criar(int dado, ExprTree *e, ExprTree *d);
void ET_Destruir(ExprTree *A);
