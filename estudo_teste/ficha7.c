#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;


void libertaLista (Palavras l){
  Palavras aux;

  while(l != NULL){
    aux = l;
    l = l->prox;
    free(aux->palavra);
  }
  free(aux);
}

int quantasP (Palavras l){
  int acc = 0;
  while(l != NULL){
    acc++;
    l = l->prox;
  }
  return acc;
}

void listaPal (Palavras l){
  while (l != NULL){
    printf("A palavra é %s e as ocorrencias sao %d\n", l->palavra, l->ocorr);
    l = l->prox;
  }
}


char * ultima (Palavras l){
  Palavras ultima;

  if(l == NULL) return NULL;

  while((l->prox) != NULL){
    ultima->palavra = l->palavra;
    l = l->prox;
  }
  return (ultima->palavra);
}

Palavras acrescentaInicio (Palavras l, char *p){
  Palavras nova = malloc(sizeof(struct celula));

  if(l == NULL){
    l->palavra = p;
    l->ocorr = 1;
    l->prox = NULL;
  }else{
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
  }
  return nova;
}

Palavras acrescentaFim (Palavras l, char *p){
  Palavras nova = malloc(sizeof(struct celula));

   nova->palavra = p;
   nova->ocorr = 1;

  if(l == NULL) return acrescentaInicio(l,p);

  Palavras cabeca = l;

  while(l->prox != NULL){
    l = l->prox;
  }
    l->prox = nova;
    nova->prox = NULL;

  return cabeca;
}

int jaexiste (Palavras l, char *p){
  while(l != NULL){
    if(l->palavra == p) return 0;
    l = l->prox;
  }
  return 1;
}

Palavras incrementa (Palavras l, char *p){
  Palavras cabeca = l;
  while(l != NULL){
    if(l->palavra == p){
      l->ocorr++;
      return cabeca;
    }
    l = l->prox;
  }
}

// Palavras acrescenta (Palavras l, char *p){
//   if(l == NULL) return acrescentaInicio(l, p);

//   if(jaexiste(l, p) == 0){
//     return incrementa(l,p);
//   } else{

//   }

// }

Palavras acrescenta(Palavras l, char *p) {
    if (l == NULL || strcmp(p, l->palavra) < 0) {
        return acrescentaInicio(l, p);
    }

    Palavras cabeca = l;
    Palavras ant = l;

    while (l != NULL) {
        if (strcmp(l->palavra, p) == 0) {
            l->ocorr++;
            return cabeca;
        }

        if (strcmp(p, l->palavra) < 0) {
            ant->prox = acrescentaInicio(l, p);
            return cabeca;
        }

        ant = l;
        l = l->prox;
    }

    Palavras novo = acrescentaInicio(l, p);
    ant->prox = novo;

    return cabeca;
}

struct celula *maisFreq(Palavras l) {
    struct celula *maior = NULL;
    if (l != NULL)
        maior = l;

    while (l != NULL) {
        if (l->ocorr > maior->ocorr) {
            maior = l;
        }

        l = l->prox;
    }

    return maior;
}
