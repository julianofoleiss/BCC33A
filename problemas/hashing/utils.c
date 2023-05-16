#include <stdlib.h>
#include <stdio.h>

int busca(int *v, int n, int x){
    for(int i = 0; i < n; i++){
        if(v[i] == x)
            return i;
    }
    return -1;
}

void imprimir_vetor(int *v, int n){
    printf("n = %d\n", n);
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int* vetor_aleatorio(int n, int max, int seed){
    srand(seed);
    int* saida = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        saida[i] = rand() % max;
    }
    return saida;
}