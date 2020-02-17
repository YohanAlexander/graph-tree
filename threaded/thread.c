#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"thread.h"

// retorna o no mais a esquerda
node* left(node* root){

    node* aux = root;

    if(aux->left != NULL){
        aux = aux->left;
        return aux;
    }

    else{
        return NULL;
    }

};

// retorna o no mais a direita
node* right(node* root){

    node* aux = root;

    if(aux->right != NULL){
        aux = aux->right;
        return aux;
    }

    else{
        return NULL;
    }

};

// aloca um novo no
node* init(TYPE data){

    node* new = malloc(sizeof(node));

    if(new == NULL){
        return NULL;
    }

    else{
        new->key = data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

};

// acha o elemento predecessor
node* predecessor(node* root){

    if(root->left!= NULL){
       node* aux1 = right(root->left);
       return aux1;
    }

    node* aux2 = root->father;

    while(aux2 != NULL && aux2->left == root){
       root = aux2;
       aux2 = aux2->father;
    }

    return root;

}

// acha o elemento sucessor
node* sucessor(node* root){

    if(root->right != NULL){
       node* aux1 = left(root->right);
       return aux1;
    }

    node* aux2 = root->father;

    while(aux2 != NULL && aux2->right == root){
       root = aux2;
       aux2 = aux2->father;
    }

    return root;

}

// busca um elemento na árvore
int search(node* root, TYPE data){

    if(root->key == data){
        return 1;
    }

    else{

        if(data > root->key){
            root = right(root);
        }

        else{
            root = left(root);
        }

        if(root == NULL){
            return 0;
        }

        search(root, data);

    }

};

// insere na esquerda
int insert_left(node* root, TYPE data){

    node* new = init(data);

    if(root->left == NULL){
        root->left = new;
        root->left->father = root;
        return 1;
    }

    else{
        return 0;
    }

};

// insere na direita
int insert_right(node* root, TYPE data){

    node* new = init(data);

    if(root->right == NULL){
        root->right = new;
        root->right->father = root;
        return 1;
    }

    else{
        return 0;
    }

};

// insere na arvore
int insert(node* root, TYPE data){

    if(root->key == data){
        return 0;
    }

    else{

        if(data > root->key){

            if(right(root) != NULL){
                root = right(root);
                insert(root, data);
            }

            else{
                insert_right(root, data);
                return 1;
            }
        }

        else{

            if(left(root) != NULL){
                root = left(root);
                insert(root, data);
            }

            else{
                insert_left(root, data);
                return 1;
            }

        }

    }

};

// remove elemento da arvore
int removet(node* root, TYPE data){

	node* father = root;

	while(root != NULL && root->key != data){

    father = root;

        if(data > root->key)
            root = right(root);

        else
            root = left(root);

    }

	if(root != NULL){

		// se tiver duas subarvores
		if(left(root) != NULL && right(root) != NULL){

			node* aux = root;
			father = root;
			root = left(root);

            while(left(root) != NULL){
				father = root;
				root = left(root);
			}

			aux->key = root->key;

		}

        // se tiver uma subarvore a esquerda
		if(left(root) == NULL && right(root) != NULL){
			if(father->left == root) father->left = right(root);
			else father->right = right(root);
		}

		// se tiver uma subarvore a direita
		else if(left(root) != NULL && right(root) == NULL){
			if(father->left == root) father->left = left(root);
			else father->right = left(root);
		}

		// se for uma folha
		else if(left(root) == NULL && right(root) == NULL){
			if(father->left == root) father->left = NULL;
			else father->right = NULL;
		}

		free(root);

    }

};

// imprime percurso em ordem
void in_order(node* root){

    if(root != NULL){
        in_order(root->left);
        printf("%d\n", root->key);
        in_order(root->right);
    }

};

// imprime percurso pre ordem
void pre_order(node* root){

    if(root != NULL){
        printf("%d\n", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }

};

// imprime percurso pos ordem
void pos_order(node* root){

    if(root != NULL){
        pos_order(root->left);
        pos_order(root->right);
        printf("%d\n", root->key);
    }

};
