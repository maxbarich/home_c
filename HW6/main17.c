#include <stdio.h>
#include <stdbool.h> // Для типа bool

// Функция проверки равенства суммы и произведения цифр
bool is_happy_number(int n) {
    if (n == 0) return false; // Для 0 сумма=0, произведение=0
    
    int sum = 0;
    int product = 1;
    int digit;
    int original = n;
    
    while (n > 0) {
        digit = n % 10; // Получаем последнюю цифру
        sum += digit;
        product *= digit;
        n /= 10; // Удаляем последнюю цифру
    }
    
    return sum == product;
}

int main() {
    int number;
    scanf("%d", &number); // Вводим число
    
    // Проверяем, что число неотрицательное
    if (number < 0) {
        printf("Число должно быть неотрицательным\n");
        return 1;
    }
    
    // Используем функцию и выводим результат
    if (is_happy_number(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
