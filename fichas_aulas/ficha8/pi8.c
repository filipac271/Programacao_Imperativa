#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack (Stack *s){
  (*s) = NULL;
}

int SisEmpty (Stack s){
    return (s == NULL);
}

int push (Stack *s, int x){

  LInt novo = newLInt(x, *s);

  if(novo == NULL){
    return 1;
  }


  (*s) = novo;

  return 0;
}



int pop (Stack *s, int *x){
  if(SisEmpty(s)){
    return 1;
  }

  LInt cabeca = (*s);

  (*x) = cabeca->valor;
  (*s) = cabeca->prox;

  free(cabeca);
  
  return 0;
}



int top (Stack s, int *x){
  if(SisEmpty(s)){
    return 1;
  }

  (*x) = s->valor;
  return 0;

}
