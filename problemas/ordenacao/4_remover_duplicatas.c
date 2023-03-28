#include <stdlib.h>
#include "utils.h"

#define DEBUG 1

// retorna um vetor com os elementos de v, sem duplicatas.
// os elementos no vetor de saída não precisam preservar a ordem da entrada.
// o número de elementos do vetor retornado deve ser escrito no parâmetro 
// de saída ns. Caso v esteja vazio, retorne NULL e *ns = 0.
int* remover_duplicatas(int *v, int n, int* ns){
    *ns = 0;
    return NULL;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);

    int *v = gerar_vetor_aleatorio(n, 42, n * 10);

    #if DEBUG
    imprimir_vetor(v, n);
    #endif

    int ns = 0;
    int* res = remover_duplicatas(v, n, &ns);

    #if DEBUG
    imprimir_vetor(res, ns);
    #endif    

    return EXIT_SUCCESS;

}