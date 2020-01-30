#ifndef BST_H
#define BST_H

typedef struct node node;
typedef int TYPE;

struct node{
    node *left, *right, *father;
    TYPE key;
};

node* left(node* root);
node* right(node* root);
node* father(node* root);
node* init(TYPE data);
int search(node* root, TYPE data);
int insert_left(node* root, TYPE data);
int insert_right(node* root, TYPE data);
int insert(node* root, TYPE data);
int removet(node* root, TYPE data);
void in_order(node* root);
void pre_order(node* root);
void pos_order(node* root);

#endif
