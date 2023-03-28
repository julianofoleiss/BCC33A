#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void trocar(int* v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int* gerar_vetor_aleatorio(int n, int seed, int max){
    int* v = malloc(sizeof(int)*n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v[i] = rand() % max;
    }
    return v;
}

int imprimir_vetor(int* v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void embaralhar(int *array, size_t n, int seed)
{
    srand(seed);
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int* gerar_vetor_aleatorio_sem_reps(int n, int seed){
    int* saida = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        saida[i] = i;
    embaralhar(saida, n, seed);
    return saida;
}


