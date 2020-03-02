#include "lst.h"
#include <stdlib.h>
#include <stdio.h>

ILISTA* LST_Criar(){
    ILISTA* novo;

    //Alocar memória para a cabeça da lista
    novo = malloc(sizeof(ILISTA));

    //Inicializar a lista vazia
    novo->primeiro = NULL;
    novo->ultimo = NULL;
    novo->tamanho = 0;

    //Retorna o endereço da estrutura alocada
    return novo;
}

int LST_Vazia(ILISTA* L){
    //O tamanho da lista é diferente de zero? Se sim, a lista
    // não é vazia, caso contrário, é vazia.
    return L->tamanho ? 0 : 1;
}

int LST_Tamanho(ILISTA* L){
    return L->tamanho;
}

int LST_Inserir(ILISTA* L, int dado){
    ILISTA_EL* novo;
    int t;

    //A lista está apontando para algum endereço diferente de NULL?
    //Assumimos que se for verdadeiro, foi alocada corretamente.
    if(L != NULL){
        //Alocar um novo nó para guardar o dado
        novo = malloc(sizeof(ILISTA_EL));
        novo->prox = NULL;
        novo->dado = dado;

        //Caso 1: a lista é vazia.
        if(LST_Vazia(L)){
            L->primeiro = novo;
            L->ultimo = novo;

        }
        else{
            //Caso 2: a lista tem pelo menos um elemento.
            //Ligar o último elemento da lista ao novo elemento e
            //atualizar o ponteiro para o último elemento.
            L->ultimo->prox = novo;
            L->ultimo = novo;
        }

        //Atualizar o tamanho da lista
        L->tamanho++;
        return 1;
    }
    return 0;
}

int LST_Buscar(ILISTA* L, int dado){
    ILISTA_EL* p;

    //Se a lista for vazia, não é possível queo item buscado esteja presente.
    if(LST_Vazia(L))
        return 0;

    //Fazer a busca linear pelo elemento
    for(p = L->primeiro; p != NULL; p = p->prox){
        //Caso o elemento for encontrado, retornar 1.
        if(p->dado == dado)
            return 1;
    }

    //Caso todos os elementos forem verificados e não encontramos o dado,
    //retornar 0, indicando que o elemento não está na lista.
    return 0;
}

void LST_Imprimir(ILISTA *L){
    ILISTA_EL* p;

    if(L != NULL){
        //Varrer a lista e imprimir todos os elementos.
        for(p = L->primeiro; p != NULL; p = p->prox){
            printf("%d, ", p->dado );
        }
        printf("\n");
    }
}







