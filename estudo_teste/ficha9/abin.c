#include "abin.h"
#include <assert.h>

int maior (int a, int b){
  if(a >= b){
    return a;
  } else return b;
}

int altura (ABin a){
  if(a == NULL) return 0;
  
  else return 1 + maior(altura(a->esq), altura(a->dir));
}

int nFolhas (ABin a){
  if(a == NULL) return 0;

  if(a-> esq == NULL && a->dir == NULL){
    return 1;
  }

  else return (nFolhas(a->esq) + nFolhas(a->dir));
}


ABin maisEsquerda (ABin a){
   if(a == NULL) return a;
    while(a->esq != NULL){
      a = a->esq;
    }
    return a;
}

void imprimeNivel (ABin a, int l){
  assert(l >= 0);
  if(a != NULL){
  if(l == 0) printf("%d\t", a->valor);
  else {
    imprimeNivel(a->esq, l-1);
    imprimeNivel(a->dir, l-1);
  }
  }
  printf("/n");
}

int procuraE (ABin a, int x){
  if (a == NULL) return 0;

  while (a != NULL){
    if(a->valor == x) return 1;
    else return (procuraE(a->dir, x) || procuraE(a->esq, x));
  }
}


//ARVORE BINARIA DE PROCURA

struct nodo *procura (ABin a, int x){
    if(a == NULL) return NULL;
    
    while(a != NULL && a ->valor != x){
      if(a->valor > x) a = a->esq;
      else a = a->dir;
    }
    return a;
}


int nivel (ABin a, int x){
    int r = 0;
    while( a != NULL && a->valor != x){
      if(a->valor > x) a = a->esq;
      else a = a->dir;
      r++;
    }
    if(a->valor == x) return r;
    return (-1);
}

void imprimeAte (ABin a, int x){
  if(a != NULL){
    imprimeAte(a->esq, x);
    if(a->valor < x){
      printf("%d\t", a->valor);
    }
    imprimeAte(a->dir, x);
  }    
}
