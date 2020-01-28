#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bst.h"

void bst_print_dot_null(TYPE key, int nullcount, FILE* stream){
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -- null%d;\n", key, nullcount);
}

void bst_print_dot_aux(node* node, FILE* stream){

    static int nullcount = 0;

    if(node->left){
        fprintf(stream, "    %d -> %d;\n", node->key, node->left->key);
        bst_print_dot_aux(node->left, stream);
    }
    else{
        //bst_print_dot_null(node->key, nullcount++, stream);
    }
    if(node->right){
        fprintf(stream, "    %d -> %d;\n", node->key, node->right->key);
        bst_print_dot_aux(node->right, stream);
    }
    else{
        //bst_print_dot_null(node->key, nullcount++, stream);
    }
}

void bst_print_dot(node* tree, FILE* stream){

    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if(!tree){
        fprintf(stream, "\n");
    }
    else if(!tree->right && !tree->left){
        fprintf(stream, "    %d;\n", tree->key);
    }
    else{
        bst_print_dot_aux(tree, stream);
    }
    fprintf(stream, "}\n");
}
