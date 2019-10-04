#ifndef __HTEA__
#define __HTEA__

#include "prime_list.h"

enum estado_noh{
    EN_LIVRE,
    EN_OCUPADO,
    EN_APAGADO
};

enum probing_strategy{
    PS_LINEAR,
    PS_RANDOM,
    PS_QUADRATIC,
    PS_DOUBLE,
};

typedef struct htea_noh{
    int chave;
    int valor;
    enum estado_noh estado;
}htea_noh;

typedef struct htea_ea{
    enum probing_strategy ps;
    htea_noh* t;
    int m;
    int n;
    prime_list_t* pl;
    int max_n;
    const char* prime_list_file;
    int (*probe_func)(struct htea_ea*, int, int);
    int (*next_m_func)(struct htea_ea*);
    void (*probe_delete_func)(struct htea_ea*);

    //atributos para o random probing.
    int* rp_P;
}htea_ea;

htea_ea* HTEA_Criar(int m, const char* prime_list, 
    enum probing_strategy ps);
int HTEA_Inserir(htea_ea** HT, int chave, int valor);
int HTEA_Remover(htea_ea* HT, int chave);
int HTEA_Buscar(htea_ea* HT, int chave);
htea_ea* HTEA_Redim(htea_ea* HT, int novo_m);
int HTEA_Hash(htea_ea* HT, int chave, int k);
void HTEA_Destroy(htea_ea* HT);

#endif