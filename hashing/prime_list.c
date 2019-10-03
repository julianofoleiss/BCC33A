#include <stdio.h>
#include <stdlib.h>
#include "prime_list.h"

void PL_Create(const char* txt_prime_list, const char* output_filename){

    FILE* input;
    FILE* output;
    char buffer[20];
    int* out_buffer;
    int nread;

    out_buffer = malloc(sizeof(int) * 1000001);

    input = fopen(txt_prime_list, "r");

    while(fgets(buffer, 20, input) != NULL){
        out_buffer[nread] = atoi(buffer);
        nread++;        
    }

    output = fopen(output_filename, "w");

    fwrite(out_buffer, sizeof(int), nread+1, output);

    printf("%d\n", nread);

    free(out_buffer);
}

int binary_search(int* v, int ini, int fim, int x){
    int m;
    
    if(ini < fim){
        m = (ini + fim)  /2;
        if(v[m] == x){
            return m;
        }
        else{
            if(x > v[m]){
                return binary_search(v, m+1, fim, x);
            }
            else{
                return binary_search(v, ini, m-1, x);
            }
        }
    }
    else{
        return ini;
    }
}

prime_list_t* PL_Load(const char* prime_data){
    prime_list_t* n;
    FILE* prime_input;

    n = malloc(sizeof(prime_list_t));
    n->n = 1000000;
    n->PL = malloc(sizeof(int) * n->n);

    prime_input = fopen(prime_data, "r");
    fread(n->PL, sizeof(int), n->n, prime_input);

    return n;
}

int PL_NextPrime(prime_list_t* pl, int n){
    int idx;
    idx = binary_search(pl->PL, 0, pl->n-1, n);
    return pl->PL[idx+1];
}

void PL_Destroy(prime_list_t* pl){
    free(pl->PL);
    free(pl);
}