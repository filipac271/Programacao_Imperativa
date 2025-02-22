#include "abin.h"
#include <assert.h>



ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int maior (int a, int b){
  if(a >= b) return a;
  else return b;
}

int altura (ABin a){
  int alt;
    if(a == NULL) alt = 0;
    else alt = 1 + maior ((altura(a->esq)), (altura(a->dir)));
  return alt;
}


int nFolhas (ABin a){
   if(a == NULL) return 0;
   if(a->esq == NULL && a->dir == NULL) return 1;
   return nFolhas(a->esq) + nFolhas(a->dir);
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
  if(a == NULL) return 0;
  
  if(a->valor == x) return 1;
  return (procuraE(a->esq, x) || procuraE(a->dir, x));
}

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
