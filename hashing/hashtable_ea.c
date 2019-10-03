#include <stdlib.h>
#include "hashtable_ea.h"
#include "prime_list.h"

htea_ea* HTEA_Criar(int m, const char* prime_list){
    htea_ea* novo;
    int i;

    novo = malloc(sizeof(htea_ea));
    novo->n = 0;
    novo->pl = PL_Load(prime_list);
    novo->prime_list_file = prime_list;
    novo->m = PL_NextPrime(novo->pl, m);
    novo->t = malloc(sizeof(htea_noh) * novo->m);

    for(i = 0; i < novo->m; i++){
        novo->t[i].estado = EN_LIVRE;
    }

    novo->max_n = novo->m / 2;

    return novo;
}

int HTEA_Inserir(htea_ea** HT, int chave, int valor){
    int idx_inicial;
    int idx;
    int k;
    htea_ea* tab;
    tab = *HT;

    idx = HTEA_Hash(tab, chave, 0);
    idx_inicial = idx;
    k = 1;

    if( (tab->n+1) >tab->max_n ){
        *HT = HTEA_Redim(tab, 2 * tab->m);
        tab = *HT;
    }

    while(tab->t[idx].estado == EN_OCUPADO){
        if( (tab->t[idx].chave == chave)){
            tab->n--;
            break;
        }
        idx = HTEA_Hash(tab, chave, k);
        k++;
        if(idx == idx_inicial){
            return -1;
        }
    }

    tab->t[idx].chave = chave;
    tab->t[idx].valor = valor;
    tab->t[idx].estado = EN_OCUPADO;
    tab->n++;

    return idx;
}

int HTEA_Remover(htea_ea* HT, int chave){

}

int HTEA_Buscar(htea_ea* HT, int chave){

}

htea_ea* HTEA_Redim(htea_ea* HT, int novo_m){
    htea_ea* novo = HTEA_Criar(novo_m, HT->prime_list_file);
    int i;
    
    for(i = 0; i < HT->m; i++){
        if(HT->t[i].estado == EN_OCUPADO){
            HTEA_Inserir(&novo, HT->t[i].chave, HT->t[i].valor);
        }
    }

    HTEA_Destroy(HT);
    return novo;
}

int HTEA_Hash(htea_ea* HT, int chave, int k){
    return ((chave % HT->m) + k ) % HT->m;
}

void HTEA_Destroy(htea_ea* HT){
    free(HT->t);
    PL_Destroy(HT->pl);
    free(HT);
}