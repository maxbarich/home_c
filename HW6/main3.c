#include <stdio.h>

// Функция вычисления среднего арифметического
int middle(int a, int b) {
    return (a + b) / 2;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2); // Вводим два числа
    
    // Проверяем, что числа неотрицательные (по условию задачи)
    if (num1 < 0 || num2 < 0) {
        printf("Числа должны быть неотрицательными\n");
        return 1;
    }
    
    // Используем функцию middle()
    int result = middle(num1, num2);
    
    printf("%d\n", result); // Выводим результат
    
    return 0;
}
