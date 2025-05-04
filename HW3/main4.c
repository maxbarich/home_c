#include <stdio.h>

int main() {
    int a, b, c;
    
    // Считываем три числа
    scanf("%d %d %d", &a, &b, &c);
    
    // Вычисляем сумму и произведение
    int sum = a + b + c;
    int product = a * b * c;
    
    // Выводим результат в требуемом формате
    printf("%d+%d+%d=%d\n", a, b, c, sum);
    printf("%d*%d*%d=%d\n", a, b, c, product);
    
    return 0;
}
