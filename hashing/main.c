#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"

int main(int argc, char** argv){
    
    int n;    
    int seed = 0;

    n = argv[1] ? atoi(argv[1]) : 10;

    srand(seed);

    printf("%d\n", n);

}
