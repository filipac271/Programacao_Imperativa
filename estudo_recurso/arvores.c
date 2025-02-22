#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;


typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;

//28

int maior (int a, int b){
  if(a >= b) return a;
  else return b;
}



int altura (ABin a){
  if (a == NULL) return 0;

  else return (1 +maior(altura(a->esq), altura(a->dir)));

}

//29
ABin cloneAB (ABin a){
  if(a == NULL) return NULL;

  ABin copia = malloc(sizeof(struct nodo));
  copia->valor = a->valor;
  copia->esq = cloneAB(a->esq);
  copia->dir = cloneAB(a->dir);

  return copia;
}

//30
void mirror (ABin *a){
  if(*a == NULL) return NULL;
  else{
  ABin temp;
  temp = (*a)->esq;
  (*a)->esq =(*a)->dir;
  (*a)->dir = temp; 

  mirror(&((*a)->esq));
  mirror(&((*a)->dir));
  }
}

//31
//esq->raiz->dir
void inorderaux(ABin tree, LInt * list) {
    LInt aux;
    if(tree) {
      //por ser uma lista ligada, temos de começar ao
      //contrario, isto é, dir -> raiz -> esq
      //porque a direita vai ficar no fim 
      //porque pomos coisas em cima de outras coisas e nao embaixo
        inorderaux(tree->dir,list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = tree->valor;
        aux->prox = *list;

        *list = aux;

        inorderaux(tree->esq,list);
    }
}

//inorder = esq -> raiz -> dir
void inorder (ABin tree, LInt * list) {
    *list = NULL;
    inorderaux(tree,list);
}

//32
//raiz->esq->dir
void preorder_aux(ABin tree, LInt *l){

  LInt aux;
  if(tree){
    preorder_aux(tree->dir, l);
    preorder_aux(tree->esq, l);

    aux =malloc(sizeof(struct lligada));
    aux->valor = tree->valor;
    aux->prox = *l;

    *l = aux  ;
  }
}

void preorder (ABin tree, LInt *l){
  *l = NULL;
  preorder_aux(tree, l);
}

//33
//esq->dir->raiz
void posorderaux (ABin tree, LInt *l){
  LInt aux;
  if(tree){
    aux = malloc(sizeof(struct lligada));
    aux->valor = tree->valor;
    aux->prox = *l;
    *l = aux;

    posorderaux(tree->dir, l);
    posorderaux(tree->esq, l);
  }
}


void posorder (ABin tree, LInt *l){
  *l = NULL;
  posorderaux(tree, l);
}

//34
int depth (ABin a, int x){
  if(a == NULL) return -1;

  if(a->valor = x) return 1;
  int esq = depth(a->esq, x);
  int dir = depth(a->dir, x);

  if(esq == -1 && dir == -1) return -1;
  if(esq == -1 && dir != -1) return 1+dir;
  if(esq != -1 && dir == -1) return 1+esq;
  if(esq != -1 && dir != -1){
    if(esq > dir) return 1+dir;
    else return 1+esq;
  }

}

//35
int freeAB (ABin a) {
    if(!a) return 0;
    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return n;
}

//36
int pruneAB (ABin *a, int l){
  int n = 0;

  if((*a) == NULL) return 0;

  if(l == 0){
    n = 1 + pruneAB(&((*a)->esq), 0) + pruneAB(&((*a)->dir), 0);
    free(*a);
    (*a)= NULL;
  } else{
    n = pruneAB(&((*a)->esq), l-1) + pruneAB(&((*a)->dir), l-1);
  }

}

//37
int iguaisAB (ABin a, ABin b) {
    if(!a && b || !b && a) return 0;
    if(!a && !b || a == b) return 1;
    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

//38

LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL (ABin a, int n){
  if (a == NULL || n < 1) return NULL;

  if (n = 1){
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a->valor;
    novo->prox = NULL;
    return novo;
  }
  else{
    return concat(nivelL(a->esq, n-1), nivelL(a->dir, n-1));
  }

}

//39
int nivelV (ABin a, int n, int v[]) {
    if(!a || n < 1) return 0;
    if(n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq,n - 1,v);
        int d = nivelV(a->dir,n - 1,v+e);
        return e + d;
    }
}

//40
//inorder: esq->raiz->dir
int dumpAbin (ABin a, int v[], int N) {
    int e, d;
    if(a && N) {
        e = dumpAbin(a->esq,v,N);
        if(e < N) {
            v[e] = a->valor;
            return 1 + e + dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;
}

// 41

ABin somasAcA (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}

// 42

int max(int a, int b) {return a > b ? a : b; }

int contaFolhas (ABin a) {
    if(!a) return 0;
    return max((a->esq ? contaFolhas(a->esq) : 0) + (a->dir ? contaFolhas(a->dir) : 0),1);
}

//43
ABin cloneMirror (ABin a){
  if(a == NULL) return NULL;

  ABin clone = malloc(sizeof(struct nodo));
  clone->valor = a;
  clone->dir = cloneMirror(a->esq);
  clone->esq = cloneMirror(a->dir);

  return clone;
}