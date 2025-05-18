#include <stdio.h>

// Функция возведения в степень
int power(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p); // Вводим число и степень
    
    // Проверяем корректность степени
    if (p < 0) {
        printf("Степень должна быть неотрицательной\n");
        return 1;
    }
    
    // Проверяем ограничение на основание
    if (n > 1000 || n < -1000) {
        printf("Основание должно быть по модулю ≤ 1000\n");
        return 1;
    }
    
    // Используем функцию power()
    int result = power(n, p);
    
    printf("%d\n", result); // Выводим результат
    
    return 0;
}
