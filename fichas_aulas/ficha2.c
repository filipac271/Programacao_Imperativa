#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 
 float multInt(int n, float m){

  float s = 0;
  for(int n1 = 0; n1 < n; n1++) 
  s += m;

  return s;
  }

float multInt2(int n, float m){
  float soma= 0.0;

while(n > 0){
  if (n % 2 == 1){
    soma += m;
  }

  n /= 2;
  m *= 2;

}

}

int mdc1(int a, int b){
  int menor;

  if(a < b){
    menor = a;
  } else {
    menor = b;
  }

  int r = 1;
  int i;
  for (i=1; i <= menor; i++) {
    if(a%i == 0 && b%i == 0){
      r = i;
    }
  }
  return r;
}


/*
int mdc1_b(int a, int b){
  int menor = (a < b) ? a : b;

  int i; 
  for (i = menor; i > 1; i--)

}
*/

int mdc2 (int a, int b){


  if(a==b) {
    return a;
  }

  if(a > b){
    return mdc2 (a-b, b);
  }
  return mdc2(a, b-a);
}

int mdc2_semrec (int a, int b){

  while (a!= 0 && b!= 0){
    if (a > b){
      a-=b;
    } else if (b > a){
      b-=a;
    } else {
      return a;
    }
  }
}

int fib1 (int n){
  
  if(n < 2) return 1;
  
  return fib1(n -1) + fib1(n-2);
  
}

int fib2 (int n){
int acc1, acc2;
acc1=acc2=1;

int i;
for(i= 3; i <= n; i++){
  //int r = acc2;
  //acc2 = acc2 + acc1
  // acc1 = r;

  acc2 = acc2 + acc1;
  acc1 = acc2 - acc1;
}
return acc2;
}




int main(){

 //assert(multInt2(2 3.0) == 6.0 );
 //assert(mdc1(4, 6) == 2);
 //assert (mdc2 (4, 6) == 2);
 // assert (mdc2_semrec (4,6)== 2);
 assert(fib1(3)==2);
 
  
  return 0;
}