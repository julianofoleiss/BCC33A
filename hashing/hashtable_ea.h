#ifndef __HTEA__
#define __HTEA__

#include "prime_list.h"

enum estado_noh{
    EN_LIVRE,
    EN_OCUPADO,
    EN_APAGADO
};

typedef struct htea_noh{
    int chave;
    int valor;
    enum estado_noh estado;
}htea_noh;

typedef struct htea_ea{
    htea_noh* t;
    int m;
    int n;
    prime_list_t* pl;
    int max_n;
    const char* prime_list_file;
}htea_ea;

htea_ea* HTEA_Criar(int m, const char* prime_list);
int HTEA_Inserir(htea_ea** HT, int chave, int valor);
int HTEA_Remover(htea_ea* HT, int chave);
int HTEA_Buscar(htea_ea* HT, int chave);
htea_ea* HTEA_Redim(htea_ea* HT, int novo_m);
int HTEA_Hash(htea_ea* HT, int chave, int k);
void HTEA_Destroy(htea_ea* HT);

#endif