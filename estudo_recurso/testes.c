#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;


typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;


//teste 31 de maio de 2022

//1
void swap(int v[], int a, int b){
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

void bubble(int v[], int N){
  int i;
  for(i = 0; i < N; i++){
    if(v[i-1]> v[i]){
      swap(v, i-1, i);
    }
  }
}
void bsort (int v[], int N){
  int i;
  for(i = N; i > 0; i--){
    bubble(v, i);
  }
}

int nesimo(int a[], int N, int i){
  bsort(a, N);

  return a[i-1];
}

//2
 LInt removeMaiores(LInt l, int x){
  LInt ant;
  LInt list = l;
  for(; list && list->valor <= x; ant = list, list = list->prox);
  if(list == NULL) return l;
  else{
    for(;list;){
      LInt temp = list->prox;
      free(list);
      list = temp;
    }
  }
  l = list;
  return l;
 }

 //3

 int existe (ABin a, int x){
  if(a == NULL) return -1;
  if(a->valor == x) return 1;
  else{
    if(x > a->valor) return existe(a->dir, x);
    if(x < a->valor) return existe(a->esq, x);
  }
 }


 LInt caminho(ABin a, int x){
  if(a == NULL) return NULL;

  int exist = existe(a, x);
  LInt lista;
  if(exist == -1) return NULL;
  else{
    lista = malloc(sizeof(struct lligada));
    lista->valor = a->valor;
    if(a->valor > x){
      lista->prox = caminho(a->esq, x);
    }
    else{
      lista->prox = caminho(a->dir, x);
    }
  }
  return lista;
 }

 //4
 void inc(char s[]){
  int tamanho = strlen(s);
  int carry = 1;
  int i;
  for(i = tamanho -1; i >0; i--){
    int digit = s[i] -'0';
    digit += carry;
    if(digit < 9){
      
      carry = 0;
    }else{
      digit = 0;
      carry = 1;
    }
    s[i] = digit +'0';

  }
  if(carry == 1){
    memmove(s+1, s, tamanho+1);
    s[0] ='1'; 
  }
 }

 //5
 int total(int p[], int N){
  int i;
  int acc = 0;
  for(i = 0; i<N; i++){
    acc = acc + p[i];
  }
  return acc;
 }

  int sacos(int p[], int N, int C){
    int acc = total(p, N);

    if(acc%C == 0){
      return(acc/C);
    } else{
      return(acc/C +1);
    }
  }


//EXAME 21 de junho 2022

//1
int pesquisa (int a[], int N, int x){
  int i;
  for(i = 0; i< N; i++){
    if(a[i] == x) return i;
  }
  return -1;
}

//2
void roda (LInt *l){
  if((*l) == NULL) return;
  LInt lista = *l;
  LInt ant;
  for(;lista->prox;ant = lista, lista = lista->prox);
  lista->prox = l;
  ant->prox = NULL;
}

//3
int contanodos (ABin a){
  if(a == NULL) return 0;
  else return 1 + contanodos(a->esq) + contanodos(a->dir);
}

int freeAB (ABin a) {
    if(!a) return 0;
    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return n;
}


int apaga (ABin a, int n){
  int nodos = contanodos(a);
  int nodosesq = contanodos(a->esq);
  int nodosdir = contanodos(a->dir);

  if(nodos < n){
    return freeAB(a);
  }
  else{
     
  }


}

//4
void checksum (char s[]){
  int i;
  int tamanho = strlen(s);
  int acc = 0;
  for(i = 0;i < tamanho-1;i++ ){
    if(i%2 ==0){
      int digit = s[i] -'0';
      digit = digit*2;
      acc = acc + digit/10 + digit%10;
    }
    else{
      int digit = s[i] -'0';
      acc = acc + digit;
    }
  }
  int controlo = 10 - (acc%10);
  s[tamanho] = controlo + '0';
  s[tamanho+1] = '\0';
}

//20 de maio de 2023

//1
int perfeito(int x){
  int i, acc = 0;
  for(i = 0; i < x/2; i++){
    if(x%i == 0){
      acc = acc+i;
    }
  }
  return(x == acc);
}

//2
typedef struct {
  int x,y;
} Ponto;

int calculadistancia (Ponto pos){
  return sqrt((pos.x * pos.x) + (pos.y * pos.y));

}

void swapP(Ponto pos[], int i, int j){
  Ponto temp = pos[i];
  pos[i] = pos[j];
  pos[j] = temp;
}

void bubbleP (Ponto pos[], int N){
  int i;
  for(i = 1; i < N; i++){
    if(calculadistancia(pos[i-1]) > calculadistancia(pos[i])){
      swapP(pos, i-1, i);
    }
  }
}


void ordena(Ponto pos[], int N){
  int i;
  for(i = N; i>0; i++){
    bubbleP(pos, i);
  }
}


//3

int depth(ABin a, int x){
  if(a == NULL) return -1;

  if(a->valor == x) return 1;
  int esq = depth(a->esq, x);
  int dir = depth(a->dir, x);

  if(esq == -1 && dir == -1) return -1;
  if(esq == -1 && dir != -1) return 1+dir;
  if(esq != -1 && dir == -1) return 1+esq;
  if(esq != -1 && dir != -1){
    if(esq > dir){
      return 1+dir;
    }
    else{
      return 1+esq;
    }
  }
}


//EXAME 13 de junho de 2023
int isFib (int x){
  int a = 0;
  int b = 1;

  while((b) <= x){
    int temp = a;
    a = b;
    b = temp +a;

    if(b == x) return 0;
  }
  return -1;
}

//2
typedef struct {
  float teste, minis;
} Aluno;

float calculanota(Aluno t){
  return (0.8*t.teste + 0.2*t.minis);
}

int moda(Aluno turma[], int N){
  int i;
  int freq = 0;
  int maisfreq = 0;
  int nota = 0;

  for(i = 0; i < N; i++){
    if(calculanota(turma[i]) == calculanota(turma[i+1])){
      freq++;
      nota = calculanota(turma[i]);
    }
    if(freq > maisfreq){
      maisfreq = freq;
      freq = 0;
    }
  }
   if(freq > maisfreq){
      maisfreq = freq;
      freq = 0;
    }
    if(nota < 10) return 0;
    return nota;
}

//3
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

//4
int verifica(char frase[], int k){
  int nletras;
  int indice;
  for(indice = 0; frase[indice] != '\0'; indice++){
    for(nletras = 0; frase[nletras] != ' '; nletras++);
    if(nletras < k) return -1;
    indice = indice +1;
    nletras = 0;
  }
  return 0;
}



//TESTE 16 de maio de 2024

//2
void rodaEsq(int a[], int N, int r){
  int aux[r];
  int i;
  int j;
  for(i = 0; i < r; i++){
    aux[i] = a[i];
  }

  for(i = 0, j = r; r < N; i++, j++){
    a[i] = a[j];
  }

  for(i= N - r, j = 0; i < N; i++, j++){
    a[i] = a[j];
  }
}

//3

int delete(int n, LInt *l) {
    // Verificar se a lista está vazia
    if (*l == NULL) {
        return -1; // Código de erro: lista vazia
    }

    LInt atual = *l;
    LInt anterior = NULL;

    // Caso especial: remover o primeiro elemento (n == 0)
    if (n == 0) {
        *l = atual->prox;
        free(atual);
        return 0; // Sucesso
    }

    // Avançar até o n-ésimo elemento ou até o final da lista
    for (int i = 0; i < n; i++) {
        if (atual == NULL) {
            return -1; // Código de erro: índice fora dos limites da lista
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Verificar se alcançamos o final da lista antes de encontrar o n-ésimo elemento
    if (atual == NULL) {
        return -1; // Código de erro: índice fora dos limites da lista
    }

    // Remover o n-ésimo elemento
    anterior->prox = atual->prox;
    free(atual);

    return 0; // Sucesso
}

//4
int maxCresc(LInt l){
  if(l == NULL) return 0;


  int max = 1;
  int maximo = 1;

  for(;l->prox; l = l->prox){
  if(l->prox->valor > l->valor){
    max++;
  }
  else{
    if(max > maximo){
      maximo = max;
      
    }
    max = 1;
  }
  }
  if(max > maximo){
      maximo = max;
    }
  return maximo;
}

//5
ABin folhaEsq(ABin a) {
    if (a == NULL) return NULL;

    if (a->esq == NULL && a->dir == NULL) {
        return a;
    }

    ABin folha = folhaEsq(a->esq);
    if (folha != NULL) {
        return folha;
    }

    return folhaEsq(a->dir);
}