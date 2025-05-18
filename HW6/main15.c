#include <stdio.h>
#include <stdbool.h> // Для типа bool

// Функция проверки, что цифры идут по возрастанию
bool grow_up(int n) {
    if (n < 10) return true; // Однозначные числа удовлетворяют условию
    
    int prev = n % 10; // Последняя цифра
    n /= 10;
    
    while (n > 0) {
        int current = n % 10; // Текущая цифра
        if (current >= prev) {
            return false;
        }
        prev = current;
        n /= 10;
    }
    
    return true;
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
    if (grow_up(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
