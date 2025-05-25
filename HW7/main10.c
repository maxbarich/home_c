#include <stdio.h>

int is_prime(int n, int delitel) {
    if (delitel * delitel > n) {
        return 1; // простое число
    }
    if (n % delitel == 0) {
        return 0; // делитель найден, число не простое
    }
    return is_prime(n, delitel + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("NO\n"); // 1 не считается простым числом
        return 0;
    }
    if (is_prime(n, 2))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
