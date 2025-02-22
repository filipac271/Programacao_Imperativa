#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int procuraNum (int num, Aluno t[], int N){
  int i;

  for(i = 0; i < N && t[i].numero <= num; i++){
    if(t[i].numero == num){
      return i;
    }
  }
  return -1;
}


void swap_aluno(Aluno t[], int i, int j) {
    Aluno tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;
}

void ordenaPorNum(Aluno t[], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (t[j].numero > t[j + 1].numero) {
                swap_aluno(t, j, j + 1);
            }
        }
    }
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (t[ind[j]].numero > t[ind[j + 1]].numero) {
                swap(ind, j, j + 1);
            }
        }
    }
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (strcmp(t[ind[j]].nome, t[ind[j + 1]].nome) > 0) {
                swap(ind, j, j + 1);
            }
        }
    }
}
