#include <stdio.h>
#include <stdbool.h> // Для типа bool

// Функция проверки четности суммы цифр
bool is_even_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // Добавляем последнюю цифру
        n /= 10;       // Удаляем последнюю цифру
    }
    return sum % 2 == 0;
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
    if (is_even_sum(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
