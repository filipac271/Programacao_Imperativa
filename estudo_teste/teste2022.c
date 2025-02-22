#include <stdio.h>
#include <string.h>

void inc(char s[]) {
    int length = strlen(s);
    int carry = 1; // Começamos com 1 para indicar o incremento inicial
    for (int i = length - 1; i >= 0; i--) {
        int digit = s[i] - '0'; // Convertendo o caractere para o valor numérico
        digit += carry; // Adicionando o carry ao dígito atual
        if (digit > 9) { // Se o dígito for maior que 9, precisamos fazer o carry
            digit = 0;
            carry = 1;
        } else {
            carry = 0; // Se não precisarmos fazer o carry, podemos parar o loop
        }
        s[i] = digit + '0'; // Convertendo o valor numérico de volta para caractere
    }
    
    // Se ainda houver um carry no final do loop, precisamos adicionar um novo dígito
    if (carry == 1) {
        // Deslocamos todos os dígitos para a direita para fazer espaço para um novo dígito
        memmove(s + 1, s, length + 1);
        s[0] = '1'; // O primeiro dígito se torna 1
    }
}

// int main() {
//     char number[] = "235";
//     printf("Número antes do incremento: %s\n", number);
//     inc(number);
//     printf("Número após o incremento: %s\n", number);
//     return 0;
// }

void swap(int a[], int i, int j) {
int aux = a[i];
a[i] = a[j];
a[j] = aux;
}

void bubble(int a[], int n) {
int i;
for (i = 1; i < n; i++)
if (a[i-1] > a[i])
swap(a, i-1, i);
}

void bsort(int a[], int n) {
int i;
for (i = n; i > 0; i--)
bubble(a, i);
}

int enesimo (int a[], int N, int i){
    bsort(a, N);
    if(i-1 <= N){
        return a[i-1];
    }else return -1;
}


int main(){

  int v[4] = {6, 12, 3, 9};
  int menor;

  menor = enesimo(v,4,4);


  printf("o menor é: %d", menor);


  return 0;
}