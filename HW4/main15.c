#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    // Вычисляем коэффициенты k и b
    double k = (double)(y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;
    
    // Выводим с округлением до двух знаков
    printf("%.2f %.2f\n", k, b);
    
    return 0;
} 
