#ifndef HEAP_H
#define HEAP_H

typedef struct heap heap;
typedef int TYPE;

struct heap{
    TYPE key[101];
};

void heapfy(void);

#endif