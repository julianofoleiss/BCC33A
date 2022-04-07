#pragma once
#include <stdbool.h>

void troca(int *v, int i, int j);
int* random_vector(int n, int max, int seed);
int* random_vector_unicos(int n, int seed);
void print_vector(int* v, int n, bool newline);
