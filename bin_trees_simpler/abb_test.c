#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

void test1(int argc, char** argv){

    ABB* a = ABB_Criar();

    ABB_Inserir(a, 40, 41);
    ABB_Inserir(a, 40, 42);
    ABB_Inserir(a, 20, 23);
    ABB_Inserir(a, 17, 0);
    ABB_Inserir(a, 50, 2);

    ABB_Imprimir(a);

    ABB_Destruir(a);
}

void test2(int argc, char** argv){

    int n = argc > 1 ? atoi(argv[1]) : 10;

    srand(1);

    ABB* a = ABB_Criar();

    for(int i = 0; i < n; i++){
        int chave = (rand() % (n*10));
        int valor = (rand() % (n*100));

        printf("Inserindo a chave %d e valor %d na árvore\n", chave, valor);
        ABB_Inserir(a, chave, chave);
    }

    ABB_Imprimir(a);

    ABB_Destruir(a);
}

void test3(int argc, char** argv){

    ABB* a = ABB_Criar();

    ABB_Inserir(a, 40, 41);
    ABB_Inserir(a, 40, 42);
    ABB_Inserir(a, 20, 23);
    ABB_Inserir(a, 17, 0);
    ABB_Inserir(a, 50, 2);
    ABB_Inserir(a, 60, 2);

    ABB_Imprimir(a);

    ABB_Remover(a, 40);
    ABB_Imprimir(a);

    ABB_Remover(a, 20);
    ABB_Imprimir(a);

    ABB_Remover(a, 50);
    ABB_Imprimir(a);

    ABB_Remover(a, 60);
    ABB_Imprimir(a);    

    ABB_Remover(a, 17);
    ABB_Imprimir(a);    

    ABB_Destruir(a);
}

void test4(int argc, char** argv){

    ABB* a = ABB_Criar();

    ABB_Inserir(a, 40, 41);
    ABB_Inserir(a, 40, 42);
    ABB_Inserir(a, 20, 23);
    ABB_Inserir(a, 17, 0);
    ABB_Inserir(a, 50, 2);

    ABB_Imprimir(a);
    
    NOH* r = ABB_Buscar(a, 40);
    printf("%d\n", r ? r->chave : -1);

    r = ABB_Buscar(a, 20);
    printf("%d\n", r ? r->chave : -1);    

    r = ABB_Buscar(a, 17);
    printf("%d\n", r ? r->chave : -1);        

    r = ABB_Buscar(a, 50);
    printf("%d\n", r ? r->chave : -1);        

    r = ABB_Buscar(a, 0);
    printf("%d\n", r ? r->chave : -1);        

    ABB_Destruir(a);
}


int main(int argc, char** argv){
    // test1(argc, argv);
    
    // test2(argc, argv);

    // test3(argc, argv);

    // test4(argc, argv);

    return 0;
}