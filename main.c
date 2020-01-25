#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bintree.h"
#include"graph.h"

int main(){

    node* a;
    int escolha = 1;
    int x = 0;

    do {
        printf("\n\n\n");
        printf("########################################\n\n");
        printf("Digite a opcao desejada:\n");
        printf("1-> Inicializar arvore.\n");
        printf("2-> Inserir Elemento.\n");
        printf("3-> Retirar Elemento.\n");
        printf("4-> Buscar elemento.\n");
        printf("\n\n#####################################\n\n\n\n\n->");

        scanf("%d", &escolha);
        fflush(stdin);
        printf("\n\n");

        switch (escolha){
            case 1:
                a = abb_cria();
                if (a == NULL){
                    printf ("Arvore inicializada com sucesso!\n");
                    printf("\n\n\n");
                    break;
                }
            case 2:
                printf("Digite o elemento a ser inserido na arvore:\n");
                scanf("%d", &x);
                fflush(stdin);
                a = abb_insere(a, x);
                printf("\n\n\n");
                break;
            case 3:
                printf ("Digite o elemento a ser retirado na arvore:\n");
                scanf ("%d", &x);
                fflush(stdin);
                a = abb_retira(a, x);
                printf ("\n\n\n");
                break;
            case 4:
                printf ("Digite o elemento que você deseja buscar:\n");
                scanf ("%d", &x);
                fflush(stdin);
                a = abb_busca (a, x);
                printf ("\n\n\n");
                break;
        }

    }while (escolha != 0); // 0 para fechar o menu
    return 0;
}