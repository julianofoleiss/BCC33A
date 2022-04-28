#include "ilist.h"
#include <stdlib.h>
#include <stdio.h>

ILIST* ILIST_Criar(int alloc_step){
    ILIST* novo;
    int i;

    novo = malloc(sizeof(ILIST));

    novo->alloc = alloc_step;
    novo->alloc_step = alloc_step;
    novo->max = 0;
    novo->tam = 0;
    novo->nos = malloc(sizeof(INOH) * novo->alloc);
    novo->itpos = 0;
    for(i = 0; i < novo->alloc; i++){
        novo->nos[i].ocupado = 0;
    }

    return novo;

}

int ILIST_Inserir(ILIST *L, int chave, int valor){
    int i;
    int desocupado;
    desocupado = -1;

    for(i = 0; i < L->max; i++){
        if( (L->nos[i].chave == chave) && L->nos[i].ocupado){
            desocupado = -1;
            L->tam--;
            break;
        }
        if(L->nos[i].ocupado == 0){
            if (desocupado == -1)
                desocupado = i;
        }
    }

    if(desocupado != -1)
        i = desocupado;

    if(i >= L->max)
        L->max++;
        
    if( i >= L->alloc ){
        L->alloc = L->alloc + L->alloc_step;
        L->nos = realloc(L->nos, sizeof(INOH) * L->alloc);
    }

    L->nos[i].chave = chave;
    L->nos[i].valor = valor;
    L->nos[i].ocupado = 1;
    L->tam++;

    return i;
}

int ILIST_Remover(ILIST *L, int chave){
    int i;
    i = ILIST_Buscar(L, chave);
    
    if(i != -1){
        L->tam--;
        L->nos[i].ocupado = 0;
    }

    return i;
}

int ILIST_Buscar(ILIST *L, int chave){
    int i;
    
    for(i = 0; i < L->max; i++){
        if( (L->nos[i].chave == chave) && L->nos[i].ocupado )
            return i;
    }
    
    return -1;

}

INOH* ILIST_Endereco(ILIST *L, int pos){
    if(pos != -1)
        return &L->nos[pos];
    return NULL;
}

void ILIST_Imprimir(ILIST *L, int debug){
    int i;

    printf("TAM: %d, MAX: %d\n", L->tam, L->max);

    for(i = 0; i < L->max; i++){
        if (L->nos[i].ocupado || debug){
            printf("%d -> %d", L->nos[i].chave, L->nos[i].valor);
            if(debug)
                printf(" (%d)", L->nos[i].ocupado);
            printf("\n");
        }
    }

}

size_t ILIST_Tamanho(ILIST *L){
    return L->tam;
}

void ILIST_Rebobinar(ILIST *L){
    L->itpos = 0;
}

INOH* ILIST_Prox(ILIST *L){
    INOH* prox = NULL;
    if(L->itpos < L->alloc){
        for(;L->itpos < L->alloc; L->itpos++){
            if(L->nos[L->itpos].ocupado){
                prox = &L->nos[L->itpos];
                L->itpos++;
                break;
            }
        }
    }
    return prox;
}

void ILIST_Destruir(ILIST *L){
    free(L->nos);
    free(L);
}