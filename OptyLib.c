#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define abs(n) n < 0 ? -n : n
#define mod(a, b) a % b < 0 ? a % b + b : a % b

typedef struct {
    int mod, num;
} EqTCR;

typedef struct {
    int x0, diff, indice;
} SolTCR;

long long congruence(long long base, long long exp, const long long mod,
                     int ind) {

    long long acc = 1;

    if (ind)
        printf("Phases:\n| %lld^%lld\n", base, exp);

    while (exp > 1) {
        if (exp % 2 != 0)
            acc = (acc * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
        if (ind && exp > 1)
            printf("| %lld^%lld * %lld\n", base, exp, acc);
    }
    if (ind)
        printf("| %lld * %lld\n", base, acc);

    return (base * acc) % mod;
}

void xiyi(int vars[5], int ind) {

    int ai, bi, am, xiant, xi, yi, yiant, xim, yim;

    ai = abs(vars[0]);
    bi = abs(vars[1]);
    xiant = yi = 1;
    yiant = xi = 0;

    if (ind) {
        printf("|-------|-------|-------|-------|\n");
        printf("|   ai  |   qi  |   xi  |   yi  |\n");
        printf("|-------|-------|-------|-------|\n");
        printf("| %5d |\t| %5d | %5d |\n", ai, xiant, yiant);
    }

    while (ai % bi) {
        if (ind)
            printf("| %5d | %5d | %5d | %5d |\n", bi, ai / bi, xi, yi);
        am = ai;
        ai = bi;
        xim = xi;
        yim = yi;
        xi = xiant - am / ai * xi;
        yi = yiant - am / ai * yi;
        xiant = xim;
        yiant = yim;
        bi = am % ai;
    }

    if (ind) {
        printf("| %5d | %5d | %5d | %5d |\n", bi, am / ai, xi, yi);
        printf("| %5d |\t|\t|\t|\n", 0);
        printf("|-------|-------|-------|-------|\n");
    }

    if (abs(vars[0]) != vars[0])
        xi *= -1;
    if (abs(vars[1]) != vars[1])
        yi *= -1;

    vars[2] = bi;
    vars[3] = xi;
    vars[4] = yi;
}

void MxVCop26(int matriz[2][2], int vetor[2]) {

    int vetorP[2], i, t;

    for (i = 0; i < 2; i++) {
        vetorP[i] = 0;
        for (t = 0; t < 2; t++)
            vetorP[i] += matriz[i][t] * vetor[t];
    }
    for (i = 0; i < 2; i++)
        vetor[i] = mod(vetorP[i], 26);
}

int CodeStrM2x2(int matriz[2][2], char str[]) {

    int vetor[2], i, t, overflow;

    i = overflow = 0;

    do {
        for (t = 0; t < 2; t++, i++)
            if (str[i])
                vetor[t] = str[i] - 'a';
            else
                vetor[t] = overflow = 1;

        MxVCop26(matriz, vetor);
        for (t = 0; t < 2; t++)
            str[i + t - 2] = vetor[t] + 'a';

    } while (str[i - 1] && str[i] && str[i] != '0' && str[i] != '1');

    if (str[i] == '1')
        overflow = 1;
    str[i] = '\0';

    return overflow;
}

int mdc(long long a, long long b) {

    long long ai = a, bi = b, am;

    while (ai % bi != 0) {
        am = bi;
        bi = ai % bi;
        ai = am;
    }
    return bi;
}

int coprime(long long a, long long b) { return mdc(a, b) == 1; }

long long inverse(long long num, long long mod) {

    long long ai, bi, am, xiant, xi, xim;

    const long long diff = mod / mdc(num, mod);

    ai = mod(num, mod);
    bi = mod;
    xiant = 1;
    xi = 0;

    while (ai % bi != 0) {
        xim = xiant;
        xiant = xi;
        xi = (xim - (ai / bi) * xiant) % diff;
        am = ai;
        ai = bi;
        bi = am % ai;
    }
    return xi < 0 ? xi + mod : xi;
}

void M2x2InvCop26(int matriz[2][2]) {

    int inv, permutation;

    inv = (int) (inverse(matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0],
                         26));

    permutation = matriz[0][0];
    matriz[0][0] = mod(inv * matriz[1][1], 26);
    matriz[0][1] = mod(matriz[0][1] * -1 * inv, 26);
    matriz[1][0] = mod(matriz[1][0] * -1 * inv, 26);
    matriz[1][1] = mod(inv * permutation, 26);
}

int PrimeFact(long long input, int lstPrime[]) {

    static int i = 0;

    long long raiz = (long long) (sqrt(input));

    while (input % raiz-- != 0)
        ;

    if (++raiz == 1)
        lstPrime[i++] = input;

    else {
        PrimeFact(raiz, lstPrime);
        PrimeFact(input / raiz, lstPrime);
    }
    return i;
}

long long nFibonacci(int n) {

    long long a = 0, b = 1, bm;

    if (n-- == 1)
        return a;
    if (n-- == 2)
        return b;

    while (n--) {
        bm = b;
        b += a;
        a = bm;
    }
    return b;
}

int isPrime(long long num) {

    long long raiz = (long long) (sqrt(num));

    while (num % raiz--)
        ;

    return ++raiz == 1;
}

long long nPrime(int n) {

    int num = 2;

    if (n-- == 1)
        return num;
    num--;

    while (n) {
        num += 2;
        if (isPrime(num))
            n--;
    }
    return num;
}

void cleanBuffer() {

    while (getchar() != '\n')
        ;
}

void M2x2Cop26(int matriz[2][2]) {

    int a, b, c, d, r;
    int vars[5];

    srand(time(NULL));
    a = mod(rand(), 25) + 1;
    while (b = mod(rand(), 25) + 1, !coprime(a, b))
        ;
    while (r = mod(rand(), 25) + 1, !coprime(r, 26))
        ;

    vars[0] = a;
    vars[1] = b;
    xiyi(vars, 0);

    c = mod(-1 * vars[4] * r, 26);
    d = mod(vars[3] * r, 26);

    matriz[0][0] = a;
    matriz[0][1] = b;
    matriz[1][0] = c;
    matriz[1][1] = d;
}

int max(int *nums, int n) {

    int ind, i;

    for (ind = 0, i = 1; i < n; i++)
        if (nums[i] > nums[ind])
            ind = i;

    return ind;
}

int mmc(int *nums, int n) {

    int multiple, found, i, ind;

    ind = max(nums, n);
    multiple = found = 0;

    while (!found) {
        multiple += nums[ind];
        for (found = 1, i = 0; i < n; i++)
            if (multiple % nums[i]) {
                found = 0;
                break;
            }
    }
    return multiple;
}

int pot(int base, int exp) {

    int x = 1;

    while (exp--)
        x *= base;

    return x;
}

int count(int ele, int lst[], int i, int n) {

    int cont;

    for (cont = 0; i < n; i++)
        if (ele == lst[i])
            cont++;

    return cont;
}

int filterRep(int lst[], int n) {

    int i, t;

    for (i = t = 0; i < n; i++)
        if (!count(lst[i], lst, 0, t))
            lst[t++] = lst[i];

    return t;
}

void simplyEqTCR(int coef[4]) {

    int den = mdc(coef[0], coef[2]);

    coef[3] -= coef[1];
    coef[0] /= den;
    coef[2] /= den;
    coef[3] /= den;
    coef[3] = (coef[3] * inverse(coef[0], coef[2])) % coef[2];
}

int GeneralizationTCR(EqTCR *lstEq, int n, int ind) {

    int i, t, k, len, cont, power;
    int raizes[100], *mods = (int *) (malloc(sizeof(int) * n));

    for (i = 0; i < n; i++) {
        for (t = i + 1; t < n; t++)
            if ((lstEq[i].num - lstEq[t].num) % (mdc(lstEq[i].mod, lstEq[t].mod)) !=
                0) {
                if (ind) {
                    printf("Its not possible to apply Generalization:\n");
                    printf(">>> %d - %d = %d is not multiple of mdc(%d,%d) = %d\n",
                           lstEq[i].num, lstEq[t].num, lstEq[i].num - lstEq[t].num,
                           lstEq[i].mod, lstEq[t].mod, mdc(lstEq[i].mod, lstEq[t].mod));
                }
                return 1;
            }
        mods[i] = lstEq[i].mod;
        lstEq[i].mod = 1;
    }

    len = PrimeFact(mmc(mods, n), raizes);

    for (i = t = 0; i < len; i++)
        if (!count(raizes[i], raizes, 0, t)) {

            power = pot(raizes[i], count(raizes[i], raizes, t, len));
            for (k = 0; k < n; k++)
                if (!(mods[k] % power)) {
                    lstEq[k].mod *= power;
                    break;
                }
            raizes[t++] = raizes[i];
        }

    if (ind)
        printf("System after generalization:\n");
    for (i = 0; i < n; i++) {
        lstEq[i].num %= lstEq[i].mod;
        if (ind && lstEq[i].mod != 1)
            printf("| x = mod(%d) %d\n", lstEq[i].mod, lstEq[i].num);
    }

    return 0;
}

SolTCR TCR(EqTCR *lstEq, int n, int ind) {

    int i, t;
    SolTCR sol = {0, 1, 1};

    for (i = 0; i < n; sol.diff *= lstEq[i++].mod) {
        for (t = i + 1; t < n; t++)
            if (!coprime(lstEq[i].mod, lstEq[t].mod)) {
                if (ind) {
                    printf("Its not possible to apply TCR:\n");
                    printf(">>> mdc(%d,%d) = %d != 1\n", lstEq[i].mod, lstEq[t].mod,
                           mdc(lstEq[i].mod, lstEq[t].mod));
                }
                if (GeneralizationTCR(lstEq, n, ind) == 1) {
                    sol.indice = 0;
                    return sol;
                }
                break;
            }
    }
    for (i = 0; i < n; i++) {
        sol.x0 += sol.diff / lstEq[i].mod *
                  inverse(sol.diff / lstEq[i].mod, lstEq[i].mod) * lstEq[i].num;
        sol.x0 %= sol.diff;
    }
    return sol;
}

int ascend(const void *x, const void *y) {

    int a = *((int *) (x));
    int b = *((int *) (y));

    return (a > b) - (a < b);
}
