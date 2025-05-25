#include <stdio.h>

void print_numbers(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);
    print_numbers(n - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    print_numbers(N);
    return 0;
}
