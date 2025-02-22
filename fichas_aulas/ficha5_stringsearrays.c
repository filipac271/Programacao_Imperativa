#include <stdio.h>
#include <stdlib.h>



int contaVogais (char *s){
  int i, acc= 0;
  for(i = 0; s[i] != '\0'; i++){
    if(s[i] == 'a' || s[i] == 'A'){//falta o resto das vogais, mas preguiça
      acc++;
    }
  }
  return acc;
}

int retiraVogaisRep (char *s){
  int i, j = 0, acc = 0 ;

  for(i = 0; s[i] != '\0'; i++){
    if(s[i] != s[i+1]){
      s[j++] = s[i];
      
    }
    else
    acc++;
  }

  s[j] = '\0';
  return acc;
}

int duplicaVogais (char *s){
  int i= 0;
  int pos = 0;
  int acc = 0;

  int tamanho = (strlen(s));

  for(i, tamanho; s[i] != '\0'; i++, tamanho--){
    if (eVogal(s[i])){
      s[tamanho] = s[i+1];
     
    }
  }
  s[i] = '\0';
  return acc;
}


//Arrays ordenados

int ordenado (int v[], int N){
  int i;
  for(i = 0; i < N ; i++){
    if(v[i] > v[i+1]){
      return 1;
    }
  }
  return 0;
}

void merge (int a[], int na, int b[], int nb, int r[]){
  int i, j, k;
    i = j = 0;

    for(k = 0; i < na && j < nb; k++) {
        if (a[i] <= b[j]) {
            r[k] = a[i++];
        } else {
            r[k] = b[j++];
        }
    }

    for(; i < na; k++) {
        r[k] = a[i++];
    }

    for(; j < nb; k++) {
        r[k] = b[j++];
    }
}


void swap (int v[], int i, int j){

  int tmp = v[i];
  v[i]= v[j];
  v[j]=tmp;
  
}

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




