#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bintree.h"

void bst_print_dot_null(file key, int nullcount, FILE* stream){
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %s -- null%d;\n", key.name, nullcount);
}

void bst_print_dot_aux(node* node, FILE* stream){

    static int nullcount = 0;

    if(node->left){
        fprintf(stream, "    %s -- %s;\n", node->key.name, node->left->key.name);
        bst_print_dot_aux(node->left, stream);
    }
    else{
        bst_print_dot_null(node->key, nullcount++, stream);
    }
    if(node->right){
        fprintf(stream, "    %s -- %s;\n", node->key.name, node->right->key.name);
        bst_print_dot_aux(node->right, stream);
    }
    else{
        bst_print_dot_null(node->key, nullcount++, stream);
    }
}

void bst_print_dot(node* tree, FILE* stream){

    fprintf(stream, "graph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if(!tree){
        fprintf(stream, "\n");
    }
    else if(!tree->right && !tree->left){
        fprintf(stream, "    %s;\n", tree->key.name);
    }
    else{
        bst_print_dot_aux(tree, stream);
    }
    fprintf(stream, "}\n");
}