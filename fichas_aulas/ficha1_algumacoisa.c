#include <stdio.h>
#include <stdlib.h>

int main(){

  int num;
  int lim;

  printf("Enter a number: ");
  scanf("%d", &num);



void xadrez(int n);{
  for (lim = 0; lim < num; lim++){
    for(int j = 0; j < num; j++)
    if(((lim + j)%2)== 0){
      printf("#");
      
    } else if((lim%2) != 0) {
      printf("_");
      
    } 
    printf("\n");
  }

}

  return 0;
}