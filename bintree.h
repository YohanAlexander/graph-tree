#ifndef BINTREE_H
#define BINTREE_H

typedef struct file file;
typedef struct node node;

struct file{
    char name[51];
    char rw[2];
    int size;
};

struct node{
    node *left, *right;
    file key;
};

node* search(node* root, file* file);
void copy(node* root, file* file);
void insert_left(node* root, file* file);
void insert_right(node* root, file* file);
void insert(node* root, file* file);
void order(node* root);
void pre_order(node* root);
void pos_order(node* root);

#endif