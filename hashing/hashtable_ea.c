#include <stdlib.h>
#include "hashtable_ea.h"
#include "prime_list.h"

int linear_probe(int x, int k){
    return k;
}

int linear_next_m(htea_ea* HT){
    int novo_m;
    
    novo_m = HT->m * 2;
    novo_m = PL_NextPrime(HT->pl, novo_m);

    return novo_m;
}

htea_ea* HTEA_Criar(int m, const char* prime_list, 
    enum probing_strategy ps){

    htea_ea* novo;
    int i;

    novo = malloc(sizeof(htea_ea));
    novo->n = 0;
    novo->pl = PL_Load(prime_list);
    novo->prime_list_file = prime_list;
    novo->m = m;
    novo->t = malloc(sizeof(htea_noh) * novo->m);
    novo->ps = ps;
    
    for(i = 0; i < novo->m; i++){
        novo->t[i].estado = EN_LIVRE;
    }

    novo->max_n = novo->m / 2;

    if(ps == PS_LINEAR){
        novo->probe_func = linear_probe;
        novo->next_m_func = linear_next_m;
    }

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
        *HT = HTEA_Redim(tab, tab->next_m_func(tab) );
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
    htea_ea* novo = HTEA_Criar(novo_m, HT->prime_list_file, 
        HT->ps);

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
    return ((chave % HT->m) 
                + HT->probe_func(chave, k) ) 
                % HT->m;
}

void HTEA_Destroy(htea_ea* HT){
    free(HT->t);
    PL_Destroy(HT->pl);
    free(HT);
}


