#pragma once

typedef enum ASCIITrie_ESTADO{
    ATE_LIVRE,
    ATE_OCUPADO
} ASCIITrie_ESTADO;

typedef struct ASCIITrie{
    int val;
    ASCIITrie_ESTADO estado;
    struct ASCIITrie* filhos[256];
} ASCIITrie;

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char *chave);
void AT_Inserir(ASCIITrie **T, unsigned char *chave, 
    int val);
ASCIITrie* AT_Criar();
void AT_Remover(ASCIITrie **T, unsigned char *chave);
void AT_Imprimir(ASCIITrie* T);