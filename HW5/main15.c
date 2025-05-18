#include <stdio.h>

int main() {
    int number;
    int count = 0; // Счётчик чётных чисел
    
    while (1) {
        scanf("%d", &number); // Читаем очередное число
        
        if (number == 0) {
            break; // Выходим из цикла при встрече нуля
        }
        
        if (number % 2 == 0) { // Проверяем чётность
            count++; // Увеличиваем счётчик для чётных чисел
        }
    }
    
    printf("%d\n", count); // Выводим результат
    
    return 0;
}
