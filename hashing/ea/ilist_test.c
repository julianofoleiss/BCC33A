#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"

int main(int argc, char** argv){
    
    int n;    
    int seed = 0;

    n = argv[1] ? atoi(argv[1]) : 10;

    srand(seed);

    ILIST* L;
    int i;
    int chave;
    L = ILIST_Criar(3);

    for(i = 0; i < n; i++){
        chave = rand() % (n*1);
        printf("%d\n", chave);
        ILIST_Inserir(L, chave, chave * 2);
        //ILIST_Imprimir(L, 1);
    }

    ILIST_Imprimir(L, 1);

    ILIST_Remover(L, 3);
    ILIST_Imprimir(L, 1);
    ILIST_Remover(L, 3);
    ILIST_Imprimir(L, 1);
    ILIST_Remover(L, 1);
    ILIST_Imprimir(L, 1);
    ILIST_Remover(L, 1);
    ILIST_Imprimir(L, 1);
    ILIST_Remover(L, 5);
    ILIST_Imprimir(L, 1);    

    for(i = 0; i < n; i++){
        chave = rand() % (n*1);
        if(i == 9)
            chave = 8;
        printf("%d\n", chave);
        ILIST_Inserir(L, chave, chave * 2);
        ILIST_Imprimir(L, 1);
    }

    printf("%d\n", n);

}
