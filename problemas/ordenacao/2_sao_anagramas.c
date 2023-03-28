#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utils.h"

#define DEBUG 1

// retorna true se s e t são anagramas. Caso contrário, retorna false.
// s e t são strings terminadas em 0.
bool sao_anagramas(char *s, char *t){
    return false;
}

int main(int argc, char** argv){
    char* s1 = malloc(sizeof(char) * (strlen(argv[1])+1));
    char* s2 = malloc(sizeof(char) * (strlen(argv[2])+1));

    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    #if DEBUG
    printf("%u\n", sao_anagramas(s1, s2) ? 1 : 0);
    #endif
    
    return EXIT_SUCCESS;
}