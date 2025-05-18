#include <stdio.h>
#include <ctype.h> // Для функции toupper()

// Функция перевода строки в верхний регистр
void to_uppercase(char* str) {
    for (int i = 0; str[i] != '.'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = toupper(str[i]); // или str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main() {
    char input[1000]; // Буфер для ввода строки
    
    // Читаем строку до точки
    int i = 0;
    while (1) {
        char c = getchar();
        input[i++] = c;
        if (c == '.') break;
    }
    input[i] = '\0'; // Добавляем завершающий нуль-символ
    
    // Применяем функцию преобразования
    to_uppercase(input);
    
    // Выводим результат
    printf("%s\n", input);
    
    return 0;
}
