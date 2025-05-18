#include <stdio.h>
#include <stdlib.h> // Для abs()

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    number = abs(number); // Работаем с абсолютным значением
    
    int count = 0; // Счётчик цифр 9
    
    while (number > 0) {
        if (number % 10 == 9) { // Проверяем текущую цифру
            count++;
            if (count > 1) { // Если нашли больше одной девятки
                printf("NO\n");
                return 0; // Завершаем программу досрочно
            }
        }
        number /= 10; // Переходим к следующей цифре
    }
    
    printf(count == 1 ? "YES\n" : "NO\n");
    return 0;
}
