#include <stdio.h>

// Рекурсивная функция печати чисел от 1 до n
void print_numbers(int current, int n) {
    if (current > n) {
        return; // Базовый случай - выход из рекурсии
    }
    
    printf("%d ", current); // Печатаем текущее число
    print_numbers(current + 1, n); // Рекурсивный вызов для следующего числа
}

int main() {
    int n;
    scanf("%d", &n); // Вводим число N
    
    // Проверяем, что число положительное
    if (n <= 0) {
        printf("Число должно быть натуральным (положительным)\n");
        return 1;
    }
    
    print_numbers(1, n); // Вызываем рекурсивную функцию
    printf("\n"); // Переход на новую строку после вывода
    
    return 0;
}
