#include <stdio.h>

int main() {
    int arr[10];
    int sum = 0;

    // Чтение 10 чисел
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Подсчет суммы положительных элементов
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    // Вывод результата
    printf("%d\n", sum);

    return 0;
}
