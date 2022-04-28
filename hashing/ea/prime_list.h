#ifndef __PL__
#define __PL__

typedef struct prime_list_t{
    int* PL;
    int n;
}prime_list_t;

void PL_Create(const char* txt_prime_list, const char* output_filename, int n_primes);
prime_list_t* PL_Load(const char* prime_data, int n_primes);
int PL_NextPrime(prime_list_t* pl, int n);
void PL_Destroy(prime_list_t* pl);

#endif