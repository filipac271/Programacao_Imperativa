#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues 

void SinitQueue (SQueue q){
	q->front= 0;
  q->length = 0;
}

int  SisEmptyQ (SQueue q){
    return q->length == 0;
}

int  Senqueue (SQueue q, int x){
  if(q->length == Max){
    return 1;
  }
   q->values[(q->front + q->length) % Max] = x;
   q->length++;
	return 0;
}

int  Sdequeue (SQueue q, int *x) {
  if(SisEmptyQ(q)){
    return 1;
  }

  *x = q->values[q->front];
  q->length--;
  q->front = (q->front +1) % Max;

}

int  Sfront (SQueue q, int *x) {
	if(SisEmptyQ(q)){
    return 1;
  }

  *x=q->values[q->front];
	
	return 0;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
	int *valores = realloc(q-> values, 2* q->size * sizeof(int));
  if(valores == NULL){
    return 1;
  }

  q->size *= 2;
  int i, k;
  k = q->size -1;

  for(i = q->length -1; i < q->front; i--, k--){
    valores[k] = q->values[i];
  }

  q->values = valores;
  q->front = k + 1;	
}

void DinitQueue (DQueue q) {
	q->length = 0;
  q->front = 0;
  q->size = Max;
  q->values = malloc(q->size * sizeof(int));
}

int  DisEmptyQ (DQueue q) {
  return q->length == 0;
}

int  Denqueue (DQueue q, int x){
	if(q->length == q->size){
    dupQueue(q);
  }
	return (-1);
}

int  Ddequeue (DQueue q, int *x){
	// ...
	return (-1);
}

int  Dfront (DQueue q, int *x){
	// ...
	return (-1);
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}