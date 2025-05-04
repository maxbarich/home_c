#include <stdio.h>

int main() {
    int a, b;
    
    // Считываем два числа
    scanf("%d %d", &a, &b);
    
    // Выводим в порядке возрастания
    if (a < b) {
        printf("%d %d\n", a, b);
    } else {
        printf("%d %d\n", b, a);
    }
    
    return 0;
}
