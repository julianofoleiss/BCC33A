#include "exprtree.h"
#include <stdlib.h>

ExprTree* ET_Criar(int dado, ExprTree *e, ExprTree *d){
    ExprTree *n;
    
    n = malloc(sizeof(struct ExprTree));
    n->dado = dado;
    n->esq = e;
    n->dir = d;

    return n;
}

void ET_Destruir(ExprTree *A){
    if(A == NULL)
        return;
    ET_Destruir(A->esq);
    ET_Destruir(A->dir);
    free(A);
}

// static int ET_GenDOT_R(ExprTree *A, FILE* saida, int *id){
//     int e, d, me;

//     if(A == NULL)
//         return 0;

//     e = ET_GenDOT_R(A->esq, saida, id);
//     d = ET_GenDOT_R(A->dir, saida, id);

//     me = (*id)++;

//     if(A->tipo_no == ETTN_CONSTANTE)
//         fprintf(saida, "%d [label=\"%d\"];\n", me, A->dado.constante);
//     else
//         fprintf(saida, "%d [label=\"%c\"];\n", me, A->dado.op);

//     if(e || d){
//         if(e)
//             fprintf(saida, "%d -> %d;\n", me, e);
//         if(d)
//             fprintf(saida, "%d -> %d;\n", me, d);
//     }

//     return me;

// }

// void ET_GenDOT(ExprTree *A, const char* arq_saida){

//     FILE* saida;
//     int id = 1;

//     saida = fopen(arq_saida, "w");

//     fprintf(saida, "digraph G {\n");

//     ET_GenDOT_R(A, saida, &id);

//     fprintf(saida, "}\n");

//     fclose(saida);

// }
