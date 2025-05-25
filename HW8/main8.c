#include <stdio.h>

int main() {
    int arr[12];

    // Чтение массива
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    // Инверсия первой трети (элементы 0-3)
    for (int i = 0; i < 2; i++) {
        int temp = arr[i];
        arr[i] = arr[3 - i];
        arr[3 - i] = temp;
    }

    // Инверсия второй трети (элементы 4-7)
    for (int i = 4; i < 4 + 2; i++) {
        int temp = arr[i];
        arr[i] = arr[7 - (i - 4)];
        arr[7 - (i - 4)] = temp;
    }

    // Инверсия третьей трети (элементы 8-11)
    for (int i = 8; i < 8 + 2; i++) {
        int temp = arr[i];
        arr[i] = arr[11 - (i - 8)];
        arr[11 - (i - 8)] = temp;
    }

    // Вывод результата
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
