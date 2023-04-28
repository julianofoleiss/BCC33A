#pragma once

#include <stdlib.h>

typedef struct INOH{
    int chave;
    int valor;
    int ocupado;
} INOH;

typedef struct ILIST{
    INOH *nos;
    int max;
    int tam;
    int alloc;
    int alloc_step;
    int itpos;
} ILIST;

//Cria uma lista vazia de capacidade inicial *alloc_step*.
//Retorna um ponteiro para a lista criada.
ILIST* ILIST_Criar(int alloc_step);

//Insere um novo par (*chave*,*valor*) na lista L. 
//Retorna a posição que o elemento foi inserido.
int ILIST_Inserir(ILIST *L, int chave, int valor);

//Remove um elemento *chave* da lista L.
//Retorna a posição que o elemento ocupava na lista.
//Caso o elemento não estivesse na lista, retorna -1.
int ILIST_Remover(ILIST *L, int chave);

//Busca um elemento *chave* na lista L.
//Retorna a posição que o elemento ocupa na lista.
//Caso o elemento não esteja na lista, retorna -1.
int ILIST_Buscar(ILIST *L, int chave);

//Imprime a lista L. 
//Um valor diferente de zero para a variável *debug* 
//imprime informações adicionais.
void ILIST_Imprimir(ILIST *L, int debug);

//Retorna o endereço do nó na posição *pos* da lista.
//Caso a posição seja inválida, retorna NULL.
INOH* ILIST_Endereco(ILIST *L, int pos);

//Retorna o número de elementos na lista L.
size_t ILIST_Tamanho(ILIST *L);

//Rebobina o iterador da lista L para a primeira posição
void ILIST_Rebobinar(ILIST *L);

//Retorna o nó atual do iterador da lista L e avança o iterador.
INOH* ILIST_Prox(ILIST *L);

//Desaloca os recursos da lista L.
void ILIST_Destruir(ILIST *L);
