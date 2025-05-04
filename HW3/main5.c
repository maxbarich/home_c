#include <stdio.h>

int main() {
    int a, b, c;
    
    // Считываем три целых числа
    scanf("%d %d %d", &a, &b, &c);
    
    // Вычисляем среднее арифметическое
    double average = (a + b + c) / 3.0;
    
    // Выводим результат с двумя знаками после запятой
    printf("%.2f\n", average);
    
    return 0;
}
