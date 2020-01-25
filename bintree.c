#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bintree.h"

node* search(node* root, file* file){

    int32_t cmp = strcmp(file->name, root->key.name);

    if(cmp < 0 && root->left != NULL){
        return search(root->left, file);
    }

    if(cmp > 0 && root->right != NULL){
        return search(root->right, file);
    }

    else{
        return root;
    }

};

void copy(node* root, file* file){

    strcpy(root->key.name, file->name);
    strcpy(root->key.rw, file->rw);
    root->key.size = file->size;

};

void insert_left(node* root, file* file){

    node* new = malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;
    root->left = new;
    copy(root->left, file);

};

void insert_right(node* root, file* file){

    node* new = malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;
    root->right = new;
    copy(root->right, file);

};

void insert(node* root, file* file){

    node* new = malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;

    node* no = search(root, file);

    if(strcmp(file->name, no->key.name) == 0){
            if(strcmp(no->key.rw, "rw") == 0){
                copy(no, file);
            }
        }

    if(strcmp(file->name, no->key.name) < 0){
            insert_left(no, file);
        }

    if(strcmp(file->name, no->key.name) > 0){
            insert_right(no, file);
        }

};

void order(node* root){

    if(root != NULL){
        order(root->left);
        printf("%s %s %d ", root->key.name, root->key.rw, root->key.size);
        if(root->key.size == 1)
            printf("byte\n");
        else
            printf("bytes\n");
        order(root->right);
    }

};

void pre_order(node* root){

    if(root != NULL){
        printf("%s %s %d ", root->key.name, root->key.rw, root->key.size);
        if(root->key.size == 1)
            printf("byte\n");
        else
            printf("bytes\n");
        pre_order(root->left);
        pre_order(root->right);
    }

};

void pos_order(node* root){

    if(root != NULL){
        pos_order(root->left);
        pos_order(root->right);
        printf("%s %s %d ", root->key.name, root->key.rw, root->key.size);
        if(root->key.size == 1)
            printf("byte\n");
        else
            printf("bytes\n");
    }

};