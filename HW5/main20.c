#include <stdio.h>
#include <math.h> // Для функции sqrt()

int main() {
    int number;
    scanf("%d", &number); // Вводим натуральное число
    
    // Проверка на простоту
    if (number <= 1) {
        printf("NO\n"); // Числа 0 и 1 не являются простыми
        return 0;
    }
    
    if (number == 2) {
        printf("YES\n"); // 2 - единственное чётное простое число
        return 0;
    }
    
    if (number % 2 == 0) {
        printf("NO\n"); // Все остальные чётные числа не простые
        return 0;
    }
    
    // Проверяем делители от 3 до квадратного корня из числа
    int is_prime = 1; // Флаг простоты числа
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            is_prime = 0;
            break;
        }
    }
    
    printf(is_prime ? "YES\n" : "NO\n");
    return 0;
}
