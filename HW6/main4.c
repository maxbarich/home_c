#include <stdio.h>

// Функция вычисления f(x) по заданной формуле
int calculate_f(int x) {
    if (x < -2) {
        return 4;
    } else if (x >= 2) {
        return x * x + 4 * x + 5;
    } else { // -2 ≤ x < 2
        return x * x;
    }
}

int main() {
    int x;
    int max_value = -2147483648; // Начальное значение (минимальное для int)
    
    while (1) {
        scanf("%d", &x); // Читаем число
        
        if (x == 0) { // Конец последовательности
            break;
        }
        
        int current = calculate_f(x); // Вычисляем f(x)
        
        if (current > max_value) { // Обновляем максимум
            max_value = current;
        }
    }
    
    printf("%d\n", max_value); // Выводим наибольшее значение
    
    return 0;
}
