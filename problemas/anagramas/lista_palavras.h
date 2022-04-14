#pragma once
#include <stdlib.h>

#define TAM_MAX_PALAVRA 50

typedef struct{
    char palavra_ord[TAM_MAX_PALAVRA+1];
    char palavra_org[TAM_MAX_PALAVRA+1];
} Palavra;

typedef struct{
    Palavra** palavras;
    size_t n;
} Lista_Palavras;

Lista_Palavras* LP_Carregar(char* dicionario);
void LP_Destruir(Lista_Palavras* lp);
void LP_OrdenarPorPalavraOrd(Lista_Palavras* lp);
int LP_BuscarPalavra(Lista_Palavras* lp, char* x);
void LP_ImprimirAnagramas(Lista_Palavras* lp, char* x);
