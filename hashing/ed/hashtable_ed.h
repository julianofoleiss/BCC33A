#pragma once

#include "ilist.h"

typedef struct THED {
    ILIST** t;
    int m;
} THED;

THED* THED_Criar(int m, int alloc_step);
int THED_Hash(THED* HT, int chave);
void THED_Inserir(THED* HT, int chave, int valor);
void THED_Remover(THED* HT, int chave);
INOH* THED_Buscar(THED* HT, int chave);
