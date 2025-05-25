#include <stdio.h>

int main() {
    int arr[5];
    double sum = 0.0;

    // Чтение 5 чисел
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Вычисление среднего
    double average = sum / 5.0;

    // Вывод с точностью 3 знака
    printf("%.3f\n", average);

    return 0;
}
