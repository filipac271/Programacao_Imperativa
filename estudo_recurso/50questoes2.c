#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;

int length (LInt l) {
  int acc = 0;
  while(l != NULL){
    l = l->prox;
    acc++;
  }
}

void freeL (LInt l){
  while(l != NULL){
    LInt temp;
    temp = l;
    l = l->prox;
    free(temp);
    }
}

//4
LInt reverseL (LInt l){
   LInt r = NULL;
   LInt t;

   while(l != NULL){
    t = l;
    l = l->prox;
    t->prox = r;
    r = t;
   }
   return r;
}

//13
void init (LInt *l) {
    LInt prev = NULL;
    for(;(*l)->prox;prev = *l, l = &((*l)->prox));
    if(!prev) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

//14
void appendL(LInt *l, int x){
  LInt novo = malloc(sizeof(struct lligada));
  novo->valor = x;
  novo->prox = NULL;

  if(!(*l)) (*l) = novo;
   else {
       for(;(*l)->prox; l = &((*l)->prox));
       (*l)->prox = novo;
   }
}

//15
void concatL(LInt *a, LInt b){
  if(*a == NULL) (*a) = b;
  else{
    for(; (*a)->prox; a = &((*a)->prox));
    (*a)->prox = b;
  }
}

//16
LInt cloneL2 (LInt l){
    LInt r, *e;
    e = &r;

    while(l != NULL){
        *e = malloc(sizeof(struct lligada));
        (*e)->valor = l->valor;
        e = &((*e)->prox);
        l = l->prox;
    }
    *e = NULL;
    return r;
    
}

//17
LInt cloneTev (LInt l){
  if(l == NULL) return l;

  LInt r = NULL;
  while(l != NULL){
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = l->valor;
    l = l->prox;
    novo->prox = r;
    r = novo;    
  }
  return r;
}

//18
int maximo (LInt l){
  if(l == NULL) return 0;

  int max = 0;
  while(l != NULL){
    if(l->valor > max){
      max = l->valor;
    }
    l = l->prox;
  }
  return max;
}

//19
int take (int n, LInt *l) {
    int i = 0;
    for(;i < n && *l; i++, l = &((*l)->prox));
    if(!(*l)) return i;
    for(;*l;) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

//20
int drop (int n, LInt *l){
  int i = 0;
  LInt temp;
  for(; i < n && *l; i++, l = &((*l)->prox)){
    temp = *l;
    free(temp);
  }
  return i;

}