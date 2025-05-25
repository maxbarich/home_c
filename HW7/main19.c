#include <stdio.h>

int acounter(void) {
    char ch;
    ch = getchar();

    if (ch == '.') {
        // Конец строки
        return 0;
    }

    // Подсчет 'a' в текущем символе
    int count = (ch == 'a') ? 1 : 0;

    // Рекурсивный вызов для следующего символа
    return count + acounter();
}

int main() {
    int result = acounter();
    printf("%d\n", result);
    return 0;
}
