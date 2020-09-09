#include <stdlib.h>

#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED* HT, int chave){
    return chave % HT->m;
}

THED* THED_Criar(int m, int alloc_step){
    THED *nova;
    int i;

    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);

    return nova;
}

void THED_Inserir(THED* HT, int chave, int valor);
void THED_Remover(THED* HT, int chave);
INOH* THED_Buscar(THED* HT, int chave);