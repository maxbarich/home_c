#include <stdio.h>
#include <math.h> // Для fabs() и M_PI

// Функция вычисления косинуса через ряд Тейлора
float cosinus(float x) {
    // Переводим градусы в радианы
    x = x * M_PI / 180.0f;
    
    float result = 0.0f;
    float term = 1.0f; // Первый член ряда (1)
    int n = 0;
    
    while (fabs(term) >= 0.001f) {
        result += term;
        n += 2;
        term = -term * x * x / ((n - 1) * n);
    }
    
    return result;
}

int main() {
    int angle;
    scanf("%d", &angle); // Вводим угол в градусах
    
    // Проверяем диапазон ввода
    if (angle < 0 || angle > 90) {
        printf("Угол должен быть от 0 до 90 градусов\n");
        return 1;
    }
    
    // Вычисляем и выводим косинус с точностью до 0.001
    float result = cosinus((float)angle);
    printf("%.3f\n", result);
    
    return 0;
}
