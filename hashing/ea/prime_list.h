#ifndef __PL__
#define __PL__

typedef struct prime_list_t{
    int* PL;
    int n;
}prime_list_t;

/*
    Converte um arquivo-texto contendo um número primo por linha (já ordenado)
    em um arquivo binário. *n_primes* é o número de primos que se deseja salvar na saída.
*/
void PL_Create(const char* txt_prime_list, const char* output_filename, int n_primes);

/*
    Carrega uma lista de números primos em formato binário 
    (inteiros de 4 bytes como em primes1.dat) e retorna uma 
    estrutura dinâmica prime_list_t, que representa uma lista
    de primos que pode ser pesquisada de forma eficiente
    usando *PL_NextPrime*. (primes1.dat tem 1000000 números primos)
*/
prime_list_t* PL_Load(const char* prime_data, int n_primes);

/*
    Retorna o próximo número primo após *n*. Recebe uma lista de primos
    carregada usando *PL_Load*. Complexidade: O(lg(pl->n)).
*/
int PL_NextPrime(prime_list_t* pl, int n);

/*
    Desaloca os recursos usados pela lista de primos pl.
*/
void PL_Destroy(prime_list_t* pl);

#endif