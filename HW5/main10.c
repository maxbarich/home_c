                                               #include <stdio.h>
#include <stdlib.h> // Для abs()

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    number = abs(number); // Работаем с абсолютным значением
    
    // Обработка особых случаев:
    // 1. Число из одной цифры всегда удовлетворяет условию
    if (number < 10) {
        printf("YES\n");
        return 0;
    }
    
    int prev_digit = number % 10; // Начинаем с последней цифры
    number /= 10;
    
    while (number > 0) {
        int current_digit = number % 10;
        
        // Проверяем, что текущая цифра НЕ меньше предыдущей
        if (current_digit >= prev_digit) {
            printf("NO\n");
            return 0;
        }
        
        prev_digit = current_digit;
        number /= 10;
    }
    
    printf("YES\n");
    return 0;
}
