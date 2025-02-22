#include <stdio.h>
#include <stdlib.h>

void triangulo(int n) {
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = n - i; j > 0; j--) {
            putchar(' ');
        }

        for (k = 1; k <= (i * 2 - 1); k++) {
            if (i > 2) {
                putchar('*');
            } else {
                putchar('*');
            }
        }
        putchar('\n');
    }
}
