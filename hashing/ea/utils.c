#include <stdlib.h>

static inline void trocar(int* x, int* y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int* criar_vetor_ordenado(int n){
    int* v;
    int i;

    v = malloc(sizeof(int) * n);

    for(i = 0; i < n; i++)
        v[i] = i;
    
    return v;
}

void embaralhar(int *v, int ini, int fim){
    int i, j;

    for(i = fim-1; i > ini; i--){
        j = (rand() % (i + 1));
        j = j <= ini? ini+1 : j;
        trocar(&v[i], &v[j]);
    }

}
