#include <stdio.h>
#include <math.h> //gcc -lm circulo.c

int distancia(i, j, x, y){
  
  return (sqrt((pow((i-x), 2)) + (pow((j-y), 2))));
}


void circulo(int r){

int diametro = 2*r;
int c = 0; //contador de # 


for(int i= 0; i < diametro; i++){
    for(int j = 0; j < diametro; j++){

      if (distancia(i, j, r, r) < r) {
      putchar("#");
      c++;
    } else {
    putchar(' ');
  }
}
 putchar('\n');
}
}

int main(){
  int r;
  
  printf("Da-me o raio: ");
  scanf("%d\n", r);

  return 0;
}