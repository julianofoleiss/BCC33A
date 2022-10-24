#include <stdio.h>
#include <stdlib.h>

#include "hashtable_ea.h"

int* intersecao(int* a, int nA, int* b, int nB, size_t* nSaida){

}

int* uniao(int* a, int nA, int* b, int nB, size_t* nSaida){

}

int* diferenca(int* a, int nA, int* b, int nB, size_t* nSaida){

}

int* diferenca_simetrica(int* a, int nA, int* b, int nB, size_t* nSaida){

}

void imprimir_vetor(int *v, int n){
    printf("n = %d\n", n);
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int* vetor_aleatorio(int n, int max, int seed){
    int* saida = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        saida[i] = rand() % max;
    }
    return saida;
}

int main(int argc, char** argv){

    //Teste 1

    int a[] = {1, 4, 2, 3, 1, 1, 5};
    int b[] = {1, 7, 0, 2};
    size_t n = 0;
    int *i = intersecao(a, 7, b, 4, &n);
    imprimir_vetor(i, n);

    size_t nu = 0;
    int *u = uniao(a, 7, b, 4, &nu);
    imprimir_vetor(u, nu);

    size_t nd = 0;
    int *d = diferenca(a, 7, b, 4, &nd);
    imprimir_vetor(d, nd);

    size_t nds = 0;
    int *ds = diferenca_simetrica(a, 7, b, 4, &nds);
    imprimir_vetor(ds, nds);    

    //Teste 2

    // int* x = vetor_aleatorio(1000, 10000, 0);
    // int* y = vetor_aleatorio(1000, 10000, 0);
    // size_t nz = 0;
    // int *z = intersecao(x, 1000, y, 1000, &nz);
    // imprimir_vetor(z, nz);


    return 0;
}
