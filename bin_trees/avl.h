#pragma once

typedef struct AAVL{
    int chave;
    int dado;
    int fb;
    struct AAVL *esq;
    struct AAVL *dir;
} AAVL;


void AAVL_Inserir(AAVL **A, int chave, int dado);
void AAVL_Imprimir(AAVL *A);
void AAVL_GenDOT(AAVL *A, const char* arq_saida);