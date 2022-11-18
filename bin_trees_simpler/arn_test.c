#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

//#define DEBUG_PRINT

void test1(int argc, char** argv){
    ARN* A = ARN_Criar();

    ARN_Inserir(A, (int)'U', 0);
    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif
    ARN_Inserir(A, (int)'T', 0);
    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif
    ARN_Inserir(A, (int)'F', 0);
    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif
    ARN_Inserir(A, (int)'P', 0);
    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif
    ARN_Inserir(A, (int)'R', 0);
    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif

    printf("Altura da árvore: %d\n", ARN_Altura(A));

    ARN_Destruir(A);
}

void test2(int argc, char** argv){
    ARN* A = ARN_Criar();

	int n, i, x;
	srand(0);
	
	n = argc < 2 ? 200 : atoi(argv[1]);
	
	for(i = 0; i < n; i++){
		x = rand() % (n*10);
        #ifdef DEBUG_PRINT
        printf("%d, ", x);
        #endif
		ARN_Inserir(A, x, x);
	}

    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif

    printf("Altura da árvore: %d\n", ARN_Altura(A));

    ARN_Destruir(A);
}

void test3(int argc, char** argv){
    ARN* A = ARN_Criar();

	int n, i, x;
	
	n = argc < 2 ? 200 : atoi(argv[1]);
	
	for(i = 0; i < n; i++){
		ARN_Inserir(A, i, i);
	}

    #ifdef DEBUG_PRINT
    ARN_Imprimir(A);
    #endif

    printf("Altura da árvore: %d\n", ARN_Altura(A));

    ARN_Destruir(A);
}

int main(int argc, char **argv){
	test1(argc, argv);
    test2(argc, argv);
	test3(argc, argv);
	return 0;
}