#include <stdio.h>

int sum_digits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sum_digits(n / 10);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", sum_digits(N));
    return 0;
}
