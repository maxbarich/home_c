#include <stdio.h>

// Функция вычисления НОД по алгоритму Евклида
int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2); // Вводим два числа
    
    // Проверяем, что числа положительные
    if (num1 <= 0 || num2 <= 0) {
        printf("Числа должны быть натуральными (положительными)\n");
        return 1;
    }
    
    // Вычисляем и выводим НОД
    int result = nod(num1, num2);
    printf("%d\n", result);
    
    return 0;
}
