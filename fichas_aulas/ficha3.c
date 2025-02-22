#include <stdio.h>


/*
int main () {
int x [15] = {1, 2, 3, 4, 5,
6, 7, 8, 9,10,
11,12,13,14,15};
int *y, *z, i;
y = x;
z = x+3;
for (i=0; i<5; i++) {
printf ("%d %d %d\n",
x[i], *y, *z);
y = y+1; z = z+2;
}
}


OUTPUT:
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12


NOTAS:


p(*(x+1)) == p x[1]

x + i * sizeof(int) -----ver depois melhor




*/


/*
int main () {
int i, j, *a, *b;
i=3; j=5;
a = b = 42;
a = &i; b = &j;
i++;
j = i + *b;
b = a;
j = j + *b;
printf ("%d\n", j);
return 0;
}

OUTPUT: 13
*/

//Exercicio 3



void swapM (int *x, int *y){

  int i, j;

   i = *x;
   j = *y;

  *x = j;
  *y = i;

}


/* --Funciona
int x = 3, y = 5;
  swapM (&x, &y);
  printf ("%d %d\n", x, y);




NOTAS:

é boa ideia criar um temporario para armazenar as coisas e assim funciona melhor, ou parece

*/


//Exercicio 4
/*

  int v[11] = {0,1,2,3,4,5,6,7,8,9,10};

  swap(v, 2, 3);
  int i;

  for( i = 0; i < 11; i++)
    printf( "%d\n", v[i]);


*/

void swap (int v[], int i, int j){

  int tmp = v[i];
  v[i]= v[j];
  v[j]=tmp;
  
}

int maximum (int v[], int N, int *m){

  if (N == 0){
    return -1;
  }

  (*m)= v[0];

  int i;
  for(i=1; i < N; i++){
    if (v[i] > (*m)){
      (*m) = v[i];
    }
  }

  return 0;
}

/* Exercicio 6
 int v[4] = {6, 12, 3, 9};

  int m;

  if(maximum(v,4,&m) == 0){
    printf("%d\n", m);
  } else {
    printf("Nao foi encontrado maximo");
  }

*/

// Exercicio 8

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

  int v[4] = {6, 12, 3, 9};

  int m;

  if(maximum(v,4,&m) == 0){
    printf("%d\n", m);
  } else {
    printf("Nao foi encontrado maximo");
  }

  return 0;
}