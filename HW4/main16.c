#include <stdio.h>

int main() {
    int a, b, c;
    
    // Считываем три числа
    scanf("%d %d %d", &a, &b, &c);
    
    // Проверяем условие возрастания
    if (a < b && b < c) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
