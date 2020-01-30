#ifndef GRAPH_H
#define GRAPH_H
#include"stdio.h"
#include"heap.h"

void bst_print_dot_aux(heap* node, FILE* stream, int i);
void bst_print_dot(heap* tree, FILE* stream);

#endif
