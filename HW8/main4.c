#include <stdio.h>

int main() {
    int arr[10];
    int max1 = -2147483648; // самый маленький int
    int max2 = -2147483648;

    // Читаем массив
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Ищем первый максимум
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }

    // Ищем второй максимум среди остальных, исключая первый
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }

    // Если все числа равны, max2 так и останется -2147483648, заменим его на max1
    if (max2 == -2147483648) {
        max2 = max1;
    }

    printf("%d\n", max1 + max2);
    return 0;
}
