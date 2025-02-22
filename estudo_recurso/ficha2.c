#include <stdio.h>
#include <stdlib.h>

float multInt1 (int n, float m){
  int i;
  float acc = 0;

  for(i = 0; i < n; i++){
    acc += m;
  }
  return acc;
}

float multInt2 (int n, float m){
  int i;
  float acc = 0;
  for(i = 1; n > 1; i++){
    n = n/2;
    m = m/2;
    if(n%2 != 0){
      acc = acc +m;
    }
  }
  return acc;
}

int mdc1 (int a, int b){
  int maiordivisor = 0;
  for (int i = a; i >0; i--){
    if(i%a == 0 && i%b == 0){
      maiordivisor = i;
    }
  }
  return maiordivisor;
}

int mdc2 (int a, int b) {
  
}
