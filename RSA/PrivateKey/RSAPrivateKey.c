#include "RSAPrivateKey.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Criacao das variaveis locais */
    long long a, b, n;
    int lstPrimes[100];

    /* Pede um input valido ao utilizador */
    printf("Public Key:\n");
    if (printf(">>> "), scanf(" ( %lld , %lld )", &n, &a) != 2) {
        printf("Public Key is invalid!\n");
        return 1;
    }

    /* Validacao do input */
    if (PrimeFact(n, lstPrimes) != 2) {
        printf("Value n is invalid!\n");
        return 1;
    }
    if (!coprime(a, (lstPrimes[0] - 1) * (lstPrimes[1] - 1))) {
        printf("Value a is invalid!\n");
        return 1;
    }

    /* Descobre o inverso de a mod (p-1)(q-1) */
    b = inverse(a, (lstPrimes[0] - 1) * (lstPrimes[1] - 1));

    /* Print da chave privada */
    printf("Correspondent Private Key:\n");
    printf("(%lld,%lld)\n", n, b);

    return 0;
}
