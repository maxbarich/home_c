#include <stdio.h>
#include <ctype.h> // Для isdigit()

// Функция проверки, является ли символ цифрой
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    char c;
    int count = 0; // Счетчик цифр
    
    while (1) {
        c = getchar(); // Читаем по одному символу
        
        if (c == '.') { // Если встретили точку - завершаем
            break;
        }
        
        if (is_digit(c)) { // Проверяем, является ли символ цифрой
            count++;
        }
    }
    
    printf("%d\n", count); // Выводим количество цифр
    
    return 0;
}
