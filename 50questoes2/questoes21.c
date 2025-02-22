#include <stdio.h>
#include <stdlib.h>

typedef struct lligada
{
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLint (int valor, LInt list){
    LInt r;
    r = malloc(sizeof(struct lligada));
    if(r != NULL){
        r->valor = valor;
        r->prox= list;
        return r;
    }
} 

void swap(int a[], int i , int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


// 1
int length(LInt l)
{
    int acc = 0;
    while (l != NULL)
    {
        acc++;
        l = l->prox;
    }
    return acc;
}

// 2 ??? ver depois
void freeL(LInt l)
{
    LInt aux;
    while (l != NULL)
    {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

// 3
void imprimeL(LInt l)
{
    while (l != NULL)
    {
        printf("%d \n"), l->valor;
        l = l->prox;
    }
}


// 5 meh
void insertOrd(LInt *lista, int valor)
{
    LInt novo = (LInt)malloc(sizeof(struct lligada)); // Aloca memória para o novo nó
    novo->valor = valor;                              // Atribui o valor ao novo nó
    novo->prox = NULL;                                // Define o próximo nó como NULL

    if (*lista == NULL || (*lista)->valor >= valor)
    {                        // Se a lista estiver vazia ou o valor for menor que o primeiro elemento
        novo->prox = *lista; // O novo nó aponta para o início da lista
        *lista = novo;       // Atualiza o ponteiro da lista para apontar para o novo nó
    }
    else
    {
        LInt current = *lista; // Ponteiro para percorrer a lista
        while (current->prox != NULL && current->prox->valor < valor)
        {                            // Enquanto não chegarmos ao final ou ao ponto de inserção
            current = current->prox; // Avança na lista
        }
        // Insere o novo nó entre current e o próximo nó
        novo->prox = current->prox;
        current->prox = novo;
    }
}

// 6 gpt, bastante estranho
int removeOneOrd(LInt *lista, int valor)
{
    if (*lista == NULL)
    {             // Se a lista estiver vazia
        return 1; // O elemento não existe na lista
    }

    LInt temp = *lista; // Ponteiro temporário para percorrer a lista
    LInt prev = NULL;   // Ponteiro para o nó anterior
    int found = 0;      // Flag para indicar se o elemento foi encontrado

    // Percorre a lista em busca do elemento
    while (temp != NULL)
    {
        if (temp->valor == valor)
        {              // Se o elemento for encontrado
            found = 1; // Define a flag como verdadeira
            break;     // Sai do loop
        }
        prev = temp;       // Atualiza o ponteiro para o nó anterior
        temp = temp->prox; // Avança para o próximo nó
    }

    if (!found)
    {             // Se o elemento não foi encontrado na lista
        return 1; // Retorna 1 indicando que o elemento não existe na lista
    }

    if (prev == NULL)
    {                        // Se o elemento a ser removido é o primeiro da lista
        *lista = temp->prox; // Atualiza o início da lista para o próximo nó
    }
    else
    {
        prev->prox = temp->prox; // Remove o nó da lista
    }

    free(temp); // Libera a memória ocupada pelo nó removido
    return 0;   // Retorna 0 indicando que a remoção foi bem-sucedida
}

//6
int removeOneOrd(LInt *l, int x) {
    LInt prev = NULL;
    for(;*l && x != (*l)->valor; prev = *l, l = &((*l)->prox));
    if(!(*l)) return 1;
    if(!prev) (*l) = (*l)->prox;
    else prev->prox = (*l)->prox;
    return 0;
}

// 7
void merge(LInt *r, LInt a, LInt b)
{
    if (!a && !b)
        return;
    if (b == NULL || a != NULL && a->valor < b->valor)
    {
        (*r) = a;
        merge(&((*r)->prox), a->prox, b);
    }
    else
    {
        (*r) = b;
        merge(&((*r)->prox), a, b->prox);
    }
}

//7
void merge (LInt *r, LInt l1, LInt l2){
    while(l1 != NULL && l2 != NULL){
        if(l1->valor < l2->valor){
            *r = l1;
            l1 = l1->prox;
        } else {
            *r = l2;
            l2 = l2->prox;
        }
        r = &((*r)->prox);
    }
    if(l1 == NULL){ 
        *r = l2;
        l2 = l2->prox;
        r = &((*r)->prox);
    } else {
        *r = l1;
        l1 = l1->prox;
        r = &((*r)->prox);
    }
}

// 8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx)
{
    if (!l)
        return;
    if (l->valor < x)
    {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else
    {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l != NULL){
        if(l->valor < x){
            *mx = l;
            l = l->prox;
            mx = &((*mx)->prox);
        } else{
            *Mx = l;
            (*mx) = NULL; //atençao!!!!!!
            l = l->prox;
            Mx = &((*Mx)->prox);
        }
    }
}


// 9
LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    if(meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for(int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}


//10
int removeAll (LInt *l, int x){
    LInt ant = NULL;
    int i= 0;
  while(*l != NULL){
    if((*l)->valor == x){
      if(!ant) (*l) = (*l)->prox;
      else ant->prox = (*l)->prox;
      i++;
    }
    else{
    ant = *l;
    l = &((*l)->prox);
    }
  }
  return i;
}

// 11
int removeDups(LInt *l) {
    int rem = 0;
    for(;*l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for(; aux; aux = prevAux->prox) {
            if(aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

// 12 nao entendi
int removeMaiorL(LInt *l) {
    int max = (*l)->valor;
    LInt prev = NULL;
    LInt maxPrev = NULL;
    LInt maxL = (*l);
    LInt list = (*l);
    for(;list; list = list->prox) {
        if(list->valor > max) {
            maxPrev = prev;
            maxL = list;
            max = list->valor;
        }
        prev = list;
    }
    if(!maxPrev) (*l) = (*l)->prox;
    else maxPrev->prox = maxL->prox;
    return max;
}

// 13
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

// 14
void appendL (LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(!(*l)) (*l) = new;
    else {
        for(;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

// 15

void concatL (LInt *a, LInt b){
    if(!(*a)) (*a) = b;
     else {
        for(;(*a)->prox; a = &((*a)->prox));
        (*a)->prox = b;
    }
}

// 16
LInt cloneL (LInt l){
    LInt r = NULL, ult;
    r = ult = malloc(sizeof(struct lligada));
    r->valor = l->valor;

    while(l != NULL){
        ult->prox = malloc(sizeof(struct lligada));
        ult->valor = l->valor;
        l= l->prox;

    }
    ult->prox = NULL;
    return r;
}

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


// 17 igual ao reverse mas com o malloc
LInt cloneRev (LInt l) {
    LInt list = NULL;
    while(l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
}

// 18
int maximo (LInt l){
    int maior = 0;
    if(!l->prox) return l->valor; //!!!!

    while(l != NULL){
        if(l->valor > maior){
            maior = l->valor;
            
        }
        l= l->prox;
    }
    return maior;
}


// 19 nao funciona nem deve ser assim, 6 testes corretor
int take (int n, LInt *l){
   int tamanho = length(l);
   int i;
   int tamanho2 = 0;

   if(tamanho <= n) return tamanho;
   if (tamanho > n){
    for(i = 0; i < n; i++){
        LInt nova = maloc(sizeof(struct lligada));
        nova->valor = (*l)->valor;
        nova = nova->prox;
        l = &((*l)->prox);
        tamanho2++;
    }
   }
    return tamanho2;
}

//19 certa
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


// 20
int drop (int n, LInt *l) {
    int i;
    for(i = 0; i < n && (*l); i++) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
    }
    return i;
}

// 21
LInt NForward (LInt l, int N) {
    int i;
    for(i = 0; i < N; i++) {
        l = l->prox;
    }
    return l;
}

// 22
int listToArray (LInt l, int v[], int N) {
    int i;
    for(i = 0; i < N && l; l = l->prox) {
        v[i++] = l->valor;
    }
    return i;
}

//23 como o jbb fez nas arvores
LInt arrayToList (int v[], int N) {
    if(N == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}


// 24
LInt somasAcL (LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for(;l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if(!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}

// 25

void remreps(LInt l) {
    if(l) {
        while(l->prox) {
            if(l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

// 26
LInt rotateL (LInt l) {
    if(!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while(temp->prox) temp = temp->prox; 
    temp->prox = l;
    l->prox = NULL;
    return list;
}

// 27
LInt parte(LInt l) {
    if(!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}

