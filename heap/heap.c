#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"heap.h"

// retorna o maior no do vetor
int largest(int i){
  return i;
};

// retorna o filho da esquerda no vetor
int left(int i){
  return 2 * i + 1;
};

// retorna o filho da direita no vetor
int right(int i){
  return 2 * i + 2;
};

// busca um elemento no heap
int search(heap* queue, int num){

  for(int i = 0; i < queue->size; i++){

    // retorna 1 se achar o elemento
    if(queue->key[i] == num){
      return 1;
    }

    // retorna 0 se nao achar
    else{
      return 0;
    }

  }

};

// troca duas posicoes no vetor
void swap(int *a, int *b){

  int temp = *b;
  *b = *a;
  *a = temp;

};

// transforma arvore em heap maximo
void heapify(heap* queue, int i){

  if(queue->size == 1){
    printf("Single element in the heap");
  }

  else{

    int larger = largest(i);
    int l = left(i);
    int r = right(i);

    // se a chave maior for a da esquerda
    if(l < queue->size && queue->key[l] > queue->key[larger])
      larger = l;

    // se a chave maior for a da direita
    if(r < queue->size && queue->key[r] > queue->key[larger])
      larger = r;

    // se a chave maior for o no atual
    if(larger != i){
      swap(&queue->key[i], &queue->key[larger]);
      heapify(queue, larger);
    }

  }

}

// insere elemento no heap
void insert(heap* queue, int newNum){

  // se for o primeiro elemento
  if(search(queue, newNum)){
    return;
  }

  // se o heap estiver vazio
  if(queue->size == 0){
    queue->key[0] = newNum;
    queue->size += 1;
  }

  // outros casos
  else{

    queue->key[queue->size] = newNum;
    queue->size += 1;

    for(int i = queue->size / 2 - 1; i >= 0; i--){
      heapify(queue, i);
    }

  }

}

// remove a raiz do heap como fila de prioridade
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

// printa o heap no terminal
void printArray(heap* queue){

    for(int i = 0; i < queue->size; ++i){
        printf("%d ", queue->key[i]);
    }

    printf("\n");

}
