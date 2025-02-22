#include <stdio.h>
#include <stdlib.h>

int vogal (char c){
  if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
    return 1;
  }
  return 0;
}

int contavogais(char *s){
  int i;
  int acc = 0;
  for(i = 0; s[i] != '\0'; i++){
    if(vogal(s[i]) == 1){
      acc++;
    }
  }
  return acc;
}

int retiraVogaisRep (char *s){
  int i, j = 0;
  int acc = 0;


  for( i = 0; s[i] != '\0'; i++){
    if(s[i] != s[i+1]){
      s[j++] = s[i];
    } else acc ++;
  }
  s[j] = '\0';
  return acc;
}

//nao funfa
int duplicaVogais (char *s){
  char *aux;

  int i;
  int j = 0;
  int acc = 0;

  for(i = 0; s[i] != '\0'; i++){
    if(evogal(s[i]) == 0){
      s[j++] = s[i];
    }else {
      s[j] = s[(j+1)] = s[i];
      j = j+2;
      acc ++;
    }
  }
  s[j] = '\0';
  return acc;

}



// ARRAYS ORDENADOS

int ordenado (int v[], int N){
  int i;
  for(i = 0; i < N; i++){
    if(v[i] > v[i+1]){
      return 0;
    }
  }
  return 1;
}

void merge(int r[], int a[], int b[], int na, int nb)
{
  int i, j, k;
  i = j = 0;

  for (k = 0; i < na && j < nb; k++)
  {
    if (a[i] <= b[j])
    {                // sinal !!!
      r[k] = a[i++]; // i++
    }
    else
    {
      r[k] = b[j++]; // j++
    }
  }

  for (; i < na; k++)
  {
    r[k] = a[i++];
  }

  for (; j < nb; k++)
  {
    r[k] = b[j++];
  }
}

void swap (int v[], int i, int j){

  int tmp = v[i];
  v[i]= v[j];
  v[j]=tmp;
  
}
// meio estranho, nao entendo muito bem
int partition (int v[], int N, int x){
  int a = 0;

  int i;
  for(i = 0; i < N; i++){
    if (v[i] <= x){
      swap (v, i, a++);
    }
  }
  return a; 
}