#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

//#define AVLDEBUG

AAVL AAVL_Criar(int dado, AAVL esq, AAVL dir){
    AAVL a;
    
    a = malloc(sizeof(struct AAVL));
    a->dado = dado;
    a->esq = esq;
    a->dir = dir;
    a->fat_bal = 0;
}

void RotDir(AAVL A){
    AAVL p, u, t;
    
    p = A;
    u = p->esq;
    t = u->dir;
    u->dir = p;
    p->esq = t;
    
    return;
}

void RotEsq(AAVL A){
    AAVL p, z, t;
    
    p = A;
    z = p->dir;
    t = z->esq;
    z->esq = p;
    p->dir = t;
    
    return;
}

void CasoE(AAVL *A, int *verificar){
    AAVL p, u, v;

    p = *A;
    u = p->esq;

    if(u->fat_bal == -1){
        //Caso E E
        #ifdef AVLDEBUG
            printf("Caso E E, Rotação D\n");
        #endif
        RotDir(*A);
        *A = u;
        p->fat_bal = 0;
    }
    else{
        //Caso E D
        #ifdef AVLDEBUG
            printf("Caso E D, Rotação E(u), D(p)\n");
        #endif          
        v = u->dir;
        RotEsq(u);
        p->esq = v;
        RotDir(p);

        if(v->fat_bal == -1) 
            p->fat_bal = 1;
        else
            p->fat_bal = 0;

        if(v->fat_bal == 1)
            u->fat_bal = -1;
        else
            u->fat_bal = 0;

        *A = v;
    }
    (*A)->fat_bal = 0;
    *verificar = 0;
}

void CasoD(AAVL *A, int *verificar){
    AAVL p, z, y;

    p = *A;
    z = p->dir;

    if(z->fat_bal == 1){
        //Caso D D
        #ifdef AVLDEBUG
            printf("Caso D D, Rotação E\n");
        #endif        
        RotEsq(*A);
        *A = z;
        p->fat_bal = 0;
    }
    else{
        //Caso D E
        #ifdef AVLDEBUG
            printf("Caso D E, Rotação D(z), E(p)\n");
        #endif              
        y = z->esq;
        RotDir(z);
        p->dir = y;
        RotEsq(p);

        if(y->fat_bal == 1) 
            p->fat_bal = -1;
        else
            p->fat_bal = 0;

        if(y->fat_bal == -1)
            z->fat_bal = 1;
        else
            z->fat_bal = 0;

        *A = y;
    }
    (*A)->fat_bal = 0;
    *verificar = 0;
}

void AAVL_InserirR(AAVL *A, int dado, int *verificar){
    if(*A == NULL){
        *A = AAVL_Criar(dado, NULL, NULL);
        *verificar = 1;
    }
    else{
        //Chave repetida
        if(dado == (*A)->dado){
            *verificar = 0;
            return;
        }
        
        if(dado < (*A)->dado){
            AAVL_InserirR(&(*A)->esq, dado, verificar);

            if(*verificar){
                switch((*A)->fat_bal){
                    case 1:
                        (*A)->fat_bal = 0;
                        *verificar = 0;
                        break;
                    case 0:
                        (*A)->fat_bal = -1;
                         break;
                    case -1:
                        CasoE(A, verificar);
                        break;
                }
            }

        }
        else{
            AAVL_InserirR(&(*A)->dir, dado, verificar);

            if(*verificar){
                switch((*A)->fat_bal){
                    case 1:
                        CasoD(A, verificar);
                        break;                    
                    case 0:
                        (*A)->fat_bal = 1;
                         break;
                    case -1:
                        (*A)->fat_bal = 0;
                        *verificar = 0;
                        break;
                }
            }

        }

    }
}

void AAVL_Inserir(AAVL *A, int dado){
    int verificar;
    
    verificar = 0;
    AAVL_InserirR(A, dado, &verificar);
}

void AAVL_Imprimir(AAVL A, int nivel, char lado){
    int i;
    for(i = 0; i < nivel; i++)
        printf("-->");
    if(A == NULL){
        printf("(%c)NONE\n", lado);
        return;
    }
    printf("(%c) %d [%d]\n" , lado, A->dado, A->fat_bal);
    AAVL_Imprimir(A->esq, nivel+1, 'e');
    AAVL_Imprimir(A->dir, nivel+1, 'd');
}
