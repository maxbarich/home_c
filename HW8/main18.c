#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    // Массив для подсчета кратных для чисел 2..9
    int counts[10] = {0}; // индексы 2..9 используются, остальные игнорируем

    for (int num = 2; num <= N; num++) {
        for (int divisor = 2; divisor <= 9; divisor++) {
            if (num % divisor == 0) {
                counts[divisor]++;
            }
        }
    }

    // Вывод результатов
    for (int divisor = 2; divisor <= 9; divisor++) {
        printf("%d %d\n", divisor, counts[divisor]);
    }

    return 0;
}
