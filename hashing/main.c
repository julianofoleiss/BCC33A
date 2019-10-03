#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ea.h"

int main(int argc, char** argv){
    
    int n, i, chave;    
    int seed = 0;

    n = argv[1] ? atoi(argv[1]) : 10;

    srand(seed);

    htea_ea* ht;

    ht = HTEA_Criar(3, "primes1.dat", PS_LINEAR);

    HTEA_Inserir(&ht, 10, 5);
    HTEA_Inserir(&ht, 11, 7);
    HTEA_Inserir(&ht, 3, 7);

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        HTEA_Inserir(&ht, chave, chave + (rand() % 10));
    }

    printf("%d\n", n);

}
