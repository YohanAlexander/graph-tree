#ifndef BINTREE_H
#define BINTREE_H
#include"stdio.h"
#include"bintree.h"

void bst_print_dot_null(file key, int nullcount, FILE* stream);
void bst_print_dot_aux(node* node, FILE* stream);
void bst_print_dot(node* tree, FILE* stream);

#endif