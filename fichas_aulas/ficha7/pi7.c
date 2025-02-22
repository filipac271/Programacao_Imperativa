#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CS50 MANUAL PAGES

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

void libertaLista (Palavras l){
    while(l != NULL){
      Palavras aux = l;
      l = l->prox;
      free(aux->palavra);

      free(aux);
    }
}

int quantasP (Palavras l){
  int acc = 0;
  while(l != NULL){
    l = l->prox;
    acc++;
  }
  return acc;
}

void listaPal (Palavras l){
    while (l != NULL){
      printf("+ %s  %d\n", l->palavra, l->ocorr);
      l = l->prox;
    }
}

char * ultima (Palavras l){
  char p;
  if(l == NULL) return NULL;
  while(l->prox != NULL){
    l = l->prox;
  }
   return l->palavra;
      
}

Palavras acrescentaInicio (Palavras l, char *p){
  Palavras novo = malloc(sizeof(struct celula));

  if(novo == NULL) return l;
  novo->palavra = strdup(p);
  novo->ocorr = 1;
  novo->prox = l;
  
    return novo;
}


Palavras acrescentaFim (Palavras l, char *p){
  if(l == NULL) return acrescentaInicio(l, p);

  Palavras cabeca = l;
  Palavras ant = l;

  while(l->prox != NULL){
    l = l->prox;
  }

  Palavras novo = malloc(sizeof(struct celula));
  if(novo != NULL){
  novo->palavra = strdup(p);
  novo->ocorr = 1;
  novo->prox = NULL;

  }

  l->prox = novo;


    return cabeca;
}

Palavras acrescenta (Palavras l, char *p){
  Palavras cabeca = l;
  Palavras ant = l;

    while(l != NULL){
      if(strcmp(l->palavra, p) == 0){
        l ->ocorr++;
        return cabeca;
      }

      if(strcmp(l->palavra, p) > 0){
        Palavras novo = acrescentaInicio(l, p);
        ant -> prox = novo;
        return cabeca;
      }
    }
    return NULL;
}

//gitlab tudo
struct celula * maisFreq (Palavras l){
    
    return NULL;
}

Palavras inicializa(Palavras dic){

}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}
