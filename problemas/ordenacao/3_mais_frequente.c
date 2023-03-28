#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define DEBUG 1

// escreve o número mais frequente de v no parametro de saída mfreq.
// caso mais que um elemento tenha a mesma frequência mais alta, retorne o primeiro deles.
// caso todos os elementos tenham a mesma frequência, retorne false;
// caso contrário, retorne true
bool mais_frequente(int *v, int n, int *mfreq){
    return false;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);

    int *v = gerar_vetor_aleatorio(n, 42, n * 10);

    #if DEBUG
    imprimir_vetor(v, n);
    #endif

    int mfreq = 0;
    bool sucesso = mais_frequente(v, n, &mfreq);

    #if DEBUG
    if(sucesso){
        printf("O elemento mais frequente do vetor é o %d!\n", mfreq);
    }
    else{
        printf("Todos os elementos do vetor possuem a mesma frequência!\n");
    }
    #endif    

    return EXIT_SUCCESS;

}