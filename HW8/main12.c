#include <stdio.h>

// Функция для сортировки части массива по возрастанию
void sortAscending(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для сортировки части массива по убыванию
void sortDescending(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10];

    // Ввод массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Сортируем первую половину (0-4) по возрастанию
    sortAscending(arr, 0, 5);
    // Сортируем вторую половину (5-9) по убыванию
    sortDescending(arr, 5, 10);

    // Вывод результата
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
