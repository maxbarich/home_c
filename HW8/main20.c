#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    // Сравнение для сортировки по убыванию
    return (*(char*)b - *(char*)a);
}

int main() {
    char num_str[20]; // буфер для числа, достаточно для любых входных данных
    scanf("%s", num_str);

    // Определяем длину строки
    int len = 0;
    while (num_str[len] != '\0') {
        len++;
    }

    // Сортируем символы по убыванию
    qsort(num_str, len, sizeof(char), cmp);

    // Выводим результат
    printf("%s\n", num_str);

    return 0;
}
