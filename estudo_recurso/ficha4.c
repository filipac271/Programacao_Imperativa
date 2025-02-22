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
  int i, j;
  int acc = 0;

  for(i = 0, j = 0; s[i] !='\0'; i++){
    if(s[i] != s[i+i]){
      s[j++] = s[i];
    }
    else acc++;
  }
  return acc;
}

 int duplicaVogais (char *s){
  int i;
  int j;
  int acc = 0;
  for( i = 0, j = 0; s[i] != '\0'; i++){
    if(vogal(s[i]) == i){
      s[j] = s[(j+1)] = s[i];
      j = j+2;
      acc++;
    }
    else{
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
  return acc;
 }

 int ordenado (int v[], int N){
  int i;
  for(i = 0; i < N; i++){
    if(v[i+1] < v[i]) return 0;
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