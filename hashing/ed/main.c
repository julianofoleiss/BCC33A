#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

int main(int argc, char** argv){
    
    int n, m, i, chave;    

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;
    m = argc > 2 ? atoi(argv[2]) : n << 2;

    srand(seed);

    THED* ht;

    ht = THED_Criar(m, 10);

    THED_Inserir(ht, 10, 5);
    THED_Inserir(ht, 11, 7);
    THED_Inserir(ht, 13, 0);

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        THED_Inserir(ht, chave, chave + (rand() % 10));
    }

}
