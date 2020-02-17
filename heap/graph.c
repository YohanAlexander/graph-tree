#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"heap.h"

// escreve no arquivo dot os nos auxiliares
void bst_print_dot_aux(heap* heap, FILE* stream){

    for(int i = 0; i < heap->size - 1; i++){

        int l = left(i);
        int r = right(i);

        if(l < heap->size){
            fprintf(stream, "    %d -> %d;\n", heap->key[i], heap->key[l]);
        }

        if(r < heap->size){
            fprintf(stream, "    %d -> %d;\n", heap->key[i], heap->key[r]);
        }

    }

}

// escreve os nos no arquivo dot
void bst_print_dot(heap* heap, FILE* stream){

    fprintf(stream, "digraph HEAP {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if(heap->size == 0){
        fprintf(stream, "\n");
    }

    else if(heap->size == 1){
        fprintf(stream, "    %d;\n", heap->key[0]);
    }

    else{
        bst_print_dot_aux(heap, stream);
    }

    fprintf(stream, "}\n");

}
