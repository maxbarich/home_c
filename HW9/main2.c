#include <stdio.h>
#include <string.h>

// Функция для подсчёта и вывода цифр по возрастанию
void print_digits_counts(const char *number) {
    int counts[10] = {0};

    // Подсчет количества каждой цифры
    for (int i = 0; number[i] != '\0'; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            counts[number[i] - '0']++;
        }
    }

    // Вывод цифр и их количества в порядке возрастания
    for (int digit = 0; digit <= 9; digit++) {
        if (counts[digit] > 0) {
            printf("%d %d\n", digit, counts[digit]);
        }
    }
}


int main() {
    char number[1001];
    scanf("%1000s", number);
    print_digits_counts(number);
    return 0;
}
