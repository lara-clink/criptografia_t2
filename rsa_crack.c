#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para verificar se um número é primo
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Função para fatorar n e encontrar p e q
void find_factors(int n, int *p, int *q) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            *p = i;
            *q = n / i;
            return;
        }
    }
}

// Função para calcular o inverso modular (a * x ≡ 1 (mod m))
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

int main() {
    int e, n, p = 0, q = 0, phi, d;

    printf("Digite o valor de e: ");
    scanf("%d", &e);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Encontrar p e q
    find_factors(n, &p, &q);

    if (p == 0 || q == 0) {
        printf("Erro: Não foi possível fatorar n.\n");
        return 1;
    }

    printf("Fatores encontrados: p = %d, q = %d\n", p, q);

    // Calcular phi(n)
    phi = (p - 1) * (q - 1);

    // Calcular d (inverso modular de e mod phi)
    d = mod_inverse(e, phi);

    if (d == 0) {
        printf("Erro: Não foi possível calcular o inverso modular.\n");
        return 1;
    }

    printf("Chave privada d: %d\n", d);

    return 0;
}
