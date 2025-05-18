#include <stdio.h>
#include <stdlib.h> // Для abs()

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    number = abs(number); // Работаем с абсолютным значением
    
    // Обрабатываем особый случай - число 0
    if (number == 0) {
        printf("YES\n");
        return 0;
    }
    
    while (number > 0) {
        int digit = number % 10; // Получаем текущую цифру
        if (digit % 2 != 0) {    // Если цифра нечётная
            printf("NO\n");
            return 0; // Завершаем программу сразу
        }
        number /= 10; // Переходим к следующей цифре
    }
    
    printf("YES\n"); // Если дошли сюда - все цифры чётные
    return 0;
}
