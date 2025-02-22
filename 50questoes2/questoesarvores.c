#include <stdio.h>
#include <stdlib.h>

typedef struct lligada
{
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
  if(a == NULL) return 0;
  else return (1+ (maior((altura (a->esq)), (altura (a->dir)))));
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
  if((*a)){
    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;

    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
  }

}

//31

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
void preorderaux(ABin a, LInt *l) {
    LInt aux;
    if(a) {
//mesmo raciocinio do outro, estamos a empilhar pratos
//primeiro direita para ficar em baixo, depois esquerde e no topo a raiz
        preorderaux(a->dir,l);
        preorderaux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

//preorder raiz -> esq -> dir
void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}

//33

void posorderaux (ABin a, LInt *l){
  LInt aux;
  if(a){
    LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = (*l);
        (*l) = new;

    posorderaux(a->dir, l);
    posorderaux(a->esq, l);
  }

}

// postorder esq-> dir ->raiz
void posorder (ABin a, LInt *l){
  *l = NULL;
  posorderaux(a, l);

}

//34

int depth(ABin a, int x) {
    if(!a) return -1;

    if(a->valor == x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;

    if(esq < dir){
      return esq +1;
    } else {
      return dir +1;
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

// 38

LInt concat(LInt a, LInt b) {
    if(!a) return b;
    LInt temp = a;
    while(temp->prox) temp = temp->prox;
    temp->prox = b;
    return a;
}
 
LInt nivelL (ABin a, int n) {
    if(!a || n < 1) return NULL;
    if(n == 1) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else return concat(nivelL(a->esq,n - 1),nivelL(a->dir,n - 1));
} 

// 39

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

// 40

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

// 43

ABin cloneMirror (ABin a) {
    if(!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new;
}


//ATE AQUI

// 44

int addOrd (ABin *a, int x) {
    while(*a) {
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = new->dir = NULL;
    (*a) = new;
    return 0;
}

// 45

int lookupAB(ABin a, int x) {
    while(a) {
        if(a->valor == x) return 1;
        if(a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return 0;
}

// 46

int depthOrd (ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;
    int d = depthOrd((a->valor < x ? a->dir : a->esq),x);
    return d == -1 ? d : 1 + d;
}

// 47

int maiorAB (ABin a) {
    while(a->dir) a = a->dir;
    return a->valor;
}

// 48

void removeMaiorA (ABin *a) {
    if(!(*a)->dir) {
        ABin temp = (*a);
        free(*a);
        (*a) = temp->esq;
    }
    else removeMaiorA(&((*a)->dir));
}

// 49

int quantosMaiores (ABin a, int x) {
    if(!a) return 0;
    if(a->valor <= x) return quantosMaiores(a->dir,x);
    else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

// 50

void listToBTree (LInt l, ABin *a) {
    if(!l) return;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2;
    LInt temp = l, prev = NULL;
    int i;
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    if(l != temp) listToBTree(l,&(new->esq));
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}

// 51

int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
}