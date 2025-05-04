#include <stdio.h>

int main() {
    int number;
    
    // Считываем трехзначное число
    scanf("%d", &number);
    
    // Разделяем число на цифры
    int digit1 = number / 100;        // Первая цифра (сотни)
    int digit2 = (number / 10) % 10;  // Вторая цифра (десятки)
    int digit3 = number % 10;         // Третья цифра (единицы)
    
    // Вычисляем сумму цифр
    int sum = digit1 + digit2 + digit3;
    
    // Выводим результат
    printf("%d\n", sum);
    
    return 0;
}
