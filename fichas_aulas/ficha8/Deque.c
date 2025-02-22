#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

 // ver no gitlab depois
void initDeque (Deque *q){
  (q->back)= NULL;
}

int DisEmpty (Deque q){
  return ((q.back == NULL)); // se tiver só um elemento o front e o back sao o mesmo
    
}
int pushBack (Deque *q, int x){
    
}

int pushFront (Deque *q, int x){
    return -1;
}
int popBack (Deque *q, int *x){
    return -1;
}
int popFront (Deque *q, int *x){
    return -1;
}
int popMax (Deque *q, int *x){

  if(DisEmpty(*q)){
    return 1;
  }

  DList maximo = q->front;
  DList t =  q->front;
  while(t->prox != NULL){
    if(maximo->valor < t->valor){
    maximo = t;
  } 

  t = t->prox;
}
(*x) = maximo->valor;

if(maximo->ant != NULL){
  maximo->ant->prox = maximo->prox;
} else {
  (*q)->front = maximo->prox;
}


if(maximo->ant != NULL){
  maximo->ant->prox = maximo->prox;
} else {
  (*q)->back = maximo->ant;
}



}
int back (Deque q, int *x){
    return -1;
}
int front (Deque q, int *x){
    return -1;
}