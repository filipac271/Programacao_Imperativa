#include <stdio.h>
#include <stdlib.h>
 
 float multInt1 (int n, float m){
  int i;
  float r = 0;
  for (i = 0; i < n; i++){
    r = r + m;
  }
  return r;
 }

float multInt2 (int n, float m){
  float r = 0;

  while(n != 0){
    if(n%2 != 0){
      r = r + m;
     
    }

    n = n/2;
    m = m *2;
  }
  return r;
}


int mdc1 (int a, int b){
  int menorn = 0;

  if( a < b){
    menorn = a;
  } else{
    menorn = b;
  }

  int r = 1;
  int i;
  for (i=1; i <= menorn; i++) {
    if(a%i == 0 && b%i == 0){
      r = i;
    }
  }
  return r;
}

int mdc2 (int a, int b){
  if(a > b){
    a = a-b;
  } else if(a < b){
    b = b-a;
  } else return a;

  while(a != 0 && b != 0){
    if(a > b){
    a = a-b;
  } else if(a < b){
    b = b-a;
  } else return a;
  }
  return a;
}

int mdc3 (int a, int b){
    if(a > b){
    a = a-b;
  } else if(a < b){
    b = b-a;
  } else return a;

  while(a != 0 && b != 0){
    if(a > b){
    a = a%b;
  } else if(a < b){
    b = b%a;
  } else return a;
  }
  return a;
}

int fib1 (int n){
  if(n < 2) return 1;

  else return (fib1(n-1) + fib1(n-2));
}


int fib2 (int n){
  int acc1, acc2;
  acc1=acc2=1;

  int i;

for(i= 3; i <= n; i++){
  
  acc2 = acc2 + acc1;
  acc1 = acc2 - acc1;
}
return acc2;
}



//Main 

 int main (){
  int n = 3;
  float m = 2.5;

  float resultado = multInt2(n, m);

  printf("o resultado é %f\n", resultado);

  return 0;

 }