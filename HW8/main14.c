#include <stdio.h>

int main() {
    int arr[10], result[10];
    int count_result = 0;

    // Чтение массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Обработка: для каждого элемента ищем, встречается ли он более одного раза
    for (int i = 0; i < 10; i++) {
        int current = arr[i];
        int count = 0;
        // Проверяем, сколько раз встречается текущий элемент
        for (int j = 0; j < 10; j++) {
            if (arr[j] == current) {
                count++;
            }
        }
        // Если более одного раза и еще не добавлен в результат
        if (count > 1) {
            int already_in_result = 0;
            for (int k = 0; k < count_result; k++) {
                if (result[k] == current) {
                    already_in_result = 1;
                    break;
                }
            }
            if (!already_in_result) {
                result[count_result++] = current;
            }
        }
    }

    // Вывод результата
    for (int i = 0; i < count_result; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
