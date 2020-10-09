#include "MDC.h"
#include <stdio.h>

int main() {

    /* Criacao das variaveis locais */
    long long a, b;

    /* Pede ao utilizador inputs validos */
    printf("Insere 2 valores:\n");
    if (printf(">>> "), scanf(" %lld", &a) != 1) {
        printf("Invalid input!\n");
        return 1;
    }
    if (printf(">>> "), scanf(" %lld", &b) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    /* Print do mdc(a,b) */
    printf("mdc(%lld,%lld) = %d\n", a, b, mdc(abs(a), abs(b)));

    return 0;
}
