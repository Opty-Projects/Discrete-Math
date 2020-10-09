#include "RSAPublicKey.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    /* Criacao das variaveis locais */
    long long p, q, p_q_, a;

    /* Valor maximo para nao dar overflow */
    const long long MAX = (long long) (sqrt(sqrt(LONG_MAX))) - 1;

    /* Gera p, q primos < MAX */
    srand(time(NULL));
    while (p = rand() % MAX, !isPrime(++p))
        ;
    while (q = rand() % MAX, !isPrime(++q))
        ;

    /* Gera a coprimo coprimo e < (p-1)(q-1) */
    p_q_ = (p - 1) * (q - 1) - 1;
    while (a = rand() % p_q_, !coprime(++a, p_q_ + 1))
        ;

    /* Print da chave publica */
    printf("Public Key:\n");
    printf("(%lld,%lld)\n", p * q, a);

    return 0;
}
