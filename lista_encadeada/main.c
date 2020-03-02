#include <stdlib.h>

#include "lst.h"

int main(int argc, char** argv){

    ILISTA* L = NULL;

    L = LST_Criar();

    LST_Imprimir(L);

    LST_Inserir(L, 1);

    LST_Imprimir(L);

    LST_Inserir(L, 2);

    LST_Imprimir(L);

    LST_Inserir(L, 3);

    LST_Imprimir(L);

    return 0;
}
