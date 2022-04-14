#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lista_palavras.h"

int main(int argc, char** argv)
{
    Lista_Palavras* lp = LP_Carregar("br.txt");
    LP_OrdenarPorPalavraOrd(lp);
    LP_ImprimirAnagramas(lp, argv[1]);
    LP_Destruir(lp);

    return EXIT_SUCCESS;
}



