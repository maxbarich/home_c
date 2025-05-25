#include <stdio.h>

int main() {
    int arr[10];
    int max_count = 0;
    int result = 0;

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Перебираем каждый элемент и считаем, сколько раз он встречается
    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        // Если встречается чаще всех предыдущих, запоминаем
        if (count > max_count) {
            max_count = count;
            result = arr[i];
        }
    }

    // Вывод числа, которое встречается чаще всего
    printf("%d\n", result);
    return 0;
}
