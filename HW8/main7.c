#include <stdio.h>

int main() {
    int arr[10];

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Инверсия первой половины (индексы 0-4)
    for (int i = 0; i < 5 / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }

    // Инверсия второй половины (индексы 5-9)
    for (int i = 5; i < 5 + 5 / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[9 - (i - 5)];
        arr[9 - (i - 5)] = temp;
    }

    // Вывод массива
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
