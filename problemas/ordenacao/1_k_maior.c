#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define DEBUG 1

// retorna o k-ésimo maior elemento do vetor.
// pré-condição: o vetor não possui elementos repetidos
// k=1 retorna o maior elemento
// k=2 retorna o segundo maior elemento
// k=....
// k=n retorna o menor elemento
int k_maior(int *v, int n, int k){
    return 0;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    int *v = gerar_vetor_aleatorio_sem_reps(n, 42);

    #if DEBUG
    imprimir_vetor(v, n);
    #endif

    int res = k_maior(v, n, k);

    #if DEBUG
    printf("O %u-ésimo maior elemento do vetor é o %d!\n", k, res);
    #endif    

    return EXIT_SUCCESS;

}