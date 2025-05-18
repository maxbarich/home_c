#include <stdio.h>

int main() {
    int n;
    // Ввод числа (с проверкой, что оно <= 100)
    scanf("%d", &n);
    
    if (n < 1 || n > 100) {
        printf("Число должно быть от 1 до 100\n");
        return 1; // Завершаем программу с ошибкой
    }
    
    // Выводим квадраты и кубы чисел от 1 до n
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }
    
    return 0;
}
