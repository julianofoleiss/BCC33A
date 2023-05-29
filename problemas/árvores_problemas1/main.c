#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "abb.h"

/*
    Retorna a maior chave da ABB A.
*/
int ABB_Max(ABB* A){
    
}

/*
    Retorna a menor chave da ABB A.
*/
int ABB_Min(ABB* A){
    
}

/*
    Retorna o número de nós da ABB A.
*/
int ABB_N(ABB* A){
    
}

/*
    Calcula a altura da ABB A. 
    A altura de uma ABB é o número de arestas do caminho mais longo 
    entre a raiz até alguma folha.
*/
int ABB_Altura(ABB* A){
    
}

/*
    Retorna o k-ésimo menor elemento da ABB A.
    O k-ésimo menor elemento é o k-ésimo elemento quando os elementos
    da ABB são ordenados em ordem crescente.
*/
int ABB_KesimoMenor(ABB* A, int k){
    
}

/*
    Uma ABB é dita balanceada se para todo nó, a diferença entre as alturas
    de suas subárvores esquerda e direita é no máximo 1.

    Retorne true se a ABB A é balanceada e false caso contrário.
*/
bool ABB_Balanceada(ABB* A){

}

/////////////////////// TESTES ///////////////////////

void teste_max(){
    ABB *A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 3, 3);
    ABB_Inserir(A, 7, 7);
    ABB_Inserir(A, 1, 1);
    ABB_Inserir(A, 4, 4);
    ABB_Inserir(A, 6, 6);
    ABB_Inserir(A, 9, 9);
    ABB_Inserir(A, 0, 0);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 8, 8);
    ABB_Imprimir(A);
    printf("Máximo: %d\n", ABB_Max(A)); // 9
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Imprimir(A);
    printf("Máximo: %d\n", ABB_Max(A)); // 5
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Imprimir(A);
    printf("Máximo: %d\n", ABB_Max(A)); // -1
    ABB_Destruir(A);   
}

void teste_min(){
    ABB *A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 3, 3);
    ABB_Inserir(A, 7, 7);
    ABB_Inserir(A, 1, 1);
    ABB_Inserir(A, 4, 4);
    ABB_Inserir(A, 6, 6);
    ABB_Inserir(A, 9, 9);
    ABB_Inserir(A, 0, 0);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 8, 8);
    ABB_Imprimir(A);
    printf("Mínimo: %d\n", ABB_Min(A)); // 0
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Imprimir(A);
    printf("Mínimo: %d\n", ABB_Min(A)); // 5
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Imprimir(A);
    printf("Mínimo: %d\n", ABB_Min(A)); // -1
    ABB_Destruir(A);   
}

void teste_n(){
    ABB *A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 3, 3);
    ABB_Inserir(A, 7, 7);
    ABB_Inserir(A, 1, 1);
    ABB_Inserir(A, 4, 4);
    ABB_Inserir(A, 6, 6);
    ABB_Inserir(A, 9, 9);
    ABB_Inserir(A, 0, 0);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 8, 8);
    ABB_Imprimir(A);
    printf("Número de nós: %d\n", ABB_N(A)); // 10
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Imprimir(A);
    printf("Número de nós: %d\n", ABB_N(A)); // 1
    ABB_Destruir(A);

    A = ABB_Criar();
    ABB_Imprimir(A);
    printf("Número de nós: %d\n", ABB_N(A)); // 0
    ABB_Destruir(A);    

    A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 3, 3);
    ABB_Imprimir(A);
    printf("Número de nós: %d\n", ABB_N(A)); // 2
    ABB_Destruir(A);
}

void teste_altura(){
    //teste 1: 3
    ABB* A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 15, 15);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 1, 1);
    ABB_Imprimir(A);
    printf("Altura: %d\n", ABB_Altura(A)); // 3
    ABB_Destruir(A);

    //teste 2: 0
    A = ABB_Criar();
    ABB_Imprimir(A);
    printf("Altura: %d\n", ABB_Altura(A)); // 0
    ABB_Destruir(A);

    //teste 3: 0
    A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Imprimir(A);
    printf("Altura: %d\n", ABB_Altura(A)); // 0
    ABB_Destruir(A);

    //teste 4: 1
    A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Inserir(A, 5, 5);
    ABB_Imprimir(A);
    printf("Altura: %d\n", ABB_Altura(A)); // 1
    ABB_Destruir(A);
}

void teste_kesimo(){
    ABB *A = ABB_Criar();
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 3, 3);
    ABB_Inserir(A, 7, 7);
    ABB_Inserir(A, 1, 1);
    ABB_Inserir(A, 4, 4);
    ABB_Inserir(A, 6, 6);
    ABB_Inserir(A, 9, 9);
    ABB_Inserir(A, 0, 0);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 8, 8);

    printf("o 3º menor elemento é: %d\n", ABB_KesimoMenor(A, 3)); // 2
    printf("o 5º menor elemento é: %d\n", ABB_KesimoMenor(A, 5)); // 4
    printf("o 7º menor elemento é: %d\n", ABB_KesimoMenor(A, 7)); // 6
    printf("o 1º menor elemento é: %d\n", ABB_KesimoMenor(A, 1)); // 0

    ABB_Destruir(A);
}

void teste_balanceada(){

    //Teste 1: Não-balanceada
    ABB* A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 15, 15);
    ABB_Inserir(A, 2, 2);
    ABB_Inserir(A, 1, 1);
    ABB_Imprimir(A);
    printf("Árvore Balanceada? %s\n", ABB_Balanceada(A) ? "Sim" : "Não");
    ABB_Destruir(A);

    //Teste 2: Balanceada
    A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Inserir(A, 5, 5);
    ABB_Inserir(A, 15, 15);
    ABB_Inserir(A, 2, 2);
    ABB_Imprimir(A);
    printf("Árvore Balanceada? %s\n", ABB_Balanceada(A) ? "Sim" : "Não");
    ABB_Destruir(A);

    //Teste 3: Balanceada
    A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Imprimir(A);
    printf("Árvore Balanceada? %s\n", ABB_Balanceada(A) ? "Sim" : "Não");
    ABB_Destruir(A);

    //Teste 4: Balanceada
    A = ABB_Criar();
    ABB_Imprimir(A);
    printf("Árvore Balanceada? %s\n", ABB_Balanceada(A) ? "Sim" : "Não");
    ABB_Destruir(A);

    //Teste 5: Balanceada
    A = ABB_Criar();
    ABB_Inserir(A, 10, 10);
    ABB_Inserir(A, 5, 5);    
    ABB_Imprimir(A);
    printf("Árvore Balanceada? %s\n", ABB_Balanceada(A) ? "Sim" : "Não");
    ABB_Destruir(A);    
}

int main(int argc, char** argv){

    //Testes ABB_Max
    //teste_max();

    //Testes ABB_Min
    //teste_min();

    //Testes ABB_N
    //teste_n();

    //Testes ABB_Altura
    //teste_altura();

    //Testes ABB_KesimoMenor
    //teste_kesimo();

    //Testes ABB_Balanceada
    //teste_balanceada();

    return 0;
}