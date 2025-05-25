#include <stdio.h>

void print_prime_factors(int n) {
    // Находим первый делитель, если есть
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
            print_prime_factors(n / i);
            return;
        }
    }
    // Если делителей не осталось, число простое
    printf("%d ", n);
}

int main() {
    int N;
    scanf("%d", &N);
    print_prime_factors(N);
    printf("\n");
    return 0;
}
