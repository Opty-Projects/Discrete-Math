#include "N_Fibonacci.h"
#include <stdio.h>

int main() {

    /* Criacao da variavel local */
    int n;

    /* Pede ao utilizador um input valido */
    printf("Insert n € N:\n");
    if (printf(">>> "), scanf(" %d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    /* Print do n-ésimo termo da serie fibonacci */
    printf("%lld\n", nFibonacci(n));

    return 0;
}
