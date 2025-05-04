#include <stdio.h>

int main() {
    int a, b, c;
    
    // Считываем три числа
    scanf("%d %d %d", &a, &b, &c);
    
    // Находим наибольшее число
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    
    // Выводим результат
    printf("%d\n", max);
    
    return 0;
}
