#include "utils.h"

int partition(int *v, int p, int r)
{
    int x = v[r];
    int i = p-1;
    for(int j = p; j < r; j++)
    {
        if(v[j] <= x)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);
    return i+1;
}

void quicksort_(int *v, int e, int d)
{
    if(e < d)
    {
        int q = partition(v, e, d);
        quicksort_(v, e, q-1);
        quicksort_(v, q+1, d);
    }
}

void quicksort(int *v, int n)
{
    quicksort_(v, 0, n-1);
}