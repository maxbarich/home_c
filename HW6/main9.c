#include <stdio.h>

// Функция вычисления факториала
unsigned long long factorial(int n) {
    if (n < 0) return 0; // Факториал отрицательного числа не определен
    if (n == 0) return 1; // 0! = 1
    
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n); // Вводим число
    
    // Проверяем корректность ввода
    if (n < 0 || n > 20) {
        printf("Число должно быть от 0 до 20\n");
        return 1;
    }
    
    // Вычисляем и выводим факториал
    unsigned long long result = factorial(n);
    printf("%llu\n", result);
    
    return 0;
}
