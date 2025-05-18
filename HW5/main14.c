#include <stdio.h>

int main() {
    int number;
    int count = 0; // Счётчик чисел
    
    // Читаем числа до тех пор, пока не встретим 0
    while (1) {
        scanf("%d", &number);
        
        if (number == 0) {
            break; // Выходим из цикла при встрече нуля
        }
        
        count++; // Увеличиваем счётчик для каждого ненулевого числа
    }
    
    printf("%d\n", count); // Выводим результат
    
    return 0;
}
