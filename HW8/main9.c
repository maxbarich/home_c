#include <stdio.h>

int main() {
    int arr[10];

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Временная переменная для хранения последнего элемента
    int last = arr[9];

    // Сдвиг вправо на 1
    for (int i = 9; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;

    // Вывод массива
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
