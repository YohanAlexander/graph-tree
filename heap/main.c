#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"heap.h"
#include"graph.h"

void menu(void){

    printf("\n###### Heap-Visualizer ######\n\n");
    printf("1 -> Inserir valor na fila\n"); //Insere novo numero
    printf("2 -> Desenfileirar valor\n");
    printf("3 -> Imprimir heap\n"); //imprime no formato de arvore
    printf("0 -> Finalizar o programa\n\n");

}

int main(void){

    FILE* graph = fopen("heap.dot", "w+");
    heap* queue = malloc(sizeof(queue));
    int caso, valor;

    menu();

    do{

        printf(">>> ");
        scanf("%d", &caso);

        switch(caso){

            case 1:
            printf("Enfileirar um valor: ");
            scanf("%d", &valor);
            insert(queue, valor);
            printf("Inserido com sucesso\n");
            fflush(stdin);
            menu();
            break;

            case 2:
            deleteRoot(queue, valor);
            printf("Raiz removida com sucesso\n");
            menu();
            fflush(stdin);
            break;

            case 3:
            //bst_print_dot(queue, graph);
            printArray(queue);
            printf("Para visualizar o heap use make dot\n");
            fflush(stdin);
            menu();
            break;

            default:
            printf("Valor inválido!\n");

        }

    }

    while(caso != 0);

    fclose(graph);
    return 0;

}
