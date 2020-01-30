#ifndef HEAP_H
#define HEAP_H

typedef struct heap heap;
typedef int TYPE;

struct heap{
    TYPE key[101];
    int size;
};

int largest(int i);
int left(int i);
int right(int i);
int search(heap* queue, int num);
void swap(int *a, int *b);
void heapify(heap* queue, int i);
void insert(heap* queue, int newNum);
void deleteRoot(heap* queue, int num);
void printArray(heap* queue);

#endif