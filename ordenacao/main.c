#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

//Esta função aloca e inicializa um vetor de n inteiros aleatórios
int* gerar_vetor_aleatorio(int n){
    int i;
    int* v;

    //Alocar vetor na heap com n elementos.
    v = malloc(sizeof(int) * n);
    //Inicializar o vetor com numeros aleatórios de 0 a (n*10)-1
    for(i = 0; i < n; i++){
        v[i] = rand() % (n*10);
        #ifdef DEBUG
            printf("%d, ", v[i]);
            fflush(stdout);
        #endif
    }

    return v;
}

void imprimir_vetor(int* v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d, ", v[i]);
        fflush(stdout);
    }
}

int main(int argc, char** argv){
    
    int* v = NULL;
    int n = 0;
    int i;

    //pegar o tamanho do vetor aleatório a ser gerado da linha de comando.
    //No VSCODE, dá pra alterar esse valor no arquivo .vscode/launch.json, na opção "args"
    n = atoi(argv[1]);
    srand(0);

    v = gerar_vetor_aleatorio(n);

    //imprimir_vetor(v, n);

    return 0;
}
