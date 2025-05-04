
#include <stdio.h>

int main() {
    int numbers[5];
    
    // Считываем пять чисел
    for(int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Находим минимальное и максимальное значения
    int min = numbers[0];
    int max = numbers[0];
    
    for(int i = 1; i < 5; i++) {
        if(numbers[i] < min) {
            min = numbers[i];
        }
        if(numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    // Вычисляем и выводим сумму
    printf("%d\n", min + max);
    
    return 0;
}
