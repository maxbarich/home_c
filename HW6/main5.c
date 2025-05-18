#include <stdio.h>

// Функция вычисления суммы чисел от 1 до n
int sum_to_n(int n) {
    return n * (n + 1) / 2;  // Используем формулу арифметической прогрессии
}

int main() {
    int n;
    scanf("%d", &n);  // Вводим число N
    
    // Проверяем, что число положительное
    if (n <= 0) {
        printf("Число должно быть положительным\n");
        return 1;
    }
    
    // Используем функцию sum_to_n()
    int result = sum_to_n(n);
    
    printf("%d\n", result);  // Выводим результат
    
    return 0;
}
