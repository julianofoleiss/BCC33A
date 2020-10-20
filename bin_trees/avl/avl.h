#pragma once

typedef struct AAVL{
    int chave;
    int dado;
    int fb;
    struct AAVL *esq;
    struct AAVL *dir;
} AAVL;


void AAVL_Inserir(AAVL **A, int chave, int dado);
//Essa função mostra uma representação textual da árvore no terminal
void AAVL_Imprimir(AAVL *A);
/*Essa função gera uma representação visual em formato .dot
No linux tem um programa chamado xdot que abre esse arquivo.*/
void AAVL_GenDOT(AAVL *A, const char* arq_saida);
