#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"heap.h"

int largest(int i){
    return i;
};

int left(int i){
    return 2 * i + 1;
};

int right(int i){
    return 2 * i + 2;
};

void swap(int *a, int *b){

  int temp = *b;
  *b = *a;
  *a = temp;

};

void heapify(heap* queue, int i){

  if(queue->size == 1){
    printf("Single element in the heap");
  }

  else{

    int larger = largest(i);
    int l = left(i);
    int r = right(i);

    if(l < queue->size && queue->key[l] > queue->key[larger])
      larger = l;

    if(r < queue->size && queue->key[r] > queue->key[larger])
      larger = r;

    if(larger != i){
      swap(&queue->key[i], &queue->key[larger]);
      heapify(queue, larger);
    }

  }

}

void insert(heap* queue, int newNum){

  if(queue->size == 0){
    queue->key[0] = newNum;
    queue->size += 1;
  }

  else{

    queue->key[queue->size] = newNum;
    queue->size += 1;

    for(int i = queue->size / 2 - 1; i >= 0; i--){
      heapify(queue, i);
    }

  }

}

void deleteRoot(heap* queue, int num){

    int i;

    for(i = 0; i < queue->size; i++){
        if(num == queue->key[i]){
            break;
        }
    }

    swap(&queue->key[i], &queue->key[queue->size - 1]);
    queue->size -= 1;

    for(int i = queue->size / 2 - 1; i >= 0; i--){
        heapify(queue, i);
    }

}

void printArray(heap* queue){

    for(int i = 0; i < queue->size; ++i){
        printf("%d ", queue->key[i]);
    }

    printf("\n");

}