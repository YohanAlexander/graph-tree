#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bst.h"
#include"graph.h"

void menu(void){

    printf("\n###### BST-Visualizer ######\n\n");
    printf("1 -> Inserir valor\n"); //Insere novo numero
    printf("2 -> Buscar valor\n");
    printf("3 -> Remover valor\n");
    printf("4 -> Imprimir árvore\n"); //imprime no formato de arvore
    printf("0 -> Finalizar o programa\n\n");

}

int main(void){

    FILE* graph = fopen("bst.dot", "w+");
    node* tree = malloc(sizeof(node));
    int caso, valor;

    menu();

    do{

        printf(">>> ");
        scanf("%d", &caso);

        switch(caso){

            case 1:
            printf("Insira um valor: ");
            scanf("%d", &valor);
            if(insert(tree, valor))
                printf("Inserido com sucesso\n");
            else
                printf("Já está na árvore\n");
            fflush(stdin);
            menu();
            break;

            case 2:
            printf("Busque um valor: ");
            scanf("%d", &valor);
            if(search(tree, valor))
                printf("Está na árvore\n");
            else
                printf("Não tem na árvore\n");
            fflush(stdin);
            menu();
            break;

            case 3:
            printf("Remova um valor: ");
            scanf("%d", &valor);
            if(removet(tree, valor))
                printf("Removido com sucesso\n");
            else
            menu();
            fflush(stdin);
            break;

            case 4:
            bst_print_dot(tree, graph);
            printf("Para visualizar a árvore use make dot\n");
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
