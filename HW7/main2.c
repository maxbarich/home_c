#include <stdio.h>

// Рекурсивная функция вычисления суммы чисел от 1 до n
int sum_to_n(int n) {
    if (n == 1) {  // Базовый случай
        return 1;
    }
    return n + sum_to_n(n - 1);  // Рекурсивный вызов
}

int main() {
    int n;
    scanf("%d", &n);  // Вводим число N
    
    // Проверяем, что число положительное
    if (n <= 0) {
        printf("Число должно быть натуральным (положительным)\n");
        return 1;
    }
    
    int result = sum_to_n(n);  // Вычисляем сумму
    printf("%d\n", result);    // Выводим результат
    
    return 0;
}
