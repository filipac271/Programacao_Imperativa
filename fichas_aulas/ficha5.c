#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno {
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno;


void dumpV(int v[], int N) {
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", v[i]);
}
void imprimeAluno(Aluno *a) {
    int i;
    printf("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for (i = 1; i < 6; i++)
        printf(", %d", a->miniT[i]);
    printf(") %5.2f %d\n", a->teste, nota(*a));
}

int nota(Aluno a) {
    float mediaMiniTestes;
    int somaMiniTestes = 0;
    int i;

    for (i = 0; i < NUM_MINI_TESTES; i++) {
        somaMiniTestes += a.miniT[i];
    }

    mediaMiniTestes = somaMiniTestes / NUM_MINI_TESTES;

    if (mediaMiniTestes < 5) {
        return 0;
    }

    float mediaPonderada = 0.8 * a.teste + 0.2 * mediaMiniTestes;

    int notaFinal = (int)mediaPonderada + 0.5;

    // if (notaFinal < 10) {
    //     return 0;
    // }

    // return notaFinal;

    return notaFinal < 10 ? 0 : notaFinal;
}


void ordenaPorNumero(Aluno t[], int N){
  int i, j; Aluno c;
  for(i = 0; i < N; i++){
    c = t[i];
  }
  for(j = i; j > 0 && t[j-i].numero > c.numero ; j--){
    t[j] = t[j-1];
    t[j] = c;

  }
}








































