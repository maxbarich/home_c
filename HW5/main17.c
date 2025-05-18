#include <stdio.h>

// Функция проверки, является ли число "счастливым"
int is_lucky(int num) {
    int sum = 0, product = 1, digit;
    int temp = num;
    
    while (temp > 0) {
        digit = temp % 10;
        sum += digit;
        product *= digit;
        temp /= 10;
    }
    
    return (sum == product && num >= 10); // Проверяем условие и что число ≥10
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n <= 10) {
        printf("Число должно быть больше 10\n");
        return 1;
    }
    
    int first = 1; // Флаг для правильного форматирования вывода
    
    for (int i = 10; i <= n; i++) {
        if (is_lucky(i)) {
            if (!first) {
                printf(" "); // Добавляем пробел перед числом, если оно не первое
            }
            printf("%d", i);
            first = 0; // После первого числа сбрасываем флаг
        }
    }
    
    printf("\n");
    return 0;
}
