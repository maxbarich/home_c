#include <stdio.h>

int main() {
    int arr[12];
    double sum = 0.0;

    // Чтение 12 чисел
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Вычисление среднего
    double average = sum / 12.0;

    // Вывод с точностью до двух знаков
    printf("%.2f\n", average);

    return 0;
}
