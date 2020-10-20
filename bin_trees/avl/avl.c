#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

#define AAVL_DEBUG 1

static AAVL* AAVL_Criar(int chave, int dado){
    AAVL* novo;

    novo = malloc(sizeof(AAVL));
    novo->fb = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->dado = dado;
    novo->chave = chave;

    return novo;
}

static void RotDir(AAVL *A){
    AAVL *p, *u, *t;
    p = A;
    u = p->esq;
    t = u->dir;
    u->dir = p;
    p->esq = t;

    return;
}

static void RotEsq(AAVL *A){
    AAVL *p, *z, *t;
    p = A;
    z = p->dir;
    t = z->esq;
    z->esq = p;
    p->dir = t;

    return;
}

static void CasoE(AAVL **A, int *verificar){
    AAVL *p, *u, *v;
    p = *A;
    u = p->esq;

    if(u->fb == 1){
        #if AAVL_DEBUG
            printf("Caso E, RotDir(p)\n");
        #endif
        // caso E
        RotDir(p);
        *A = u;
        p->fb = 0;

    }
    else{
        #if AAVL_DEBUG
            printf("Caso E D, RotEsq(u), RotDir(p)\n");
        #endif        
        // caso E D
        v = u->dir;
        RotEsq(u);
        //anteriormente p->esq = u. No entanto, após a rotação, v->esq = u, logo p->esq deve apontar para v.
        p->esq = v; 
        
        RotDir(p);
        //Após a rotação p se torna o filho direito de v e v se torna a nova raíz da subárvore.
        *A = v;

        /*PARA ENTENDER A EXPLICAÇÃO ABAIXO, OLHE O ESQUEMA DO CASO E - D COM ATENÇÃO*/

        /*Antes das rotações v é a subárvore mais próxima do novo nó que desbalanceia a árvore.
        Como a inserção aumentou a altura da árvore, isso quer dizer que antes da rotação v->fb = 0.
        Considere que tanto v->esq (t2) quanto v->dir (t3) tinham altura h antes da inserção.
        
        Como t1 e v são filhos de u e ambos filhos de v tem altura h, então t1 tem altura h+1.

        Como antes da inserção subárvore enraizada em p era uma árvore AVL e p vale 2 após a inserção (estamos no caso esquerdo), 
        sabemos que p->dir tinha dois níveis a menos que p->esq. Como a altura da subárvore esquerda de p era h+3 (por conta dos nós u e v mais
        a altura das subárvores t2 ou t3, que é h), então a altura da subárvore p->dir (t4) é h+1.*/

        switch(v->fb){
            case -1:
                /*nesse caso, o novo nó foi inserido na subárvore direita de v, fazendo com que t3 tenha altura h+1 e t2 permaneça com altura h.*/

                /*Como a subarvore esquerda de u (t1) tem altura h+1 e após a rotação o filho direito de u se torna t2, que tem altura h, a subárvore 
                enraizada em u está "pendendo" para a esquerda, resultando em um fator de balanceamento 1. (u->fb = 1)*/
                u->fb = 1;
                /*Após a rotação dupla, p se torna o filho direito de v e t3 se torna filho esquerdo de p. Como o filho direito de p (t4) 
                tinha altura h+1 no início, e t3 também tem altura h+1, logo o fator de balanceamento de p se torna 0 (p->fb = 0).*/                
                p->fb = 0;
                break;

            case 0:
                u->fb = 0;
                p->fb = 0;
                break;

            case 1:
                /*Nesse caso, o novo nó foi inserido na subárvore esquerda de v, fazendo com que t2 teha altura h+1 e t3 permaneça com altura h.*/

                /*Após a rotação dupla, u se torna o filho esquerdo de v e t2 se forna o filho direito de u. Como o filho esquerdo de u (t1) tinha
                altura h+1 no início e o filho direito de u (t2) também tem altura h+1, logo o fator de balanceamtno de u se torna 0 (p->fb = 0).*/
                u->fb = 0;

                /*Como a subárvore direita de p (t4) tem altura h+1 e após a rotação o filho esquerdo de p se torna t3, que tem altura h, a subárvore
                enraizada em p está "pendendo" para a direita, resultado em um fator de balanceamento -1. (p->fb = -1)*/
                p->fb = -1;
                break;
        }
    }
    (*A)->fb = 0;
    *verificar = 0;
}

static void CasoD(AAVL **A, int *verificar){
    AAVL *p, *z, *y;
    p = *A;
    z = p->dir;

    if(z->fb == -1){
        #if AAVL_DEBUG
            printf("Caso D, RotEsq(p)\n");
        #endif
        //caso D
        RotEsq(p);
        *A = z;
        p->fb = 0;
    }
    else{
        #if AAVL_DEBUG
            printf("Caso D E, RotEsq(z), RotDir(p)\n");
        #endif          
        //caso D E

        y = z->esq;
        RotDir(z);

        //anteriormente p->dir = z. No entanto, após a rotação, y->dir = z, logo p->dir deve apontar para y.
        p->dir = y;
        RotEsq(p);

        //Após a rotação p se torna o filho esquerdo de y e y se torna a nova raíz da subárvore.
        *A = y;

        // A explicação dos ajustes aos fatores de balanceamento de z e p é simétrica à explicação dada no caso E D. (tente explicar como um exercício)
        switch(y->fb){
            case -1:
                z->fb = 0;
                p->fb = 1;
                break;
            case 0:
                z->fb = 0;
                p->fb = 0;
                break;
            case 1:
                z->fb = -1;
                p->fb = 0;
                break;
        }

    }
    (*A)->fb = 0;
    *verificar = 0;
}

static void AAVL_Inserir_R(AAVL **A, int chave, int dado, int *verificar){

    if(*A == NULL){
        *A = AAVL_Criar(chave, dado);
        *verificar = 1;
        return;
    }

    if(chave == (*A)->chave){
        (*A)->dado = dado;
        *verificar = 0;
        return;
    }

    if(chave < (*A)->chave){
        AAVL_Inserir_R(&(*A)->esq, chave, dado, verificar);
        /*voltando de uma possível inserção na esquerda. Caso a inserção
        tenha sido efetuada, atualizar o fator de balanceamento do nó
        A idéia é somar 1 no fator de balanceamento pq a subárvore esquerda de A
        aumentou.*/
        if(*verificar){
            switch((*A)->fb){
                case -1:
                    /*A inserção deixou a subárvore perfeitamente balanceada
                    não é necessário mais verificar.*/
                    (*A)->fb = 0;
                    *verificar = 0;
                    break;
                case 0:
                    /*A subarvore estava perfeitamente balanceada, agora está "pendendo"
                    para o lado esquerdo. é necessário continuar verificando*/
                    (*A)->fb = 1;
                    break;                    
                case 1:
                    /*Como a subárvore já está "pendendo" para o lado esquerdo, o novo nó acabou
                    de deixar a árvore desbalanceada (fb+1 = 2). Portanto, é necessário balancear a subárvore*/
                    CasoE(A, verificar);
                    break;
            }
        }
    }
    else{
        AAVL_Inserir_R(&(*A)->dir, chave, dado, verificar);

        /*voltando de uma possível inserção na direita. Caso a inserção
        tenha sido efetuada, atualizar o fator de balanceamento do nó
        A idéia é somar -1 no fator de balanceamento pq a subárvore direita de A
        aumentou.*/
        if(*verificar){
            switch((*A)->fb){
                case -1:
                    /*Como a subárvore já está "pendendo" para o lado direito, o novo nó acabou
                    de deixar a árvore desbalanceada (fb-1 = -2). Portanto, é necessário balancear a subárvore*/
                    CasoD(A, verificar);                    
                    break;
                case 0:
                    /*A subarvore estava perfeitamente balanceada, agora está "pendendo"
                    para o lado direito. é necessário continuar verificando*/
                    (*A)->fb = -1;
                    break;                    
                case 1:
                    /*A inserção deixou a subárvore perfeitamente balanceada
                    não é necessário mais verificar.*/
                    (*A)->fb = 0;
                    *verificar = 0;
                    break;
            }
        
        }
    }

}

void AAVL_Inserir(AAVL** A, int chave, int dado){
    int verificar = 0;
    AAVL_Inserir_R(A, chave, dado, &verificar);
}

static void AAVL_Imprimir_R(AAVL *A, int nivel, char lado){
    int i;
    if(A == NULL)
        return;
    for(i = 0 ; i < nivel; i++) printf(" ");
    printf("(%c) %d [%d]\n", lado, A->chave, A->fb);
    AAVL_Imprimir_R(A->esq, nivel+1, 'e');
    AAVL_Imprimir_R(A->dir, nivel+1, 'd');
}

void AAVL_Imprimir(AAVL *A){
    AAVL_Imprimir_R(A, 0, 'r');
}


static int AAVL_GenDOT_R(AAVL *A, FILE* saida, int *id){
    int e, d, me;

    if(A == NULL)
        return 0;

    e = AAVL_GenDOT_R(A->esq, saida, id);
    d = AAVL_GenDOT_R(A->dir, saida, id);

    me = (*id)++;

    fprintf(saida, "%d [label=\"%d\n(%d)\"];\n", me, A->chave, A->fb);

    if(e || d){
        if(e)
            fprintf(saida, "%d -> %d [label=\"esq\"];\n", me, e);
        if(d)
            fprintf(saida, "%d -> %d [label=\"dir\"];\n", me, d);
    }

    return me;

}

void AAVL_GenDOT(AAVL *A, const char* arq_saida){

    FILE* saida;
    int id = 1;

    saida = fopen(arq_saida, "w");

    fprintf(saida, "digraph G {\n");

    AAVL_GenDOT_R(A, saida, &id);

    fprintf(saida, "}\n");

    fclose(saida);

}