#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

static NOH* NOH_Criar(int chave, int valor){
    NOH* novo = malloc(sizeof(NOH));
    novo->chave = chave;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

ABB* ABB_Criar(){
    ABB* nova = malloc(sizeof(ABB));
    nova->raiz = NULL;
    return nova;
}

static NOH* ABB_Inserir_R(NOH* N , int chave, int valor){
    if(N == NULL){
        return NOH_Criar(chave, valor);
    }
    if(chave < N->chave){
        N->esq = ABB_Inserir_R(N->esq, chave, valor);
    }
    else {
        if(chave > N->chave){
            N->dir = ABB_Inserir_R(N->dir, chave, valor);
        }
        else{
            N->valor = valor;
        }
    }
    return N;

}


// Insere o par (chave, valor) na árvore A. 
// Caso a chave já esteja na árvore, o valor é atualizado.
void ABB_Inserir(ABB*A , int chave, int valor){
    A->raiz = ABB_Inserir_R(A->raiz, chave, valor);  
}

void ABB_Imprimir_R(NOH *A, int nivel, char lado){
    int i;
    for(i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) (%d, %d)\n", lado, A->chave, A->valor);
        ABB_Imprimir_R(A->esq, nivel+1, 'e');
        ABB_Imprimir_R(A->dir, nivel+1, 'd');
    }
}

// Imprime a árvore em pré-ordem
void ABB_Imprimir(ABB *A){
    ABB_Imprimir_R(A->raiz, 0, 'r');
}

void ABB_Destruir_R(NOH* N){
    if(N == NULL)
        return;
    ABB_Destruir_R(N->esq);
    ABB_Destruir_R(N->dir);
    free(N);
}

void ABB_Destruir(ABB* A){
    ABB_Destruir_R(A->raiz);
    free(A);
}
