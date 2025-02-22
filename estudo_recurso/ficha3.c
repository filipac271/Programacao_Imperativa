#include <stdio.h>
#include <stdlib.h>

void swapM (int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void swap (int v[], int i, int j){
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


int soma (int v[], int N){
  int i;
  int acc = 0;
  for(i=0; i < N; i++){
    acc = v[i] + acc;
  }
  return acc;
}

void inverteArray (int v[], int N){
  int i, j;
  for(i = 0, j = N; i < j; i++, j--){
    swap(v, i, j);
  }
}

int maximum (int v[], int N, int *m){
  int maior = 0;

  if(N < 0) return 1;

  for(int i = 0; i< N; i++){
    if(v[i] > maior){
      maior = v[i];
    }
  }
  *m = maior;
  return 0;
}

//meio estranho o enunciado entao yhh nao entendi se é isto que querem
 void quadrados (int q[], int N){
  int i;
  for(i = 0; i< N; i++){
    q[i] = i*i;
  }
 }


void pascal (int v[], int N) {

}