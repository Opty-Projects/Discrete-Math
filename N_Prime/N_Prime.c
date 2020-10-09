#include "N_Prime.h"
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

    /* Print do n-ésimo primo */
    printf("%lld\n", nPrime(n));

    return 0;
}
