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

//Calcula a *k*-ésima hash da *chave*.
int THEA_Hash(THEA* TH, int chave, int k);

//Cria uma tabela hash com *m* posições.
//Retorna um ponteiro para a tabela criada.
THEA* THEA_Criar(int m);

//Inserir o par (*chave*, *valor*) na tabela TH.
//Caso a chave já esteja na tabela, atualiza o valor.
//Retorna a posição em que o par foi inserido.
int THEA_Inserir(THEA *TH, int chave, int valor);

//Busca a chave *chave* na tabela TH.
//Retorna a posição em que a chave foi encontrada.
//Caso a chave não esteja na tabela, retorna -1.
int THEA_Buscar(THEA *TH, int chave);

//Remove da tabela TH a *chave*.
//Caso a *chave* não esteja na tabela, apenas retorna.
void THEA_Remover(THEA* TH, int chave);

//Libera a memória alocada para a tabela TH.
void THEA_Destruir(THEA* TH);
