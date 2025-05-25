#include <stdio.h>

// Функция для сортировки массива по последней цифре методом пузырька
void sortByLastDigit(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int lastDigitJ = arr[j] % 10;
            int lastDigitJ1 = arr[j + 1] % 10;
            if (lastDigitJ > lastDigitJ1) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10];

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Сортировка по последней цифре
    sortByLastDigit(arr, 10);

    // Вывод отсортированного массива
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
