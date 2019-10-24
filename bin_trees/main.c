#include <stdio.h>
#include "cstack.h"
#include "shunting_yard.h"
#include "ab.h"

int main(int argc, char** argv){

    //char exp[] = "(2+1) - 2 * 3 * 6 / 2 + 5";
    //char exp[] = "((2+1) - 2 * 3)+5*4";
    // char exp[] = "(((2+1) +4)- 2 * 3)+5*4 - (2*4)";

    // char* rpn;

    // rpn = shunting_yard(exp);

    // printf("%s\n", rpn);

    AB a = AB_Criar(5, AB_Criar(7, NULL, NULL), AB_Criar(8, NULL, AB_Criar(9, NULL, NULL)));

    AB_Destruir(a);


}
