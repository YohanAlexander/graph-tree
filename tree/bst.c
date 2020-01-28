#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bst.h"

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

node* father(node* root){

    node* aux = root;

    if(aux->father != NULL){
        aux = aux->father;
        return aux;
    }

    else{
        return NULL;
    }

};

node* init(TYPE data){

    node* new = malloc(sizeof(node));

    if(new == NULL){
        return NULL;
    }

    else{
        new->key = data;
        new->left = NULL;
        new->right = NULL;
        new->father = NULL;
        return new;
    }

};

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

int removet(node* root, TYPE data){

	node* father = root;

	while(root != NULL && root->key != data){
		father = root;
		if (data > root->key) root = right(root);
		else root = left(root);
	}

	if(root != NULL){

		// Se tiver duas subárvores.
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

		//É importante que esse próximo if não seja um "else if".

        //Se tiver uma subárvore à esquerda.
		if(left(root) == NULL && right(root) != NULL){
			if(father->left == root) father->left = right(root);
			else father->right = right(root);
		}

		//Se tiver uma subárvore à direita.
		else if(left(root) != NULL && right(root) == NULL){
			if(father->left == root) father->left = left(root);
			else father->right = left(root);
		}

		//Se for uma folha.
		else if(left(root) == NULL && right(root) == NULL){
			if(father->left == root) father->left = NULL;
			else father->right = NULL;
		}

		free(root);

    }

};

void order(node* root){

    if(root != NULL){
        order(root->left);
        printf("%d\n", root->key);
        order(root->right);
    }

};

void pre_order(node* root){

    if(root != NULL){
        printf("%d\n", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }

};

void pos_order(node* root){

    if(root != NULL){
        pos_order(root->left);
        pos_order(root->right);
        printf("%d\n", root->key);
    }

};
