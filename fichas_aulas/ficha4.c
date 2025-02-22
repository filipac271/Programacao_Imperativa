#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


int eVogal(char l){
  l = tolower(l);

  return(l == 'a' ||l == 'e' || l == 'i' || l == 'o' || l == 'u' );

}




int contaVogais(char *s)
{
  int acc = 0;

  for (int i = 0; s[i] != '\0'; i++)
  {
    if(eVogal(s[i]))  
       //if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
    {
      acc++;
    }
  }
  return acc;
}

int retiraVogaisRep(char *s)
{
  int i;
  int pos = 0;
  int acc = 0;

  for (i = 0; s[i] != '\0'; i++)
  {
    if (s[i] != s[i + 1])
    {
      s[pos++] = s[i];
    }
    else
    {
      acc++;
    }
  }
  s[pos] = '\0'; 
  return acc;
}

//nao funfa
int retiraVogaisRep1(char *s){
  int tamanho = strlen(s);
  char aux[tamanho+1];
  int acc = 0;

  aux[0] = s[0];

  int i;
  int j= 1;
  for(i = 1; i < tamanho; i++){
    if(eVogal(s[i]) && s[i] == s[i-1]){
      acc++;
    } else {
      aux[j++] = s[i];
      // equivalente a 
      //aux[j] = s[i];
     // j++;
    }
  }

  for(i= 0; i<j; i++){
    s[i] = aux[j];
  }

  s[j] = '\0';

}




 int duplicaVogais(char *s)
{
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


int main()
{

  assert(2 == contaVogais("Ola"));
  //assert()



  char s1[100] = "Estaa e umaa string coom duuuplicadoos";
  int x;

  printf("Testes\n");
  printf("A string \"%s\" tem %d vogais\n", s1, contaVogais(s1));

  x = retiraVogaisRep(s1);
  printf("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

  x = duplicaVogais(s1);
  printf("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);

  printf("\nFim dos testes\n");

  return 0;
}