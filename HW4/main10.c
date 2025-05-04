#include <stdio.h>

int main() {
    int numbers[5];
    
    // Считываем пять чисел
    for(int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Находим минимальное значение
    int min = numbers[0];
    for(int i = 1; i < 5; i++) {
        if(numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    // Выводим результат
    printf("%d\n", min);
    
    return 0;
}
