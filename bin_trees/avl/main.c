#include <stdio.h>

#include "avl.h"

int main(int argc, char** argv){
   
    AAVL* A = NULL;
    
    // Exemplo E E
    // AAVL_Inserir(&A, 10, 10);
    // AAVL_Inserir(&A, 5, 5);
    // AAVL_Inserir(&A, 15, 15);
    // AAVL_Inserir(&A, 3, 3);
    // AAVL_Inserir(&A, 0, 0);
    // AAVL_Inserir(&A, -1, -1);

    // Exemplo E E
    // AAVL_Inserir(&A, 7, 1);
    // AAVL_Inserir(&A, 6, 1);
    // AAVL_Inserir(&A, 5, 1);
    // AAVL_Inserir(&A, 4, 1);
    // AAVL_Inserir(&A, 3, 1);
    // AAVL_Inserir(&A, 2, 1);
    // AAVL_Inserir(&A, 1, 1);    

    // Exemplo D D
    // AAVL_Inserir(&A, 10, 10);
    // AAVL_Inserir(&A, 5, 5);
    // AAVL_Inserir(&A, 15, 15);
    // AAVL_Inserir(&A, 30, 30);
    // AAVL_Inserir(&A, 40, 40);
    // AAVL_Inserir(&A, 45, 45);

    // Exemplo D D
    // AAVL_Inserir(&A, 1, 1);
    // AAVL_Inserir(&A, 2, 1);
    // AAVL_Inserir(&A, 3, 1);
    // AAVL_Inserir(&A, 4, 1);
    // AAVL_Inserir(&A, 5, 1);
    // AAVL_Inserir(&A, 6, 1);
    // AAVL_Inserir(&A, 7, 1);
    
    // Exemplos E D
    // AAVL_Inserir(&A, 13, 13);
    // AAVL_Inserir(&A, 10, 10);
    // AAVL_Inserir(&A, 15, 15);
    // AAVL_Inserir(&A, 5, 5);
    // AAVL_Inserir(&A, 11, 11);
    // AAVL_Inserir(&A, 16, 16);
    // AAVL_Inserir(&A, 4, 4);
    // AAVL_Inserir(&A, 6, 6);
    // AAVL_Inserir(&A, 7, 7);

    // AAVL_Inserir(&A, 13, 13);
    // AAVL_Inserir(&A, 10, 10);
    // AAVL_Inserir(&A, 15, 15);
    // AAVL_Inserir(&A, 7, 7);
    // AAVL_Inserir(&A, 11, 11);
    // AAVL_Inserir(&A, 16, 16);
    // AAVL_Inserir(&A, 4, 4);
    // AAVL_Inserir(&A, 9, 9);
    // AAVL_Inserir(&A, 8, 8);

    // Exemplos D E
    // AAVL_Inserir(&A,40, 40);
    // AAVL_Inserir(&A,20, 20);
    // AAVL_Inserir(&A,70, 70);
    // AAVL_Inserir(&A,53, 53);
    // AAVL_Inserir(&A,84, 84);
    // AAVL_Inserir(&A,50, 60);

    //Essa função mostra uma representação textual da árvore no terminal
    //AAVL_Imprimir(A);

    /*Essa função gera uma representação visual em formato .dot
    No linux tem um programa chamado xdot que abre esse arquivo.*/
    //AAVL_GenDOT(A, "exemplo.dot");


}
