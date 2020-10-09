typedef struct {
    int mod, num;
} EqTCR;

typedef struct {
    int x0, diff, indice;
} SolTCR;

void simplyEqTCR(int coef[4]);
int GeneralizationTCR(EqTCR *lstEq, int n, int ind);
SolTCR TCR(EqTCR *lstEq, int n, int ind);
int mdc(long long a, long long b);
long long inverse(long long num, long long mod);
int coprime(long long a, long long b);
int max(int *nums, int n);
int mmc(int *nums, int n);
int count(int ele, int lst[], int i, int n);
int PrimeFact(long long input, int lstPrime[]);
int pot(int base, int exp);
void cleanBuffer();