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

//Imprime a tabela TH.
void THEA_Imprimir(THEA* TH);

//Retorna um vetor com as chaves da tabela TH.
int* THEA_Chaves(THEA* TH);

//Libera a memória alocada para a tabela TH.
void THEA_Destruir(THEA* TH);

//Retorna o tamanho da tabela TH.
size_t THEA_M(THEA* TH);

//Retorna o número de elementos que ocupam a tabela TH.
size_t THEA_N(THEA* TH);

//Retorna um vetor com uma cópia dos pares chave-valor da tabela TH.
ELEM* THEA_Itens(THEA* TH);

//Escreve no parâmetro de saída *valor* o valor associado à *chave* na tabela TH.
//Retorna true se o a chave está na tabela e false caso contrário.
bool THEA_Valor(THEA* TH, int chave, int* valor);
