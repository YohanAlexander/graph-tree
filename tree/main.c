#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bst.h"
#include"graph.h"

int main(void){

    FILE* graph = fopen("bst.dot", "w");
    node* tree = malloc(sizeof(node));
    int menu, valor;

    printf("###### Graph-Tree-Visualizer ######\n\n");
    printf("1 -> Inserir valor\n"); //Insere novo numero
    printf("2 -> Buscar valor\n");
    printf("3 -> Remover valor\n");
    printf("4 -> Imprimir ordem\n");
    printf("5 -> Imprimir pós-ordem\n");
    printf("6 -> Imprimir pré-ordem\n");
    printf("7 -> Imprimir árvore\n"); //imprime na tela no formato de arvore
    printf("0 -> Finalizar o programa\n\n");

    do{

        printf(">>> ");
        scanf("%d", &menu);

        switch(menu){

            case 1:
            printf("Insira um valor: ");
            scanf("%d", &valor);
            insert(tree, valor);
            fflush(stdin);
            break;

            case 2:
            printf("Busque um valor: ");
            scanf("%d", &valor);
            if(search(tree, valor))
                printf("Está na árvore\n");
            else
                printf("Não tem na árvore\n");
            fflush(stdin);
            break;

            case 3:
            printf("Remova um valor: ");
            scanf("%d", &valor);
            removet(tree, valor);
            fflush(stdin);
            break;

            case 4:
            order(tree);
            fflush(stdin);
            break;

            case 5:
            pos_order(tree);
            fflush(stdin);
            break;

            case 6:
            pre_order(tree);
            fflush(stdin);
            break;

            case 7:
            bst_print_dot(tree, graph);
            printf("Para visualizar a árvore feche o programa\n");
            fflush(stdin);
            break;

            default:
            printf("Valor inválido!\n");

        }

    }

    while(menu != 0);

    fclose(graph);
    return 0;

}
