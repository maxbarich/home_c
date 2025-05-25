#include <stdio.h>

int main() {
    int arr[12];

    // Чтение массива
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    int shift = 4; // количество сдвигов
    int temp[12];

    // Выполняем циклический сдвиг на 4
    for (int i = 0; i < 12; i++) {
        // Новая позиция элемента после сдвига
        int new_pos = (i + shift) % 12;
        temp[new_pos] = arr[i];
    }

    // Копируем результат обратно в arr
    for (int i = 0; i < 12; i++) {
        arr[i] = temp[i];
    }

    // Вывод массива
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
