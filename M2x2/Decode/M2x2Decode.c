#include "M2x2Decode.h"
#include <stdio.h>

int main() {

    /* Criacao das variaveis locais */
    char str[100], ch;
    int matriz[2][2], i, t, overflow;

    /* Pede ao utilizador para introduzir um input valido */
    printf("Insere a string codificada:\n>>> ");
    fgets(str, 100, stdin);

    /* Validacao do codigo */
    for (i = 0; str[i] != '0' && str[i] != '1'; i++)
        if (str[i] < 'a' && str[i] > 'z') {
            printf("Codigo invalido\n");
            return 1;
        }
    if (i % 2) {
        printf("Codigo invalido\n");
        return 1;
    }

    /* Input da matriz de codificacao */
    printf("Insere a matriz que a codificou:\n");
    for (i = 0; i < 2; i++)
        for (t = 0; t < 2; t++) {
            printf("(%d, %d) -> ", i + 1, t + 1);
            scanf("%d", &matriz[i][t]);
        }

    /* Limpa o buffer apos scanf */
    cleanBuffer();
    /* Pede ao utilizador outro input valido e valida-o */
    printf("You want to see the descode matrix? (y or n)\n");
    if (printf(">>> "), ch = getchar(), ch != 'y' && ch != 'n') {
        printf("Invalid input!\n");
        return 1;
    }

    /* Descobre a matriz de descodificacao */
    /* Invertendo a matriz de codificacao */
    M2x2InvCop26(matriz);

    /* Caso ch = 'y' da print da matriz usada na descodificacao da str */
    /* Caso ch = 'n' nao da print */
    if (ch - 'n') {
        printf("Descode matrix:\n");
        for (i = 0; i < 2; i++) {
            printf("| ");
            for (t = 0; t < 2; t++)
                printf("%2d ", matriz[i][t]);
            printf("|\n");
        }
    }
    /* Descodifica a str com base na matriz de descodificacao */
    /* Caso a str descodificada tenha nº letras impar overflow = 1 */
    /* Caso seja par overflow = 0 */
    overflow = CodeStrM2x2(matriz, str);

    /* Print da str descodificada */
    printf("A tua string descodificada:\n");
    printf(">>> %s", str);
    if (overflow)
        printf("\b ");
    printf("\n");

    return 0;
}
