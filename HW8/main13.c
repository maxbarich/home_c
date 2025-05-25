#include <stdio.h>

int main() {
    int arr[10];
    int result[10];
    int count = 0;

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Отбор чисел, у которых вторая с конца цифра равна нулю
    for (int i = 0; i < 10; i++) {
        int num = arr[i];
        int second_last_digit = (num / 10) % 10; // вторая с конца цифра
        if (second_last_digit == 0) {
            result[count++] = num;
        }
    }

    // Вывод результата
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
