#include "Divisors.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Criacao das variaveis locais */
    long long input;
    int lstPrimes[100], *varre, *div, i, t, x, y, n, k, j;

    /* Pede ao utilizador um input adequado */
    printf("Insert a number € N:\n");
    if (printf(">>> "), scanf("%lld", &input) != 1)
        return 1;

    /* Validacao do input */
    if (input < 1) {
        printf("Invalid input!\n");
        return 1;
    }
    if (input == 1) {
        printf("{%d}\n", 1);
        return 0;
    }

    /* Faz a fatorizacao do input */
    /* Atribui a n o nº de primos constituintes na sua fatorizacao */
    n = PrimeFact(input, lstPrimes);

    /* Cria a lista com o tamanho maximo */
    /* Como se todos os primos fossem diferentes */
    varre = (int *) (malloc(sizeof(int) * n));

    /* Conta o nº de primos iguais */
    /* Filtra os nºs primos diferentes */
    for (i = t = 0; i < n; i++)
        if (!count(lstPrimes[i], lstPrimes, 0, t)) {
            varre[t] = count(lstPrimes[i], lstPrimes, t, n);
            lstPrimes[t++] = lstPrimes[i];
        }
    /* Descobre quantos divisores tem o input */
    for (i = 0, n = 1; i < t; i++)
        n *= varre[i] + 1;

    /* Print a number of divisors */
    printf("The number has %d divisors!\n", n);

    /* Cria a lista com o tamanho adequado */
    div = (int *) (malloc(sizeof(int) * n));

    /* Preenche a lista com as combinacoes possiveis de um primo */
    i = 0;
    div[i] = 1;
    while (i++, varre[0]--)
        div[i] = lstPrimes[0] * div[i - 1];

    /* Prrenche a lista com as combinacoes possiveis dos restantes primos */
    /* Multiplicando-se aos elementos da lista */
    /* Tantas vezes quantas aparece na fatorizacao do input */
    for (x = 1, n = k = 0; x < t; x++, n = 0)
        while (k = n, n = i, varre[x]--)
            for (y = k, j = i; y < j; y++)
                div[i++] = div[y] * lstPrimes[x];

    /* Ordena a lista de divisores */
    qsort(div, i, sizeof(int), ascend);

    /* Print da lista */
    printf("List of divisors:\n{");
    for (t = 0; t < i; t++)
        printf("%d,", div[t]);
    printf("\b}\n");

    return 0;
}
