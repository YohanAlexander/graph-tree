#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bintree.h"
#include"graph.h"

int main(void){

    FILE* graph = fopen("bst.dot", "w");
    node* tree = malloc(sizeof(node));
    int menu, valor;

    printf("1 -> Inserir valor\n"); //Insere novo numero
    printf("2 -> Buscar valor\n");
    printf("3 -> Remover valor\n");
    printf("4 -> Imprimir ordem\n");
    printf("5 -> Imprimir pos-ordem\n");
    printf("6 -> Imprimir pre-ordem\n");
    printf("7 -> Imprimir arvore\n"); //imprime na tela no formato de arvore
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
                printf("Esta na arvore\n");
            else
                printf("Nao tem na arvore\n");
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
            fflush(stdin);
            break;

            default:
            printf("Valor invalido!\n");

        }

    }

    while(menu != 0);

    fclose(graph);
    return 0;

}