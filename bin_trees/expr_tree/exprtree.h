#pragma once

typedef struct ExprTree{
    struct ExprTree *esq;
    struct ExprTree *dir;
}ExprTree;

void ET_Destruir(ExprTree *A);
void ET_GenDOT(ExprTree *A, const char* arq_saida);
