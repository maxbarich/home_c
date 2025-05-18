#include <stdio.h>
#include <ctype.h> // Для isdigit()

// Функция преобразования символа цифры в число
int digit_to_num(char c) {
    return c - '0'; // Используем разницу ASCII-кодов
}

int main() {
    char c;
    int sum = 0; // Сумма цифр
    
    while (1) {
        c = getchar(); // Читаем по одному символу
        
        if (c == '.') { // Конец ввода
            break;
        }
        
        if (isdigit(c)) { // Если символ - цифра
            sum += digit_to_num(c); // Добавляем его числовое значение
        }
    }
    
    printf("%d\n", sum); // Выводим сумму
    
    return 0;
}
