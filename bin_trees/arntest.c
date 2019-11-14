#include <stdio.h>
#include <stdlib.h>
#include "arn.h"

int main(int argc, char **argv, char**envp){
	
	ARN A = NULL;
	
	//ARN_Inserir(&A, 83);
	//ARN_Inserir(&A, 69);	
	//ARN_Inserir(&A, 65);	
	//ARN_Inserir(&A, 82);
	//ARN_Inserir(&A, 67);
	//ARN_Inserir(&A, 72);
	//ARN_Inserir(&A, 88);
	//ARN_Inserir(&A, 77);
	//ARN_Inserir(&A, 80);
	//ARN_Inserir(&A, 76);
	
	//ARN_Imprimir(A, 0, 'r');

	int n, i, x;
	srand(0);
	
	n = argc < 2 ? 200 : atoi(argv[1]);
	
	for(i = 0; i < n; i++){
		x = rand() % (n*10);
		//x = i;
		ARN_Inserir(&A, x);
	}
	
	
	
}

