#include "TeoChinesRestos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* Criacao das variaveis locais */
    int i, n, coef[4];
    char ch, str[50];
    EqTCR *lst;
    SolTCR sol;

    /* Pede ao utilizador um input e valida-o */
    printf("How many equations have your system?\n>>> ");
    if (scanf(" %d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    cleanBuffer();

    /* Invorma o utilizador da estrutura a usar nas equacoes */
    printf("Insert equations like:\n");
    printf("| 1º Term = mod(__) 2º Term\n");

    /* Cria a lista de equacoes com o tamanho adequado */
    lst = (EqTCR *) (malloc(sizeof(EqTCR) * n));

    /* Pede ao utilizador as equacoes que constituem o sistema */
    printf("System:\n");
    for (i = 0; i < n; i++) {

        printf("| ");
        fgets(str, 50, stdin);

        /* Validacao do input */
        if (sscanf(str, " %d x + %d = mod ( %d ) %d", &coef[0], &coef[1], &coef[2],
                   &coef[3]) == 4)
            ;
        else if (sscanf(str, " %d x - %d = mod ( %d ) %d", &coef[0], &coef[1],
                        &coef[2], &coef[3]) == 4)
            coef[1] *= -1;
        else if (sscanf(str, " x + %d = mod ( %d ) %d", &coef[1], &coef[2],
                        &coef[3]) == 3)
            coef[0] = 1;
        else if (sscanf(str, " x - %d = mod ( %d ) %d", &coef[1], &coef[2],
                        &coef[3]) == 3) {
            coef[0] = 1;
            coef[1] *= -1;
        } else if (sscanf(str, " %d x = mod ( %d ) %d", &coef[0], &coef[2],
                          &coef[3]) == 3)
            coef[1] = 0;
        else if (sscanf(str, " x = mod ( %d ) %d", &coef[2], &coef[3]) == 2) {
            coef[0] = 1;
            coef[1] = 0;
        } else {
            printf("Invalid input\n");
            return 1;
        }

        /* Formata as equacoes do tipo x = mod(mod) num */
        simplyEqTCR(coef);
        lst[i].mod = coef[2];
        lst[i].num = coef[3];
    }

    /* Pede ao utilizador outro input valido e valida-o */
    printf("You want to see the phases of system resolution? (y or n)\n");
    if (printf(">>> "), ch = getchar(), ch != 'y' && ch != 'n') {
        printf("Invalid input!\n");
        return 1;
    }

    /* Caso ch = 'y' da print do sistema com as equacoes formatadas */
    /* Caso ch = 'n' nao da print */
    if (ch - 'n') {
        printf("System simplificated:\n");
        for (i = 0; i < n; i++)
            printf("| x = mod(%d) %d\n", lst[i].mod, lst[i].num);
    }

    /* Soluciona o sistema */
    /* Caso ch = 'y' vai dando prints das estapas de resolucao do sistema */
    /* Caso ch = 'n' nao da prints */
    sol = TCR(lst, n, ch - 'n');

    /* Print da solucao geral do sistema caso haja */
    if (sol.indice) {
        printf("General solution:\n");
        printf("| x = %d + %dk, k € Z\n", sol.x0, sol.diff);
    } else
        printf("The system have no solution\n");

    return 0;
}
