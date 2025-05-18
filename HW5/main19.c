#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number); // Вводим натуральное число
    
    // Проверяем, что число положительное (натуральное)
    if (number <= 0) {
        printf("NO\n");
        return 0;
    }
    
    int sum = 0;
    int temp = number;
    
    // Вычисляем сумму цифр числа
    while (temp > 0) {
        sum += temp % 10; // Добавляем последнюю цифру к сумме
        temp /= 10;       // Удаляем последнюю цифру
    }
    
    // Проверяем, равна ли сумма 10
    if (sum == 10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
