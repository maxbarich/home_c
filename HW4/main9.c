#include <stdio.h>

int main() {
    int numbers[5];
    
    // Считываем все пять чисел
    for(int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Находим максимальное значение
    int max = numbers[0];
    for(int i = 1; i < 5; i++) {
        if(numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    // Выводим результат
    printf("%d\n", max);
    
    return 0;
}
