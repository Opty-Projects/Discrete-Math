#include "M2x2Encode.h"
#include <stdio.h>

int main() {

    /* Criacao das variaeis locais */
    char str[100], code[100], ch;
    int vetor[2], matriz[2][2], i, t, overflow;

    /* Pede ao utilizador um input valido */
    printf("Insere a tua string ('a' <= char <= 'z'):\n>>> ");
    fgets(str, 100, stdin);

    /* Filtra a str de modo a ficar apenas com ('a' <= char <= 'z') */
    for (i = t = 0; str[t]; t++)
        if (str[t] >= 'a' && str[t] <= 'z')
            str[i++] = str[t];
    str[i++] = '\0';

    /* Pede ao utilizador outro input valido e valida-o */
    printf("You want to see the code matrix? (y or n)\n");
    if (printf(">>> "), ch = getchar(), ch != 'y' && ch != 'n') {
        printf("Invalid input!\n");
        return 1;
    }

    /* Gera uma matriz 2x2 cujo mdc(determinante, 26) = 1 */
    M2x2Cop26(matriz);

    /* Caso ch = 'y' da print da matriz usada na codificacao da str */
    /* Caso ch = 'n' nao da print */
    if (ch - 'n') {
        printf("Code matrix:\n");
        for (i = 0; i < 2; i++) {
            printf("| ");
            for (t = 0; t < 2; t++)
                printf("%2d ", matriz[i][t]);
            printf("|\n");
        }
    }
    /* Codifica a str tendo por base a matriz gerada */
    /* Caso a str tenha nº letras impar overflow = 1, caso seja par overflow = 0
   */
    overflow = CodeStrM2x2(matriz, str);

    /* Da print da str codificada */
    printf("A tua string codificada:\n");
    printf(">>> %s%d\n", str, overflow);

    return 0;
}
