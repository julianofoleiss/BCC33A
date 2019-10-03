#include "ilist.h"
#include "hashtable_ed.h"

int HT_Hash(HTED* HT, int chave){
    return chave % HT->m;
}

HTED* HT_Criar(int m, int alloc_step){
    HTED *nova;
    int i;

    nova->m = m;
    nova->t = malloc(sizeof(ILIST*) * m);
    for(i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);

    return nova;
}

void HT_Inserir(HTED* HT, int chave, int valor);
void HT_Remover(HTED* HT, int chave);
int HT_Buscar(HTED* HT, int chave);