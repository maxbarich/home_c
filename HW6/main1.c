#include <stdio.h>

// Функция вычисления модуля числа
int absolute(int num) {
    return num < 0 ? -num : num;
}

int main() {
    int number;
    scanf("%d", &number); // Вводим целое число
    
    // Используем функцию absolute()
    int result = absolute(number);
    
    printf("%d\n", result); // Выводим результат
    
    return 0;
}
