#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"

static void THEA_Redimensionar(THEA* TH, int novo_m){
    ELEM* nova, *antiga;
    int i, m_antigo;
    if(novo_m == 0)
        novo_m = 1;
    nova = malloc(sizeof(ELEM) * novo_m);
    for(i = 0; i < novo_m; i++){
        nova[i].estado = E_LIVRE;
    }
    antiga = TH->t;
    m_antigo = TH->m;
    TH->t = nova;
    TH->m = novo_m;
    TH->n = 0;
    for(i = 0; i < m_antigo; i++){
        if(antiga[i].estado == E_OCUPADO){
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
        }
    }
    free(antiga);
}

int THEA_Hash(THEA* TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA* THEA_Criar(int m){
    THEA* nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->n = 0;
    nova->t = malloc(sizeof(ELEM) * m);
    for(int i = 0; i < m; i++)
        nova->t[i].estado = E_LIVRE;
    return nova;
}

int THEA_Inserir(THEA *TH, int chave, int valor){
    int h = THEA_Buscar(TH, chave);
    if(h < 0){

        if(TH->n > (TH->m/2)){
            //printf("redimensionando de M=%ld para M=%ld\n", TH->m, TH->m*2);
            THEA_Redimensionar(TH, TH->m*2);
        }

        //chave não está na tabela, devemos encontrar
        //onde inseri-la
        if(TH->m == TH->n)
            return -1;
        int k = 0;
        h = THEA_Hash(TH, chave, k);
        while(TH->t[h].estado == E_OCUPADO){
            k++;
            h = THEA_Hash(TH, chave, k);
        }
        TH->n++;
        TH->t[h].chave = chave;
        TH->t[h].estado = E_OCUPADO;        
    }
    TH->t[h].valor = valor;
    return h;
}

int THEA_Buscar(THEA *TH, int chave){
    int k = 0;
    int h = THEA_Hash(TH, chave, k);
    while(TH->t[h].estado != E_LIVRE){
        if((TH->t[h].estado == E_OCUPADO)
            && (TH->t[h].chave == chave)){
            return h;
        }
        k++;
        h = THEA_Hash(TH, chave, k);
        if(k == TH->m)
            return -1;
    }
    return -1;
}

void THEA_Remover(THEA* TH, int chave){
    int pos = THEA_Buscar(TH, chave);
    if(pos >= 0){
        TH->t[pos].estado = E_APAGADO;
        TH->n--;
        if(TH->n < (TH->m/5)){
            //printf("redimensionando de M=%ld para M=%ld (n = %ld)\n", TH->m, TH->m/2, TH->n);
            THEA_Redimensionar(TH, TH->m/2);
        }
    }
}

void THEA_Imprimir(THEA* TH){
    printf("M=%ld, N=%ld\n", TH->m, TH->n);
    for(int i = 0; i < TH->m; i++){
        ELEM* e = &TH->t[i];
        printf("%d: (%d -> %d) [%d]\n", i,
            e->chave, e->valor, e->estado);
    }
}

int* THEA_Chaves(THEA* TH){
    if(TH->n == 0)
        return NULL;
    int* chaves = malloc(sizeof(int) * TH->n);
    int p = 0;
    for(int i = 0; i < TH->m; i++){
        if(TH->t[i].estado == E_OCUPADO){
            chaves[p] = TH->t[i].chave;
            p++;
        }
    }
    return chaves;
}

void THEA_Destruir(THEA* TH){
    free(TH->t);
    free(TH);
}

size_t THEA_M(THEA* TH){
    return TH->m;
}

size_t THEA_N(THEA* TH){
    return TH->n;
}