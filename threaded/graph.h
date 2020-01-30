#ifndef GRAPH_H
#define GRAPH_H
#include"stdio.h"
#include"thread.h"

void bst_print_dot_null(TYPE key, int nullcount, FILE* stream);
void bst_print_dot_aux(node* node, FILE* stream);
void bst_print_dot(node* tree, FILE* stream);

#endif
