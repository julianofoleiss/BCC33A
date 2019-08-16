#include <stdlib.h>
#include "lista_int.h"

T_NOH* NOH_criar(int dado){
    T_NOH* novo;
    novo = malloc(sizeof(T_NOH));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

int NOH_get_dado(T_NOH* E){
    return E->dado;
}

void NOH_set_dado(T_NOH* E, int dado){
    E->dado = dado;
}

T_NOH* NOH_get_prox(T_NOH* E){
    return E->prox;
}

T_NOH* NOH_set_prox(T_NOH* E, T_NOH* p){
    E->prox = p;
}

T_LINT* LINT_criar(){
    T_LINT* novo;
    novo = malloc(sizeof(T_LINT));
    novo->primeiro = NULL;
    novo->ultimo = NULL;
    novo->tamanho = 0;
    return novo;
}

void LINT_inserir(T_LINT *L, int dado){
    T_NOH* novo;
    novo = NOH_criar(dado);
    if(LINT_vazia(L)){
        L->primeiro = novo;
    }
    else{
        NOH_set_prox(L->ultimo, novo);
    }
    L->tamanho++;
    L->ultimo = novo;
}

T_NOH* LINT_remover(T_LINT *L, int dado){
    
}

void LINT_destruir(T_LINT *L){
    
}

T_NOH* LINT_buscar(T_LINT* L, int dado){
    
}

int LINT_vazia(T_LINT *L){
    return L->tamanho == 0 ? 1 : 0;
}
