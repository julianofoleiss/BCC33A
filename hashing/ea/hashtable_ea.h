#pragma once

#include <stdlib.h>

typedef enum ESTADO {
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM{
    int chave;
    int valor;
    ESTADO estado;
} ELEM;

typedef struct THEA{
    size_t m;
    size_t n;
    ELEM* TH;
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA* TH, int chave);
