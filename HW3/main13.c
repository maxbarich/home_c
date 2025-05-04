#include <stdio.h>

int main() {
    int number;
    
    // Считываем трехзначное число
    scanf("%d", &number);
    
    // Разделяем число на цифры
    int hundreds = number / 100;        // Цифра сотен
    int tens = (number / 10) % 10;     // Цифра десятков
    int units = number % 10;            // Цифра единиц
    
    // Вычисляем произведение цифр
    int product = hundreds * tens * units;
    
    // Выводим результат
    printf("%d\n", product);
    
    return 0;
}
