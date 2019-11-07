#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"
#include "shunting_yard.h"
#include "ab.h"
#include "abb.h"
#include "avl.h"

int main(int argc, char** argv){

    // AAVL A = NULL;

    // AAVL_Inserir(&A, 20);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 30);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 40);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 10);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 5);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 15);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    // AAVL_Inserir(&A, 35);
    // AAVL_Imprimir(A, 0, 'r');
    // printf("\n");

    int n;
    int i;
    int r;
    AAVL A = NULL;

    if(argc == 2)
        n = atoi(argv[1]);
    else
        n = 200;

    srand(0);

    for(i = 0; i < n; i++){
        //r = rand() % (n*10);
        r = i;
        //printf("inserindo %d\n", r);
        AAVL_Inserir(&A, r);
    }
    
    //AAVL_Imprimir(A, 0, 'r');

}
