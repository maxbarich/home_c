#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Для функции sqrt()

// Функция проверки числа на простоту
bool is_prime(int n) {
    if (n <= 1) return false; // 0 и 1 не простые
    if (n == 2) return true;  // 2 - единственное четное простое
    
    // Проверяем четность
    if (n % 2 == 0) return false;
    
    // Проверяем делители от 3 до sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
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
    if (is_prime(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
