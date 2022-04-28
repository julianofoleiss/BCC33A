#include "prime_list.h"
#include <stdio.h>

int main(int argc, char** argv){
    //PL_Create("primes1_strip.txt", "primes1.dat");
    prime_list_t* pl;
    pl = PL_Load("primes1.dat", 1000000);

    printf("%d\n", PL_NextPrime(pl, 1000));
}
