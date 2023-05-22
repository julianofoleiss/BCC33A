#pragma once

typedef struct ExprTree{
    struct ExprTree *esq;
    struct ExprTree *dir;
}ExprTree;

void ET_Destruir(ExprTree *A);
