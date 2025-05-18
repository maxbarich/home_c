#include <stdio.h>
#include <math.h> // Для функции pow()

// Функция вычисления количества зёрен на n-й клетке
unsigned long long grains_on_cell(int n) {
    if (n < 1 || n > 64) return 0; // Проверка диапазона
    return (unsigned long long)pow(2, n-1);
}

int main() {
    int n;
    scanf("%d", &n); // Вводим номер клетки
    
    // Проверяем корректность ввода
    if (n < 1 || n > 64) {
        printf("Номер клетки должен быть от 1 до 64\n");
        return 1;
    }
    
    // Вычисляем и выводим результат
    unsigned long long result = grains_on_cell(n);
    printf("%llu\n", result);
    
    return 0;
}
