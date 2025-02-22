#include <stdio.h>
#include <stdlib.h>

void triangulo(int n) {
    int i, j;

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= j; i++) {
        putchar('#');
        }
        putchar('\n');
    }

    for (j = n - 1; j > 0; j--) {
        for (i = j; i > 0; i--) {
            putchar('#');
        }
        putchar('\n');
    }
}
