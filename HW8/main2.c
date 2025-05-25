#include <stdio.h>

int main() {
    int arr[5];
    int min;

    // Чтение 5 чисел
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Инициализация min первым элементом
    min = arr[0];

    // Поиск минимального элемента
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Вывод результата
    printf("%d\n", min);

    return 0;
}
