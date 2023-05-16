#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"
#include "utils.h"

/*
    Retorna um novo vetor de inteiros com os elementos de v, mas sem repetições.
    n é o tamanho de v, e returnSize é um parâmetro de saída que deve ser
    atualizado com o tamanho do vetor retornado.
*/
int* dedup(int* v, int n, int* returnSize){

}

/*
    Imprime o número de ocorrências de cada elemento de v.
*/
void print_counts(int* v, int n){

}

/*
    Dado um vetor v com n elementos, indicar nos parâmetros de saída n1 e n2 
    dois elementos de v que somados são iguais a x. Caso não existam tais elementos,
    retornar false. Caso contrário, retornar true.
*/
bool twosum(int* v, int n, int x, int* n1, int* n2){

}


int main(int argc, char** argv){

    //Teste dedup
    // int v[] = {1, 5, 2, 1, 1, 1, 6, 7, 2, 5};
    // int n = sizeof(v)/sizeof(int);
    // int returnSize;
    // int* ret = dedup(v, n, &returnSize);
    // imprimir_vetor(ret, returnSize);
    // free(ret);

    //Teste print_counts
    // int v[] = {1, 5, 2, 1, 1, 1, 6, 7, 2, 5};
    // int n = sizeof(v)/sizeof(int);
    // print_counts(v, n);

    //Teste twosum
    // int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int n = sizeof(v)/sizeof(int);
    // int n1, n2;
    // if(twosum(v, n, 10, &n1, &n2))
    //     printf("%d + %d = 10\n", n1, n2);
    // else
    //     printf("Não existe\n");
    // return 0;

    return 0;
}