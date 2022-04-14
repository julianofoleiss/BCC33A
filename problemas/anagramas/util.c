#include "lista_palavras.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
size_t contar_linhas(char* dicionario)
{
    FILE* arq;
    char buf[TAM_MAX_PALAVRA+1];
    arq = fopen(dicionario, "r");
    size_t n = 0;
    while(fgets(buf, TAM_MAX_PALAVRA+1, arq))
        n++;
    fclose(arq);
    return n;
}

void ordenar_palavra(char* palavra)
{
    size_t n = strlen(palavra);
    int i, j;
    char maior;
    for(i = n-1; i > 0; i--){
        maior = 0;
        for(j = 1; j <= i; j++)
        {
            if(palavra[j] > palavra[maior])
                maior = j;
        }
        char aux = palavra[maior];
        palavra[maior] = palavra[i];
        palavra[i] = aux;
    }
}

char* stolower(char* s)
{
    char* p = s;
    while(*p){
        *p = (char)tolower(*p);
        p++;
    }
    return s;
}