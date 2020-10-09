#include "Congruence.h"
#include <stdio.h>

int main() {

    /* Criacao das variaveis locais */
    char ch;
    long long base, exp, mod;

    /* Pede ao utilizador um input valido */
    printf("Enter your congruence like:\n");
    printf("| mod(base^exp, mod)\n");
    if (printf(">>> "),
        scanf(" mod ( %lld ^ %lld , %lld )", &base, &exp, &mod) != 3) {
        printf("Invalid input!\n");
        return 1;
    }

    /* Validacao do input */
    if (base < 0 || exp < 0 || mod < 0) {
        printf("Invalid input < 0!\n");
        return 1;
    }

    /* Pede ao utilizador outro input valido e valida-o */
    printf("You want to see the phases of congruence resolution? (y or n)\n");
    if (printf(">>> "), cleanBuffer(), ch = getchar(), ch != 'y' && ch != 'n') {
        printf("Invalid input!\n");
        return 1;
    }

    /* Print do mod(base^exp, mod) */
    printf(">>> mod(%lld^%lld,%lld) = %lld\n", base, exp, mod,
           congruence(base, exp, mod, ch - 'n'));

    return 0;
}
