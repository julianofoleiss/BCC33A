#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char** argv){

    int* v;
    int n = 20;
    int i;

    v = criar_vetor_ordenado(n);
    embaralhar(v, 4, n);

    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

}