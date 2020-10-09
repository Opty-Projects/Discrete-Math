#include "PrimeFactor.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Criacao das variaveis locais */
    long long input;
    int i, n, lstPrimes[100];

    /* Pede ao utilizador um input valido */
    printf("Insert a number € N2:\n");
    if (printf(">>> "), scanf("%lld", &input) != 1)
        return 1;

    /* Validacao do input */
    if (input < 2) {
        printf("Invalid input!\n");
        return 1;
    }

    /* Print da lista que contem a fatorizacao do numero */
    n = PrimeFact(input, lstPrimes);
    qsort(lstPrimes, n, sizeof(int), ascend);

    /* Print da lista */
    printf("Integrer factorization:\n{");
    for (i = 0; i < n; i++)
        printf("%d,", lstPrimes[i]);
    printf("\b}\n");

    return 0;
}
