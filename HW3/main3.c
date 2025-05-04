#include <stdio.h>

int main() {
    int a, b, c;
  
    // Считываем три числа
    scanf("%d %d %d", &a, &b, &c);
    
    // Вычисляем сумму
    int sum = a + b + c;
    
    // Выводим результат в требуемом формате
    printf("%d+%d+%d=%d\n", a, b, c, sum);
    
    return 0;
}
