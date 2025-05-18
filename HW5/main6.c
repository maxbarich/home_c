#include <stdio.h>
#include <stdlib.h> // Для abs() (на случай отрицательных чисел)

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    // Работаем с абсолютным значением числа (чтобы корректно обрабатывать отрицательные)
    number = abs(number);
    
    int prev_digit = -1; // Предыдущая цифра (изначально несуществующая)
    int has_duplicates = 0; // Флаг: есть ли повторяющиеся цифры
    
    while (number > 0) {
        int current_digit = number % 10; // Получаем текущую цифру
        
        // Проверяем, совпадает ли текущая цифра с предыдущей
        if (current_digit == prev_digit) {
            has_duplicates = 1;
            break; // Можно выйти из цикла, так как уже нашли пару
        }
        
        prev_digit = current_digit; // Запоминаем текущую цифру как предыдущую
        number /= 10; // Убираем последнюю цифру из числа
    }
    
    // Выводим результат
    if (has_duplicates) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
