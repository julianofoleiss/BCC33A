#pragma once

typedef enum {
    C_VERMELHO,
    C_PRETO
} ARN_COR;

typedef struct NOH{
    int chave;
    int valor;
    struct NOH *esq, *dir;
    ARN_COR cor;
}NOH;

typedef struct ARN{
    NOH* raiz;
}ARN;

ARN* ARN_Criar();

// Retorna o endereço no nó que contém a chave na árvore A.
// Caso a chave não esteja na árvore, retorna NULL
NOH* ARN_Buscar(ARN* A, int chave);


// Insere o par (chave, valor) na árvore A. 
// Caso a chave já esteja na árvore, o valor é atualizado.
void ARN_Inserir(ARN*A , int chave, int valor);

// Imprime a árvore 
void ARN_Imprimir(ARN* A);

// Desaloca toda memória alocada para a árvore
void ARN_Destruir(ARN* A);

// Retorna a altura da árvore rubro-negra
int ARN_Altura(ARN* A);
