#include "ilist.h"

typedef struct HTED {
    ILIST** t;
    int m;
} HTED;

HTED* HT_Criar(int m, int alloc_step);
int HT_Hash(HTED* HT, int chave);
void HT_Inserir(HTED* HT, int chave, int valor);
void HT_Remover(HTED* HT, int chave);
int HT_Buscar(HTED* HT, int chave);
