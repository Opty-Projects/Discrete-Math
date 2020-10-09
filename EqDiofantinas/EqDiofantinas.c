#include "EqDiofantinas.h"
#include <stdio.h>

int main() {

    /* Criacao das variaveis locais */
    int vars[5], res, abs0, abs1, mem;
    char str[50], ch;

    /* Pede ao utilizador um input valido */
    printf("Enter your equation like:\n");
    printf("| ax +/- by = res\n>>> ");
    fgets(str, 50, stdin);

    /* Validacao do input */
    if (sscanf(str, " %d x + %d y = %d", &vars[0], &vars[1], &res) == 3)
        ;
    else if (sscanf(str, " %d x - %d y = %d", &vars[0], &vars[1], &res) == 3)
        vars[1] *= -1;
    else {
        printf("Invalid input!\n");
        return 1;
    }

    /* Pede ao utilizador outro input valido e valida-o */
    printf("You want to build the board? (y or n)\n");
    if (printf(">>> "), ch = getchar(), ch != 'y' && ch != 'n') {
        printf("Invalid input!\n");
        return 1;
    }

    /* Calcula o valor absoluto de a e de b */
    abs0 = abs(vars[0]);
    abs1 = abs(vars[1]);

    /* Caso o valor absoluto de b > a procede a troca */
    if (abs1 > abs0) {
        mem = vars[0];
        vars[0] = vars[1];
        vars[1] = mem;
    }

    /* Chama a funcao que encontra uma solucao particular */
    /* Caso ch = 'y' a funcao constroi o quadro do algaritmo de Euclides */
    /* Caso ch = 'n' a funcao nao o constroi */
    xiyi(vars, ch - 'n');

    /* Caso tenha havido troca dos valores a e b */
    /* Procede se de novo a troca tanto de a e b como xi e yi */
    /* Para que estes coincidam com a ordem dada pelo utilizador */
    if (abs1 > abs0) {
        mem = vars[0];
        vars[0] = vars[1];
        vars[1] = mem;
        mem = vars[3];
        vars[3] = vars[4];
        vars[4] = mem;
    }

    /* Print dos coeficientes */
    /* Forma do utilizador poder validar os coeficientes percebidos pelo programa
   */
    printf("A equacao diofantina com coeficientes\n");
    printf("| a = %d\n| b = %d\n| res = %d\n", vars[0], vars[1], res);

    /* Print da solucao geral da equacao */
    /* Ou explicacao pela qual nao existem solucoes em Z para a equacao */
    if (res % vars[2] != 0)
        printf("Nao tem solucoes em Z, %d nao e multiplo do mdc(%d,%d)\n", res,
               vars[0], vars[1]);
    else {
        printf("Tem como solucao geral\n");
        printf("| x = %d + (%d/%d)*k\n", vars[3] * (res / vars[2]), vars[1],
               vars[2]);
        printf("| y = %d - (%d/%d)*k\n", vars[4] * (res / vars[2]), vars[0],
               vars[2]);
        printf("Com k € Z\n");
    }
    return 0;
}
