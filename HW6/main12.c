#include <stdio.h>
#include <math.h> // Для функции fabs()

// Функция вычисления факториала
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Функция вычисления синуса через ряд Тейлора
float sinus(float x) {
    // Переводим градусы в радианы
    x = x * M_PI / 180.0f;
    
    float result = 0.0f;
    float term = x;
    int n = 1;
    
    while (fabs(term) >= 0.001f) {
        result += term;
        n += 2;
        term = -term * x * x / ((n - 1) * n);
    }
    
    return result;
}

int main() {
    float angle;
    scanf("%f", &angle); // Вводим угол в градусах
    
    // Проверяем диапазон ввода
    if (angle < 0 || angle > 90) {
        printf("Угол должен быть от 0 до 90 градусов\n");
        return 1;
    }
    
    // Вычисляем и выводим синус с точностью до 0.001
    float result = sinus(angle);
    printf("%.3f\n", result);
    
    return 0;
}
