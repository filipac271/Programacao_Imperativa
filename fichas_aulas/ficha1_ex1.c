#include <stdio.h>
#include <stdlib.h>

int main(){

  int num;

  printf("Enter a number: ");
  scanf("%d", &num);


  int lim;
  for(lim = 0; lim < num; lim++){
    for(int j = 0; j < num; j++){
      printf("#");
    }
    printf("\n");
  }


  return 0;
}