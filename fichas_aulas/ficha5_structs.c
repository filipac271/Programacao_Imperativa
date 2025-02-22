#include <math.h>
#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

#define NUM_MINI_TESTES 0.25

void dumpV(int v[], int N) {
    int i;
    for (i = 0; i < N; i++);
}
void imprimeAluno(Aluno *a) {
    int i;
    printf("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for (i = 1; i < 6; i++)
    for (i = 1; i < NUM_MINI_TESTES; i++)
        printf(", %d", a->miniT[i]);
    printf(") %5.2f %d\n", a->teste, nota(*a));
}

int nota(Aluno a) { return 0; }
float mediaMiniTestes(int miniT[]) {
    int i;
    int soma = 0;
    for (i = 0; i < NUM_MINI_TESTES; i++)
        soma += miniT[i];
    return soma * 2; // ponderado para 20 valores
}

int nota(Aluno a) {
    float notaMiniTestes = mediaMiniTestes(a.miniT);

    if (notaMiniTestes < (20 * NUM_MINI_TESTES )) {
        return 0;
    }

    float notaFinal = a.teste * 0.8 + notaMiniTestes * 0.2;

    if (notaFinal < 9.5)
        return 0;

    return round(notaFinal); // alternativamente somar 0.5
    // com a math.h temos de passar a flag -lm
}

int procuraNum(int num, Aluno t[], int N) { return -1; }


