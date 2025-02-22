#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin constroi_aux (char s[], int i){
  ABin a = malloc(sizeof(struct nodo));

  if (s[i] == '*' || s[i] == '\0') return NULL;


  if(s[i] != '\0'){
    a->valor = s[i] -'0';
    if(s[i+1] != '*'){

      a->esq = constroi_aux(s, i+1);
    } else {
      
     a->dir = constroi_aux(s, i+1);
    }
  }
  return a;
}

ABin reconstroi(char s[]){
  
  if (s[0] == '*' || s[0] == '\0') return NULL;
  
  return (constroi_aux(s, 0));
}



int main (){
  char s[] = "34**52**5*6**";

reconstroi(s);



}