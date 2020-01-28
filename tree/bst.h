#ifndef BST_H
#define BST_H

typedef struct node node;
typedef int TYPE;

struct node{
    node *left, *right, *father;
    TYPE key;
};

node* init(TYPE data);
int search(node* root, TYPE data);
int insert_left(node* root, TYPE data);
int insert_right(node* root, TYPE data);
int insert(node* root, TYPE data);
int removet(node* root, TYPE data);
void order(node* root);
void pre_order(node* root);
void pos_order(node* root);

#endif
