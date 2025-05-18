#include <stdio.h>
#include <stdlib.h> // Для abs()

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    number = abs(number); // Работаем с абсолютным значением
    
    int digits[10] = {0}; // Массив для подсчёта цифр (0-9)
    
    while (number > 0) {
        int digit = number % 10; // Получаем текущую цифру
        digits[digit]++; // Увеличиваем счётчик для этой цифры
        
        if (digits[digit] >= 2) { // Если цифра встретилась дважды
            printf("YES\n");
            return 0; // Завершаем программу
        }
        
        number /= 10; // Убираем последнюю цифру
    }
    
    printf("NO\n"); // Если дошли сюда - повторяющихся цифр нет
    return 0;
}
