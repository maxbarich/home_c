#include <stdio.h>

int main() {
    int arr[10];
    int max, min;
    int max_index = 0, min_index = 0;

    // Чтение 10 чисел
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Инициализация
    max = arr[0];
    min = arr[0];

    // Поиск максимум и минимум с их индексами
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }

    // Вывод: номер максимум, максимум, номер минимума, минимум
    // Нумерация с 1
    printf("%d %d %d %d\n", max_index + 1, max, min_index + 1, min);

    return 0;
}
