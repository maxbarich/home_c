#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    // Проверяем, что число положительное (по условию задачи)
    if (number <= 0) {
        printf("NO\n");
        return 0;
    }
    
    // Подсчитываем количество цифр
    int digits = 0;
    int temp = number;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    
    // Проверяем, ровно ли 3 цифры
    printf(digits == 3 ? "YES\n" : "NO\n");
    
    return 0;
}
