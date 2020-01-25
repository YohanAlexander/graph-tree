#ifndef HEAP_H
#define HEAP_H

typedef struct file file;
typedef struct heap heap;

struct file{
    char name[51];
    char rw[2];
    int size;
};

struct heap{
    file key[101];
};

#endif