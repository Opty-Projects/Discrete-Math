#include "InverseMod.h"
#include <stdio.h>

int main() {

    /* Criacao das variaveis locais */
    long long num, mod;

    /* Pede ao utilizador inputs validos */
    printf("Insert n, m: mod(n * ñ, m) = 1\n");
    if (printf("n = "), scanf(" %lld", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (printf("m = "), scanf(" %lld", &mod) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    num = abs(num);
    mod = abs(mod);
    /* Print ñ or no solution */
    if (!coprime(num, mod)) {
        printf("There is no ñ, mdc(%lld,%lld) = %d != 1\n", num, mod,
               mdc(num, mod));
        return 0;
    }
    printf("ñ = %lld + %lldk, k € Z\n", inverse(num, mod), mod);

    return 0;
}
