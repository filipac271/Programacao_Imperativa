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
  int i, acc = 0;

  for(i = 0; i < N; i++){
    acc = acc + v[i];
  }

  return acc;
}

void inverteArray (int v[], int N){
  int i, temp;

  for(i = 0; i != N; i++, N--){
    temp = v[i];
    v[i] = v[N];
    v[N] = temp;
  }

}

int maximum (int v[], int N, int *m){
  int i, max = 0;

  if(N == 0) return (-1);

  for(i = 0; i < N; i++){
    if(v[i] > max){
      max = v[i];
      *m = max;
    }
  }
  return 0;

}


void quadrados (int q[], int N){

  int i;

  for(i = 0; i < N; i++){
    q[i] = i*i;
  }
}

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
  int x = 3, y = 5;
swapM (&x, &y);
printf ("%d %d\n", x, y);

return 0;
}