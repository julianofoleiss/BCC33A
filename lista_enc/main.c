#include "lista_int.h"

int main(int argc, char** argv){
    T_LINT* L;
    L = LINT_criar();
    LINT_inserir(L, 9);
    LINT_inserir(L, 3);

    return 0;
}
