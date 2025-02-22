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

  for(i = 0; i < N; i++){
    acc = acc + v[i];
  }

  return acc;
}

void inverteArray (int v[], int N){
  int i;
  int j;
  for(i = 0, j = N; i != j; i++, j--){
    swap(v, i, j);
  }
}

int maximum (int v[], int N, int *m){
  int maior = 0;
  int i;
  for(i = 0; i < N; i++){
    if(v[i] > maior){
      maior = v[i];
    }
  }
  (*m) = maior;
  return (*m);
}

//nao esta feita como é pedido, no entanto nao entendi o que querem
void quadrados (int q[], int N){
  int i;
  for(i = 0; i< N; i++){
    q[i] = q[i]*q[i];
  }
}

//meio estranha nao entendi muito bem
void pascal(int v[], int N){
  if (N == 1) {
    v[0]= 1;
    printf("%d\n", v[0]);
  } else {

    int ant[N-1];
    pascal(ant, N-1);

    v[0]= 1;
    v[(N -1 )]= 1;

    int i;
    for(i = 1;i < N-1; i++){
      v[i] = ant[i-1] + ant[i];
    }

    for(i = 0; i < N; i++){
      printf("%d", v[i]);
    }
    printf("\n");


  }
}


int main(){
  //int x = 3, y = 5;
  //swapM (&x, &y);
  //printf ("%d %d\n", x, y);

  int v[10] = {1,2,4,5,6,7,8,8,4};
  int N = 10;
  int *m;

  int resultado = maximum(v, N, &m);
  printf("o resultado é %d",resultado);
}