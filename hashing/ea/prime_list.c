#include <stdio.h>
#include <stdlib.h>
#include "prime_list.h"

/*
    Converte um arquivo-texto contento um número primo por linha (já ordenado)
    em um arquivo binário. n_primes é o número de primos que se deseja salvar na saída.
*/
void PL_Create(const char* txt_prime_list, const char* output_filename, int n_primes){

    FILE* input;
    FILE* output;
    char buffer[20];
    int* out_buffer;
    int nread;

    out_buffer = malloc(sizeof(int) * n_primes);

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

static int binary_search(int* v, int ini, int fim, int x){
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

/*
    Carrega uma lista de números primos em formato binário 
    (inteiros de 4 bytes como em primes1.dat) e retorna uma 
    estrutura dinâmica prime_list_t, que representa uma lista
    de primos que pode ser pesquisada de forma eficiente
    usando PL_NextPrime. (primes1.dat tem 1000000 números primos)
*/
prime_list_t* PL_Load(const char* prime_data, int n_primes){
    prime_list_t* n;
    FILE* prime_input;

    n = malloc(sizeof(prime_list_t));
    n->n = n_primes;
    n->PL = malloc(sizeof(int) * n->n);

    prime_input = fopen(prime_data, "r");
    fread(n->PL, sizeof(int), n->n, prime_input);

    return n;
}

/*
    Retorna o próximo número primo após n. Recebe uma lista de primos
    carregada usando PL_Load. Complexidade: O(lg(pl->n)).
*/
int PL_NextPrime(prime_list_t* pl, int n){
    int idx;
    idx = binary_search(pl->PL, 0, pl->n-1, n);
    return pl->PL[idx+1];
}

/*
    Desaloca os recursos usados pela lista de primos pl.
*/
void PL_Destroy(prime_list_t* pl){
    free(pl->PL);
    free(pl);
}