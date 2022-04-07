#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "prandom.h"

void troca(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int* random_vector(int n, int max, int seed)
{
    srand(seed);
    int* v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        v[i] = rand_() % (max+1);
    }
    return v;
}

void embaralhar(int *v, int ini, int fim)
{
    int i, j;
    for(i = fim-1; i > ini; i--)
    {
        j = rand_() % (i+1);
        j = j < ini ? ini+1 : j;
        troca(v, i, j);
    }
}

int* random_vector_unicos(int n, int seed)
{
    srand(seed);
    int* v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    embaralhar(v, 0, n-1);
    return v;
}

void print_vector(int* v, int n, bool newline)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    if(newline)
        printf("\n");
}