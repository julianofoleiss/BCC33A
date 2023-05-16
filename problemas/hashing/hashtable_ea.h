#pragma once
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

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
    ELEM* t;
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA* TH, int chave);
void THEA_Imprimir(THEA* TH);
int* THEA_Chaves(THEA* TH);
void THEA_Destruir(THEA* TH);
size_t THEA_M(THEA* TH);
size_t THEA_N(THEA* TH);
ELEM* THEA_Itens(THEA* TH);
bool THEA_Valor(THEA* TH, int chave, int* valor);
