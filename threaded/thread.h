#ifndef THREAD_H
#define THREAD_H

typedef struct node node;
typedef int TYPE;

struct node{
    node *left, *right, *father;
    TYPE key;
};

node* init(TYPE data);
node* left(node* root);
node* right(node* root);
node* sucessor(node* root);
int search(node* root, TYPE data);
int insert(node* root, TYPE data);
int removet(node* root, TYPE data);
void in_order(node* root);
void pre_order(node* root);
void pos_order(node* root);

#endif
