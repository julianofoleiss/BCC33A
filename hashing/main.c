#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ea.h"

int collisions = 0;

int main(int argc, char** argv){
    
    int n, i, chave;    
    enum probing_strategy ps;

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;
    ps = argc > 2 ? atoi(argv[2]) : PS_LINEAR;

    srand(seed);

    htea_ea* ht;

    ht = HTEA_Criar(2, "primes1.dat", ps);

    HTEA_Inserir(&ht, 10, 5);
    HTEA_Inserir(&ht, 11, 7);
    HTEA_Inserir(&ht, 3, 7);

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        HTEA_Inserir(&ht, chave, chave + (rand() % 10));
    }

    printf("collisions = %d\n", collisions);

}
